#include "draw.h"
namespace vis {
    void drawBox(cv::Mat& img, cv::Point tl, cv::Point br,
             cv::Scalar color , int thickness){
        
        cv::Rect rect1(tl.x, tl.y, br.x-tl.x, br.y-tl.y);
        cv::rectangle(img,rect1,color,thickness);


             };
// 版本 B：Rect 版
void drawBox(cv::Mat& img, const cv::Rect& r,
             cv::Scalar color, int thickness){
        
    drawBox( img, r.tl(),r.br(), color, thickness);

  
             };
}
