#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QPixmap>

class enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    float ancho, alto;
public:
    enemy(QString name, float widht, float height);
    QRectF boundingRect() const;

    void up();
    void down();
    void left();
    void right();
};

#endif // ENEMY_H
