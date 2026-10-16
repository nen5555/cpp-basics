#include "opencv2/opencv.hpp"
#include <iostream>
#include "draw.h"
#include <string>

int main(){
    cv::Point p1(0,0);
    cv::Point p2(640,640);

    cv::Rect r1 = {0, 0, 640, 512};
    cv::Rect r2 = {100, 120, 640, 512};
 
    cv::Mat img = cv::Mat::zeros(800, 800, CV_8UC3);
     vis::drawBox(img, p1, p2,cv::Scalar(0, 0, 255),2);
    vis::drawBox(img,r1,cv::Scalar(0, 255, 0), 2);
   

    
    std::cout << "img: " << img.cols << " x " << img.rows << "\n";
    std::cout << "p1: " << p1 << "  p2: " << p2 << "\n";
    std::cout << "rect: " << cv::Rect(p1, p2) << "\n";  // 看 w/h 是否合理

    cv::imwrite("out.png", img);

    return 0;


}