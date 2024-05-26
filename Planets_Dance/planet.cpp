#include "planet.h"


planet::planet(QString name, float mass, float radius)
{
    masa = mass;
    radio = radius;

    setPixmap (QPixmap(name).scaled(2*radio,2*radio));
}

QRectF planet::boundingRect() const
{
    return QRectF(-radio,-radio,4*radio,4*radio);
}
