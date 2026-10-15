#pragma once
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

int area(const Rect& r);
bool contains(const Rect&r,const Point& p);

int intersectArea(const Rect& a, const Rect& b);