#include "coin.h"

coin::coin(int x, int y,int r_)
{
    r = r_;
    posx = x;
    posy = y;
}
int coin::getR() const
{
    return r;
}

void coin::setR(int value)
{
    r = value;
}

int coin::getPosx() const
{
    return posx;
}

void coin::setPosx(int value)
{
    posx = value;
}

int coin::getPosy() const
{
    return posy;
}

void coin::setPosy(int value)
{
    posy = value;
}

QRectF coin::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void coin::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(boundingRect());
}

