#ifndef ENEMYJET_H
#define ENEMYJET_H

#include "enemy.h"

class Enemyjet : public Enemy
{
public:
    Enemyjet();

public slots:
    void move();

};

#endif // ENEMYJET_H
