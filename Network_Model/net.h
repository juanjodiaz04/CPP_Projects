#ifndef NET_H
#define NET_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <direct.h>
#include <set>
#include <limits>
#include "node.h"
#include <stack>
#include <algorithm>
#include <random>

class net
{
public:
    net();
    net(std::string name, std::string path = "", std::string folder = "");
    //~net();
    void set_net_name(std::string name);
    void set_net_path(std::string path);
    void set_net_folder(std::string folder);
    void set_net_binary(bool binary);
    //std::string get_net_info();
    //void set_net_info(std::string info);
    bool is_read_available();
    //void append_net_info(std::string info);
    std::vector<std::string> get_net_rows();
    void set_net_separator(char separator);
    //void set_net_info_formatted(std::vector<std::string> row);
    std::vector<std::string> get_net_columns();
    //void append_net_info_formatted(std::vector<std::string> row);

    /* Operaciones de la Red*/

    int N_nodes  = 1; // Número de nodos
    std::vector<std::string> get_nodes(const std::string& str1, const std::string& str2);
    void set_n_nodes(int size);
    std::vector<std::vector<int>> matrix; //Matriz de adyacencia
    void create_matrix(int size);
    void display_matrix();

    void del_node_col(int col);
    void del_node_row(int row);
    std::vector<std::string> nodes; //Vector de strings donde están los nombres de los nodos

    /* Cambio de Métodos*/

    void net_connect(net & red);
    void add_node(net &red, const std::vector<int>& connection);
    void del_node(net &red, char node);
    void change_cost(net &red, std::vector<std::string> line);
    void set_nodes(net &red);
    void disc_node(char node);

    /* Dijkstra */

    int dijkstra(const std::vector<std::vector<int>>& matr, char Origen, char Destino);
    std::vector<int> d_path(const std::vector<std::vector<int>>& matr, char Origen, char Destino);

    /*Clase nodo anidada*/

    std::map<std::string,node> objetos;
    void crear_objetos(std::vector<std::vector<int>>& matriz, std::vector<std::string>& nodos);

    //crear red aleatoria
    void aleatory(int maxCost, double probability);


private:
    std::string name;
    std::string path;
    std::string folder;
    bool is_named, is_binary;
    char separator, row_separator = '\n';

    std::string concat_net_name();
    //void create_net();
    std::vector<std::string> split(std::string row);
    void create_folder();
    std::string concat_folder_name();

    void add_node_col(const std::vector<int>& col);
    void add_node_row(const std::vector<int>& row);
    void node_conection(std::vector<std::string> str_in);
};

#endif // NET_H
