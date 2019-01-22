#ifndef GAMECARDICON_H
#define GAMECARDICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class GameCardIcon : public QGraphicsPixmapItem
{
public :
    GameCardIcon();
    GameCardIcon(int cardID);
    void setPic();
    int myID;
    bool is_hero=false;
    bool is_selectable;
    bool owned;
    QGraphicsPixmapItem * myStatus = new QGraphicsPixmapItem();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
};

#endif // GAMECARDICON_H
