#include "healthpack.h"
#include "game.h"
#include "player.h"

extern Game * game;

Healthpack::Healthpack()
{
    setPixmap(QPixmap(":/item/healthpack.png"));
    connect(game->moveTimer,SIGNAL(timeout()),this,SLOT(move()));
}

void Healthpack::move()
{
    if(this->pos().y()>game->height())
    {
        game->scene->removeItem(this);
        delete this;
        return;
    }

    //heal player
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0; i<colliding_items.size();++i)
    {
        Player * player = dynamic_cast<Player *> (colliding_items[i]);
        if(player)
        {
            game->scene->removeItem(this);
            player->setHealth(1);
            delete this;
            return;
         }
     }
    setPos(x(),y()+6);
}
