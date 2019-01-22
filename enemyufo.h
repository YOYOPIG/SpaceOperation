#ifndef ENEMYUFO_H
#define ENEMYUFO_H

#include "enemy.h"

class Enemyufo : public Enemy
{
public:
    Enemyufo();

public slots:
    void move(); //move left and right
    void shoot();

private:
    bool toRight;
    short int move_counter;
};

#endif // ENEMYUFO_H
