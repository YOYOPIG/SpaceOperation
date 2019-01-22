#ifndef HEALTHPACK_H
#define HEALTHPACK_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Healthpack : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Healthpack();

public slots:
    void move();
};

#endif // HEALTHPACK_H
