#include "internal-header.hpp"
/*
#include <boost/math/special_functions/sin_pi.hpp>
#include <boost/math/special_functions/cos_pi.hpp>
*/

#define PLENTY_DIGITS_OF_TAU 6.28318530717958647692528676655900576839433879875021164194988918461563281257241799725606965068423413596429617302656


AntiPerspectiveViewer::AntiPerspectiveViewer(cv::InputArray image_unsized,
					  cv::String windowname,
					  cv::Size size,
					  int *distance,
					  double *angle) :
					  windowname{windowname},
					  size{size},
					  distance{distance},
					  angle{angle} {
	cv::namedWindow(windowname,cv::WINDOW_NORMAL);
	cv::resize(image_unsized, image, size, 0, 0, cv::INTER_NEAREST);
}

void AntiPerspectiveViewer::draw() {
	cv::Mat frame;
	counter_perspective(image, frame, size, *distance, *angle);
	cv::imshow(windowname, frame);
}

void AntiPerspectiveViewer::counter_perspective(cv::InputArray src,
								cv::OutputArray dst,
								cv::Size size,
								int d,
								double theta) {
	//swapping sine and cosine instead of subtracting 90 degrees from theta
	double st = std::cos(theta);
	double ct = std::sin(theta);
	int x = size.width/2, y = size.height/2;
	cv::warpPerspective(src, dst, cv::Matx<double, 3, 3>(
			d + (x * st), 0, x * ((d * ct) - d - (x * st)),
			y * st, d * ct, -x * y * st, //would it be faster to translate on the GPU?
			st, 0, (d * ct) - (x * st)
		), size);
}

int run_viewer() {
	cv::Mat image = cv::imread("8by8m.png");
	const cv::Size size{700, 700};
	int d, ind = 10, in_t = 91;
	double t;
	AntiPerspectiveViewer viewer(image, "Result", size, &d, &t);
	if (image.size().empty()) return 1;
	cv::imshow("Source", image);
	cv::createTrackbar("Distance", "Result", &ind, 100);
	cv::createTrackbar("Angle", "Result", &in_t, 180);
	while ((cv::waitKey(100) & 0xff) != 27) {
		d = 100 * ind;
		t = PLENTY_DIGITS_OF_TAU * in_t / (double)360;
		viewer.draw();
	}
	return 0;
}

//Test
