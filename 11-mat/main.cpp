#include "opencv2/opencv.hpp"
#include <iostream>
#include <string>
#include "opencv2/imgproc.hpp"

void printInfo(const cv::Mat& m){
    std::cout << "Rows: " << m.rows << std::endl;
    std::cout << "Cols: " << m.cols << std::endl;
    std::cout << "Channels: " << m.channels() << std::endl;
    std::cout << "Type: " << m.type() << std::endl;
    std::cout << "Depth: " << m.depth() << std::endl;
    std::cout << "Size: " << m.elemSize() << std::endl;
    std::cout << "Step Size: " << m.step << std::endl;
    std::cout << "Is Continuous: " << m.isContinuous() << std::endl;


};

cv::Mat toGray(const cv::Mat& bgr){
    cv::Mat gray(bgr.rows, bgr.cols, CV_8UC1);
    for(int i = 0; i < bgr.rows; ++i){
        for(int j = 0; j < bgr.cols; ++j){
            cv::Vec3b px = bgr.at<cv::Vec3b>(i, j);
            uchar grayValue = static_cast<uchar>(0.299 * px[2] + 0.587 * px[1] + 0.114 * px[0]);
            gray.at<uchar>(i, j) = grayValue;
        }
    }
    return gray;
}


int main(){
    cv::Mat img = cv::imread("data/baboon.jpg");
    if(img.empty()){
        std::cerr << "Error: Could not read image" << std::endl;
        return 1;
    }
    printInfo(img);

    cv::Vec3b px = img.at<cv::Vec3b>(20, 10);// Access pixel at (x, y)

    std::cout << "Pixel Value: " << px << std::endl;

    cv::Mat gray = toGray(img);
    cv::Mat gray1(img.rows, img.cols, CV_8UC1);  
    cv::cvtColor(img, gray1, cv::COLOR_BGR2GRAY);
    double maxDiff = cv::norm(gray, gray1, cv::NORM_INF);  
    std::cout << "Maximum difference between custom and OpenCV grayscale: " << maxDiff << std::endl;

    cv::imwrite("gray_mine.png", gray);

    cv::Mat a =img;
    cv::Mat c =img.clone();


    img.setTo(cv::Scalar(0, 0, 255)); // Set all pixels to red
    cv::imwrite("low_copy.png", a);
    cv::imwrite("high_copy.png", c);

    std::cout << "(void*)img.data: " << (void*)img.data << std::endl;
    std::cout << "(void*)a.data: " << (void*)a.data << std::endl;
    std::cout << "(void*)c.data: " << (void*)c.data << std::endl;


    return 0;


}

/*
记录 
(void*)img.data: 0x7cf0bda30840
(void*)a.data: 0x7cf0bda30840
(void*)c.data: 0x7cf0ba73e840
a是low copy, c是high copy
a的数据和img共享, c的数据是独立的
img变化时 c不会变化, a会变化

所以一般都是low copy.深copy浪费资源

result:
time@CHINAMI-MOUF7VN:~/dev/cpp-basics/11-mat$ ./build/main 
Rows: 512
Cols: 512
Channels: 3
Type: 16
Depth: 0
Size: 3
Step Size: 1536
Is Continuous: 1
Pixel Value: [69, 170, 172]
Maximum difference between custom and OpenCV grayscale: 1
(void*)img.data: 0x7cf0bda30840
(void*)a.data: 0x7cf0bda30840
(void*)c.data: 0x7cf0ba73e840
*/