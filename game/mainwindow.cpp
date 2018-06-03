#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "icon.h"
#include <QTimer>
#include <map>
#include <iostream>
#include <QPixmap>
#include <QCursor>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _game.initWorld("");//TODO 应该是输入有效的地图文件
    QCursor *myCursor=new QCursor(QPixmap("C:\\Users\\67549\\Desktop\\5690530967350055f\\more\\cursor.png"),-1,-1);
    this->setCursor(*myCursor);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter *pa;
    pa = new QPainter();
    pa->begin(this);
    this->_game.showback(pa);
    pa->drawPixmap(rect(),QPixmap ("C:\\Users\\67549\\Desktop\\Qt.map\\back.jpg"));

    this->_game.show(pa);
/*    if(i==1)
    {
        pa->drawImage(QRect (100,200,38,89),QImage ("C:\\Users\\67549\\Desktop\\5690530967350055f\\NPC_1\\03\\image 1.png"),QRect (0,0,38,89));
        i=2;
    }
    if(i==2)
    {
        pa->drawImage(QRect (100,200,38,202),QImage ("C:\\Users\\67549\\Desktop\\5690530967350055f\\NPC_1\\03\\image 3.png"),QRect (0,0,38,89));
        i=3;
    }
    if(i==3)
    {
        pa->drawImage(QRect (100,200,38,215),QImage ("C:\\Users\\67549\\Desktop\\5690530967350055f\\NPC_1\\03\\image 5.png"),QRect (0,0,38,89));
        i=0;
    }*/
    pa->end();
    delete pa;

}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    //direction = 1,2,3,4 for 上下左右
    if(e->key() == Qt::Key_A)
    {
        this->_game._player.changedirect(3);
        this->_game.handlePlayerMove1(3,16);

    }
    else if(e->key() == Qt::Key_D)
    {
        this->_game._player.changedirect(4);
        this->_game.handlePlayerMove1(4,16);

    }
    else if(e->key() == Qt::Key_W)
    {
        this->_game._player.changedirect(1);
        this->_game.handlePlayerMove1(1,16);
    }
    else if(e->key() == Qt::Key_S)
    {
         this->_game._player.changedirect(2);
         this->_game.handlePlayerMove1(2,16);
          //      this->move();
    }
    this->repaint();
}


