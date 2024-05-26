#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <qgraphicsscene.h>
#include "planet.h"
#include <math.h>
#include <QCoreApplication>
#include <QFile>
#include <fstream>
#include <string>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    /*Escena*/
    QGraphicsScene *scene;
    int zx = 2000;
    int zy = 1200;
    int mov_scale = 8;

    /*Movimiento */

    QTimer *time;

    float x,y,r,vx,vy,ax,ay,T,k,t_f;
    float G = 1;

    /*Planetas*/
    int n_p = 0;
    QList <planet*> planetas;

    /*Datos*/
    double** m_d;
    void save_data(const std::string& path);
    bool first_opened = false;


private slots:

    void iniciar_clicked();
    void parar_clicked();
    void simulation_step();
};
#endif // MAINWINDOW_H
