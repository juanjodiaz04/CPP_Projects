#include "enemy.h"

enemy::enemy(QString name, float width, float height)
{

    ancho = width;
    alto = height;
    setPixmap (QPixmap(name));
}

QRectF enemy::boundingRect() const
{
    return QRectF(-ancho/2, -alto/2, 2*ancho, 2*alto);
}

void enemy::up()
{

}
