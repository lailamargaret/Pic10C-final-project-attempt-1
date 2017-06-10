#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>
#include<QMediaPlayer>
#include<QGraphicsPixmapItem>

//slots are reactions to signals

class Bullet : public QObject, public QGraphicsRectItem {
Q_OBJECT
public:
    Bullet();

public slots:
   void move();
private:
   QMediaPlayer sound;

};

#endif // BULLET_H
