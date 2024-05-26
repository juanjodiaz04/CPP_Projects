#include "juego.h"
#include <fstream>
#include <string>


void imprimir_historial(const std::string& path);
/*Funcion que imprime en la consola el historial de partidas anteriores
*
*@parametros: const std::string& path.
*@return: void.
*/

int main()
{

    std::string path = "results.txt";

    char opcion = '1';

    while(opcion != '0'){

        std::cout << "\n-- Bienvenido al juego de Othello --\n------------------------------------\n";
        std::cout << "1 - Jugar una nueva partida\n";
        std::cout << "2 - Mostrar historial de partidas\n";
        std::cout << "0 - Salir del Juego\n";
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;

        switch(opcion)
        {
        case '0': std::cout << "\n------------------------------------\nHas salido \n------------------------------------\n\n"<<std::endl;
            break;

        case '1': std::cout <<"\n------------------------------------\nNueva Partida \n------------------------------------\n\n";
            {
                juego* game = new juego;
                game->start_game();
                game->juego_finalizado(game,path);

                delete game;
            }
            break;
        case '2': std::cout << "\n------------------------------------\nHistorico de Partidas \n------------------------------------\n\n"<<std::endl;
            {
                imprimir_historial(path);
            }
            break;

        default:
        {
            std::cout <<"\nSeleccionaste una opcion invalida \n";
        }
        }
    }

    return 0;

}

///* Función para imprimir el historial de partidas*/

void splitt_line(std::string* data, std::string row)
/*Funcion que lee una fila del archivo de texto en formato string y la separa en un array dinámico
*
*@parametros: std::string* data, std::string row.
*@return: void.
*/

{
    int pos = 1;
    int index = 0;

    for(unsigned int i=0;i<row.length() && pos>=0;i=pos+1,index++){
        pos = row.find(';',i);
        data[index] = row.substr(i,pos-i);
    }
}

void imprimir_historial(const std::string &path)
{
    std::ifstream archivo(path);
    std::string line;
    int game_num = 1;

    if (!archivo.is_open()) {
        std::cerr << "Error: El archivo no es accesible." << std::endl;
        return;
    }

    else{
        std::string* data = new std::string[5]; //Array temporal para leer cada línea del archivo de texto

        while(!archivo.eof()){
            std::getline(archivo,line);

            if (line == "") break; // Si llega a la última línea

            splitt_line(data, line);
            std::cout << "Juego " << game_num << "\n";
            std::cout << "Fecha: " << data[0] << "\n";
            std::cout << "Jugador 1: " << data[1] << "\n";
            std::cout << "Jugador 2: " << data[2] << "\n";
            std::cout << "Ganador: " << data[3] << "\n";
            std::cout << "Numero de fichas: " << data[4] << "\n";
            std::cout << "------------------------------------\n";
            game_num++;
        }
        delete[] data;
    }
}
