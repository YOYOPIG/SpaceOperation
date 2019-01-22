#include "game.h"
#include "player.h"
#include "enemy.h"
#include "enemyspawner.h"
#include "menubutton.h"
#include "stagebutton.h"
#include "stage.h"
#include "gamecardmanager.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QSignalMapper>
#include <QFont>
#include <QBrush>
#include <cstdlib>
#include <QMediaPlaylist>
#include <QDebug>

Game::Game()
{
    //Create new scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1920,1080);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1920,1080);

    //init
    manager = new GameCardManager();
    bgm = new QMediaPlayer();
    shootSE = new QMediaPlayer();
    skill1SE = new QMediaPlayer();
    skill2SE = new QMediaPlayer();
    current_stage = 0;

    //open menu
    setBackgroundBrush(QBrush(QImage(":/ui/resource/menu.jpg")));
    QGraphicsTextItem * topic = new QGraphicsTextItem(QString(" Space Operation "));
    topic->setDefaultTextColor(Qt::white);
    QFont topicFont("HACKED",100);
    topic->setFont(topicFont);
    topic->setPos(350,100);
    scene->addItem(topic);
    Menubutton * but1 = new Menubutton(1);
    but1->setPos(650,400);
    scene->addItem(but1);
    connect(but1,SIGNAL(clicked()),this,SLOT(stageSelect()));
    Menubutton * but2 = new Menubutton(2);
    but2->setPos(650,600);
    scene->addItem(but2);
    connect(but2,SIGNAL(clicked()),manager,SLOT(add_icons()));
    Menubutton * but3 = new Menubutton(3);
    but3->setPos(650,800);
    scene->addItem(but3);
    connect(but3,SIGNAL(clicked()),this,SLOT(close()));

    shootSE->setMedia(QUrl::fromLocalFile("E:\\YOYOPIG\\coding ex\\games\\Space Operation\\Resource\\laser.wav"));  //no mp3 files!!
    bgm->setMedia(QUrl::fromLocalFile("E:\\YOYOPIG\\project3\\project3_7 Beta\\Monody.mp3"));
    bgm->setVolume(50);
    bgm->play();


    /*


    //create player
    Player * player = new Player();
    scene->addItem(player);

    //spawn enemy
    EnemySpawner * enemySpawner = new EnemySpawner();
    */
}

void Game::restart()
{
    //open menu
    setBackgroundBrush(QBrush(QImage(":/ui/resource/menu.jpg")));
    QGraphicsTextItem * topic = new QGraphicsTextItem(QString(" Space Operation "));
    topic->setDefaultTextColor(Qt::white);
    QFont topicFont("HACKED",100);
    topic->setFont(topicFont);
    topic->setPos(350,100);
    scene->addItem(topic);
    Menubutton * but1 = new Menubutton(1);
    but1->setPos(650,400);
    scene->addItem(but1);
    connect(but1,SIGNAL(clicked()),this,SLOT(stageSelect()));
    Menubutton * but2 = new Menubutton(2);
    but2->setPos(650,600);
    scene->addItem(but2);
    connect(but2,SIGNAL(clicked()),manager,SLOT(add_icons()));
    Menubutton * but3 = new Menubutton(3);
    but3->setPos(650,800);
    scene->addItem(but3);
    connect(but3,SIGNAL(clicked()),this,SLOT(close()));
    bgm->setMedia(QUrl::fromLocalFile("E:\\YOYOPIG\\project3\\project3_7 Beta\\Monody.mp3"));
    bgm->setVolume(50);
    bgm->play();
}

void Game::stageSelect()
{
    scene->clear();
    Stagebutton * but1 = new Stagebutton(1);
    but1->setPos(10,50);
    scene->addItem(but1);
    Stagebutton * but2 = new Stagebutton(2);
    but2->setPos(650,50);
    scene->addItem(but2);
    Stagebutton * but3 = new Stagebutton(3);
    but3->setPos(1290,50);
    scene->addItem(but3);

    connect(but1,SIGNAL(clicked()),this,SLOT(enterStage()));
    connect(but2,SIGNAL(clicked()),this,SLOT(enterStage()));
    connect(but3,SIGNAL(clicked()),this,SLOT(enterStage()));

}

void Game::enterStage()
{
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    if(current_stage==3)
         playlist->addMedia(QUrl::fromLocalFile("E:\\YOYOPIG\\coding ex\\games\\Space Operation\\Resource\\bossbgm.wav"));
    else
        playlist->addMedia(QUrl::fromLocalFile("E:\\YOYOPIG\\music\\bgm\\gamebgm.wav"));
    bgm->setPlaylist(playlist);
    bgm->setVolume(50);
    bgm->play();
    scene->clear();
    //init. timers
    moveTimer = new QTimer();
    moveTimer->start(10);
    qDebug()<<current_stage;
    Stage * stage = new Stage(current_stage);
}
