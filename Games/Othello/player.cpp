#include "player.h"

char player::getColor()
{
    return color;
}

void player::setColor(char newColor)
{
    color = newColor;
}

unsigned int player::getFichas()
{
    return fichas;
}

void player::addFichas(unsigned int newFichas)
{
    fichas += newFichas;
}

void player::restFichas(unsigned int newFichas)
{
    fichas -= newFichas;
    if(fichas < 0) fichas = 0;
}

void player::setFichas(unsigned int newFichas)
{
    fichas = newFichas;
}

player::player()
{

}
