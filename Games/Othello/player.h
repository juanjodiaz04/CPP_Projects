#ifndef PLAYER_H
#define PLAYER_H


class player
{
private:

    char color;
    unsigned int fichas;

public:

    player();

    char getColor();
/*Funcion que retorna el color del jugador
*
*@parametros: void.
*@return: char color.
*/

    void setColor(char newColor);
/*Funcion que recibe un caracter y cambia
*el valor de color por newColor.
*
*@parametros: char newColor (- o *).
*@return: void.
*/

    unsigned int getFichas();
/*Funcion que retorna la cantidad de fichas del jugador.
*
*@parametros: void.
*@return: unsigned int.
*/

    void addFichas(unsigned int newFichas);
/*Funcion que recibe un unsigned int y aumenta el valor del atributo
*en newFichas.
*
*@parametros: unsigned int newFichas.
*@return: void.
*/

    void restFichas(unsigned int newFichas);
/*Funcion que recibe un unsigned int y disminuye el valor del atributo
*en newFichas, si el atributo es 0, no hace nada.
*
*@parametros: unsigned int restFichas.
*@return: void.
*/

    void setFichas(unsigned int newFichas);
/*Funcion que recibe un unsigned int y cambia el valor del atributo
*por newFichas.
*
*@parametros: unsigned int newFichas.
*@return: void.
*/

};

#endif // PLAYER_H
