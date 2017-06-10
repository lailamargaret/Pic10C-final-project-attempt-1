#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>

class MyRect : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
   MyRect(QGraphicsItem * parent = 0);
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();
private:
   // QMediaPlayer * bulletsound;
};

#endif // MYRECT_H
