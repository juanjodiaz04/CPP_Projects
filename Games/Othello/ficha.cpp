#include "ficha.h"

unsigned int ficha::getX()
{
    return x;
}

void ficha::setX(unsigned int newX)
{
    x = newX;
}

unsigned int ficha::getY()
{
    return y;
}

void ficha::setY(unsigned int newY)
{
    y = newY;
}

ficha::ficha()
{
    char color = ' ';
}

void ficha::setColor(char newcolor)
{
    color = newcolor;
}

char ficha::getColor()
{
    return color;
}

void ficha::printColor()
{
    std::cout << color << '|';
}
