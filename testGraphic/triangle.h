#ifndef TRIANGLE_H
#define TRIANGLE_H
#include<string.h>
#include "point.h"
#include "line.h"
#include <QPainter>

class Triangle
{
public:
    Triangle(){}
    Triangle(Point &pp1, Point &pp2, Point &pp3);
    void show(QPainter & painter);
private:
    Point _pp1, _pp2, _pp3;
    Line line1, line2, line3;
};

#endif // TRIANGLE_H
