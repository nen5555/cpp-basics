#include "draw.h"
#include "opencv2/imgproc.hpp"

 namespace vis {  void drawBox(cv::Mat& img, cv::Point tl, cv::Point br,
             cv::Scalar color , int thickness){
        
        cv::rectangle(img,tl,br,color,thickness);

             };
         
// 版本 B：Rect 版
void drawBox(cv::Mat& img, const cv::Rect& r,
             cv::Scalar color, int thickness){
        
    drawBox( img, r.tl(),r.br(), color, thickness);

             };
    
            }