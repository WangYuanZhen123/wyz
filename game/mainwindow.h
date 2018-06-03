#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QPainter>
#include<QKeyEvent>
#include "rpgobj.h"
#include "world.h"
#include<QTime>
#include<QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);
    void move();

protected slots:
   // void randomMove();//响应时钟事件的函数
private slots:



private:
    Ui::MainWindow *ui;
    World _game;
 //   QTimer *timer;
        //时钟，控制玩家移动频率
};





#endif // MAINWINDOW_H
