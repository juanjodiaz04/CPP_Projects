#ifndef PLANET_H
#define PLANET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QPixmap>

class planet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    float radio;
public:
    float masa;
    planet(QString name, float mass, float radius);
    QRectF boundingRect() const;
};

#endif // PLANET_H
