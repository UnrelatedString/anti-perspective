#include "internal-header.hpp"

int all_together(std::string const& filename) {
	cv::Mat vimage = cv::imread(filename);
	const cv::Size vsize{700, 700};
	int d = 1000, calib = 50; //assume fixed distance??
	double t;
	AntiPerspectiveViewer viewer(vimage, "Result", vsize, &d, &t);
	cv::createTrackbar("Calibrate", "Result", &calib, 100);

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
					mwfx = (frame.cols/2) - landmarks[27].x;
					cv::drawMarker(frame, landmarks[27], {0,0,255});
				}
				fnum++;
			}
		}
		//cv::imshow("Tracking",frame);

		//calib is 100* the pixel units distance over half the frame width
		t = std::acos(mwfx / (calib * frame.cols / 50));
		viewer.draw();
		//std::cout << mwfx << " " << calib << "\n";
		if ((cv::waitKey(1) & 0xff) == 27) break;
	}
	std::cout << "done\n";
	return 0;
}
