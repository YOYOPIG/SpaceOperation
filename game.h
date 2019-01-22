#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include <QMultimedia>
#include <QMediaPlayer>
#include "gamecardmanager.h"

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game();
    void restart();
    QGraphicsScene * scene;
    QTimer * moveTimer;
    GameCardManager * manager;
    //current card data is needed!
    int playerID=0;                   //0: oldplane 1:jet 2:spaceship1 3:spaceship2 4:protector 5: warmachine
    int skill1ID=6;                   //6-13
    int skill2ID=7;
    int current_stage;
    int current_score;
    GameCardIcon * selectedCard = nullptr;
    QMediaPlayer * bgm;
    QMediaPlayer * shootSE;
    QMediaPlayer * skill1SE;
    QMediaPlayer * skill2SE;


public slots:
    void stageSelect();
    void enterStage();
};

#endif // GAME_H
