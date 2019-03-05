#include "internal-header.hpp"

#include <iostream>
#include <vector>
#include <opencv2/face.hpp>
#include <cmath>

int select() {
    cv::Ptr<cv::face::Facemark> facemark = cv::face::FacemarkLBF::create();
    facemark->loadModel("lbfmodel.yaml");
    cv::VideoCapture cam(0);
    cv::Mat frame;
    cam.read(frame);
    cam.read(frame);
    cv::Rect r;
    std::vector<cv::Rect> i{ {0, 0, 0, 0} };
    std::vector< std::vector<cv::Point2f> > o;
    while ((r = cv::selectROI("Image", frame)).height) {
        i[0] = r;
        facemark->fit(frame, i, o);
        cv::face::drawFacemarks(frame, o[0]);
        cv::drawMarker(frame, o[0][27], {0,255,0});
        cv::rectangle(frame, r, {0, 0, 255});
        cv::imshow("Image", frame);
        cv::waitKey(0);
        cam.read(frame);
    }
    return 0;
}
