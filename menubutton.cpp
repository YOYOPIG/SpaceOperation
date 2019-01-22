#include "menubutton.h"
#include <QPixmap>

Menubutton::Menubutton(int buttype, QGraphicsItem *parent)
{
    if(buttype==1)
        setPixmap(QPixmap(":/ui/resource/button1.png"));
    if(buttype==2)
        setPixmap(QPixmap(":/ui/resource/button2.png"));
    if(buttype==3)
        setPixmap(QPixmap(":/ui/resource/button3.png"));
    if(buttype==4)
        setPixmap(QPixmap(":/ui/resource/button4.png"));


}

void Menubutton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}
