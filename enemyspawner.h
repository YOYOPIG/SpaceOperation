#ifndef ENEMYSPAWNER_H
#define ENEMYSPAWNER_H

#include <QObject>
#include <QTimer>

class EnemySpawner : public QObject
{
    Q_OBJECT
public:
    EnemySpawner();
    EnemySpawner(int ID);
    QTimer * spawnEnemyTimer = new QTimer();
    int gameTime;
    int time_index;
    bool boss_killed;
public slots:
    void spawnEnemy();
    void bossDead();
private:
    int stageID;
    bool boss_spawned;


};

#endif // ENEMYSPAWNER_H
