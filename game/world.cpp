#include "world.h"
#include "icon.h"
#include "rpgobj.h"
#include<iostream>
using namespace std;

void World::initWorld(string mapFile){
    //TODO 下面这部分逻辑应该是读入地图文件，生成地图上的对象
    //player 5 5
    this->_player.initObj("player");
    this->_player.setPosX(15*32);
    this->_player.setPosY(20*32);
    this->_player.changedirect(2);

    this->npc1.initObj("npc1");
    this->npc1.setPosX(40*32);
    this->npc1.setPosY(15*32);
    this->npc2.initObj("npc2");
    this->npc2.setPosX(30*32);
    this->npc2.setPosY(15*32);
    this->npc3.initObj("npc3");
    this->npc3.setPosX(20*32);
    this->npc3.setPosY(15*32);




    RPGObj obj[400];
    int i, j=0, k=0;
    j=0;k=24*32;
    for(i=0;i<60;i++)
    {
        obj[i].initObj("stone");
        obj[i].setPosX(j);
        obj[i].setPosY(k);
        j+=32;
    }
    j=0;k=15*32;
    for(i=60;i<120;i++)
    {
        obj[i].initObj("stone");
        obj[i].setPosX(j);
        obj[i].setPosY(k);
        j+=32;
    }
    j=54*32;k=24*32;
    for(i=120;i<123;i++)
    {
        obj[i].initObj("stone");
        obj[i].setPosX(j);
        obj[i].setPosY(k);
        k-=32;
    }
    j=55*32;k=22*32;
    for(i=123;i<126;i++)
    {
        obj[i].initObj("stone");
        obj[i].setPosX(j);
        obj[i].setPosY(k);
        j+=32;
    }
    j=57*32;k=22*32;
    for(i=126;i<129;i++)
    {
        obj[i].initObj("stone");
        obj[i].setPosX(j);
        obj[i].setPosY(k);
        k-=32;
    }
    j=57*32;k=19*32;
    for(i=129;i<132;i++)
    {
        obj[i].initObj("stone");
        obj[i].setPosX(j);
        obj[i].setPosY(k);
        j+=32;
    }





    for(i=0;i<132;i++)
    {
        this->_objs.push_back(obj[i]);
    }

}


void World::showback(QPainter * painter)
{

    vector<RPGObj>::iterator it;
    for(it=this->_objs.begin();it!=this->_objs.end();it++){
        (*it).show(painter);
    }

}

void World::show(QPainter *painter)
{
  //  this->_player.show(painter);
    this->npc1.show(painter);
    this->npc2.show(painter);
    this->npc3.show(painter);
        if(_player.geti()==0)
        {
            this->_player.show(painter);
        }
        else if(_player.geti()==1)
        {
            if(_player.getdirect() == 2)
            {
                painter->drawImage(QRect (_player.getPosX(),_player.getPosY()+4,69,90),QImage ("C:\\Users\\67549\\Desktop\\5690530967350055f\\NPC_1\\04\\image 75.png"),QRect (0,0,69,90));
            }
            else if(_player.getdirect() == 3)
            {
                painter->drawImage(QRect (_player.getPosX(),_player.getPosY()+4,90,90),QImage ("C:\\Users\\67549\\Desktop\\5690530967350055f\\NPC_1\\04\\image 95.png"),QRect (0,0,90,90));

            }
            else if(_player.getdirect() == 4)
            {
                painter->drawImage(QRect (_player.getPosX(),_player.getPosY()+4,90,90),QImage ("C:\\Users\\67549\\Desktop\\5690530967350055f\\NPC_1\\04\\image 96.png"),QRect (0,0,90,90));

            }
            else if(_player.getdirect() == 1)
            {
                painter->drawImage(QRect (_player.getPosX(),_player.getPosY()+4,62,106),QImage ("C:\\Users\\67549\\Desktop\\5690530967350055f\\NPC_1\\04\\image 121.png"),QRect (0,0,62,106));

            }
        }
        else if(_player.geti()==2)
        {
            if(_player.getdirect() == 2)
            {
                painter->drawImage(QRect (_player.getPosX(),_player.getPosY()+8,69,90),QImage ("C:\\Users\\67549\\Desktop\\5690530967350055f\\NPC_1\\04\\image 79.png"),QRect (0,0,69,90));

            }
            else if(_player.getdirect() == 3)
            {
                painter->drawImage(QRect (_player.getPosX(),_player.getPosY()+8,100,100),QImage ("C:\\Users\\67549\\Desktop\\5690530967350055f\\NPC_1\\04\\image 103.png"),QRect (0,0,100,100));
            }
            else if(_player.getdirect() == 4)
            {
                painter->drawImage(QRect (_player.getPosX(),_player.getPosY()+8,100,100),QImage ("C:\\Users\\67549\\Desktop\\5690530967350055f\\NPC_1\\04\\image 104.png"),QRect (0,0,100,100));
            }
            else if(_player.getdirect() == 1)
            {
                painter->drawImage(QRect (_player.getPosX(),_player.getPosY()+8,69,106),QImage ("C:\\Users\\67549\\Desktop\\5690530967350055f\\NPC_1\\04\\image 127.png"),QRect (0,0,69,106));
            }
        }


}



