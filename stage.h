#ifndef STAGE_H
#define STAGE_H

#include <QObject>
#include <QProgressBar>
#include <QGraphicsTextItem>
#include "enemyspawner.h"

class Stage : public QObject{
    Q_OBJECT
public:
    Stage();
    Stage(int ID);
    QGraphicsTextItem *scoreText;
    QGraphicsTextItem *countdown;

public slots:
    void checkIfWin();
    void win();
    void lose();
    void gameOver();


private:
    EnemySpawner * enemySpawner;
    int stageID;
    //QProgressBar * HPBar;
    //QProgressBar * MPBar;

};

#endif // STAGE_H
