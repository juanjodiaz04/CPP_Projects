#ifndef AMMUNITION_H
#define AMMUNITION_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QPixmap>
#include <QTimer>
#include <QKeyEvent>
#include <QEventLoop>
#include "enemy.h"
#include "main_character.h"
#include <cmath>

class ammunition: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    ammunition( int posx,int posy,QString dir, int tipo);
    void setShoot();
    int damage, posx,posy ;
    QTimer *timer;
    QPixmap *balita;
    QString dir1;

    float Vo,A,T,k;
    unsigned int n;
    void detect_colision();

    int height;
    int width;

    QRectF boundingRect() const;



public slots:
    void moveup();
    void updatePosition();
    void updatePosition1();



};

#endif // AMMUNITION_H
