#include "internal-header.hpp"

#include <opencv2/face.hpp>

int repeated_detection_old() {
    cv::CascadeClassifier face_detector("/usr/local/share/OpenCV/haarcascades/haarcascade_frontalface_default.xml");
    cv::Ptr<cv::face::Facemark> facemark = cv::face::FacemarkLBF::create();
    facemark->loadModel("lbfmodel.yaml");
    cv::VideoCapture cam(0);
    cv::Mat frame, gray;
    cam.read(frame);
    int pmwidth = 0;
    int fails = 0;
    int maxdelta = frame.cols / 20;
    while (cam.read(frame)) {
        std::vector<cv::Rect> faces;
        cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
        face_detector.detectMultiScale(gray, faces);
        int mwidth = 0;
        int fnum = 0;
        int mwfnum = -1;
        for (cv::Rect const& f : faces) {
            if (f.width > mwidth) {
                mwidth = f.width;
                mwfnum = fnum;
            }
            fnum++;
        }
        if (pmwidth && mwidth && (std::abs(pmwidth - mwidth) < maxdelta))
            fails = 0;
        else {
            fails++;
            if (fails > 10)
                pmwidth = 0;
        }
        std::vector< std::vector<cv::Point2f> > landmarks;
        // to do: find best face, possibly crop input to expanded roi to aid in pseudo-tracking
        // best face possibly most stable, possibly largest, ???
        // handle it not being present
        if (facemark->fit(frame, faces, landmarks)) {
            fnum = 0;
            for (std::vector<cv::Point2f> const& v : landmarks) {
                cv::face::drawFacemarks(frame, v);
                cv::drawMarker(frame, v[27], {0,255,0}); // point between eyes
                if (mwfnum == fnum) {
                    cv::rectangle(frame, faces[fnum], {0, 0, 255}, 3);
                    //std::cout << v[27] << std::endl;
                }
                fnum++;
            }
        }
        else
            cv::putText(frame, "Detection failed!", {100, 80}, cv::FONT_HERSHEY_SIMPLEX, .75, {255, 0, 255});
        cv::imshow("Facemark Text", frame);
        if ((cv::waitKey(1) & 0xff) == 27) break;
    }
    std::cout << "done";
    return 0;
}
