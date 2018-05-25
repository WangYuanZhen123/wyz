#ifndef PEOPLE_H
#define PEOPLE_H
#include "rectangle.h"
#include "triangle.h"
#include "line.h"
#include "circle.h"
#include <QPainter>

class People
{
public:
    People(){}
    People(Circle cir, Rectangle rec, Line line1, Line line2, Line line3, Line line4, Line line5);
    void show(QPainter & painter);
private:
    Circle _cir;
    Rectangle _rec;
    Line _line1, _line2, _line3, _line4, _line5;
};

#endif // PEOPLE_H
