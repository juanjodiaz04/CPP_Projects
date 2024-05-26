#include "ammunition.h"

ammunition::ammunition(int x, int y ,QString direction, int tipo)
{

    timer = new QTimer(this);

    A=9;
    Vo= 2;
    T = 0.01;

    //Periodo de muestreo en segundos
    n = 0;
    k = 2;//Factor de velocidad

    posx= x;
    posy = y;

    height = 40;
    width = 40;
    if (tipo==1){
        timer->start(1000*T);

        setPos(posx,posy);

        damage= 10;


        dir1=direction;
        setShoot();
        connect(timer,SIGNAL(timeout()),this,SLOT(moveup()));
    }
    if(tipo==2){
         QTransform rotation;
         rotation.rotate(180);
         damage= 10;

        timer->start(1000*T);
        setPixmap ((QPixmap(":/new/prefix1/sprites/48.png").scaled(width,height)).transformed(rotation));
        connect(timer,SIGNAL(timeout()),this,SLOT(updatePosition()));

    }
    if(tipo==3){
        QTransform rotation;
        rotation.rotate(180);
        damage= 10;

        timer->start(1000*T);
        setPixmap ((QPixmap(":/new/prefix1/sprites/48.png").scaled(width,height)).transformed(rotation));
        connect(timer,SIGNAL(timeout()),this,SLOT(updatePosition1()));

    }
}


void ammunition::setShoot(){
    if (dir1 == "up"){
        posx+=7;
        posy-=15;

    }
    else if (dir1 == "left"){
        posx -=5;
        posy+=15;
    }
    else if(dir1 == "down"){
        posy +=15;
        posx+=3;
    }
    else if(dir1 == "right"){
        posx +=8;
        posy += 15;

    }
}

QRectF ammunition::boundingRect() const
{
    return QRectF(-width/2, -height/2, 2*width, 2*height);
}

void ammunition::moveup(){
    QTransform rotation;




    if (dir1 == "up"){

        posy =posy- Vo-0.5*(A)*(n*n*k*k*T*T);
        setPos(posx,posy);


        setPixmap (QPixmap(":/new/prefix1/sprites/49.png").scaled(width,height));
        setPixmap (QPixmap(":/new/prefix1/sprites/50.png").scaled(width,height));
        n++;
    }
    else if (dir1 == "left"){
        posx =posx- Vo-0.5*(A)*(n*n*k*k*T*T);
        setPos(posx,posy);

        rotation.rotate(-90);
        setPixmap ((QPixmap(":/new/prefix1/sprites/49.png").scaled(width,height)).transformed(rotation));
        setPixmap ((QPixmap(":/new/prefix1/sprites/50.png").scaled(width,height)).transformed(rotation));
        n++;
    }
    else if(dir1 == "down"){

        posy =posy+ Vo+0.5*(A)*(n*n*k*k*T*T);
        setPos(posx,posy);

        rotation.rotate(180);
        setPixmap ((QPixmap(":/new/prefix1/sprites/49.png").scaled(width,height)).transformed(rotation));
        setPixmap ((QPixmap(":/new/prefix1/sprites/50.png").scaled(width,height)).transformed(rotation));
        n++;
    }
    else if(dir1 == "right"){

        posx =posx+ Vo+0.5*(A)*(n*n*k*k*T*T);
        setPos(posx,posy);

        rotation.rotate(90);
        setPixmap ((QPixmap(":/new/prefix1/sprites/49.png").scaled(width,height)).transformed(rotation));
        setPixmap ((QPixmap(":/new/prefix1/sprites/50.png").scaled(width,height)).transformed(rotation));
        n++;
    }

}

void ammunition::updatePosition() {
    // Calcular las nuevas posiciones utilizando la ecuación de movimiento parabólico

    posx = posx + k;
    posy=  posy - k * T*n + 0.5 * A * std::pow(T*n, 2);

    // Actualizar la posición del objeto
    setPos(posx, posy);

    // Incrementar el tiempo
    n++;
}

void ammunition::updatePosition1() {
    // Calcular las nuevas posiciones utilizando la ecuación de movimiento parabólico


    posx = posx - k;
    posy=  posy - k * T*n + 0.5 * A * std::pow(T*n, 2);

    // Actualizar la posición del objeto
    setPos(posx, posy);

    // Incrementar el tiempo
    n++;
}
