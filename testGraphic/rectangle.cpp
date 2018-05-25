#include <rectangle.h>
#include "point.h"
#include "line.h"
#include <cmath>
#include<algorithm>
#include<iostream>
#include <QPainter>
using namespace std;

Rectangle::Rectangle(Point &lb_pt, Point &rt_pt):
    _LB(lb_pt),
    _RT(rt_pt),
    _LT(_LB.getX(),_RT.getY()),
    _RB(_RT.getX(),_LB.getY()),
    _left_line(_LB,_LT),
    _right_line(_RB,_RT),
    _bottom_line(_LB,_RB),
    _top_line(_LT,_RT)
{}

Rectangle::Rectangle(const Rectangle &rec):
    _LB( rec._LB),
    _RT( rec._RT),
    _LT(_LB.getX(),_RT.getY()),
    _RB(_RT.getX(),_LB.getY()),
     _left_line(_LB,_LT),
     _right_line(_RB,_RT),
     _bottom_line(_LB,_RB),
     _top_line(_LT,_RT)
{

}
void Rectangle::show(QPainter &painter){
    this->_left_line.show(painter);
    this->_bottom_line.show(painter);
    this->_right_line.show(painter);
    this->_top_line.show(painter);
}
