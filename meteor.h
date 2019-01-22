#ifndef METEOR_H
#define METEOR_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Meteor : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Meteor();

public slots:
    void move();

private:
    int rot_degree;
};

#endif // METEOR_H
