#include "triangle.h"
#include "point.h"
#include "line.h"
#include <cmath>
#include<algorithm>
#include<iostream>
#include <QPainter>
using namespace std;

Triangle::Triangle(Point &pp1, Point &pp2, Point &pp3):
    _pp1(pp1),
    _pp2(pp2),
    _pp3(pp3),
    line1(_pp1,_pp2),
    line2(_pp1,_pp3),
    line3(_pp2,_pp3)
{}
void Triangle::show(QPainter &painter)
{
    this->line1.show(painter);
    this->line2.show(painter);
    this->line3.show(painter);
}
