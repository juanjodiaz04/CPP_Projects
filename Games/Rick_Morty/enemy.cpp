#include "enemy.h"

enemy::enemy(int tipo1, main_character &personaje)
{
    personaje1= &personaje;
    speed= 5;
    tipo=tipo1;
    width = 55;
    height = 55;

    //timer de movimiento
    timer = new QTimer(this);

    //timer secuencia de muerte
    timer_dead = new QTimer;

    if (tipo == 1){

        timer->start(100);
        setPixmap (QPixmap(":/new/prefix1/sprites/tammy_down1.png").scaled(width,height));
        setHealth(50);
        posx= 260;
        posy = 20;
        speedx = 2* speed;
        speedy = 1*speed;
        damage= 10;


        connect(timer,SIGNAL(timeout()),this,SLOT(movetammy()));

    }
    if (tipo == 2){

        setPixmap (QPixmap(":/new/prefix1/sprites/enemy2_left.png").scaled(width,height));
        setHealth(70);
        posx= 100;
        posy =100;

        damage=15;

        centerX = 250;
        centerY = 250;
        radius = 150;
        omega = 0.1;

        //Periodo de muestreo en segundos
        T = 0.01;
        n = 0;
        k = 10;
        //timer_tickets = new QTimer;
        timer->start(1000*T);
        connect(timer,SIGNAL(timeout()),this,SLOT(movetickets()));
        //timer_dead_tammy = new QTimer;
    }
    if (tipo==3){

        timer->start(100);
        setPixmap (QPixmap(":/new/prefix1/sprites/tammy_down1.png").scaled(width,height));
        setHealth(100);
        posx= 10;
        posy = 10;
        speed= 0.05;
        damage=20;
        connect(timer,SIGNAL(timeout()),this,SLOT(move_story_master()));

    }
     if (tipo==4){
       setPixmap (QPixmap(":/new/prefix1/sprites/Nave_1.png").scaled(width,height));
       posx= 10;
       posy = 30;
       damage=0;
    }


    setPos(posx,posy);


}
void enemy::movetammy(){


    posx +=speedx;
    posy += speedy;
    setPos(posx, posy);


    // Verificar colisión con las paredes
    if (posx <= 0 || x() >= 450) {
        speedx = -speedx; // Invertir la velocidad en X en caso de colisión

    }

    if (posy <= 0 || posy >= 450) {
        speedy = -speedy; // Invertir la velocidad en Y en caso de colisión

        if(speedy >= 0){
            setPixmap((QPixmap (":/new/prefix1/sprites/tammy_down1.png").scaled(width,height)));
        }
        if (speedy<0){
            setPixmap((QPixmap (":/new/prefix1/sprites/tammy_up1.png").scaled(width,height)));
        }

    }

}

void enemy::movetickets()
{
    QTransform reflection;
    reflection.scale(-1, 1);

    // Obtener el tiempo actual en segundos


    //Calcular las nuevas coordenadas del objeto
    posx = centerX + radius * cos(omega * k*n*T);
    posy = centerY + radius * sin(omega * k*n*T);
    if(posx >250){
        setPixmap((QPixmap (":/new/prefix1/sprites/enemy2_left.png").scaled(50,50).transformed(reflection)));
    }
    else{
        setPixmap (QPixmap(":/new/prefix1/sprites/enemy2_left.png").scaled(width,height));
    }

    setPos(posx,posy);
    n++;

}




void enemy::move_story_master()
{

    scale= 3;
    if  (count<=1 *scale ){
        setPixmap (QPixmap(":/new/prefix1/sprites/enemy3_down1.png").scaled(width,height));
        count++;
    }
    else if(count <= 2* scale){
        setPixmap (QPixmap(":/new/prefix1/sprites/enemy3_down2.png").scaled(width,height));
        count++;
    }
    else if(count <= 3* scale){
        setPixmap (QPixmap(":/new/prefix1/sprites/enemy3_down3.png").scaled(width,height));
        count++;
        if (count == 3*scale){
            count= 0;
        }
    }

    posx+=  speed*(personaje1->posx-posx);
    posy+=  speed*(personaje1->posy-posy);

    setPos(posx,posy);
}






void enemy::dead_sequency()
{
    scale= 4;

    if(count <1 *scale){
        setPixmap(QPixmap (":/new/prefix1/sprites/explosion1.png").scaled(40,40));
        count++;
    }
    else if ((count>=1*scale) && (count< scale*2)){
        setPixmap(QPixmap (":/new/prefix1/sprites/explosion2.png").scaled(40,40));
        count++;
    }
    else if ((count>=2*scale) && (count< scale*3)){
        setPixmap(QPixmap (":/new/prefix1/sprites/explosion3.png").scaled(40,40));
        count++;
    }
    else if((count>=3*scale) && (count< scale*4)){
        setPixmap(QPixmap (":/new/prefix1/sprites/explosion4.png").scaled(50,50));
        count++;
        if (count== 4*scale){

            if (tipo == 1){
                emit delete_tammy();
            }
            else if(tipo==2){
                emit delete_tickets();
            }
            else if (tipo==3){
                emit delete_story_master();
            }



        }
    }
}


float enemy::getx(){
    return posx;
}

void enemy::dead(){

    timer->stop();

    timer_dead->start(30);

    connect(timer_dead,SIGNAL(timeout()),this,SLOT(dead_sequency()));


}



QRectF enemy::boundingRect() const
{
    return QRectF(-width/2, -height/2, 2*width, 2*height);

}



