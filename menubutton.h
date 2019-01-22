#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

class Menubutton : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    // constructors
    Menubutton(int buttype, QGraphicsItem* parent=0); //buttype : 1=start, 2=hangar, 3=exit

    // public methods (events)
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
signals:
    void clicked();
};

#endif // MENUBUTTON_H
