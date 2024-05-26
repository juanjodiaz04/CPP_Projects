#include "node.h"

node::node()
{
    nombre_nodo = "";

}

node::node(std::string nombre){

    nombre_nodo= nombre;

}

void node::añadir_enlace(std::string nodo_nuevo, int costo_nuevo ){

    enlaces[nodo_nuevo]= costo_nuevo;

}

void node::borrar_enlace(std::string nodo_borrar){
    enlaces.erase(nodo_borrar);
}

int node::calcular_costo(std::string nodo_calcular){
    int cost= 0;
    cost= enlaces[nodo_calcular];

    return cost;
}

void node::modificar_costo(std::string nodo_modif, int nuevo_costo){
    if(enlaces.find(nodo_modif)==enlaces.end()){
        std::cout<< "Este nodo no existe";
    }
    else{
        enlaces.emplace(nodo_modif,nuevo_costo);
    }

}

void node::imprimir_enlaces_y_costos(){
    for (it= enlaces.begin();it != enlaces.end() ;it++) {
        std::cout << it -> first<< "  "<< it -> second;
        std::cout <<std::endl;
    }
}


