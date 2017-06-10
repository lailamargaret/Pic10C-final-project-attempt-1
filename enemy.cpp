#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>
#include "health.h"
#include "game.h"

extern Game * game;

Enemy::Enemy()
{
    int random_number = rand() % 700;
    //set random position
    setPos(random_number, 0);

    //set the bullet's size/draw
    setPixmap(QPixmap(":/images/enemy.jpg"));

    // connect
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50); //sets timer's time to 50 ms
}

void Enemy::move(){ //gets called periodically
    setPos(x(), y() + 5);
    if(pos().y() > 600){
       game->health->decrease();
        scene()->removeItem(this);
        delete this;

    }
}
