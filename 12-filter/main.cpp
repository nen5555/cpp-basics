#include "opencv2/opencv.hpp"
#include <iostream>
#include <string>
#include "opencv2/imgproc.hpp"

cv::Mat mannalTthreshold(const cv::Mat& src ,double T){
    cv::Mat dst = cv::Mat::zeros(src.size(),CV_8UC1);
    for(int y=0;y<src.rows;y++){
        const uchar* s = src.ptr<uchar>(y);
        uchar * d = dst.ptr<uchar>(y);
        for(int x=0;x<src.cols;++x){
            d[x]=(s[x]>T)?255:0;
        }

    }
    return dst;
}



int main(){
    cv::Mat g = cv::imread("data/baboon.jpg", cv::IMREAD_GRAYSCALE);
    if(g.empty()){
        std::cerr << "Error: Could not read image" << std::endl;
        return 1;
      
    }
      double T=128;
        cv::Mat bina = mannalTthreshold(g,T);
        cv::imwrite("bina0.png",bina);
        
    if (!cv::imwrite("bina0.png", bina)) {
        std::cerr << "imwrite failed" << std::endl;
        return 1;
    }

    std::cout << "saved bina0.png, size = " << bina.size() << std::endl;
    return 0;
        return 1;

}


