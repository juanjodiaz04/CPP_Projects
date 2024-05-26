#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QKeyEvent>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* Creación de la escena */
    scene = new QGraphicsScene(); //Crear Escena
    ui->graphicsView->setScene(scene); //Asociar Escena

    /* Lapiz y Brochas */

    /*
    QPen pen(Qt::transparent, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin); //Color, grosor,tipo de línea
    QBrush brush(Qt::black);
    QPen lines(Qt::red, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    */

    QImage Bg("Images/PM_BG.png");
    QBrush Bgimg(Bg);

    /* Fondo de la Escena */

    int sc_factor = 2;

    ui->graphicsView->setBackgroundBrush(Bgimg);
    scene->setSceneRect(0,0,(ui->graphicsView->width() - 1)/sc_factor,(ui->graphicsView->height() - 2)/sc_factor); //
    ui->graphicsView->scale(sc_factor,sc_factor);

    /* PixelMaps */

    fantasmita = new enemy("Images/Pink_Ghost.png",14,14);
    pac = new pacman("Images/Right_Pac.png",13,13);

    //QPixmap PM1("Images/Pink_Ghost.png"); //Fantasma
    //QPixmap PM2("Images/Right_Pac.png");

    //fig1 = new QGraphicsPixmapItem();
    //fig2 = new QGraphicsPixmapItem();

    scene->addItem(fantasmita);
    scene->addItem(pac);

    fantasmita->setPos(6,5);
    pac->setPos(6,229);//Esquinas del mapa = (6,5),(206,5),(6,229),(206,229)

    /* Agregar Elementos */
    //l1 = scene->addLine(0,0,0,150,pen);
    //l2 = scene->addLine(0,0,150,0,pen);
    //r1 = scene->addRect(-50,-50,100,60,pen,fill);
    //e1 = scene->addEllipse(150,150,250,250,pen,fill);

    /* Monedas */

    //Creacion de monedas
    for (int i = 10; i < 220 ; i+= 15){
        for (int j = 10; j < 3*17 ; j+= 34)
        {
            monedas.push_back(new coin(i,j,3));
            scene->addItem(monedas.back());
            monedas.back()->setPos(i,j);
        }
    }

    for (int i = 10; i < 220 ; i+= 23)
    {
        monedas.push_back(new coin(i,24,3));
        scene->addItem(monedas.back());
        monedas.back()->setPos(i,27);
    }

    for (int i = 10; i < 220 ; i+= 15)
    {
        monedas.push_back(new coin(i,65,3));
        scene->addItem(monedas.back());
        monedas.back()->setPos(i,65);
    }

    for (int i = 55 ; i < 175+15 ; i+= 15)
    {
        monedas.push_back(new coin(i,89,3));
        scene->addItem(monedas.back());
        monedas.back()->setPos(i,89);
    }

    for (int i = 10 ; i < 90 ; i+= 15)
    {
        monedas.push_back(new coin(i,114,3));
        scene->addItem(monedas.back());
        monedas.back()->setPos(i,114);
    }

    for (int i = 152 ; i < 220 ; i+= 15)
    {
        monedas.push_back(new coin(i,114,3));
        scene->addItem(monedas.back());
        monedas.back()->setPos(i,114);
    }

    for (int i = 55 ; i < 175+15 ; i+= 15)
    {
        monedas.push_back(new coin(i,138,3));
        scene->addItem(monedas.back());
        monedas.back()->setPos(i,138);
    }

    for (int i = 10 ; i < 220 ; i+= 15)
    {
        monedas.push_back(new coin(i,162,3));
        scene->addItem(monedas.back());
        monedas.back()->setPos(i,162);
    }

    for (int i = 10 ; i < 220 ; i+= 15)
    {
        monedas.push_back(new coin(i,186,3));
        scene->addItem(monedas.back());
        monedas.back()->setPos(i,186);
    }

    for (int i = 10 ; i < 220 ; i+= 15)
    {
        monedas.push_back(new coin(i,210,3));
        scene->addItem(monedas.back());
        monedas.back()->setPos(i,210);
    }

    for (int i = 10 ; i < 220 ; i+= 15)
    {
        monedas.push_back(new coin(i,234,3));
        scene->addItem(monedas.back());
        monedas.back()->setPos(i,234);
    }

    /* Timer */
    timer = new QTimer(this);
    timer->start(40);
    connect(timer,SIGNAL(timeout()),this,SLOT(movimiento_enemigo()));

    /* Obstáculos */

    /* Definición de cada obstáculo */

    walls.push_back(new obstacles(21,20,24,15)); scene->addItem(walls.back());
    walls.push_back(new obstacles(61,20,32,15)); scene->addItem(walls.back());
    walls.push_back(new obstacles(109,5,8,30)); scene->addItem(walls.back());
    walls.push_back(new obstacles(133,20,32,15)); scene->addItem(walls.back());
    walls.push_back(new obstacles(181,20,24,15)); scene->addItem(walls.back());

    walls.push_back(new obstacles(0,76,45,31)); scene->addItem(walls.back());
    walls.push_back(new obstacles(21,52,24,7)); scene->addItem(walls.back());
    walls.push_back(new obstacles(61,52,8,55)); scene->addItem(walls.back());
    walls.push_back(new obstacles(61,76,32,7)); scene->addItem(walls.back());
    walls.push_back(new obstacles(85,52,56,7)); scene->addItem(walls.back());
    walls.push_back(new obstacles(109,52,8,31)); scene->addItem(walls.back());
    walls.push_back(new obstacles(133,76,32,7)); scene->addItem(walls.back());
    walls.push_back(new obstacles(157,52,8,55)); scene->addItem(walls.back());
    walls.push_back(new obstacles(181,52,24,7)); scene->addItem(walls.back());
    walls.push_back(new obstacles(181,76,44,31)); scene->addItem(walls.back());

    walls.push_back(new obstacles(0,124,45,31)); scene->addItem(walls.back());
    walls.push_back(new obstacles(61,124,8,31)); scene->addItem(walls.back());
    walls.push_back(new obstacles(157,124,8,31)); scene->addItem(walls.back());
    walls.push_back(new obstacles(181,124,44,31)); scene->addItem(walls.back());

    walls.push_back(new obstacles(85,148,56,7)); scene->addItem(walls.back());
    walls.push_back(new obstacles(109,148,8,31)); scene->addItem(walls.back());

    walls.push_back(new obstacles(21,172,24,7)); scene->addItem(walls.back());
    walls.push_back(new obstacles(37,172,8,31)); scene->addItem(walls.back());
    walls.push_back(new obstacles(61,172,32,7)); scene->addItem(walls.back());
    walls.push_back(new obstacles(133,172,32,7)); scene->addItem(walls.back());
    walls.push_back(new obstacles(181,172,8,31)); scene->addItem(walls.back());
    walls.push_back(new obstacles(181,172,24,7)); scene->addItem(walls.back());

    walls.push_back(new obstacles(0,196,21,7)); scene->addItem(walls.back());
    walls.push_back(new obstacles(85,196,56,7)); scene->addItem(walls.back());
    walls.push_back(new obstacles(206,196,19,7)); scene->addItem(walls.back());

    walls.push_back(new obstacles(61,196,8,31)); scene->addItem(walls.back());
    walls.push_back(new obstacles(109,196,8,31)); scene->addItem(walls.back());
    walls.push_back(new obstacles(157,196,8,31)); scene->addItem(walls.back());

    walls.push_back(new obstacles(21,220,71,7)); scene->addItem(walls.back());
    walls.push_back(new obstacles(133,220,71,7)); scene->addItem(walls.back());

    walls.push_back(new obstacles(85,100,19,3)); scene->addItem(walls.back());
    walls.push_back(new obstacles(121,100,19,3)); scene->addItem(walls.back());
    walls.push_back(new obstacles(85,100,3,31)); scene->addItem(walls.back());
    walls.push_back(new obstacles(138,100,3,31)); scene->addItem(walls.back());
    walls.push_back(new obstacles(85,128,56,3)); scene->addItem(walls.back());

    /* Detección de colisión de monedas */

    for (int i = 0; i < monedas.size(); i++)
    {
        for (int j = 0; j < walls.size(); j++)
        {
            if (monedas[i]->collidesWithItem(walls.at(j),Qt::IntersectsItemBoundingRect))
            {
                scene->removeItem(monedas.at(i));
                monedas.removeAt(i);
            }
        }
    }
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{

    if (e->key()==Qt::Key_A && pac->pos().x() >= 8 )
    {
        pac->setPixmap(QPixmap ("Images/Left_Pac.png").scaled(10,10));
        obst_collition(e);
        pac->setPos(pac->pos().x() - 4,pac->pos().y());
    }
    else if (e->key()==Qt::Key_S && pac->pos().y() <= 227 )
    {
        pac->setPixmap(QPixmap ("Images/Down_Pac.png").scaled(10,10));
        obst_collition(e);
        pac->setPos(pac->pos().x(),pac->pos().y() + 3);
    }
    else if (e->key()==Qt::Key_D && pac->pos().x() <= 206 )
    {
        pac->setPixmap(QPixmap ("Images/Right_Pac.png").scaled(10,10));
        obst_collition(e);
        pac->setPos(pac->pos().x() + 4,pac->pos().y());
    }
    else if (e->key()==Qt::Key_W && pac->pos().y() >= 7 )
    {
        pac->setPixmap(QPixmap ("Images/Up_Pac.png").scaled(10,10));
        obst_collition(e);
        pac->setPos(pac->pos().x(),pac->pos().y() - 3);
    }
    else if(e->key()==Qt::Key_D && pac->pos().y() > 105 && pac->pos().y() < 120)
    {
        pac->setPixmap(QPixmap ("Images/Right_Pac.png"));
        pac->setPos(0,pac->pos().y());
    }

    else if(e->key()==Qt::Key_A && pac->pos().y() > 105 && pac->pos().y() < 120)
    {
        pac->setPixmap(QPixmap ("Images/Left_Pac.png"));
        pac->setPos(205,pac->pos().y());
    }

    /* Conseguir Monedas */
    for (int i = 0; i < monedas.size(); i++)
    {
        if (pac->collidesWithItem(monedas.at(i)))
        {
            scene->removeItem(monedas.at(i));
            monedas.removeAt(i);
            break;
        }
    }


}

