#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include <QMediaPlayer>

Game::Game(QWidget *parent){

   scene = new QGraphicsScene();
   scene->setSceneRect(0,0,800,600);
   setScene(scene);
   setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   setFixedSize(800,600);


    MyRect * player = new MyRect();
    player -> setRect(0,0, 100,100);

    //add item to scene
    scene->addItem(player);

    //make item focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player -> setFocus();
    player->setPos(width()/2, height() - player->rect().height());

   //create the score
    score = new Score();
    scene->addItem(score);

    //health
    health = new Health();
    health->setPos(health->x(), health->y()+25);
    scene->addItem(health);

    //spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

    //music
    // QMediaPlayer * music = new QMediaPlayer();
    // music->setMedia(QUrl("qrc:/sounds/bgsound.mp3"));
    // music->play();

    show();
}
