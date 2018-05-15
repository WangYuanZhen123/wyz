#include "mw1.h"
#include "ui_mw1.h"
#include "icon.h"
#include <QTimer>
#include <map>
#include <iostream>
#include<QPixmap>

using namespace std;
int g=0, h=0;
MW1::MW1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MW1)
{
    ui->setupUi(this);

    //init game world
    _game.initWorld("");//TODO 应该是输入有效的地图文件

    //以下是对时钟的初始化
    timer = new QTimer(this);
   // timer2 = new Qtimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(randomMove()));//timeoutslot()为自定义槽
        //时钟事件与randomMove函数绑定
    timer->start(100);
    timer->setInterval(300);

  //  connect(timer2,SIGNAL(timeout()),this,SLOT(randownumber));
   // timer->start(100);

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
        //设置随机数种子
}

MW1::~MW1()
{
    delete ui;
}

void MW1::paintEvent(QPaintEvent *e){
    QPainter *pa;
    pa = new QPainter();
    pa->begin(this);
    if(_game.getx1()==20 && _game.gety1()==18)
    {
        h=1;
    }
    if(_game.get_x()==_game.getx1() && _game.get_y()==_game.gety1())
    {
        g=1;
    }
    if(h==1)
    {
        pa->drawPixmap(rect(), QPixmap("C:\\Users\\67549\\Desktop\\Qt.map\\win.png"));
    }
    else if(g==1)
    {
        pa->drawPixmap(rect(), QPixmap("C:\\Users\\67549\\Desktop\\Qt.map\\lose.png"));
    }
    else
    {
        this->_game.show(pa);
    }
    pa->end();
    delete pa;
}

void MW1::keyPressEvent(QKeyEvent *e)
{
    //direction = 1,2,3,4 for 上下左右
    if(e->key() == Qt::Key_A)
    {
        this->_game.handlePlayerMove1(3,1);
    }
    else if(e->key() == Qt::Key_D)
    {
        this->_game.handlePlayerMove1(4,1);
    }
    else if(e->key() == Qt::Key_W)
    {
        this->_game.handlePlayerMove1(1,1);
    }
    else if(e->key() == Qt::Key_S)
    {
         this->_game.handlePlayerMove1(2,1);
    }
    this->repaint();
}


void MW1::randomMove(){
    int d = 1 + rand()%4;
    this->_game.handlePlayerMove(d,1);
    this->repaint();
}
