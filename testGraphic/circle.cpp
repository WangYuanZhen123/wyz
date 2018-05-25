#include "circle.h"
#include <QPainter>
#include <cmath>
#include<algorithm>
#include<iostream>
using namespace std;

Circle::Circle(Point &core, int a, int b):
    _core(core),
    _a(a),
    _b(b)
{}

void Circle::show(QPainter & painter){
    painter.drawEllipse(this->_core.getX(),this->_core.getY(),this->_a,this->_b);
}
