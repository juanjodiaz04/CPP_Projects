#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qgraphicsscene.h>
#include "coin.h"
#include "obstacles.h"
#include "enemy.h"
#include "pacman.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    void keyPressEvent(QKeyEvent *e);

    ~MainWindow();

private slots:
    void moveghost();
    void movimiento_enemigo();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    /* Elementos */
    QGraphicsLineItem *l1, *l2; //Lineas
    QGraphicsTextItem *text; //Objetos de Texto
    QGraphicsRectItem *r1;   //Objetos Rectángulo
    QGraphicsEllipseItem *e1; //Objetos Elipses

    /*PixelMap*/
    QGraphicsPixmapItem *fig1;
    QGraphicsPixmapItem *fig2;

    /*Obstáculos*/
    QList <obstacles*> walls;
    QList <coin *> monedas;

    void obst_collition(QKeyEvent *e);

    /*Timer*/
    QTimer *timer;

    /* Enemigos*/
    QList <enemy *> fantasmas;
    enemy *fantasmita;

    /*Personaje */
    pacman *pac;

    void end_message();

};
#endif // MAINWINDOW_H
