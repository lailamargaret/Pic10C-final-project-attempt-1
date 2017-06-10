#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include "enemy.h"
#include "game.h"
#include<QMediaPlayer>
#include <QGraphicsPixmapItem>


//external global object called game of type game*
extern Game * game;

Bullet::Bullet()
{
    //set the bullet's size/draw
    setRect(0,0, 10, 50);

    // connect
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50); //sets timer's time to 50 ms
}

void Bullet::move(){ //gets called periodically
   //if bullet collides w/ enemy, destroy both
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
           //increase score
            game->score->increase();

            //remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

           //destroy
            delete colliding_items[i];
            delete this;
            return;
          }
    }

    setPos(x(), y()-10);
    if(pos().y() + rect().height()< 0){
        scene()->removeItem(this);
        delete this;
    }
}
