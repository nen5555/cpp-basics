#pragma once

#include "opencv2/core.hpp"

namespace vis {
// 版本 A：两点版
void drawBox(cv::Mat& img, cv::Point tl, cv::Point br,
             cv::Scalar color = cv::Scalar(0, 255, 0), int thickness = 2);
// 版本 B：Rect 版
void drawBox(cv::Mat& img, const cv::Rect& r,
             cv::Scalar color = cv::Scalar(0, 255, 0), int thickness = 2);
}