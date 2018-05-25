#include "world.h"
#include "icon.h"
#include "rpgobj.h"
#include<iostream>
using namespace std;

void World::initWorld(string mapFile){
    //TODO 下面这部分逻辑应该是读入地图文件，生成地图上的对象
    //player 5 5
    this->_player.initObj("satan");
    this->_player.setPosX(12);
    this->_player.setPosY(7);
    this->player1.initObj("player");
    this->player1.setPosX(1);
    this->player1.setPosY(0);

    RPGObj obj[400], obj1, obj2, obj3, obj4, obj5, obj6, obj7, obj8, obj9;
    int i, j=0, k=0;
    for(i=0;i<20;i++)
    {
        obj[i].initObj("stone");
        obj[i].setPosX(j);
        obj[i].setPosY(k);
        j++;
    }
    j=0;k=1;
    for(i=20;i<40;i++)
    {
        obj[i].initObj("stone");
        obj[i].setPosX(j);
        obj[i].setPosY(k);
        k++;
    }
    j=1;k=20;
    for(i=40;i<60;i++)
    {
        obj[i].initObj("stone");
        obj[i].setPosX(j);
        obj[i].setPosY(k);
        j++;
    }
    j=20;k=0;
    for(i=60;i<79;i++)
    {
        obj[i].initObj("stone");
        obj[i].setPosX(j);
        obj[i].setPosY(k);
        k++;
    }
    obj[79].initObj("fruit");
    obj[79].setPosX(20);
    obj[79].setPosY(19);

    j=1;k=2;
    for(i=80;i<85;i++)
    {
        obj[i].initObj("tree");
        obj[i].setPosX(j);
        obj[i].setPosY(k);
        k=k+2;
    }
    j=3;k=2;
    for(i=85;i<90;i++)
    {
        obj[i].initObj("tree");
        obj[i].setPosX(j);
        obj[i].setPosY(k);
        k=k+2;
    }
    j=6;k=14;
    for(i=90;i<93;i++)
    {
        obj[i].initObj("tree");
        obj[i].setPosX(j);
        obj[i].setPosY(k);
        j=j+2;
    }

    j=13;k=14;
    for(i=93;i<96;i++)
    {
        obj[i].initObj("tree");
        obj[i].setPosX(j);
        obj[i].setPosY(k);
        j=j+2;
    }
    j=7;k=2;
    for(i=96;i<99;i++)
    {
        obj[i].initObj("tree");
        obj[i].setPosX(j);
        obj[i].setPosY(k);
        j=j+2;
    }
    j=7;k=4;
    for(i=99;i<102;i++)
    {
        obj[i].initObj("tree");
        obj[i].setPosX(j);
        obj[i].setPosY(k);
        j=j+2;
    }
    j=7;k=8;
    for(i=102;i<105;i++)
    {
        obj[i].initObj("tree");
        obj[i].setPosX(j);
        obj[i].setPosY(k);
        j=j+2;
    }
    j=7;k=10;
    for(i=105;i<108;i++)
    {
        obj[i].initObj("tree");
        obj[i].setPosX(j);
        obj[i].setPosY(k);
        j=j+2;
    }
    j=14;k=2;
    for(i=108;i<110;i++)
    {
        obj[i].initObj("tree");
        obj[i].setPosX(j);
        obj[i].setPosY(k);
        j=j+2;
    }
    j=14;k=4;
    for(i=110;i<112;i++)
    {
        obj[i].initObj("tree");
        obj[i].setPosX(j);
        obj[i].setPosY(k);
        j=j+2;
    }
    j=14;k=8;
    for(i=112;i<114;i++)
    {
        obj[i].initObj("tree");
        obj[i].setPosX(j);
        obj[i].setPosY(k);
        j=j+2;
    }
    j=14;k=10;
    for(i=114;i<116;i++)
    {
        obj[i].initObj("tree");
        obj[i].setPosX(j);
        obj[i].setPosY(k);
        j=j+2;
    }
    j=6;k=2;
    for(i=116;i<121;i++)
    {
        obj[i].initObj("grass");
        obj[i].setPosX(j);
        obj[i].setPosY(k);
        k++;
    }
    j=6;k=8;
    for(i=121;i<125;i++)
    {
        obj[i].initObj("grass");
        obj[i].setPosX(j);
        obj[i].setPosY(k);
        k++;
    }
    j=1;k=14;
    for(j=1;j<5;j++)
    {
        for(i=119+j*6;i<125+6*j;i++)
        {
            obj[i].initObj("grave");
            obj[i].setPosX(j);
            obj[i].setPosY(k);
            k++;
        }
        k=14;
    }
    j=6;k=19;
    for(i=149;i<162;i++)
    {
        obj[i].initObj("jar");
        obj[i].setPosX(j);
        obj[i].setPosY(k);
        j++;
    }

    j=8;k=1;
    for(k=1;k<3;k++)
    {
        for(i=158+k*4;i<162+k*4;i++)
        {
            obj[i].initObj("cactus");
            obj[i].setPosX(j);
            obj[i].setPosY(k+15);
            j++;
        }
        j=8;
    }
    j=13;k=1;
    for(k=1;k<3;k++)
    {
        for(i=164+k*6;i<170+k*6;i++)
        {
            obj[i].initObj("cactus");
            obj[i].setPosX(j);
            obj[i].setPosY(k+15);
            j++;
        }
        j=13;
    }
    obj1.initObj("well");
    obj1.setPosX(6);
    obj1.setPosY(16);

    obj2.initObj("wine");
    obj2.setPosX(2);
    obj2.setPosY(12);

    obj3.initObj("wine");
    obj3.setPosX(2);
    obj3.setPosY(13);

    obj4.initObj("wine");
    obj4.setPosX(8);
    obj4.setPosY(18);

    obj5.initObj("wine");
    obj5.setPosX(9);
    obj5.setPosY(18);

    obj6.initObj("fruit");
    obj6.setPosX(1);
    obj6.setPosY(12);

    obj7.initObj("fruit");
    obj7.setPosX(1);
    obj7.setPosY(13);

    obj8.initObj("fruit");
    obj8.setPosX(7);
    obj8.setPosY(6);

    obj9.initObj("fruit");
    obj9.setPosX(8);
    obj9.setPosY(6);



    for(i=0;i<182;i++)
    {
        this->_objs.push_back(obj[i]);
    }
    this->_objs.push_back(obj1);
    this->_objs.push_back(obj2);
    this->_objs.push_back(obj3);
    this->_objs.push_back(obj4);
    this->_objs.push_back(obj5);
    this->_objs.push_back(obj6);
    this->_objs.push_back(obj7);
    this->_objs.push_back(obj8);
    this->_objs.push_back(obj9);

}


