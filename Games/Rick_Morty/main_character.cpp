#include "main_character.h"


main_character::main_character(int tipo1)
{
    tipo=tipo1;
    if (tipo == 1){
        setPixmap (QPixmap(":/new/prefix1/sprites/rick1.png").scaled(50,50));
        posx= 250;
        posy = 250;
        setPos(posx,posy);
        speed = 8;
        health=110;

    }




    if (tipo == 0){
        setPixmap (QPixmap(":/new/prefix1/sprites/morty_down1.png").scaled(50,50));
        posx= 250;
        posy = 250;
        setPos(posx,posy);
        speed = 10;
        health=100;

    }




}



void main_character::moveup()
{

    if (tipo==1){
        if(count <1 *scale){
            setPixmap(QPixmap (":/new/prefix1/sprites/rick_up1.png").scaled(50,50));
            count++;
        }
        else if ((count>=1*scale) && (count< scale*2)){
            setPixmap(QPixmap (":/new/prefix1/sprites/rick_up2.png").scaled(50,50));
            count++;
        }
        else if ((count>=2*scale) && (count< scale*3)){
            setPixmap(QPixmap (":/new/prefix1/sprites/rick_up3.png").scaled(50,50));
            count++;
        }
        else if((count>=3*scale) && (count< scale*4)){
            setPixmap(QPixmap (":/new/prefix1/sprites/rick_up1.png").scaled(50,50));
            count++;
            if (count == 4*scale){
                count =0;
            }
        }
    }
    if (tipo == 0){
        if(count <1 *scale){
            setPixmap(QPixmap (":/new/prefix1/sprites/morty_up1.png").scaled(50,50));
            count++;
        }
        else if ((count>=1*scale) && (count< scale*2)){
            setPixmap(QPixmap (":/new/prefix1/sprites/morty_up2.png").scaled(50,50));
            count++;
        }
        else if ((count>=2*scale) && (count< scale*3)){
            setPixmap(QPixmap (":/new/prefix1/sprites/morty_up1.png").scaled(50,50));
            count++;
        }
        else if((count>=3*scale) && (count< scale*4)){
            setPixmap(QPixmap (":/new/prefix1/sprites/morty_up3.png").scaled(50,50));
            count++;
            if (count == 4*scale){
                count =0;
            }
        }
    }
    posy-=speed;
    setPos(posx, posy);
}

