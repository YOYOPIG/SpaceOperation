#include "stagebutton.h"
#include "game.h"
#include<iostream>

extern Game *game;

Stagebutton::Stagebutton()
{
    std::cerr<<"button error! no ID \n";
}

Stagebutton::Stagebutton(int ID)
{
    stageID = ID;
    switch (ID) {
    case 1:
        setPixmap(QPixmap(":/ui/resource/stage1.png"));
        break;
    case 2:
        setPixmap(QPixmap(":/ui/resource/stage2.png"));
        break;
    case 3:
        setPixmap(QPixmap(":/ui2/stage3.png"));
        break;

    default:
        break;
    }

}

void Stagebutton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    game->current_stage = stageID;
    emit clicked();
}

