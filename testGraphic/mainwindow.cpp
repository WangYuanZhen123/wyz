#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter> 
#include "rectangle.h"
#include "triangle.h"
#include "house.h"
#include "circle.h"
#include "people.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
} 

void MainWindow::setRectangle(Rectangle rec){
    this->_rec = rec;
}

void MainWindow::setTriangle(Triangle tri){
    this->_tri = tri;
}

void MainWindow::setHouse(House house){
    this->_house = house;
}

void MainWindow::setCircle(Circle circle){
    _circle = circle;
}

void MainWindow::setPeople(People people){
    _people = people;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);    
    painter.setPen(QPen(Qt::blue,4));//设置画笔形式
  //  this->_rec.show(painter);
    //this->_tri.show(painter);
    this->_house.show(painter);
   // this->_circle.show(painter);
    this->_people.show(painter);
}


