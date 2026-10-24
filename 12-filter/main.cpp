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

cv::Mat mannualFilter22D3x3(const cv::Mat& src, const cv::Mat& k){
    CV_Assert(src.type()==CV_8UC1);
    CV_Assert(k.rows == 3 && k.cols ==3);

    cv::Mat dst=cv::Mat::zeros(src.size(),CV_8UC1);

    for(int y = 1;y<src.rows-1;y++){
        const uchar* s0 = src.ptr<uchar>(y-1);
        const uchar* s1 = src.ptr<uchar>(y);
        const uchar* s2 = src.ptr<uchar>(y+1);

        uchar* d = dst.ptr<uchar>(y);

        for(int x=1;x<=src.cols-1;x++){
            float sum = 0.1f;
            sum+=s0[x-1]*k.at<float>(0,0);
            sum+=s0[x]*k.at<float>(0,1);
            sum+=s0[x+1]*k.at<float>(0,2);

            sum+=s1[x-1]*k.at<float>(1,0);
            sum+=s1[x  ]*k.at<float>(1,1);
            sum+=s1[x+1]*k.at<float>(1,2);


            sum+=s2[x-1]*k.at<float>(2,0);
            sum+=s2[x]*k.at<float>(2,1);
            sum+=s2[x+1]*k.at<float>(2,2);

            d[x] = cv::saturate_cast<char>(sum);
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

    std::cout << "saved bia0.png, size = " << bina.size() << std::endl;
    cv::Mat k=(cv::Mat_<float>(3,3)<<-1,-1,-1,-1,8,-1,-1,-1,-1);
    cv::Mat k1=(cv::Mat_<float>(3,3)<<1,1,1,1,1,1,1,1,1);
    cv::Mat k2=(cv::Mat_<float>(3,3)<<-1,0,1,-2,0,2,-1,-0,-1);
    cv::Mat k3=(cv::Mat_<float>(3,3)<<-1,-2,-1,0,0,0,1,2,1);

    cv::Mat mine = mannualFilter22D3x3(g,k);
    cv::Mat mine1 = mannualFilter22D3x3(g,k1);
    cv::Mat mine2 = mannualFilter22D3x3(g,k2);
    cv::Mat mine3 = mannualFilter22D3x3(g,k3);

    cv::imwrite("mine.png",mine);
    if (!cv::imwrite("mine.png", mine)) {
        std::cerr << "gen mine imwrite failed" << std::endl;
        return 1;
    }

    cv::imwrite("mine1.png",mine1);
    if (!cv::imwrite("mine1.png", mine1)) {
        std::cerr << "gen mine1 imwrite failed" << std::endl;
        return 1;
    }
        cv::imwrite("mine2.png",mine2);
    if (!cv::imwrite("mine2.png", mine2)) {
        std::cerr << "gen mine2 imwrite failed" << std::endl;
        return 1;
    }
        cv::imwrite("mine3.png",mine3);
    if (!cv::imwrite("mine3.png", mine3)) {
        std::cerr << "gen mine3 imwrite failed" << std::endl;
        return 1;
    }

    std::cout << "saved gen.png, size = " << bina.size() << std::endl;
        return 1;

}