void MainWindow::moveghost()
{
    if(fantasmita->pos().x() + 5 <= 206)
    {
        fantasmita->setPos(fantasmita->pos().x() + 2,fantasmita->pos().y());
    }
    else
    {
        fantasmita->setPos(6,fantasmita->pos().y()+16);
        if(fantasmita->pos().y() >= 227)
        {
            fantasmita->setPos(5,6);
        }
    }

    /* Detección de colisión con pacman*/

    if (pac->collidesWithItem(fantasmita))
    {
        pac->setPixmap(QPixmap ("Images/Ded1.png"));
        pac->setPixmap(QPixmap ("Images/Ded2.png"));
        pac->setPixmap(QPixmap ("Images/Ded3.png"));
        pac->setPixmap(QPixmap ("Images/Ded4.png"));
    }



    for (int i = 0; i < walls.size(); i++)
    {
        if (fantasmita->collidesWithItem(walls.at(i)))
        {
            fantasmita->setPixmap(QPixmap ("Images/Dead_Ghost.png"));
            fantasmita->setPos(fantasmita->pos().x() - 2,fantasmita->pos().y()+ 1);

            break;
        }
        else
        {
            fantasmita->setPixmap(QPixmap ("Images/Pink_Ghost.png"));
        }
    }
}

void MainWindow::movimiento_enemigo(){

    if (fantasmita->pos().x() < pac->pos().x()){
        fantasmita->setPos(fantasmita->pos().x() + 2,fantasmita->pos().y());
        for (int i = 0;i < walls.size();i++) {
            if(fantasmita->collidesWithItem(walls.at(i))){
                fantasmita->setPos(fantasmita->pos().x() - 2,fantasmita->pos().y());
            }
        }
        if (fantasmita->collidesWithItem(pac)){
            end_message();
        }
    }
    else if (fantasmita->x() > pac->x()){
        fantasmita->setPos(fantasmita->pos().x() - 2,fantasmita->pos().y());
        for (int i = 0;i < walls.size();i++) {
            if(fantasmita->collidesWithItem(walls.at(i))){
                fantasmita->setPos(fantasmita->pos().x() + 2,fantasmita->pos().y());
            }
        }
        if (fantasmita->collidesWithItem(pac)){
            end_message();
        }
    }
    if (fantasmita->y() < pac->y()){
        fantasmita->setPos(fantasmita->pos().x(),fantasmita->pos().y()+2);
        for (int i = 0;i < walls.size();i++) {
            if(fantasmita->collidesWithItem(walls.at(i))){
                fantasmita->setPos(fantasmita->pos().x(),fantasmita->pos().y()-2);
            }
        }
        if (fantasmita->collidesWithItem(pac)){
            end_message();
        }
    }
    else if (fantasmita->y() > pac->y()){
        fantasmita->setPos(fantasmita->pos().x(),fantasmita->pos().y()-2);
        for (int i = 0;i < walls.size();i++) {
            if(fantasmita->collidesWithItem(walls.at(i))){
                fantasmita->setPos(fantasmita->pos().x(),fantasmita->pos().y() + 2);
            }
        }
        if (fantasmita->collidesWithItem(pac)){
            end_message();
        }
    }
    if (pac->collidesWithItem(fantasmita))
    {
        pac->setPixmap(QPixmap ("Images/Ded1.png"));
        pac->setPixmap(QPixmap ("Images/Ded2.png"));
        pac->setPixmap(QPixmap ("Images/Ded3.png"));
        pac->setPixmap(QPixmap ("Images/Ded4.png"));
    }
}

void MainWindow::obst_collition(QKeyEvent *e)
{
    for (int i = 0; i < walls.size(); i++)
    {
        if (pac->collidesWithItem(walls.at(i)))
        {
            if (e->key()==Qt::Key_A)
            {
                pac->setPos(pac->pos().x() + 7,pac->pos().y());
            }
            else if (e->key()==Qt::Key_S)
            {
                pac->setPos(pac->pos().x(),pac->pos().y()- 7);
            }
            else if (e->key()==Qt::Key_D)
            {
                pac->setPos(pac->pos().x() - 7,pac->pos().y());
            }
            else if (e->key()==Qt::Key_W)
            {
                pac->setPos(pac->pos().x(),pac->pos().y()+ 7);
            }
            break;
        }
    }
}

void MainWindow::end_message()
{
    /*Mensaje de finalización*/

    QMessageBox mensaje;
    mensaje.setWindowTitle("PacMan");
    mensaje.setText("¡Perdiste!");
    mensaje.setIcon(QMessageBox::Critical);
    mensaje.setStandardButtons(QMessageBox::Ok);
    mensaje.setDefaultButton(QMessageBox::Ok);
    mensaje.exec();

    QApplication::quit();
}

MainWindow::~MainWindow()
{
    delete ui;
}



