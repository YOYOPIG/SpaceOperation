#include "enemyspawner.h"
#include "enemy.h"
#include "enemyjet.h"
#include "enemyufo.h"
#include "game.h"
#include "healthpack.h"
#include "meteor.h"
#include "boss.h"
#include <cstdlib>
#include <QDebug>

extern Game * game;

EnemySpawner::EnemySpawner()
{
    connect(spawnEnemyTimer,SIGNAL(timeout()),this,SLOT(spawnEnemy()));
    spawnEnemyTimer->start(1000);
    gameTime = 0;
}

EnemySpawner::EnemySpawner(int ID)
{
    stageID = ID;
    connect(spawnEnemyTimer,SIGNAL(timeout()),this,SLOT(spawnEnemy()));
    spawnEnemyTimer->start(1000);
    gameTime = 0;
    boss_killed=false;
    boss_spawned=false;
    srand(time(NULL));
}

void EnemySpawner::spawnEnemy()
{
    gameTime++;
    switch (stageID) {
    case 1:
    {
        Enemy * enemy = new Enemy();
        enemy->setPos(620+(rand()%1250),0);
        game->scene->addItem(enemy);
        break;
    }
    case 2:
    {
        int spawn_index = rand()%2+1;
        if(spawn_index == 1)
        {
            Enemyufo * enemy = new Enemyufo();
            enemy->setPos(620+(rand()%1250),0);
            game->scene->addItem(enemy);
        }
        else
        {
            Enemyjet * enemy = new Enemyjet();
            enemy->setPos(620+(rand()%1250),0);
            game->scene->addItem(enemy);
        }

        if(gameTime%50==0&&gameTime!=0)
        {
            Healthpack * hpack = new Healthpack();
            hpack->setPos(620+(rand()%1250),0);
            game->scene->addItem(hpack);
        }
        if(gameTime%10==0&&gameTime!=0)
        {
            Meteor * met = new Meteor();
            met->setPos(620+(rand()%1250),0);
            game->scene->addItem(met);
        }
        if(gameTime==40)
        {
            Enemyjet * enemy1 = new Enemyjet();
            enemy1->setPos(620,0);
            game->scene->addItem(enemy1);
            Enemyjet * enemy2 = new Enemyjet();
            enemy2->setPos(720,0);
            game->scene->addItem(enemy2);
            Enemyjet * enemy3 = new Enemyjet();
            enemy3->setPos(820,0);
            game->scene->addItem(enemy3);
            Enemyjet * enemy4 = new Enemyjet();
            enemy4->setPos(920,0);
            game->scene->addItem(enemy4);
            Enemyjet * enemy5 = new Enemyjet();
            enemy5->setPos(1020,0);
            game->scene->addItem(enemy5);
        }
        if(gameTime==45)
        {
            Enemyjet * enemy1 = new Enemyjet();
            enemy1->setPos(1420,0);
            game->scene->addItem(enemy1);
            Enemyjet * enemy2 = new Enemyjet();
            enemy2->setPos(1520,0);
            game->scene->addItem(enemy2);
            Enemyjet * enemy3 = new Enemyjet();
            enemy3->setPos(1620,0);
            game->scene->addItem(enemy3);
            Enemyjet * enemy4 = new Enemyjet();
            enemy4->setPos(1720,0);
            game->scene->addItem(enemy4);
            Enemyjet * enemy5 = new Enemyjet();
            enemy5->setPos(1820,0);
            game->scene->addItem(enemy5);
        }
        if(gameTime>120)
        {
            Enemyufo * enemy = new Enemyufo();
            enemy->setPos(620+(rand()%1250),0);
            game->scene->addItem(enemy);
            Enemyjet * enemy2 = new Enemyjet();
            enemy2->setPos(620+(rand()%1250),0);
            game->scene->addItem(enemy2);

        }

        break;
    }
    case 3:
    {
        if(!boss_spawned)
        {
            boss_spawned = true;
            Boss * boss = new Boss();
            boss->setPos(970,0);
            game->scene->addItem(boss);
            connect(boss,SIGNAL(dead()),this,SLOT(bossDead()));
            return;
        }
        int spawn_index = rand()%2+1;
        if(spawn_index == 1)
        {
            Enemyufo * enemy = new Enemyufo();
            enemy->setPos(620+(rand()%1250),0);
            game->scene->addItem(enemy);
        }
        else
        {
            Enemyjet * enemy = new Enemyjet();
            enemy->setPos(620+(rand()%1250),0);
            game->scene->addItem(enemy);
        }
    }

    default:
        break;
    }


    /*int spawn_index = rand()%2+1;
    if(spawn_index == 1)
    {
        Enemyufo * enemy = new Enemyufo();
        enemy->setPos(620+(rand()%1250),0);
        game->scene->addItem(enemy);
    }
    else
    {
        Enemyjet * enemy = new Enemyjet();
        enemy->setPos(620+(rand()%1250),0);
        game->scene->addItem(enemy);
    }*/

}

void EnemySpawner::bossDead()
{
    boss_killed = true;
}
