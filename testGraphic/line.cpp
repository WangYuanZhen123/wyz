#include "line.h"
#include <QPainter>
#include <cmath>
#include<algorithm>
#include<iostream>
using namespace std;


Line::Line(Point &a, Point &b):_pa(a),_pb(b){
}

Line::Line (Line &l): _pa(l._pa), _pb(l._pb) {//组合类的复制构造函数
}

void Line::show(QPainter & painter){
    //painter.save();
    painter.drawLine(this->_pa.getX(),this->_pa.getY(),this->_pb.getX(),this->_pb.getY());
    //painter.restore();
}

