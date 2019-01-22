#ifndef STAGEBUTTON_H
#define STAGEBUTTON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

class Stagebutton : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Stagebutton();
    Stagebutton(int ID);
    int stageID;
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
signals:
    void clicked();
};


#endif // STAGEBUTTON_H
