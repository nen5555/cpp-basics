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

class RingBuffer{
public:
    RingBuffer();
    bool push(int value);
    bool pop(int& value);
    int size() const;
    bool empty() const;
    bool full() const;
private:
    static const int KCapacity = 4;
    int data_[KCapacity];
    int head_;
    int tail_;
    int count_;

};

 RingBuffer::RingBuffer():head_(0),tail_(0),count_(0){};

 bool RingBuffer::empty() const{
    
    return count_ ==0;
 }

 int RingBuffer::size() const{
    return count_;
 }
 bool RingBuffer::full() const{

    return count_ ==4;
 };

//head_ 为当前 应该存的数字的下标 tail_为当前取的数字的下标 count_为数目
//
//存一个数字 判断是为为满 满的话 设置为不能输入 
//当前为空的话 输入一个数字 先放进去  head 指向下一个存储的位置 
 bool RingBuffer::push(int value)  {
   if(full()){
    return false;
   }else{
    
    data_[(head_)%KCapacity] =value;
    head_= head_+1;
    count_+=1;
   }

   return true;
 }

  bool RingBuffer::pop(int& value)  {
   if(empty()){
    return false;
   }else{

    value = data_[tail_%KCapacity] ;

    std::cout <<"pop:"<<value<<std::endl;
    tail_ += 1;
    count_ -=1;;
   }
   return true;
 }




 int intersectArea(const Rect& a, const Rect& b){
    int area = 0;
    int lapLP = a.topRL.x > b.topRL.x?a.topRL.x: b.topRL.x;
    int lapRP = a.topRL.x+a.width > b.topRL.x+b.width ? b.topRL.x+b.width:a.topRL.x+a.width ;

    int lapHP = a.topRL.y > b.topRL.y?  a.topRL.y : b.topRL.y;
    int lapLoP = a.topRL.y+a.height > b.topRL.y+b.height ? b.topRL.y+b.height:a.topRL.y+a.height  ;

    if(lapLP  >= lapRP  || lapLoP <=lapHP){
        return area = 0;
    }else{
        area = (lapRP  - lapLP )*( lapLoP - lapHP );
    }


    return area;

 }


//计算 起始点的相对位置
//坐标系设置为 向右 向下为正 笛卡尔坐标系有点难思考 
//特殊情况 两个点一样 长度 宽度一样 则完全重合 
//假设 a矩形不变 b沿着对角线 向右下角移动 则重叠区域 (a.topRL.x+width - b.topRL.x )* a.topRL.y+height - b.topRL.y)
//特殊情况 如果 

//右上角移动时 重叠区域为  (b.height-(b.topRL.Y - a.topRL.y))*(a.width - (a.topRL.x -b.topRL.x))
//特殊情况 

