#include "internal-header.hpp"

int all_together() {
	cv::Mat vimage = cv::imread("8by8m.png");
	const cv::Size vsize{700, 700};
	int d = 10, calib, t = 91;
	AntiPerspectiveViewer viewer(vimage, "Result", vsize, &d, &t);
	cv::createTrackbar("Calibrate", "Result", &calib, 500);

	cv::VideoCapture cam(0);
	cv::Mat frame;
	cam.read(frame);
	cam.read(frame);
	RepeatedFacemarkDetection detector(frame.cols / 20);
	std::pair<std::vector< std::vector<cv::Point2f> >, int> face_data;
	std::vector< std::vector<cv::Point2f> > faces;
	int fnum;
	int mwfnum;

	float mwfx; //why is it a float?

	while (1) {
			cam.read(frame);
			face_data = detector.get_face(frame);
			faces = face_data.first;
			mwfnum = face_data.second;
	        if (mwfnum != -1) {
	            fnum = 0;
	            for (std::vector<cv::Point2f> const& landmarks : faces) {
	                if (mwfnum == fnum) {
	                	mwfx = landmarks[27].x;
	                }
	                fnum++;
	            }
	        }

	        if ((cv::waitKey(1) & 0xff) == 27) break;
	    }
}
