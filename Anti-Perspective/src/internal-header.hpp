#ifndef INTERNAL_HEADER_HPP_
#define INTERNAL_HEADER_HPP_

#include <opencv2/opencv.hpp>
#include <opencv2/face.hpp>
#include <utility>

class AntiPerspectiveViewer {
	int *distance;
	double *angle;
	cv::String windowname;
	cv::Mat image;
	cv::Size size;
public:
	AntiPerspectiveViewer(cv::InputArray image_unsized,
				              cv::String windowname,
							  cv::Size size,
							  int *distance,
							  double *angle);
	void draw();
	static void counter_perspective(cv::InputArray src,
								        cv::OutputArray dst,
								        cv::Size size,
								        int d,
								        double theta);
};

class RepeatedFacemarkDetection {
	cv::CascadeClassifier face_detector;
	cv::Ptr<cv::face::Facemark> facemark;
	int pmwidth;
	int fails;
	int maxdelta;
public:
	RepeatedFacemarkDetection(int maximum_delta);
	std::pair<std::vector<std::vector<cv::Point2f> >, int> get_face(cv::Mat frame);
};

int run_viewer();
int select();
int repeated_detection_mysterious();
int all_together();

#endif