// int intersectArea(const Rect& a, const Rect& b){
//     int area = 0;
//     //b点位于a点右下角情况 
//      //情况1 a.toprl.x+a.width < b.toplf.x || a.toprl.y+height <b.toprl.y 无重叠 0
//         //情况2 a.toprl.x+a.width > b.toprl.x+b.width && a.toprl.y+a.height >b.toprl.y+b.height 则完全包含 s=b.width*b.height
//         //情况3 只有 a.toprl.x+a.width > b.toprl.x+b.width 则面积为  b.width *(a.toprl.y + a.height - b.top.x)
//         //情况4 a.toprl.y+a.height >b.toprl.y+b.height则面积为 b.height *(a.toprl.x+a.width - b.topr1.x)
//         //最终情况 (a.toprl.y + a.height - b.top.x)**(a.toprl.x+a.width - b.topr1.x)
//     if(a.topRL.x <= b.topRL.x && a.topRL.y <= b.topRL.y){
//        if(a.topRL.x+a.width < b.topRL.x ||a.topRL.y+a.height<b.topRL.y){
//         area = 0;
//        }else if(a.topRL.x+a.width>b.topRL.x+b.width && a.topRL.y+a.height > b.topRL.y+b.height){
//         area= b.height*b.width;
//        }else if(a.topRL.x+a.width>b.topRL.x+b.width){
//         area = b.width * (a.topRL.y+a.height-b.topRL.y);
//        }else if( a.topRL.y+a.height > b.topRL.y+b.height)
//         {
//           area = b.height*(a.topRL.x+a.width - b.topRL.x);
//          }
//        else{
//         area = (a.topRL.y+a.height-b.topRL.y) *(a.topRL.x+a.width - b.topRL.x);
//        }   
//     } 
//     //b点位于a点右上角 情况类似
//     // 在右上角 所以只需要判断 b.topr.x 是否落在 a.topr.x+width 
//     //没落 area= 0
//     ///落在里面后 如果b.top.y+height <a.top.y s=0
//     // b.top.y+height > a.top.y 并且小于 a.top.y+height 则area = (a.top.x+width - b.topr.x)*(b.top.y+b.height -a.top.y) 
//     // 直接 大于 a.top.y+height area=a.height *(a.top.x+width - b.topr.x)
//     else if(a.topRL.x < b.topRL.x && a.topRL.y > b.topRL.y){
//         if(b.topRL.x >= a.topRL.x+a.width)
//         {
//             area = 0;
//         }
//         else {
//             if(b.topRL.y+b.height < a.topRL.y){
//                 area = 0;
//             }else if((b.topRL.y+b.height > a.topRL.y)&&(b.topRL.y+b.height < a.topRL.y+a.height)){
//                 area = (a.topRL.x+a.width - b.topRL.x)*(b.topRL.y+b.height-a.topRL.y);
//             }else{
//                 area = a.height *(a.topRL.x+a.width - b.topRL.x);
//             }
//         }

//     }// 假设b点在a点左上角 这等价于a b点交换相对位置 和 b点位于a点右下角情况一致 交换一下两个点即可
//     else if(a.topRL.x > b.topRL.x && a.topRL.y > b.topRL.y){
//         if(b.topRL.x+b.width < a.topRL.x ||b.topRL.y+b.height<a.topRL.y){
//         area = 0;
//        }else if(b.topRL.x+b.width>a.topRL.x+a.width && b.topRL.y+b.height > a.topRL.y+a.height){
//         area= a.height*a.width;
//        }else if(b.topRL.x+b.width>a.topRL.x+a.width){
//         area = a.width * (b.topRL.y+b.height-a.topRL.y);
//        }else if( b.topRL.y+b.height > a.topRL.y+a.height)
//         {
//           area = a.height*(b.topRL.x+b.width - a.topRL.x);
//          }
//        else{
//         area = (b.topRL.y+a.height-a.topRL.y) *(b.topRL.x+b.width - a.topRL.x);
//        }   
//         //同上
//     }else {
//         if(a.topRL.x >= b.topRL.x+b.width)
//         {
//             area = 0;
//         }
//         else {
//             if(a.topRL.y+a.height < b.topRL.y){
//                 area = 0;
//             }else if((a.topRL.y+a.height > b.topRL.y)&&(a.topRL.y+a.height < b.topRL.y+b.height)){
//                 area = (b.topRL.x+b.width - a.topRL.x)*(a.topRL.y+a.height-b.topRL.y);
//             }else{
//                 area = b.height *(b.topRL.x+b.width - a.topRL.x);
//             }
//         }
//     }
//     return area;


// };

int main(){
    Rect r{{0,0},10,5};
    Rect r1{{1,1},2,2};

    Point po{5,3};


    RingBuffer rb{};


    int area1 = 0;

    area1 = area(r);
    std::cout <<"the r's area is :" << area1 <<std::endl;

    bool inornotin = false;
    inornotin = contains(r,po);
    std::cout <<"the po in r is " << inornotin <<std::endl;

    int laparea = 0;
    laparea = intersectArea(r,r1);
    std::cout <<"the laparea is:"<<laparea<<std::endl;
 

    rb.empty();
    rb.push(1);
    rb.push(2);
    rb.push(3);
    rb.push(4);
    rb.push(5);

    int a;
    int b;
    

    rb.pop(a);
    rb.pop(b);

    rb.push(6);
    rb.push(7);
    int c,d,e,f;
    rb.pop(c);
    rb.pop(d);
    rb.pop(e);
    rb.pop(f);


        
    };

   


