#include "obstacles.h"

obstacles::obstacles(int x, int y, int w_, int h_)
{
    w = w_;
    h = h_;
    posx = x;
    posy = y;
}

QRectF obstacles::boundingRect() const
{
    return QRectF(posx, posy, w, h);
}

void obstacles::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::transparent);
    painter->drawRect(boundingRect());
}

