#include "point.h"
#include <cmath>
#include<algorithm>
#include<iostream>
using namespace std;

Point::Point(const Point &p) {	//复制构造函数的实现
    _x = p._x;
    _y = p._y;
    //cout<< "Calling the copy constructor of Point"<<this->getX()<<","<<this->getY()<< endl;
}


float Point::getX(){
    return this->_x;
}
float Point::getY(){
    return this->_y;
}


