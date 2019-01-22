#include "enemy.h"
#include "ebullet.h"
#include "game.h"
#include "player.h"
#include <QPixmap>

extern Game * game;

Enemy::Enemy()
{
    setPixmap(QPixmap(":/enemy/bot.png"));
    shootTimer = new QTimer();
    connect(shootTimer,SIGNAL(timeout()),this,SLOT(shoot()));
    connect(game->moveTimer,SIGNAL(timeout()),this,SLOT(move()));
    //shootTimer->start(1500);
}

void Enemy::shoot()
{
    Ebullet * ebullet = new Ebullet();
    ebullet->setPos(x()+20,y());
    game->scene->addItem(ebullet);
}

void Enemy::move()
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
    setPos(x(),y()+5);
}
