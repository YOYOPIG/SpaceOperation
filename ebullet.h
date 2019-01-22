#ifndef EBULLET_H
#define EBULLET_H
#include <QObject>
#include <QGraphicsPixmapItem>

class Ebullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Ebullet();
    Ebullet(int ID);

public slots:
    void move();

private:
    int bulletID;
};

#endif // EBULLET_H
