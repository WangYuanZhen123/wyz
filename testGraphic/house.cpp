#include "house.h"
#include <rectangle.h>
#include "point.h"
#include "line.h"
#include "circle.h"
#include <cmath>
#include<algorithm>
#include<iostream>
#include <QPainter>
using namespace std;

House::House(Rectangle rec1, Rectangle rec2, Triangle tri, Circle cir, Line line1, Line line2):
    _rec1(rec1),
    _rec2(rec2),
    _tri(tri),
    _cir(cir),
    _line1(line1),
    _line2(line2)
{}

void House::show(QPainter &painter)
{
    this->_rec1.show(painter);
    this->_rec2.show(painter);
    this->_tri.show(painter);
    this->_cir.show(painter);
    this->_line1.show(painter);
    this->_line2.show(painter);
}

