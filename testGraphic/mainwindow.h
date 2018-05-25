#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "point.h"
#include "rectangle.h"
#include "triangle.h"
#include "house.h"
#include "circle.h"
#include "people.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setRectangle(Rectangle rec);
    void setTriangle(Triangle tri);
    void setHouse(House house);
    void setCircle(Circle circle);
    void setPeople(People people);
protected:
    void paintEvent(QPaintEvent *);

private:
    Ui::MainWindow *ui;
    Rectangle _rec;
    Triangle _tri;
    House _house;
    Circle _circle;
    People _people;
};

#endif // MAINWINDOW_H
