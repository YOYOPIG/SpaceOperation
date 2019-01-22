#ifndef CARDMANAGER_H
#define CARDMANAGER_H

#include "gamecardicon.h"
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class GameCardManager : public QObject
{
    Q_OBJECT
public:
    GameCardManager();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void showSidePlane();
    void hideSidePlane();
    void showSidePerk();
    void hideSidePerk();
    bool isInLineup(int ID);
    int owned_cards[21];
    GameCardIcon * player;
    GameCardIcon * skill1;
    GameCardIcon * skill2;
    GameCardIcon * plane1;
    GameCardIcon * plane2;
    GameCardIcon * plane3;
    GameCardIcon * plane4;
    GameCardIcon * plane5;
    GameCardIcon * plane6;
    GameCardIcon * perk1;
    GameCardIcon * perk2;
    GameCardIcon * perk3;
    GameCardIcon * perk4;
    GameCardIcon * perk5;
    GameCardIcon * perk6;
    GameCardIcon * perk7;
    GameCardIcon * perk8;



signals:
    void clicked();
public slots:
    void add_icons();
    void back();

};

#endif // CARDMANAGER_H
