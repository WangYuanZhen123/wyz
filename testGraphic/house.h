#ifndef HOUSE_H
#define HOUSE_H
#include "line.h"
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"
#include <QPainter>

class House
{
public:
    House(){}
    House(Rectangle rec1, Rectangle rec2, Triangle tri, Circle cir, Line line1, Line line2);
    void show(QPainter & painter);
private:
    Rectangle _rec1;
    Rectangle _rec2;
    Triangle _tri;
    Circle _cir;
    Line _line1, _line2;
};

#endif // HOUSE_H
