#include "rpgobj.h"
#include <iostream>

void RPGObj::initObj(string type)
{
    //TODO 所支持的对象类型应定义为枚举

    if (type.compare("stone")==0){
        this->_coverable = false;
        this->_eatable = false;
         i=0;
    }

    else if (type.compare("player")==0){
        this->_coverable = false;
        this->_eatable = false;
        i=0;
    }
    else if (type.compare("npc1")==0){
        this->_coverable = false;
        this->_eatable = false;
         i=0;
    }
    else if (type.compare("npc2")==0){
        this->_coverable = false;
        this->_eatable = false;
         i=0;
    }
    else if (type.compare("npc3")==0){
        this->_coverable = false;
        this->_eatable = false;
         i=0;
    }
    else if (type.compare("people4")==0){
        this->_coverable = false;
        this->_eatable = false;
         i=0;
    }
    else if (type.compare("people5")==0){
        this->_coverable = false;
        this->_eatable = false;
         i=0;
    }
    else{
        //TODO 应由专门的错误日志文件记录
        cout<<"invalid ICON type."<<endl;
        return;
    }
    if(type.compare("player")==0)
    {
        this->_icon = ICON::findICON(type);
        QImage all;
        all.load("C:\\Users\\67549\\Desktop\\5690530967350055f\\NPC_1\\04\\image 1.png");
        this->_pic = all.copy(QRect(_icon.getSrcX(), _icon.getSrcY(), _icon.getWidth(), _icon.getHeight()));
    }
    else if(type.compare("npc1")==0)
    {
        this->_icon = ICON::findICON(type);
        QImage all;
        all.load("C:\\Users\\67549\\Desktop\\5690530967350055f\\NPC_1\\11\\image 1.png");
        this->_pic = all.copy(QRect(_icon.getSrcX(), _icon.getSrcY(), _icon.getWidth(), _icon.getHeight()));
    }
    else if(type.compare("npc2")==0)
    {
        this->_icon = ICON::findICON(type);
        QImage all;
        all.load("C:\\Users\\67549\\Desktop\\5690530967350055f\\NPC_1\\12\\image 1.png");
        this->_pic = all.copy(QRect(_icon.getSrcX(), _icon.getSrcY(), _icon.getWidth(), _icon.getHeight()));
    }
    else if(type.compare("npc3")==0)
    {
        this->_icon = ICON::findICON(type);
        QImage all;
        all.load("C:\\Users\\67549\\Desktop\\5690530967350055f\\NPC_1\\10\\image 19.png");
        this->_pic = all.copy(QRect(_icon.getSrcX(), _icon.getSrcY(), _icon.getWidth(), _icon.getHeight()));
    }
    else
    {
        this->_icon = ICON::findICON(type);
        QImage all;
        all.load("C:\\Users\\67549\\Desktop\\Qt.map\\TileB.png");
        this->_pic = all.copy(QRect(_icon.getSrcX(), _icon.getSrcY(), _icon.getWidth(), _icon.getHeight()));
    }
}

void RPGObj::show(QPainter * pa){
 //   int gSize = ICON::GRID_SIZE;
    pa->drawImage(this->_pos_x,this->_pos_y,this->_pic);
}

void RPGObj::changei(int m)
{
    this->i=m;
}


