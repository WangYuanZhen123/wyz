#ifndef WORLD_H
#define WORLD_H
#include "rpgobj.h"
#include <vector>
#include <string>
#include <QPainter>
#include "player.h"

class World : public Player
{
    friend class MainWindow;
public:
    World(){}
    ~World(){}
    void initWorld(string mapFile);
        //输入的文件中定义了初始状态下游戏世界有哪些对象，出生点在哪
        /*e.g.
           player 5 5
           stone 3 3
           fruit 7 8
         */
    void showback(QPainter * painter);
        //游戏世界里的背景
    void show(QPainter *painter);
        //现实游戏世界里的角色

    void handlePlayerMove1(int direction, int steps);
        //假定只有一个玩家
    int get_x(){return _player.getPosX();}
    int get_y(){return _player.getPosY();}


    /* void showmoving(QPainter *painter);
     void handlePlayerMove(int direction, int steps);
         //假定只有一个玩家*/


private:
    vector<RPGObj> _objs;
    Player _player;
    Player npc1, npc2, npc3;
    Player enemy1, enemy2, ememy2;
};

#endif // WORLD_H
