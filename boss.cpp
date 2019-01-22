#include "game.h"
#include "boss.h"
#include "ebullet.h"
#include "player.h"
#include "bullet.h"
#include <cstdlib>
#include <qmath.h>

extern Game * game;

Boss::Boss()
{
    setPixmap(QPixmap(":/boss/boss.png"));
    shootTimer = new QTimer();
    health = 100;
    redir_index = 20;
    connect(shootTimer,SIGNAL(timeout()),this,SLOT(shoot()));
    connect(game->moveTimer,SIGNAL(timeout()),this,SLOT(move()));
    shootTimer->start(1000);
    HP = new QProgressBar();
    HP->setTextVisible(false);
    HP->setRange(0,health);
    HP->setValue(health);
    HP->setGeometry(150, 450 , 400 , 50 );
    QGraphicsProxyWidget *HPproxy = game->scene->addWidget(HP);
}

Boss::~Boss()
{
    emit dead();
}

void Boss::shoot()
{
    Ebullet * ebullet = new Ebullet(1);
    ebullet->setPos(x()+295,y()+250);
    game->scene->addItem(ebullet);
    Ebullet * ebullet2 = new Ebullet(3);
    ebullet2->setPos(x()+295,y()+250);
    game->scene->addItem(ebullet2);
    Ebullet * ebullet3 = new Ebullet(4);
    ebullet3->setPos(x()+295,y()+250);
    game->scene->addItem(ebullet3);
}

void Boss::move()
{
    if(redir_index==60)
    {
        redir_index = 0;
        direction_angle = rand()%360+1;
    }
    else
        redir_index++;

    //damage player when collide, be damaged when hit
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0; i<colliding_items.size();++i)
    {
        Player * player = dynamic_cast<Player *> (colliding_items[i]);
        if(player)
        {
            if(player->getHealth()>1)
                player->beDamaged();
            if(health<=0)
            {
                delete this;
                return;
            }
         }
        Bullet * bul = dynamic_cast<Bullet *> (colliding_items[i]);
        if(bul)
        {
                health = health-2;
                game->scene->removeItem(bul);
                delete bul;
                HP->setValue(health);
                if(health<=0)
                {
                    delete this;
                    return;
                }
        }
     }

    //move
    double STEP_SIZE = 5;
    double dy = STEP_SIZE * qSin(qDegreesToRadians(direction_angle));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(direction_angle));
    if(x()+dx<=1320 && x()+dx>=620)
        setPos(x()+dx,y());
    if(y()+dy>=0&&y()+dy<=400)
        setPos(x(),y()+dy);


}
