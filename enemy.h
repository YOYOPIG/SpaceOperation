#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QObject>

class Enemy : public QObject, public QGraphicsPixmapItem
{
Q_OBJECT
public :
    Enemy();
    QTimer * shootTimer;

public slots:
    virtual void shoot();
    virtual void move();

};

#endif // ENEMY_H