/*void World::handlePlayerMove(int direction, int steps){

    int x, y;
    vector<RPGObj>::iterator it;
    switch (direction){
        case 1:
            y = _player.getPosY()+8;
            x = _player.getPosX();
            y -= steps;
            for(it=_objs.begin();it!=_objs.end();it++)
            {
                if(x>=(*it).getPosX()&&x<(*it).getPosX()+(*it).getWidth() && y>=(*it).getPosY()&&y<(*it).getPosY()+(*it).getHeight())
                {
                    if((*it).canCover()==false)
                    {
                        steps=0;
                        handlePlayerMove(3,8);
                    }
                    break;
                }
            }
            break;
        case 2:
            y = _player.getPosY()+8;
            x = _player.getPosX();
            y += steps;
            for(it=_objs.begin();it!=_objs.end();it++)
            {

                if(x>=(*it).getPosX()&&x<(*it).getPosX()+(*it).getWidth() && y>=(*it).getPosY()&&y<(*it).getPosY()+(*it).getHeight())
                {
                    if((*it).canCover()==false)
                    {
                        steps=0;
                        handlePlayerMove(4,8);
                    }
                    break;
                }
            }
            break;
        case 3:
        y = _player.getPosY()+8;
        x = _player.getPosX();
        x -= steps;
        for(it=_objs.begin();it!=_objs.end();it++)
        {

            if(x>=(*it).getPosX()&&x<(*it).getPosX()+(*it).getWidth() && y>=(*it).getPosY()&&y<(*it).getPosY()+(*it).getHeight())
            {
                if((*it).canCover()==false)
                {
                    steps=0;
                    handlePlayerMove(2,8);
                }
                break;
            }
        }
        break;
        case 4:
        y = _player.getPosY()+8;
        x = _player.getPosX();
        x += steps;
        for(it=_objs.begin();it!=_objs.end();it++)
        {
            if(x>=(*it).getPosX()&&x<(*it).getPosX()+(*it).getWidth() && y>=(*it).getPosY()&&y<(*it).getPosY()+(*it).getHeight())
            {
                if((*it).canCover()==false)
                {
                    steps=0;
                    handlePlayerMove(1,8);
                }
                break;
            }
        }
        break;
    }
    this->_player.move(direction, steps);

}*/


void World::handlePlayerMove1(int direction, int steps){
    int x, y;
    vector<RPGObj>::iterator it;
    switch (direction){
        case 1:
            y = _player.getPosY()+32;
            x = _player.getPosX();
            y -= 32;
            for(it=_objs.begin();it!=_objs.end();it++)
            {

                if(x>=(*it).getPosX()&&x<(*it).getPosX()+(*it).getWidth() && y>=(*it).getPosY()&&y<(*it).getPosY()+(*it).getHeight())
                {
                    if((*it).canEat()==true)
                    {
                        it=_objs.erase(it);
                        it--;
                    }
                    else if((*it).canCover()==false)
                    {
                        steps=0;
                    }
                    break;
                }
            }
            break;
        case 2:
            y = _player.getPosY()+32;
            x = _player.getPosX();
            y += 32;
            for(it=_objs.begin();it!=_objs.end();it++)
            {

                if(x>=(*it).getPosX()&&x<(*it).getPosX()+(*it).getWidth() && y>=(*it).getPosY()&&y<(*it).getPosY()+(*it).getHeight())
                {
                    if((*it).canEat()==true)
                    {
                        it=_objs.erase(it);
                        it--;
                    }
                    else if((*it).canCover()==false)
                    {
                        steps=0;
                    }
                    break;
                }
            }

            break;
        case 3:
        y = _player.getPosY()+32;
        x = _player.getPosX();
        x -= 32;
        for(it=_objs.begin();it!=_objs.end();it++)
        {

            if(x>=(*it).getPosX()&&x<(*it).getPosX()+(*it).getWidth() && y>=(*it).getPosY()&&y<(*it).getPosY()+(*it).getHeight())
            {
                if((*it).canEat()==true)
                {
                    it=_objs.erase(it);
                    it--;
                }
                else if((*it).canCover()==false)
                {
                    steps=0;
                }
                break;
            }
        }

        break;
        case 4:
        y = _player.getPosY()+32;
        x = _player.getPosX();
        x += 32;
        for(it=_objs.begin();it!=_objs.end();it++)
        {

            if(x>=(*it).getPosX()&&x<(*it).getPosX()+(*it).getWidth() && y>=(*it).getPosY()&&y<(*it).getPosY()+(*it).getHeight())
            {
                if((*it).canEat()==true)
                {
                    it=_objs.erase(it);
                    it--;
                }
                else if((*it).canCover()==false)
                {
                    steps=0;
                }
                break;
            }
        }
        break;
    }
    if(_player.geti()==0)
        _player.changei(1);
    else if(_player.geti()==1)
        _player.changei(2);
    else if(_player.geti()==2)
        _player.changei(1);
    this->_player.move(direction, steps);
}
