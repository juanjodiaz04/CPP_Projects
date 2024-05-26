#ifndef OBSTACLES_H
#define OBSTACLES_H

#include <QGraphicsItem>
#include <QPainter>

class obstacles : public QGraphicsItem
{
private:

    int w,h;
    int posx, posy;

public:
    obstacles(int x, int y,int w_, int h_);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // OBSTACLES_H
