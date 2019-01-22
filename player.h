#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QtGamepad/QGamepad>
#include <QtGamepad/QGamepadKeyNavigation>
#include <QtGamepad/QGamepadManager>
#include <QProgressBar>

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player();
    QGamepad * gamepad = new QGamepad();
    void beDamaged(); //set health function
    void setHealth(int dh);
    int getHealth();
    bool toShoot;
    bool toUseSkill1;
    bool toUseSkill2;
    QGraphicsPixmapItem * shield;


signals:
    void mushroom();
    void attack();
    void die();

public slots:
    void checkGamepad();
    void move();
    void shoot();
    void skill1();
    void skill2();

private:
    int health;
    int mana;
    bool have_shield;

    QProgressBar * HPBar;
    QProgressBar * MPBar;
};

#endif // PLAYER_H
