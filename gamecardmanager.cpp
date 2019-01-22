#include "gamecardmanager.h"
#include "gamecardicon.h"
#include "game.h"
#include "menubutton.h"
#include <QGraphicsItem>
#include <QPixmap>
#include <QBrush>
#include <QImage>
#include <QDebug>
#include <iostream>

extern Game * game;

GameCardManager::GameCardManager()
{
    for(int i=0;i<14;i++)
    {
        owned_cards[i]=0;
    }
    owned_cards[0]=1;
    owned_cards[1]=1;
    owned_cards[6]=1;
    owned_cards[7]=1;

}


void GameCardManager::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

void GameCardManager::showSidePlane()
{
    game->scene->addItem(plane1);
    game->scene->addItem(plane2);
    game->scene->addItem(plane3);
    game->scene->addItem(plane4);
    game->scene->addItem(plane5);
    game->scene->addItem(plane6);
}

void GameCardManager::hideSidePlane()
{
    game->scene->removeItem(plane1);
    game->scene->removeItem(plane2);
    game->scene->removeItem(plane3);
    game->scene->removeItem(plane4);
    game->scene->removeItem(plane5);
    game->scene->removeItem(plane6);
}

void GameCardManager::showSidePerk()
{
    game->scene->addItem(perk1);
    game->scene->addItem(perk2);
    game->scene->addItem(perk3);
    game->scene->addItem(perk4);
    game->scene->addItem(perk5);
    game->scene->addItem(perk6);
    game->scene->addItem(perk7);
    game->scene->addItem(perk8);
}

void GameCardManager::hideSidePerk()
{
    game->scene->removeItem(perk1);
    game->scene->removeItem(perk2);
    game->scene->removeItem(perk3);
    game->scene->removeItem(perk4);
    game->scene->removeItem(perk5);
    game->scene->removeItem(perk6);
    game->scene->removeItem(perk7);
    game->scene->removeItem(perk8);
}

bool GameCardManager::isInLineup(int ID)
{
    if(ID == game->playerID||ID == game->skill1ID||ID == game->skill2ID)
    {
        return true;
    }
    else
        return false;
}

void GameCardManager::add_icons()
{
    //set background
    game->scene->clear();
    game->setBackgroundBrush(QBrush(QImage(":/ui/resource/hangar.jpg")));
    Menubutton * but = new Menubutton(4);
    but->setPos(1200,900);
    game->scene->addItem(but);
    connect(but,SIGNAL(clicked()),this,SLOT(back()));

    //set default player
    player = new GameCardIcon(game->playerID);

    //set default skills
    skill1 = new GameCardIcon(game->skill1ID);
    skill2 = new GameCardIcon(game->skill2ID);
    player->setPos(50,80);
    skill1->setPos(500,100);
    skill2->setPos(750,100);
    game->scene->addItem(player);
    game->scene->addItem(skill1);
    game->scene->addItem(skill2);

    //set side skill
    if(owned_cards[6]==0)
        perk1 = new GameCardIcon(100);
    else
        perk1 = new GameCardIcon(6);
    if(isInLineup(6))
        perk1->setPixmap(QPixmap(":/cards/selected1.jpg"));
    if(owned_cards[7]==0)
        perk2 = new GameCardIcon(100);
    else
        perk2 = new GameCardIcon(7);
    if(isInLineup(7))
        perk2->setPixmap(QPixmap(":/cards/selected1.jpg"));
    if(owned_cards[8]==0)
        perk3 = new GameCardIcon(100);
    else
        perk3 = new GameCardIcon(8);
    if(isInLineup(8))
        perk3->setPixmap(QPixmap(":/cards/selected1.jpg"));
    if(owned_cards[9]==0)
        perk4 = new GameCardIcon(100);
    else
        perk4 = new GameCardIcon(9);
    if(isInLineup(9))
        perk4->setPixmap(QPixmap(":/cards/selected1.jpg"));
    if(owned_cards[10]==0)
        perk5 = new GameCardIcon(100);
    else
        perk5 = new GameCardIcon(10);
    if(isInLineup(10))
        perk5->setPixmap(QPixmap(":/cards/selected1.jpg"));
    if(owned_cards[11]==0)
        perk6 = new GameCardIcon(100);
    else
        perk6 = new GameCardIcon(11);
    if(isInLineup(11))
        perk6->setPixmap(QPixmap(":/cards/selected1.jpg"));
    if(owned_cards[12]==0)
        perk7 = new GameCardIcon(100);
    else
        perk7 = new GameCardIcon(12);
    if(isInLineup(12))
        perk7->setPixmap(QPixmap(":/cards/selected1.jpg"));
    if(owned_cards[13]==0)
        perk8 = new GameCardIcon(100);
    else
        perk8 = new GameCardIcon(13);
    if(isInLineup(13))
        perk8->setPixmap(QPixmap(":/cards/selected1.jpg"));



    //set positions of perk
    perk1->setPos(40,540);
    perk2->setPos(280,540);
    perk3->setPos(520,540);
    perk4->setPos(760,540);
    perk5->setPos(40,790);
    perk6->setPos(280,790);
    perk7->setPos(520,790);
    perk8->setPos(760,790);


    //set side hero
    if(owned_cards[0]==0)
        plane1 = new GameCardIcon(-1);
    else
        plane1 = new GameCardIcon(0);
    if(isInLineup(0))
        plane1->setPixmap(QPixmap(":/hero/selected2.jpg"));
    if(owned_cards[1]==0)
        plane2 = new GameCardIcon(-1);
    else
        plane2 = new GameCardIcon(1);
    if(isInLineup(1))
        plane2->setPixmap(QPixmap(":/hero/selected2.jpg"));
    if(owned_cards[2]==0)
        plane3 = new GameCardIcon(-1);
    else
        plane3 = new GameCardIcon(2);
    if(isInLineup(2))
        plane3->setPixmap(QPixmap(":/hero/selected2.jpg"));
    if(owned_cards[3]==0)
        plane4 = new GameCardIcon(-1);
    else
        plane4 = new GameCardIcon(3);
    if(isInLineup(3))
        plane4->setPixmap(QPixmap(":/hero/selected2.jpg"));
    if(owned_cards[4]==0)
        plane5 = new GameCardIcon(-1);
    else
        plane5 = new GameCardIcon(4);
    if(isInLineup(4))
        plane5->setPixmap(QPixmap(":/hero/selected2.jpg"));
    if(owned_cards[5]==0)
        plane6 = new GameCardIcon(-1);
    else
        plane6 = new GameCardIcon(5);
    if(isInLineup(5))
        plane6->setPixmap(QPixmap(":/hero/selected2.jpg"));

    //set position of side plane
    plane1->setScale(0.75);
    plane2->setScale(0.75);
    plane3->setScale(0.75);
    plane4->setScale(0.75);
    plane5->setScale(0.75);
    plane6->setScale(0.75);
    plane1->setPos(25,590);
    plane2->setPos(350,590);
    plane3->setPos(675,590);
    plane4->setPos(25,802);
    plane5->setPos(350,802);
    plane6->setPos(675,802);

}

void GameCardManager::back()
{
    game->playerID = this->player->myID;
    game->skill1ID = this->skill1->myID;
    game->skill2ID = this->skill2->myID;

    game->scene->clear();
    game->restart();
}
