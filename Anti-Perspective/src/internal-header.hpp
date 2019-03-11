#ifndef INTERNAL_HEADER_HPP_
#define INTERNAL_HEADER_HPP_

#include <opencv2/opencv.hpp>

void counter_perspective(cv::InputArray, cv::OutputArray, cv::Size, int, int);
int run_viewer();
int select();
int repeated_detection_old();

#endif
