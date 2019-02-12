#include <iostream>
#include <opencv2/opencv.hpp>
#include <cmath>
#include <boost/math/special_functions/sin_pi.hpp>
#include <boost/math/special_functions/cos_pi.hpp>
#include <utility>

int run_viewer() {
    cv::Mat image = cv::imread("8by8m.png");
    const cv::Size size{700, 700};
    if (image.size().empty()) return 1;
    cv::resize(image, image, size, 0, 0, cv::INTER_NEAREST);
    cv::imshow("Source", image);
    cv::namedWindow("Result");
    int ind = 10, t = 91; //ind = input distance, highgui doesn't like having a slider from 0 to 10000
    cv::createTrackbar("Distance", "Result", &ind, 100);
    cv::createTrackbar("Angle", "Result", &t, 180);
    cv::Mat frame;
    const int x = size.width/2, y = size.height/2;
    double st, ct;
    int d;
    while ((cv::waitKey(100) & 0xff) != 27) {
        //swapping sine and cosine instead of subtracting 90 degrees from t
        st = boost::math::cos_pi(t/(double)180);
        ct = boost::math::sin_pi(t/(double)180);
        d = 100 * ind;
        cv::warpPerspective(image, frame, cv::Matx<double, 3, 3>(
            d + (x * st), 0, x * ((d * ct) - d - (x * st)),
            y * st, d * ct, -x * y * st, //would it be faster to translate on the GPU?
            st, 0, (d * ct) - (x * st)
        ), size);
        cv::imshow("Result", frame);
    }
    return 0;
}
