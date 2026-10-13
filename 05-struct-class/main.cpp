#include<iostream>
#include<algorithm>
#include<limits>
#include<vector>
#include<string>
#include<cctype>
#include<sstream>

struct Point{
    int x;
    int y;
};

struct Rect{
    Point topRL;
    int width;
    int height;
};

int area(const Rect& r){
    return r.width*r.height;
};
bool contains(const Rect&r,const Point& p){
    if(p.x>=r.topRL.x && p.y>=r.topRL.y && p.x <=r.topRL.x + r.width && p.y <= r.topRL.y + r.height)
     return true;

     else
      return false;
};

//计算 起始点的相对位置
//特殊情况 两个点一样 长度 宽度一样 则完全重合 
//假设 a矩形不变 b沿着对角线 向右下角移动 则重叠区域 (a.topRL.x+width - b.topRL.x )* a.topRL.y+height - b.topRL.y)
//右上角移动时 a 

int intersectArea(const Rect& a, const Rect& b){


};
