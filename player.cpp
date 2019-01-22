#include "player.h"
#include "game.h"
#include "bullet.h"
#include <QPixmap>
#include <QTimer>
#include <QtGamepad/QGamepad>
#include <QtGamepad/QGamepadKeyNavigation>
#include <QtGamepad/QGamepadManager>
#include <QList>
#include <QKeyEvent>
#include <QDebug>

extern Game * game;

Player::Player()
{
    setPixmap(QPixmap(":/image/player.png"));
    setPos(1250,980);
    shield = new QGraphicsPixmapItem();
    shield->setPixmap(QPixmap(":/skill/gameshield.png"));
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(checkGamepad()));
    timer->start(10);
    connect(this,SIGNAL(mushroom()),this,SLOT(move()));
    connect(gamepad,SIGNAL(buttonXChanged(bool)),this,SLOT(shoot()));
    connect(gamepad,SIGNAL(buttonYChanged(bool)),this,SLOT(skill1()));
    connect(gamepad,SIGNAL(buttonBChanged(bool)),this,SLOT(skill2()));
    toShoot = true;
    toUseSkill1 = true;
    toUseSkill2 = true;
    have_shield = false;
    health = 10;
    mana=50;                     //debug use
    HPBar = new QProgressBar();
    HPBar->setTextVisible(false);
    HPBar->setRange(0,health);
    HPBar->setValue(health);
    HPBar->setGeometry(150, 50 , 400 , 50 );
    QGraphicsProxyWidget *HPproxy = game->scene->addWidget(HPBar);
    //proxy->setZValue(15);

    MPBar = new QProgressBar();
    QPalette pal;
    pal.setColor(MPBar->backgroundRole(), Qt::red);
    MPBar->setPalette(pal);
    MPBar->setTextVisible(false);
    MPBar->setRange(0,mana);
    MPBar->setValue(mana);
    MPBar->setGeometry(150, 150 , 400 , 50 );
    MPBar->setStyleSheet("*{ background-color: rgb(45, 50, 30); }");
    MPBar->setPalette(pal);
    QGraphicsProxyWidget *MPproxy = game->scene->addWidget(MPBar);
}

void Player::beDamaged()
{
    if(have_shield)
    {
        have_shield = false;
        game->scene->removeItem(shield);
        return;
    }
    health = health-1;
    HPBar->setValue(health);
    if(health==0) //game over
    {
        emit die();
        return;
    }
}

void Player::setHealth(int dh)
{
    if(health+dh<=10)
        health = health + dh;
    HPBar->setValue(health);
}

int Player::getHealth()
{
    return health;
}

void Player::checkGamepad()
{
    /*if(gamepad->isConnected())
        qDebug()<<"connected!";
    else
        qDebug()<<"gamepad disconnected!";*/
    if(gamepad->axisLeftX()!=0)
    {
        emit mushroom();
    }

}

void Player::move()
{
    if(pos().x()+ 8*gamepad->axisLeftX()<1863 && pos().x()+ 8*gamepad->axisLeftX()>620)
    {
        if(have_shield)
            shield->setPos(x()-30 + 8*gamepad->axisLeftX(),y()-10);
        setPos(x() + 8*gamepad->axisLeftX(),y());
    }
    if(pos().y()+8*gamepad->axisLeftY()>0 && pos().y()+8*gamepad->axisLeftY()<980)
    {
        if(have_shield)
            shield->setPos(x()-30,y()-10+8*gamepad->axisLeftY());
        setPos(x(),y()+8*gamepad->axisLeftY());
    }
}

void Player::shoot()
{
    if(toShoot) //shoot!
    {
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+20,y());
        game->scene->addItem(bullet);
        toShoot = false;
        /*if(game->shootSE->state()==QMediaPlayer::PlayingState)
            game->shootSE->setPosition(0);
        else if(game->shootSE->state()==QMediaPlayer::StoppedState)
            game->shootSE->play();*/
    }
    else //dont shoot! (release button)
    {
        toShoot = true;
    }
}

void Player::skill1()
{
    if(toUseSkill1)
    {
        switch (game->skill1ID) {
        case 6:
            if(health<=9&&mana>=10)
            {
                health++;
                HPBar->setValue(health);
                mana= mana-10;
                MPBar->setValue(mana);
            }
            break;
        case 7:
            if(have_shield||mana<10)
                break;
            have_shield = true;
            shield->setPos(x()-30,y()-10);
            game->scene->addItem(shield);
            mana= mana-10;
            MPBar->setValue(mana);
        default:
            break;
        }
        toUseSkill1 = false;
    }
    else
    {
        toUseSkill1 = true;
    }
}

void Player::skill2()
{
    if(toUseSkill2)
    {
        switch (game->skill2ID) {
        case 6:
            if(health<=9&&mana>=10)
            {
                health++;
                HPBar->setValue(health);
                mana= mana-10;
                MPBar->setValue(mana);
            }
            break;
        case 7:
            if(have_shield||mana<10)
                break;
            have_shield = true;
            shield->setPos(x()-30,y()-10);
            game->scene->addItem(shield);
            mana= mana-10;
            MPBar->setValue(mana);
        default:
            break;
        }
        toUseSkill2 = false;
    }
    else
    {
        toUseSkill2 = true;
    }
}
