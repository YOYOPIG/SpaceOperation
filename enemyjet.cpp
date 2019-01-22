#include "enemyjet.h"
#include "game.h"
#include "player.h"

extern Game *game;

Enemyjet::Enemyjet()
{
    setPixmap(QPixmap(":/enemy/jet.png"));
    shootTimer->start(1500);
    connect(game->moveTimer,SIGNAL(timeout()),this,SLOT(move()));
}

void Enemyjet::move()
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
    setPos(x(),y()+1);
}
