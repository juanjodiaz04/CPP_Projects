#include "pacman.h"

pacman::pacman(QString name, float width, float height)
{

    ancho = width;
    alto = height;
    setPixmap (QPixmap(name).scaled(10,10));
}

QRectF pacman::boundingRect() const
{
    return QRectF(-ancho/2, -alto/2, 2*ancho, 2*alto);
}
