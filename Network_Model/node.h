#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <direct.h>
#include <set>
#include <map>

class node
{
private:
    std::string nombre_nodo;
    std::map<std::string,int>::iterator it;
    std::map<std::string,int> enlaces;

public:
    node();
    node(std::string nombre);
    int calcular_costo(std::string nodo_calcular );
    void añadir_enlace(std::string nodo_nuevo, int costo_nuevo);
    void borrar_enlace(std::string nodo_borrar);
    void modificar_costo(std::string nodo_modif, int nuevo_costo);
    void imprimir_enlaces_y_costos();

};

#endif // NODE_H
