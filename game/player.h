#ifndef PLAYER_H
#define PLAYER_H
#include "rpgobj.h"
#include <QPainter>

class Player: public RPGObj
{
public:
    Player(int m=2):direct(m){}
    ~Player(){}
    void move(int direction, int steps=1);
        //direction =1,2,3,4 for 上下左右
    void eatfruit(string str);
    void changedirect(int k);  //改变方向
    int getdirect(){return direct;}   //返回方向
private:
    int direct;   //行走方向
};

#endif // PLAYER_H
