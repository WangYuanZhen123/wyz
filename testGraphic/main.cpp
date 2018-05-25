#include "mainwindow.h"
#include <QApplication>
#include <QPainter>
#include "line.h"
#include "point.h"
#include "rectangle.h"
#include "triangle.h"
#include "house.h"
#include "circle.h"
#include "people.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Point  p1(600,200), p2(300,500), p3(900,500), p4(300,900), p5(900,900), p6(450,900), p7(600,680), p8(700,560);
    Point p9(700,600), p90(780,600), p10(740,560), p100(740,640);
    Rectangle rec1(p3, p4);
    Rectangle rec2(p6, p7);
    Triangle tri(p1,p2,p3);
    Circle circle(p8, 80, 80);
    Line line11(p9,p90), line22(p10,p100);
    House house(rec1, rec2, tri, circle, line11, line22);

    Point pp1(1210,500), pp2(1250,600), pp3(1250,640), pp4(1190,800), pp5(1310,640);
    Point pp6(1190,700), pp60(1100,750),pp7(1310,700),pp70(1400,750),pp8(1210,800),pp80(1190,900),pp9(1290,800),pp90(1310,900);
    Circle circle1(pp1,80,100);
    Rectangle rec3(pp4,pp5);
    Line line1(pp2,pp3), line2(pp6,pp60), line3(pp7,pp70), line4(pp8,pp80), line5(pp9,pp90);
    People people(circle1, rec3, line1, line2, line3, line4, line5);
    w.setHouse(house);
    w.setPeople(people);
 //   w.setCircle(circle);
 //   w.setRectangle(rec);
 //   w.setTriangle(tri);
    w.show();

    return a.exec();
}
