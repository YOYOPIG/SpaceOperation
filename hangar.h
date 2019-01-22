#ifndef HANGAR_H
#define HANGAR_H

#include <QObject>

class Hangar:public QObject
{
    Q_OBJECT
public:
    Hangar();
    void enterHangar();
};

#endif // HANGAR_H
