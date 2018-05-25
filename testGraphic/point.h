#ifndef POINT_H
#define POINT_H


class Point{
public :
    Point(float xx = 0, float yy = 0) {
            _x = xx;
            _y = yy;
    }
    Point(const Point &p);

    float getX();
    float getY();
private:
    float _x;
    float _y;
};

#endif // POINT_H
