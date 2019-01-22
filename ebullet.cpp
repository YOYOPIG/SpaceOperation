#include "ebullet.h"
#include "game.h"
#include "player.h"
#include <QPixmap>
#include <QList>

extern Game * game;

Ebullet::Ebullet()
{
    bulletID = 1;
    setPixmap(QPixmap(":/enemy/ebullet.png"));
    connect(game->moveTimer,SIGNAL(timeout()),this,SLOT(move()));
}

Ebullet::Ebullet(int ID)
{
    bulletID = ID;
    switch (ID) {
    case 1:
        setPixmap(QPixmap(":/enemy/ebullet.png"));
        break;
    case 2:
        setPixmap(QPixmap(":/enemy/ebullet2.png"));
        break;
    case 3:
        setPixmap(QPixmap(":/enemy/ebullet.png"));
        break;
    case 4:
        setPixmap(QPixmap(":/enemy/ebullet.png"));
        break;
    default:
        break;
    }
    connect(game->moveTimer,SIGNAL(timeout()),this,SLOT(move()));
}

void Ebullet::move()
{
    if(this->pos().y()>game->height())
    {
        game->scene->removeItem(this);
        delete this;
        return;
    }

    //damage player
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0; i<colliding_items.size();++i)
    {
        Player * player = dynamic_cast<Player *> (colliding_items[i]);
        if(player)
        {
            game->scene->removeItem(this);
            player->beDamaged();
            delete this;
            return;
         }
     }
    switch (bulletID) {
    case 1:
        setPos(x(),y()+10);
        break;
    case 2:
        setPos(x(),y()+10);
        break;
    case 3:
        setPos(x()+10,y()+10);
        break;
    case 4:
        setPos(x()-10,y()+10);
        break;

    default:
        break;
    }

}
