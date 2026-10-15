#include "opencv2/opencv.hpp"
#include <iostream>
#include "geometry.h"
#include <string>

int main(){
    Rect r1 = {{0, 0}, 640, 512};
    Rect r2 = {{100, 120}, 640, 512};
    std::cout << intersectArea(r1, r2) << std::endl;

    cv::Mat img1 = cv::Mat::zeros(480, 640, CV_8UC3);
    cv::Mat img2 = cv::Mat::zeros(480, 640, CV_8UC3);
    cv::Mat img = cv::Mat::zeros(800, 800, CV_8UC3);

    

    cv::Rect rect1(r1.topRL.x, r1.topRL.y, r1.width, r1.height);
    cv::Rect rect2(r2.topRL.x, r2.topRL.y, r2.width, r2.height);

 
    cv::rectangle(img, rect1, cv::Scalar(0, 255, 0), -1);
    cv::rectangle(img, rect2, cv::Scalar(0, 0, 255), -1);

    cv::Rect intersectionRectarea = rect1 & rect2;
    int area = intersectionRectarea.area();
    std::cout << "Intersection area: " << area << std::endl;

    std::string text = "area"+std::to_string(area);
    cv::putText(img, text, cv::Point(10, 30), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(255, 255, 255), 2);

    cv::imwrite("out.png", img);



    return 0;


}