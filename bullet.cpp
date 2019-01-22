#include "bullet.h"
#include "game.h"
#include "enemy.h"
#include <QPixmap>
#include <QList>

extern Game * game;

Bullet::Bullet()
{
    setPixmap(QPixmap(":/image/bullet1.png"));
    connect(game->moveTimer,SIGNAL(timeout()),this,SLOT(move()));
    //bulTimer->start(10);
}

void Bullet::move()
{
    if(this->pos().y()<-50)
    {
        game->scene->removeItem(this);
        delete this;
        return;
    }

    //kill enemies
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0; i<colliding_items.size();++i)
    {
        Enemy * bot = dynamic_cast<Enemy *> (colliding_items[i]);
        if(bot)
        {

            //scene()->removeItem(colliding_items[i]);
            game->scene->removeItem(this);
            game->scene->removeItem(bot);
            game->current_score += 100;
            delete bot;
            delete this;
            return;
         }
     }
    setPos(x(),y()-15);
}
