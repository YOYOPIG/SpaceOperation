#ifndef BOSS_H
#define BOSS_H

#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QObject>
#include <QProgressBar>

class Boss : public  QObject, public QGraphicsPixmapItem
{
Q_OBJECT
public :
    Boss();
    ~Boss();
    QTimer * shootTimer;

signals:
    dead();


public slots:
    virtual void shoot();
    virtual void move();

private:
    double direction_angle;
    int redir_index;
    int health;
    QProgressBar * HP;
};

#endif // BOSS_H
