#include "opencv2/opencv.hpp"
#include <iostream>
#include "draw.h"
#include <string>

int main(){
    cv::Point p1(50,50);
    cv::Point p2(150,120);

    cv::Rect r1 = {200, 80, 120, 100};
    cv::Rect r2 = {60, 180, 80, 60};
 
    cv::Mat img = cv::Mat::zeros(300, 400, CV_8UC3);
     vis::drawBox(img, p1, p2);
    vis::drawBox(img,r1,cv::Scalar(0,  0,255), 3);
    vis::drawBox(img,r2,cv::Scalar(255,0 , 0), 2);
  


    cv::imwrite("out.png", img);

    return 0;


}