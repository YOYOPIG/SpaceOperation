#include "stage.h"
#include "game.h"
#include "player.h"
#include "enemyspawner.h"
#include "menubutton.h"
#include <QBrush>
#include <QImage>
#include <QGraphicsTextItem>
#include <QGraphicsProxyWidget>
#include <QtGui>
#include <QColor>

extern Game *game;

Stage::Stage()
{
    return;
}

Stage::Stage(int ID)
{
    game->current_score = 0;
    stageID = ID;
    enemySpawner = new EnemySpawner();

    QGraphicsTextItem *hpText = new QGraphicsTextItem(QString("HP"));
    hpText->setDefaultTextColor(Qt::black);
    QFont HPFont("HACKED",40);
    hpText->setFont(HPFont);
    hpText->setPos(70,40);
    game->scene->addItem(hpText);

    QGraphicsTextItem *mpText = new QGraphicsTextItem(QString("MP"));
    mpText->setDefaultTextColor(Qt::black);
    mpText->setFont(HPFont);
    mpText->setPos(70,140);
    game->scene->addItem(mpText);

    scoreText = new QGraphicsTextItem();
    scoreText->setPlainText(QString("Score : ") + QString::number(game->current_score));
    scoreText->setDefaultTextColor(Qt::black);
    scoreText->setFont(HPFont);
    scoreText->setPos(70,240);
    game->scene->addItem(scoreText);

    countdown = new QGraphicsTextItem();
    countdown->setPlainText(QString("Time Remaining : ") + QString::number(180-enemySpawner->gameTime));
    countdown->setDefaultTextColor(Qt::black);
    countdown->setFont(HPFont);
    countdown->setPos(70,540);


    //create player
    Player * player = new Player();
    game->scene->addItem(player);
    connect(player,SIGNAL(die()),this,SLOT(lose()));
    connect(game->moveTimer,SIGNAL(timeout()),this,SLOT(checkIfWin()));

    switch (ID) {
    case 1:
    { //if declaring data in case, don't forget the {}s!
        game->setBackgroundBrush(QBrush(QImage(":/ui/resource/background1.png")));
        QGraphicsTextItem *objText = new QGraphicsTextItem(QString("Objective : \n Get 1500 score"));
        objText->setDefaultTextColor(Qt::black);
        QFont font("HACKED", 35);
        objText->setFont(font);
        objText->setPos(70,340);
        game->scene->addItem(objText);

        //spawn enemy
        enemySpawner = new EnemySpawner(1);
        break;

    }
    case 2:
    {
        game->setBackgroundBrush(QBrush(QImage(":/ui/resource/background.png")));
        QGraphicsTextItem *objText = new QGraphicsTextItem(QString("Objective : \n Survive 180 seconds"));
        objText->setDefaultTextColor(Qt::black);
        QFont font("HACKED", 35);
        objText->setFont(font);
        objText->setPos(70,340);
        game->scene->addItem(objText);
        enemySpawner = new EnemySpawner(2);
        game->scene->addItem(countdown);
        break;
    }
    case 3:
    {
        game->setBackgroundBrush(QBrush(QImage(":/ui2/background3.png")));
        QGraphicsTextItem *objText = new QGraphicsTextItem(QString("Objective : \n Kill the boss"));
        objText->setDefaultTextColor(Qt::black);
        QFont font("HACKED", 35);
        objText->setFont(font);
        objText->setPos(70,340);
        game->scene->addItem(objText);
        enemySpawner = new EnemySpawner(3);
        break;
    }

    default:
        break;
    }
}

void Stage::checkIfWin()
{
    scoreText->setPlainText(QString("Score : ") + QString::number(game->current_score));
    countdown->setPlainText(QString("Time Remaining : ") + QString::number(180-enemySpawner->gameTime));
    switch (stageID) {
    case 1:
        if(game->current_score >=1500)
            win();
        break;
    case 2:
        if(enemySpawner->gameTime>180)
            win();
        break;
    case 3:
        if(enemySpawner->boss_killed)
            win();
        break;
    default:
        break;
    }
}

void Stage::win()
{
    game->scene->clear();
    enemySpawner->spawnEnemyTimer->stop();
    game->moveTimer->stop();
    QGraphicsPixmapItem *white = new QGraphicsPixmapItem();
    white->setPixmap(QPixmap(":/ui/resource/white.png"));
    white->setOpacity(0.5);
    game->scene->addItem(white);
    QGraphicsPixmapItem * victory = new QGraphicsPixmapItem();
    victory->setPixmap(QPixmap(":/ui2/win.jpg"));
    victory->setPos(120,15);
    Menubutton * but = new Menubutton(4);
    but->setPos(1200,800);                                      //relocation !!
    connect(but,SIGNAL(clicked()),this,SLOT(gameOver()));
    game->scene->addItem(victory);
    game->scene->addItem(but);
}

void Stage::lose()
{
    game->scene->clear();
    enemySpawner->spawnEnemyTimer->stop();
    game->moveTimer->stop();
    QGraphicsPixmapItem *white = new QGraphicsPixmapItem();
    white->setPixmap(QPixmap(":/ui/resource/white.png"));
    white->setOpacity(0.5);
    game->scene->addItem(white);
    QGraphicsPixmapItem * fail = new QGraphicsPixmapItem();
    fail->setPixmap(QPixmap(":/ui/resource/lose.jpg"));
    fail->setPos(120,15);
    Menubutton * but = new Menubutton(4);
    but->setPos(200,800);
    connect(but,SIGNAL(clicked()),this,SLOT(gameOver()));
    game->scene->addItem(fail);
    game->scene->addItem(but);
}

void Stage::gameOver()
{
    game->scene->clear();
    enemySpawner->spawnEnemyTimer->stop();
    game->restart();
    delete this;
}