void main_character::moveleft()
{
    if (tipo==1){
        if(count <1 *scale){
            setPixmap(QPixmap (":/new/prefix1/sprites/rick_left1.png").scaled(50,50));
            count++;
        }
        else if ((count>=1*scale) && (count< scale*2)){
            setPixmap(QPixmap (":/new/prefix1/sprites/rick_left2.png").scaled(50,50));
            count++;
        }
        else if ((count>=2*scale) && (count< scale*3)){
            setPixmap(QPixmap (":/new/prefix1/sprites/rick_left3.png").scaled(50,50));
            count++;
        }
        else if((count>=3*scale) && (count< scale*4)){
            setPixmap(QPixmap (":/new/prefix1/sprites/rick_left4.png").scaled(50,50));
            count++;
            if (count == 4*scale){
                count =0;
            }
        }
    }
    if (tipo == 0){
        if(count <1 *scale){
            setPixmap(QPixmap (":/new/prefix1/sprites/morty_left1.png").scaled(50,50));
            count++;
        }
        else if ((count>=1*scale) && (count< scale*2)){
            setPixmap(QPixmap (":/new/prefix1/sprites/morty_left2.png").scaled(50,50));
            count++;
        }
        else if ((count>=2*scale) && (count< scale*3)){
            setPixmap(QPixmap (":/new/prefix1/sprites/morty_left1.png").scaled(50,50));
            count++;
        }
        else if((count>=3*scale) && (count< scale*4)){
            setPixmap(QPixmap (":/new/prefix1/sprites/morty_left3.png").scaled(50,50));
            count++;
            if (count == 4*scale){
                count =0;
            }
        }
    }

    posx-=speed;
    setPos(posx, posy);
}
void main_character::moveright()
{
    QTransform reflection;
    reflection.scale(-1, 1);

    if (tipo == 1){
        if(count <1 *scale){

            setPixmap((QPixmap (":/new/prefix1/sprites/rick_left1.png").scaled(50,50).transformed(reflection)));

            count++;
        }
        else if ((count>=1*scale) && (count< scale*2)){
            setPixmap((QPixmap (":/new/prefix1/sprites/rick_left2.png").scaled(50,50).transformed(reflection)));
            count++;
        }
        else if ((count>=2*scale) && (count< scale*3)){
            setPixmap((QPixmap (":/new/prefix1/sprites/rick_left3.png").scaled(50,50).transformed(reflection)));
            count++;
        }
        else if((count>=3*scale) && (count< scale*4)){
            setPixmap((QPixmap (":/new/prefix1/sprites/rick_left4.png").scaled(50,50).transformed(reflection)));
            count++;
            if (count == 4*scale){
                count =0;
            }
        }
    }
    if (tipo == 0){
        if(count <1 *scale){

            setPixmap((QPixmap (":/new/prefix1/sprites/morty_left1.png").scaled(50,50).transformed(reflection)));

            count++;
        }
        else if ((count>=1*scale) && (count< scale*2)){
            setPixmap((QPixmap (":/new/prefix1/sprites/morty_left2.png").scaled(50,50).transformed(reflection)));
            count++;
        }
        else if ((count>=2*scale) && (count< scale*3)){
            setPixmap((QPixmap (":/new/prefix1/sprites/morty_left1.png").scaled(50,50).transformed(reflection)));
            count++;
        }
        else if((count>=3*scale) && (count< scale*4)){
            setPixmap((QPixmap (":/new/prefix1/sprites/morty_left3.png").scaled(50,50).transformed(reflection)));
            count++;
            if (count == 4*scale){
                count =0;
            }
        }
    }



    posx+=speed;
    setPos(posx, posy);
}
void main_character::movedown()
{
    if(tipo == 1){
        if(count <1 *scale){
            setPixmap(QPixmap (":/new/prefix1/sprites/rick1.png").scaled(50,50));
            count++;
        }
        else if ((count>=1*scale) && (count< scale*2)){
            setPixmap(QPixmap (":/new/prefix1/sprites/rick2.png").scaled(50,50));
            count++;
        }
        else if ((count>=2*scale) && (count< scale*3)){
            setPixmap(QPixmap (":/new/prefix1/sprites/rick1.png").scaled(50,50));
            count++;
        }
        else if((count>=3*scale) && (count< scale*4)){
            setPixmap(QPixmap (":/new/prefix1/sprites/rick3.png").scaled(50,50));
            count++;
            if (count == 4*scale){
                count =0;
            }
        }
    }

    if (tipo == 0){
        if(count <1 *scale){
            setPixmap(QPixmap (":/new/prefix1/sprites/morty_down1.png").scaled(50,50));
            count++;
        }
        else if ((count>=1*scale) && (count< scale*2)){
            setPixmap(QPixmap (":/new/prefix1/sprites/morty_down2.png").scaled(50,50));
            count++;
        }
        else if ((count>=2*scale) && (count< scale*3)){
            setPixmap(QPixmap (":/new/prefix1/sprites/morty_down1.png").scaled(50,50));
            count++;
        }
        else if((count>=3*scale) && (count< scale*4)){
            setPixmap(QPixmap (":/new/prefix1/sprites/morty_down3.png").scaled(50,50));
            count++;
            if (count == 4*scale){
                count =0;
            }
        }
    }
    posy+=speed;
    setPos(posx, posy);
}

void main_character::colision()
{
    if (tipo == 0)
    {
        setPixmap(QPixmap (":/new/prefix1/sprites/morty_sel.png").scaled(50,50));
    }
    else if (tipo == 1)
    {
        setPixmap(QPixmap (":/new/prefix1/sprites/rick_sinvida.png").scaled(50,50));
    }

}

QRectF main_character::boundingRect() const
{
     return QRectF(-50/2, -50/2, 2*50, 2*50);
}
