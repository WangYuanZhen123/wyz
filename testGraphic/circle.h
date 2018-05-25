#ifndef CIRCLE_H
#define CIRCLE_H
#include <QPainter>
#include "point.h"

class Circle
{
public:
    Circle(){}
    Circle(Point &core, int a, int b);
    void show(QPainter & painter);
private:
    Point _core;
    int _a, _b;
};

#endif // CIRCLE_H
