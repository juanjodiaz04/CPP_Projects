#ifndef TABLERO_H
#define TABLERO_H
#include "ficha.h"
#include "player.h"


class tablero
{
private:

    ficha **matriz;                  //representacion bidimensional del tablero
    unsigned int fichas;             //cantidad de fichas sobre el tablero
    std::string *nombres_col;        //nombres de las columnas del tablero, se usa para comprobar entradas
    short jug_actual, enemy, winner, saltos; //turno, ganador
    short *dy, *dx;                  //diferencias en y y en x para recorrer alrededor de una casilla

//  ****

    bool checkFlip(char color, int y, int x, int i);
/*Funcion que recibe un caracter (color), cuatro enteros
*y retorna un buleano.
*
*Comprueba si hay una ficha del jugador en la misma linea de la ficha a colocar,
*es decir, si encuentra una ficha del jugador a la izquierda, derecha, arriba, abajo o diagonales.
*
*@parametros: char color (- o *), int x (columna) int y (fila) int i posicion en dy dx.
*@return: bool.
*/
    bool Isfree(int y, int x);
/*Funcion que recibe dos enteros (fila, columna)
*y verifica si esa posicion está vacía.
*
*@parametros: int x (columna) int y (fila).
*@return: bool.
*/

    void robarFichas(char color, int y, int x, int i);
/*Funcion que recibe un caracter (color) y cuatro enteros
*y cambia las fichas presentes en una misma linea por las del
*jugador.
*
*@parametros: char color (- o *), int x (columna) int y (fila) int i posicion en dy dx.
*@return: void.
*/
    void nombreCols();
/*Funcion que guarda en un arreglo de std::srings
*letras mayusculas de la A a la Z (segun la cantidad solicitada).
*
*@parametros: void.
*@return: void.
*/
    void printNombresCol();
/*Funcion que muestra por pantalla los datos presentes en
*un std::string.
*
*@parametros: void.
*@return: void.
*/

public:

    tablero();   //constructor
    player jugadores[2];

//  ****

    std::string *getNombres_col() const;
/*Funcion que retorna la posicion de memoria de un arreglo de std::string
*
*@parametros: void.
*@return: std::string *.
*/

    unsigned int current_player();
/*Funcion que retorna el turno del jugador actual.
*
*@parametros: void.
*@return: unsigned int.
*/

    unsigned int enemy_player();
/*Funcion que retorna el turno del adversario.
*
*@parametros: void.
*@return: unsigned int.
*/

    bool comprobarMov(int x, int y);
/*Funcion que recibe un par ordenado y comprueba si un movimiento desde ahi es
*valido.
*
*@parametros: int x, int y.
*@return: bool.
*/

    void hacerMovimiento(int x, int y);
/*Funcion que recibe una posicion en el tablero y realiza los
*cambios en el tablero.
*
*@parametros: int x (columna), int y (fila).
*@return: void.
*/

    void printTablero();
/*Funcion que muestra por pantalla el
*tablero del juego.
*
*@parametros: void.
*@return: void.
*/

    bool comprobarEstado();
/*Funcion que verifica si el juego ha terminado
*
*@parametros: void.
*@return: bool.
*/

    short darGanador();
/*Funcion que retorna el jugador ganador.
*
*@parametros: void.
*@return: short.
*/

    void status_game();
/*Funcion que muestra por pantalla el estado del juego
*
*@parametros: void.
*@return: void.
*/
    void cederTurno();
/*Funcion que cambia el turno del jugador actual por su contrincante.
*
*@parametros: void.
*@return: void.
*/

    void setSaltos(short newSaltos);
/*Funcion que recibe un short y cambia el valor de saltos
*por newSaltos.
*
*@parametros: short.
*@return: void.
*/

    void addSaltos();
/*Funcion que incrementa el atributo saltos en 1.
*
*@parametros: void.
*@return: void.
*/
    ~tablero();   //destructor
};

#endif // TABLERO_H
