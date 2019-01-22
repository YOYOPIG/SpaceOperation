#include "meteor.h"
#include "game.h"
#include "bullet.h"
#include "ebullet.h"
#include "player.h"
#include<QTransform>

extern Game * game;

Meteor::Meteor()
{
    setPixmap(QPixmap(":/item/meteor.png"));
    connect(game->moveTimer,SIGNAL(timeout()),this,SLOT(move()));
    rot_degree = 0;
    setTransformOriginPoint(x()+75,y()+72);
}

void Meteor::move()
{
    if(this->pos().y()>game->height())
    {
        game->scene->removeItem(this);
        delete this;
        return;
    }

    //block bullets
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0; i<colliding_items.size();++i)
    {
        Bullet * bul = dynamic_cast<Bullet *> (colliding_items[i]);
        if(bul)
        {
            game->scene->removeItem(bul);
            delete bul;
         }
        Ebullet * ebul = dynamic_cast<Ebullet *> (colliding_items[i]);
        if(ebul)
        {
            game->scene->removeItem(ebul);
            delete ebul;
         }
     }

    //damage player
    for(int i=0; i<colliding_items.size();++i)
    {
        Player * player = dynamic_cast<Player *> (colliding_items[i]);
        if(player)
        {
            player->beDamaged();
            player->beDamaged();
            delete this;
            return;
         }
     }
    setPos(x(),y()+3);
    setRotation(rot_degree);
    rot_degree +=1;
}
