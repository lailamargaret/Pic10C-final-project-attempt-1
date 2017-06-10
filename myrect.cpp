#include "myrect.h"
#include <QKeyEvent>
#include "bullet.h"
#include <QDebug>
#include <QGraphicsScene>
#include "enemy.h"

MyRect::MyRect(QGraphicsItem *parent)
{
    //bullet sound here
    setPixmap(QPixmap("/images/player.png"));
}

void MyRect::keyPressEvent(QKeyEvent * event)
{
   if (event -> key() == Qt::Key_Left){
       if(pos().x() > 0)
            setPos(x()-10, y());
   }

   else if (event -> key() == Qt::Key_Right){
       if(pos().x() +100 < 800)
            setPos(x()+10, y());
   }

   else if (event -> key() == Qt::Key_Space){
       //create a bullet on top of the player
       Bullet * bullet = new Bullet();
       bullet -> setPos(x(), y());
       //returns a reference to the scene
       scene () -> addItem(bullet);
   }
}

void MyRect::spawn(){
    //create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
