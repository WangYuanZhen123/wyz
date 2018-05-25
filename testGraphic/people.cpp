#include "people.h"
#include <rectangle.h>
#include "point.h"
#include "line.h"
#include "circle.h"
#include "rectangle.h"
#include <cmath>
#include<algorithm>
#include<iostream>
#include <QPainter>

People::People(Circle cir, Rectangle rec, Line line1, Line line2, Line line3, Line line4, Line line5):
    _cir(cir),
    _rec(rec),
    _line1(line1),
    _line2(line2),
    _line3(line3),
    _line4(line4),
    _line5(line5)
{}

void People::show(QPainter &painter)
{
    this->_cir.show(painter);
    this->_rec.show(painter);
    this->_line1.show(painter);
    this->_line2.show(painter);
    this->_line3.show(painter);
    this->_line4.show(painter);
    this->_line5.show(painter);
}
