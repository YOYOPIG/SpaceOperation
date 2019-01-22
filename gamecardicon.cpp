#include "gamecardicon.h"
#include "gamecardmanager.h"
#include "game.h"
#include <QPixmap>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

extern Game * game;

GameCardIcon::GameCardIcon()
{
    setAcceptHoverEvents(true);
    myID=0;
    return;
}

GameCardIcon::GameCardIcon(int cardID)
{
    setAcceptHoverEvents(true);
    myID = cardID;
    setPic();
    is_selectable = true;
    if(myID==-1||myID==100)
        is_selectable = false;

    //debug use
    myStatus->setPixmap(QPixmap(":/images/Yee.png"));
}

void GameCardIcon::setPic()
{
    //set pixmap to different cards
    switch (myID) {
    case -1:
        setPixmap(QPixmap(":/hangar/unknown.png"));
        is_hero=true;
        break;
    case 0:
        setPixmap(QPixmap(":/hangar/plane1.png"));
        is_hero=true;
        break;
    case 1:
        setPixmap(QPixmap(":/hangar/plane2.png"));
        is_hero=true;
        break;
    case 2:
        setPixmap(QPixmap(":/hangar/plane3.png"));
        is_hero=true;
        break;
    case 3:
        setPixmap(QPixmap(":/hangar/plane4.png"));
        is_hero=true;
        break;
    case 4:
        setPixmap(QPixmap(":/hangar/plane5.png"));
        is_hero=true;
        break;
    case 5:
        setPixmap(QPixmap(":/hangar/plane6.png"));
        is_hero=true;
        break;
    case 6:
        setPixmap(QPixmap(":/hangar/heal.png"));
        break;
    case 7:
        setPixmap(QPixmap(":/hangar/shield.png"));
        break;
    case 100:
        setPixmap(QPixmap(":/hangar/lockicon.png"));
        break;
    default:
        break;
    }
}

void GameCardIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //remove status
    game->scene->removeItem(this->myStatus);
    //no card was picked
    if(game->selectedCard==nullptr)
    {
        game->selectedCard = this;
        this->setOpacity(0.666666);
        if(is_hero)
        {
            game->manager->showSidePlane();
        }
        else
        {
            game->manager->showSidePerk();
        }

        // main deck unselectable
        game->manager->player->is_selectable = false;
        game->manager->skill1->is_selectable = false;
        game->manager->skill2->is_selectable = false;
    }

    //a card is picked, ready to swap
    else
    {
        if(is_selectable)
        {
            if(myID == game->manager->skill1->myID||myID == game->manager->skill2->myID||myID == game->manager->player->myID)
            {
                game->selectedCard->setOpacity(1);

                game->selectedCard = nullptr;
                if(is_hero)
                {
                    game->manager->hideSidePlane();
                }
                else
                {
                    game->manager->hideSidePerk();
                }
                game->manager->player->is_selectable = true;
                game->manager->skill1->is_selectable = true;
                game->manager->skill2->is_selectable = true;
                return;
            }
                                                //here
            //swap back deck pic
            switch (game->selectedCard->myID) {
            case 1:
                game->manager->perk1->setPixmap(QPixmap(":/hangar/heal.png"));
                break;
            case 2:
                game->manager->perk2->setPixmap(QPixmap(":/hangar/shield.png"));
                break;
            case 3:
                game->manager->perk3->setPixmap(QPixmap(":/cards/darkGVirus.jpg"));
                break;
            case 4:
                game->manager->perk4->setPixmap(QPixmap(":/cards/trojan.jpg"));
                break;
            case 5:
                game->manager->perk5->setPixmap(QPixmap(":/cards/trojBug.jpg"));
                break;
            case 6:
                game->manager->perk6->setPixmap(QPixmap(":/cards/worm.jpg"));
                break;
            case 7:
                game->manager->perk7->setPixmap(QPixmap(":/cards/spy.jpg"));
                break;
            case 8:
                game->manager->perk8->setPixmap(QPixmap(":/cards/bug.jpg"));
                break;
            case 9:
                game->manager->plane1->setPixmap(QPixmap(":/cards/penguin.jpg"));
                break;
            case 10:
                game->manager->plane2->setPixmap(QPixmap(":/cards/defenser.jpg"));
                break;
            case 11:
                game->manager->plane3->setPixmap(QPixmap(":/cards/arrow.jpg"));
                break;
            case 12:
                game->manager->plane4->setPixmap(QPixmap(":/cards/bomb.jpg"));
                break;
            case 13:
                game->manager->plane5->setPixmap(QPixmap(":/cards/missile.jpg"));
                break;
            case 14:
                game->manager->plane6->setPixmap(QPixmap(":/cards/poison.jpg"));
                break;
            default:
                break;
            }

            game->selectedCard->myID = this->myID;
            game->selectedCard->setPic();
            game->selectedCard->setOpacity(1);

            game->selectedCard = nullptr;
            if(is_hero)
            {
                this->setPixmap(QPixmap(":/hero/selected2.jpg"));
                game->manager->hideSidePlane();
            }
            else
            {
                this->setPixmap(QPixmap(":/cards/selected1.jpg"));
                game->manager->hideSidePerk();
            }
            //main deck selectable
            game->manager->player->is_selectable = true;
            game->manager->skill1->is_selectable = true;
            game->manager->skill2->is_selectable = true;
        }
        else //unselectable
        {
            game->selectedCard->setOpacity(1);

            if(is_hero)
            {
                if(game->selectedCard->is_hero)
                    game->manager->hideSidePlane();
                else
                    game->manager->hideSidePerk();
            }
            else
            {
                if(game->selectedCard->is_hero)
                    game->manager->hideSidePlane();
                else
                    game->manager->hideSidePerk();
            }
            game->selectedCard = nullptr;
            game->manager->player->is_selectable = true;
            game->manager->skill1->is_selectable = true;
            game->manager->skill2->is_selectable = true;
        }
    }

}

void GameCardIcon::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    if(is_selectable&&myID!=-1&&myID!=22)
    {
        if(game->selectedCard == nullptr)
            myStatus->setPos(1100,200);
        else
            myStatus->setPos(100,200);
        game->scene->addItem(myStatus);
    }
}

void GameCardIcon::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    if(is_selectable&&myID!=-1&&myID!=22)
        game->scene->removeItem(myStatus);
}
