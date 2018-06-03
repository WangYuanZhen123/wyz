#include "icon.h"
#include<iostream>
//int ICON::GRID_SIZE = 32;


pair<string,ICON> pairArray[] =
{
    make_pair("stone",ICON("stone",4*32,9*32, 1*32, 1*32)),

    make_pair("player",ICON("player",0,0, 77, 95)),
    make_pair("npc1",ICON("npc1",0,0,106,101)),
    make_pair("npc2",ICON("npc2",0,0,74,97)),
    make_pair("npc3",ICON("npc3",0,0,104,82)),
    make_pair("people4",ICON("people4",0,0,50,110)),
    make_pair("people5",ICON("people5",0,0,50,110))
};

map<string,ICON> ICON::GAME_ICON_SET(pairArray,pairArray+sizeof(pairArray)/sizeof(pairArray[0]));


ICON::ICON(string name, int x, int y, int w, int h){
    this->typeName = name;
    this->srcX = x;
    this->srcY = y;
    this->width = w;
    this->height = h;
}

ICON ICON::findICON(string type){
    map<string,ICON>::iterator kv;
    kv = ICON::GAME_ICON_SET.find(type);
    if (kv==ICON::GAME_ICON_SET.end()){

       cout<<"Error: cannot find ICON"<<endl;
       return ICON();
    }
    else{
        return kv->second;
    }
}
