#include "geometry.h"

int area(const Rect& r){
    return r.width*r.height;
};

bool contains(const Rect&r,const Point& p){
    if(p.x>=r.topRL.x && p.y>=r.topRL.y && p.x <=r.topRL.x + r.width && p.y <= r.topRL.y + r.height)
     return true;

     else
      return false;
};

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
        //area = (lapRP  - lapLP )*( lapHP - lapLoP );
    }


    return area;

 };

 /*
 /home/time/dev/cpp-basics/08-gtest/tests/test_geometry.cpp:41: Failure
Expected equality of these values:
  intersectArea(r1,r2)
    Which is: -4
  4

/home/time/dev/cpp-basics/08-gtest/tests/test_geometry.cpp:42: Failure
Expected equality of these values:
  intersectArea(r1,r3)
    Which is: -10
  10

/home/time/dev/cpp-basics/08-gtest/tests/test_geometry.cpp:43: Failure
Expected equality of these values:
  intersectArea(r1,r4)
    Which is: -1
  1

[  FAILED  ] geometrytest.intersectAreatest (0 ms)
[----------] 3 tests from geometrytest (7 ms total)

[----------] Global test environment tear-down
[==========] 8 tests from 2 test suites ran. (7 ms total)
[  PASSED  ] 7 tests.
[  FAILED  ] 1 test, listed below:
[  FAILED  ] geometrytest.intersectAreatest
 */