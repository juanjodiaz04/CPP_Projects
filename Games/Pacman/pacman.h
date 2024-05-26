#ifndef PACMAN_H
#define PACMAN_H


#include <QObject>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QPixmap>

class pacman : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    float ancho, alto;
public:
    pacman(QString name, float widht, float height);
    QRectF boundingRect() const;
};

#endif // PACMAN_H
