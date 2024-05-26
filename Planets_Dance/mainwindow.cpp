#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);  // Ejemplo tiro parabolico

    /* Creación de la escena */
    scene = new QGraphicsScene(); //Crear Escena
    ui->graphicsView->setScene(scene); //Asociar Escena

    /*Fondo*/
    QImage Bg(":/BG.jpg");
    QBrush Bgimg(Bg);

    /* Fondo de la Escena */

    double sc_factor = 0.25;

    ui->graphicsView->setBackgroundBrush(Bgimg);
    scene->setSceneRect(0,0,(ui->graphicsView->width() - 2)/sc_factor,(ui->graphicsView->height() - 2)/sc_factor);
    ui->graphicsView->scale(sc_factor,sc_factor);

    // Nuevo origen del QgraphicsView
    double newOriginX = -ui->graphicsView->width() / 2.0 + 350;
    double newOriginY = -ui->graphicsView->height() / 2.0;

    // Establecer el origen en las coordenadas definidas
    scene->setSceneRect(newOriginX, newOriginY, ui->graphicsView->width(), ui->graphicsView->height());

    /*Objetos de la Escena*/

    planetas.push_back(new planet(":/Planet_1.png",700000,100)); scene->addItem(planetas.back()); n_p++;
    planetas.push_back(new planet(":/Planet_2.png",70,70)); scene->addItem(planetas.back()); n_p++;
    planetas.push_back(new planet(":/Planet_3.png",70,70)); scene->addItem(planetas.back()); n_p++;
    planetas.push_back(new planet(":/Planet_4.png",70,70)); scene->addItem(planetas.back()); n_p++;
    planetas.push_back(new planet(":/Planet_5.png",70,70)); scene->addItem(planetas.back()); n_p++;

    /*Datos de la Matriz*/

    m_d = new double*[n_p];
    for (int i = 0; i < n_p; ++i) {
        m_d[i] = new double[6];
    }

    for (int i = 0; i < planetas.size(); i++)
    {
        planetas[i]->setPos(300*i,300*i);
    }


    time = new QTimer;

    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(iniciar_clicked()));
    connect(time,SIGNAL(timeout()),this,SLOT(simulation_step()));
    connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(parar_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::save_data(const std::string &path)
{
    std::ofstream archivo;

    if (first_opened == false)
    {
        archivo.open(path, std::ios::out); // Limpiar el archivo
        archivo << "| x1 | y1 | x2 | y2 | x3 | y3 | x4 | y4 | x5 | y5 |" << std::endl;
        archivo.close();
        first_opened = true;
    }

    archivo.open(path, std::ios::app); // Modo Append

    if(!archivo.is_open()) {
        std::cerr << "Error: El archivo no es accesible." << std::endl;
    }

    else {
        for (int i = 0; i < n_p; i++)
        {
            for (int j = 0; j < 2; ++j) {

                archivo << m_d[i][j];

                if (i + j < n_p + 1)
                {
                    archivo << ';';
                }
            }
        }
        archivo << std::endl;
        archivo.close();
    }
}

void MainWindow::iniciar_clicked()
{
    /*Data Format*/
    /* | x | y | vx | vy | ax | ay | */

    /*Planeta 1*/
    x = ui->xo->value(); m_d[0][0] = x;
    y = ui->yo->value(); m_d[0][1] = y;
    vx = ui->vxo->value(); m_d[0][2] = vx;
    vy = ui->vyo->value(); m_d[0][3] = vy;

    /*Planeta 2*/
    x = ui->xo_2->value(); m_d[1][0] = x;
    y = ui->yo_2->value(); m_d[1][1] = y;
    vx = ui->vxo_2->value(); m_d[1][2] = vx;
    vy = ui->vyo_2->value(); m_d[1][3] = vy;

    /*Planeta 3*/
    x = ui->xo_3->value(); m_d[2][0] = x;
    y = ui->yo_3->value(); m_d[2][1] = y;
    vx = ui->vxo_3->value(); m_d[2][2] = vx;
    vy = ui->vyo_3->value(); m_d[2][3] = vy;

    /*Planeta 4*/
    x = ui->xo_4->value(); m_d[3][0] = x;
    y = ui->yo_4->value(); m_d[3][1] = y;
    vx = ui->vxo_4->value(); m_d[3][2] = vx;
    vy = ui->vyo_4->value(); m_d[3][3] = vy;

    /*Planeta 5*/
    x = ui->xo_5->value(); m_d[4][0] = x;
    y = ui->yo_5->value(); m_d[4][1] = y;
    vx = ui->vxo_5->value(); m_d[4][2] = vx;
    vy = ui->vyo_5->value(); m_d[4][3] = vy;



    T = 10; //Periodo de muestreo en segundos
    k = 100; //Factor de velocidad
    t_f = 10; //Factor Temporal

    for (int i = 0; i < n_p; i++){
        planetas[i]->setPos(m_d[i][0],m_d[i][1]);
    }

    time->start(100*T/k);
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(true);

}

void MainWindow::parar_clicked()
{
    time->stop();
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(false);
}

void MainWindow::simulation_step()
{

    for (int k = 0; k < n_p; ++k) {
        double Ax = 0.0;
        double Ay = 0.0;

        for (int i = 0; i < n_p; ++i) {
            if (i != k) {

                double dx = planetas[i]->pos().x() - planetas[k]->pos().x();
                double dy = planetas[i]->pos().y() - planetas[k]->pos().y();

                r = sqrt(dx * dx + dy * dy);

                Ax = Ax + (planetas[i]->masa * dx) / (r * r * r);
                Ay = Ay + (planetas[i]->masa * dy) / (r * r * r);
            }
        }
        m_d[k][4] = G*Ax;
        m_d[k][5] = G*Ay;
    }


    for (int i = 0; i < n_p ; i++){

        /*Speed*/
        m_d[i][2] = m_d[i][2] + m_d[i][4]*T/t_f; //Vx
        m_d[i][3] = m_d[i][3] + m_d[i][5]*T/t_f; //Vy

        /*Position*/

        m_d[i][0] = m_d[i][0] + m_d[i][2]*T/t_f; //x
        m_d[i][1] = m_d[i][1] + m_d[i][3]*T/t_f; //y

        int xsc,ysc;

        xsc = m_d[i][0]/mov_scale;
        ysc = m_d[i][1]/mov_scale;

        planetas[i]->setPos(xsc, ysc);

    }

    save_data("C:/QtProjects/Repositorio/Info-2/P6_Start/Registros.txt");

}

