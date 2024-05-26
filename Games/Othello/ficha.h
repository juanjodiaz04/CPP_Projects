#ifndef FICHA_H
#define FICHA_H
#include <iostream>
#include "macros.h"

class ficha
{

private:
    char color = ' ';
    unsigned int x;
    unsigned int y;

public:
    ficha(); //constructor.

    void setColor(char newcolor);
/*Funcion que recibe un caracter
*y cambia el caracter de color por el de newcolor
*
*@parametros: char newcolor.
*@return: void.
*/

    char getColor();
/*Funcion que retorna el valor del
*atributo color.
*
*@parametros: void.
*@return: char.
*/

    void printColor();
/*Funcion que muestra por consola
*el valor de color.
*
*@parametros: void.
*@return: void.
*/

    unsigned int getX();
/*Funcion que retorna un entero que representa
*la coordenada x de la ficha.
*
*@parametros: void.
*@return: unsigned int.
*/

    void setX(unsigned int newX);
/*Funcion que cambia el valor de x por
*newX.
*
*@parametros: unsigned int.
*@return: void.
*/

    unsigned int getY();
/*Funcion que retorna un entero que representa
*la coordenada y de la ficha.
*
*@parametros: void.
*@return: unsigned int y.
*/

    void setY(unsigned int newY);
/*Funcion que cambia el valor de y por
*newY.
*
*@parametros: unsigned int.
*@return: void.
*/

};

#endif // FICHA_H
