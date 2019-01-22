#include "enemyufo.h"
#include"ebullet.h"
#include "player.h"
#include "game.h"
#include "cstdlib"

extern Game * game;

Enemyufo::Enemyufo()
{
    move_counter = 0;
    toRight = true;
    setPixmap(QPixmap(":/enemy/ufo2.png"));
    shootTimer->start(2000);
    connect(game->moveTimer,SIGNAL(timeout()),this,SLOT(move()));
}

void Enemyufo::move()
{
    //damage player when collide
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



    //move
    if(move_counter>80) //pause for a while
    {
        setPixmap(QPixmap(":/enemy/ufo2.png"));
        move_counter++;
        if(move_counter>=100)
        {
            move_counter=0;
            //randomize direction
            int dir = rand()%100+1;
            if(dir>=65)
                toRight = !toRight;
        }
        return;
    }
    if(toRight)
    {
        setPixmap(QPixmap(":/enemy/ufo.png"));
        if(this->pos().x()+110>game->width())
        {
            toRight = false;
            return;
        }
        setPos(x()+3,y());
        move_counter++;
        return;
    }
    if(!toRight)
    {
        setPixmap(QPixmap(":/enemy/ufo3.png"));
        if(this->pos().x()-5<620)
        {
            toRight = true;
            return;
        }
        setPos(x()-3,y());
        move_counter++;
        return;
    }
}

void Enemyufo::shoot()
{
    Ebullet * ebullet = new Ebullet(2);
    ebullet->setPos(x()+40,y());
    game->scene->addItem(ebullet);
}

