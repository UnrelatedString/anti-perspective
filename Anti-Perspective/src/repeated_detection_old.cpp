#include "internal-header.hpp"

#include <opencv2/face.hpp>

class RepeatedFacemarkDetection {

	cv::CascadeClassifier face_detector;
	cv::Ptr<cv::face::Facemark> facemark;
	int pmwidth;
	int fails;
	int maxdelta;

public:

	RepeatedFacemarkDetection(int maximum_delta) :
		face_detector("/usr/local/share/OpenCV/haarcascades/haarcascade_frontalface_default.xml"),
		facemark{cv::face::FacemarkLBF::create()},
		pmwidth{0},
		fails{0},
		maxdelta{maximum_delta}
	{
		facemark->loadModel("lbfmodel.yaml");
	}

	std::pair<std::vector< std::vector<cv::Point2f> >, int> get_face(cv::Mat frame) {
		cv::Mat gray;
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
			return std::make_pair(landmarks, mwfnum);
		} else {
			return {{}, -1};
		}
	}
};

int repeated_detection_mysterious() {
	cv::Mat frame;
	cv::VideoCapture cam(0);
	cam.read(frame);
	cam.read(frame);
	RepeatedFacemarkDetection detector(frame.cols / 20);
	std::pair<std::vector< std::vector<cv::Point2f> >, int> face_data;
	std::vector< std::vector<cv::Point2f> > faces;
	int fnum;
	int mwfnum;
	while (1) {
		cam.read(frame);
		face_data = detector.get_face(frame);
		faces = face_data.first;
		mwfnum = face_data.second;
        if (mwfnum != -1) {
            fnum = 0;
            for (std::vector<cv::Point2f> const& landmarks : faces) {
                cv::face::drawFacemarks(frame, landmarks);
                cv::drawMarker(frame, landmarks[27], {0,255,0}); // point between eyes
                if (mwfnum == fnum) {
                    //cv::rectangle(frame, face_rectangles[fnum], {0, 0, 255}, 3); // should it also still be able to get the rectangles?
                    //std::cout << landmarks[27] << std::endl;
                	cv::drawMarker(frame, landmarks[27], {0,0,255});
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
