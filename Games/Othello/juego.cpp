#include "juego.h"

juego::juego()
{
    Datosjuego = new std::string *[2];
    for(unsigned int i = 0; i < 2; i++)
    {
        Datosjuego[i] = new std::string[2];
    }
}

void juego::jugar(std::string name1, std::string name2)
{
    unsigned int x, y;

    std::cout << "\nEl juego ha iniciado, ** en Othello siempre inician las negras! **\n\n";
    table.printTablero();
    table.status_game();
    while (table.comprobarEstado())
    {
        if(table.current_player() == 1) {

            std::cout << "Turno de " << name1 << " (" << black<< ")" << "\n";
        }
        else std::cout << "Turno de " << name2 << " (" << white << ")" << "\n";

        y = entradaNum();    //verificar las filas
        x = entradaString(); //verificar las columnas

        if(x == 0 && y == 0) {
            table.addSaltos();
            table.cederTurno();
        }

        else {
            if (table.comprobarMov(x-1, y-1))
            {
                table.hacerMovimiento(x-1, y-1);
            }
            else
            {
                std::cout << "Movimiento incorrecto\n";
            }
            table.printTablero();
            table.status_game();
            table.setSaltos(0);
        }
    }

    std::cout << "Fin de la partida!\n------------------------------------\n";

    if (table.darGanador() != -1)
    {
        std::cout << " *** Ganador -> ";
        if(table.darGanador() == 0)
            std::cout << name2 << " <- con " << table.jugadores[0].getFichas() << " fichas ***\n";
        else if (table.darGanador() == 1)
            std::cout << name1 << " <- con " << table.jugadores[1].getFichas() << " fichas ***\n";
    }
    else
    {
        std::cout << "--- Empate ---\n";
    }
}

unsigned int juego::entradaNum()
{
    int y;

    while(true) {
        std::cout << "Ingrese la fila: ";
        if(std::cin >> y) {
            if(y >= 0 && y <= rows) return y;

            else {
                std::cout << "Entrada no valida\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }

        else {
            std::cout << "Entrada no valida\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

unsigned int juego::entradaString()
{
    std::string *nombres;
    std::string x;
    std::locale loc;
    unsigned int x_;

    nombres = table.getNombres_col();

    while(true) {

        std::cout << "Ingrese la columna: ";
        std::cin >> x;
        if(x != "0")
        {
            for (char &c : x) {               //pasamos a mayusculas
                c = std::toupper(c, loc);
            }

            for (int i = 0; i < rows; i++) {  //buscamos los nombres

                if(x == nombres[i]) {          //buscamos si coinciden
                    x_ = i + 1;                //retornamos la posicion encontrada
                    return x_;
                }
            }
            std::cout << "columna incorrecta\n";
        }
        else
        {
            return x_ = 0;
        }
    }
}

void juego::start_game()
{
    std::string name1;
    std::string name2;

    reglas();

    std::cout<<"Ingrese el nombre del jugador 1: ";
    std::cin>>name1;
    std::cout<<"Ingrese el nombre del jugador 2: ";
    std::cin>>name2;

    set_jugadores(name1, name2);
    jugar(name1, name2);
}

void juego::set_jugadores(std::string pl1, std::string pl2)
{
    Datosjuego[0][0] = pl1;
    Datosjuego[1][0] = pl2;
}

void juego::set_fichas()
{
    Datosjuego[0][1] = std::to_string(table.jugadores[0].getFichas());
    Datosjuego[1][1] = std::to_string(table.jugadores[1].getFichas());
}

void juego::append_results(const std::string &path)
{
    std::string* data = new std::string[5];

    // Fecha y hora
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(now);
    std::string horaActual = std::ctime(&time);
    horaActual.pop_back(); //Quitar el caracter de finalización de línea

    data[0] = horaActual; //Fecha y hora de la partida
    data[1] = Datosjuego[0][0]; //Nombre del primer jugador
    data[2] = Datosjuego[1][0]; // Nombre del segundo jugador

    if (table.darGanador() == -1)
    {
        data[3] = "Empate";
        data[4] = Datosjuego[0][1]; //Igual número de fichas
    }
    else
    {
        bool gan;
        gan = table.darGanador();
        data[3] = Datosjuego[!gan][0]; //Jugador Ganador
        data[4] = Datosjuego[gan][1]; //Número de Fichas del ganador
    }
    std::ofstream archivo(path, std::ios::app); // Modo Append

    if(!archivo.is_open()) {
        std::cerr << "Error: El archivo no es accesible." << std::endl;
    }

    else {
        for (int i = 0; i < 5; ++i) {
            archivo << data[i];
            if (i < 1) {
                archivo << ';';
            }
        }
        archivo << std::endl;

        archivo.close();
    }

    delete[] data;
}

void juego::reglas()
{
    std::cout << "------------------------------------" << std::endl;
    std::cout << "Reglas" << std::endl;
    std::cout << "------------------------------------\n" << std::endl;
    std::cout << "1. Othello se juega en un tablero de 8x8." << std::endl;
    std::cout << "2. Hay dos jugadores, uno con fichas negras(-) y otro con fichas blancas(*)." << std::endl;
    std::cout << "3. El juego comienza con cuatro fichas en el centro del tablero." << std::endl;
    std::cout << "4. Los jugadores se alternan para colocar una ficha de su color en el tablero." << std::endl;
    std::cout << "5. Para hacer un movimiento valido, debes rodear fichas del oponente entre tus fichas en cualquier direccion." << std::endl;
    std::cout << "6. Todas las fichas del oponente encerradas se voltean y se convierten en tus fichas." << std::endl;
    std::cout << "7. El juego continua hasta que no se pueden realizar mas movimientos legales." << std::endl;
    std::cout << "8. El jugador con mas fichas de su color en el tablero al final del juego gana." << std::endl;
    std::cout << "9. Si un jugador no puede hacer un movimiento valido, pasa su turno al oponente." << std::endl;
    std::cout << "10. El juego termina cuando ambos jugadores cedieron sus turnos consecutivamente o el tablero esta lleno." << std::endl;
    std::cout << "11. Para ceder un turno ingrese fila 0, columna 0\n" << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "Para comenzar define el nombre de los jugadores" << std::endl;
    std::cout << "-----------------------------------------------------\n" << std::endl;
}

void juego::juego_finalizado(juego *game, const std::string &path)
{
    std::cout<<"\n";
    std::cout<<"Los resultados seran agregados al historial " <<std::endl;
    std::cout<<"\n"<<"\n";
    game->set_fichas();
    game->append_results(path);

}

juego::~juego()
{
    for(unsigned int i = 0; i < 2; i++)
    {
        delete []Datosjuego[i];
    }
    delete []Datosjuego;
}
