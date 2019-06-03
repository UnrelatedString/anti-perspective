#include "internal-header.hpp"

#include <boost/math/special_functions/sin_pi.hpp>
#include <boost/math/special_functions/cos_pi.hpp>

class AntiPerspectiveViewer {

	int *distance;
	int *angle;
	cv::String windowname;
	cv::Mat image;
	cv::Size size;

public:

	AntiPerspectiveViewer(cv::InputArray image_unsized,
			              cv::String windowname,
						  cv::Size size,
						  int *distance,
						  int *angle) :
						  windowname{windowname},
						  size{size},
						  distance{distance},
						  angle{angle} {
		cv::namedWindow(windowname,cv::WINDOW_NORMAL);
		cv::resize(image_unsized, image, size, 0, 0, cv::INTER_NEAREST);
	}

	void draw() {
		cv::Mat frame;
		counter_perspective(image, frame, size, *distance, *angle);
		cv::imshow(windowname, frame);
	}

	static void counter_perspective(cv::InputArray src,
							        cv::OutputArray dst,
							        cv::Size size,
							        int d,
							        int theta) {
		//swapping sine and cosine instead of subtracting 90 degrees from theta
		double st = boost::math::cos_pi(theta/(double)180);
		double ct = boost::math::sin_pi(theta/(double)180);
		int x = size.width/2, y = size.height/2;
		cv::warpPerspective(src, dst, cv::Matx<double, 3, 3>(
				d + (x * st), 0, x * ((d * ct) - d - (x * st)),
				y * st, d * ct, -x * y * st, //would it be faster to translate on the GPU?
				st, 0, (d * ct) - (x * st)
			), size);
	}

};

int run_viewer() {
	cv::Mat image = cv::imread("8by8m.png");
	const cv::Size size{700, 700};
	int d, ind = 10, t = 91;
	AntiPerspectiveViewer viewer(image, "Result", size, &d, &t);
	if (image.size().empty()) return 1;
	cv::imshow("Source", image);
	cv::createTrackbar("Distance", "Result", &ind, 100);
	cv::createTrackbar("Angle", "Result", &t, 180);
	while ((cv::waitKey(100) & 0xff) != 27) {
		d = 100 * ind;
		viewer.draw();
	}
	return 0;
}

//Test
