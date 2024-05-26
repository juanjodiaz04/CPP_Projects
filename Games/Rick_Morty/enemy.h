#ifndef ENEMY_H
#define ENEMY_H
#include "character.h"
#include "main_character.h"
#include <QTimer>
#include <cmath>
#include <QList>

class enemy:  public character
{
public:
    Q_OBJECT
public:
    enemy(int tipo1, main_character &personaje);

    int tipo, damage;
    //tamy movimeinto rebota con los limites
    float posx,posy,speedx,speedy;
    //ticket please movimiento circular
    int  centerX ;
    int  centerY ;
    int  radius ;
    float  omega;
    float T,k,n;

    // timers tammy
    QTimer *timer;
    QTimer *timer_dead;

    //timer tickets plese
    //QTimer *timer_image_story;
    //QTimer *timer_dead_tickets;

    float getx();
    void dead();
    main_character *personaje1;


    QRectF boundingRect() const;


signals:
    void delete_tammy();
    void delete_tickets();
    void delete_story_master();
public slots:
    // moviemiento de los enemigos

    void movetammy();
    void movetickets();
    void move_story_master();

    // secuencia de muerte
    void dead_sequency();




};

#endif // ENEMY_H
