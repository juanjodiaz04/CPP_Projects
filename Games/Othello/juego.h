#ifndef JUEGO_H
#define JUEGO_H

#include "tablero.h"
#include <chrono>
#include <fstream>
#include <string>
#include <locale>

class juego
{
private:

    std::string** Datosjuego;              //Matriz dinámica que almacena los datos de resumen de partida

    //****

    void jugar(std::string name1, std::string name2);
    /*Funcion que inicia la partida en el tablero
    *
    *@parametros: std::string name1, std::string name2.
    *@return: void.
    */
    unsigned int entradaNum();
    /*Funcion que verifica si una entrada numérica es válida
    *
    *@parametros: void.
    *@return: unsigned int.
    */
    unsigned int entradaString();
    /*Funcion que verifica si una entrada de tipo string es válida
    *
    *@parametros: void.
    *@return: unsigned int.
    */
    void set_jugadores(std::string pl1, std::string pl2);
    /*Funcion que verifica ingresa los nombres de los jugadores en la matriz de datos
    *
    *@parametros: std::string pl1, std::string pl2.
    *@return: void.
    */
    void set_fichas();
    /*Funcion que ingresa el número de fichas de cada jugador en la matriz de datos
    *
    *@parametros: void.
    *@return: void.
    */
    void append_results(const std::string& path);
    /*Funcion que añade un registro de resultados al archivo de texto donde se almacenan los datos
    *
    *@parametros: const std::string& path.
    *@return: void.
    */
    void reglas();
    /*Funcion que imprime las reglas de juego en pantalla
    *
    *@parametros: void.
    *@return: void.
    */
public:
    juego();
    tablero table;           //Objeto tablero anidado en la clase juego

    //****

    void start_game();
    /*Funcion que ejecuta todos los elementos y funciones requeridas para empezar la partida
    *
    *@parametros: void.
    *@return: void.
    */

    void juego_finalizado(juego* game, const std::string& path);
    /*Funcion que ejecuta todos los elementos y funciones requeridas para finalizar la partida
    *
    *@parametros: juego* game, const std::string& path.
    *@return: void.
    */

    ~juego();
};

#endif // JUEGO_H