void World::show(QPainter * painter){
    if(_player.getPosX()==player1.getPosX() && _player.getPosY()==player1.getPosY())
    {

    }
    vector<RPGObj>::iterator it;
    for(it=this->_objs.begin();it!=this->_objs.end();it++){
        (*it).show(painter);
    }
    this->_player.show(painter);
    this->player1.show(painter);
}

void World::handlePlayerMove(int direction, int steps){

    int x, y;
    vector<RPGObj>::iterator it;
    switch (direction){
        case 1:
            y = _player.getPosY()+1;
            x = _player.getPosX();
            y -= steps;
            for(it=_objs.begin();it!=_objs.end();it++)
            {
                if(x>=(*it).getPosX()&&x<(*it).getPosX()+(*it).getWidth() && y>=(*it).getPosY()&&y<(*it).getPosY()+(*it).getHeight())
                {
                    if((*it).canCover()==false)
                    {
                        steps=0;
                        handlePlayerMove(3,1);
                    }
                    break;
                }
            }
            break;
        case 2:
            y = _player.getPosY()+1;
            x = _player.getPosX();
            y += steps;
            for(it=_objs.begin();it!=_objs.end();it++)
            {

                if(x>=(*it).getPosX()&&x<(*it).getPosX()+(*it).getWidth() && y>=(*it).getPosY()&&y<(*it).getPosY()+(*it).getHeight())
                {
                    if((*it).canCover()==false)
                    {
                        steps=0;
                        handlePlayerMove(4,1);
                    }
                    break;
                }
            }
            break;
        case 3:
        y = _player.getPosY()+1;
        x = _player.getPosX();
        x -= steps;
        for(it=_objs.begin();it!=_objs.end();it++)
        {

            if(x>=(*it).getPosX()&&x<(*it).getPosX()+(*it).getWidth() && y>=(*it).getPosY()&&y<(*it).getPosY()+(*it).getHeight())
            {
                if((*it).canCover()==false)
                {
                    steps=0;
                    handlePlayerMove(2,1);
                }
                break;
            }
        }
        break;
        case 4:
        y = _player.getPosY()+1;
        x = _player.getPosX();
        x += steps;
        for(it=_objs.begin();it!=_objs.end();it++)
        {
            if(x>=(*it).getPosX()&&x<(*it).getPosX()+(*it).getWidth() && y>=(*it).getPosY()&&y<(*it).getPosY()+(*it).getHeight())
            {
                if((*it).canCover()==false)
                {
                    steps=0;
                    handlePlayerMove(1,1);
                }
                break;
            }
        }
        break;
    }
    this->_player.move(direction, steps);

}


void World::handlePlayerMove1(int direction, int steps){
    int x, y;
    vector<RPGObj>::iterator it;
    switch (direction){
        case 1:
            y = player1.getPosY()+1;
            x = player1.getPosX();
            y -= steps;
            if(player1.getPosX()==_player.getPosX() && player1.getPosY()==_player.getPosY())
            {

                break;
            }
            for(it=_objs.begin();it!=_objs.end();it++)
            {

                if(x>=(*it).getPosX()&&x<(*it).getPosX()+(*it).getWidth() && y>=(*it).getPosY()&&y<(*it).getPosY()+(*it).getHeight())
                {
                    if((*it).canEat()==true)
                    {
                        it=_objs.erase(it);
                        it--;
                        player1.changegrade();
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
            y = player1.getPosY()+1;
            x = player1.getPosX();
            y += steps;
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
        y = player1.getPosY()+1;
        x = player1.getPosX();
        x -= steps;
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
        y = player1.getPosY()+1;
        x = player1.getPosX();
        x += steps;
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
    this->player1.move(direction, steps);
}
