#ifndef ENEMY_H
#define ENEMY_H


#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>

//slots are reactions to signals

class Enemy : public QObject, public QGraphicsPixmapItem {
Q_OBJECT
public:
    Enemy();

public slots:
   void move();

};


#endif // ENEMY_H
