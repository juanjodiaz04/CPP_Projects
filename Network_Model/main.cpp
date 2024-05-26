#include <iostream>
#include "net.h"

#include "node.h"

// #include "functions.h"

int main()
{

    int opt = 1;
    while(opt !=0){
        std::cout<<"Seleccione una de las opciones: "<<std::endl<<"1 para red por archivo de texto"<<std::endl<<"2 para red aleatoria"<<std::endl;
        std::cout<<"0 para salir"<<std::endl;
        std::cin>>opt;

        if(opt == 0)
        {
            std::cout<<"Saliste exitosamente"<<std::endl;
            break;
        }

        else if(opt == 1 || opt == 2)
        {

            net red("P4_Grafo.txt","C:/QtProjects/Repositorio/Info-2/P4_Entrega/Creat_File");
            red.set_net_separator(' ');

            if (opt == 1){

                std::cout<<"Red por archivo de texto"<<std::endl;
                red.set_nodes(red);
                red.set_n_nodes(red.nodes.size());
                red.create_matrix(red.N_nodes);
                red.net_connect(red);
                red.crear_objetos(red.matrix, red.nodes);
            }

            else if (opt == 2){

                    std::cout<<"Red aleatoria"<<std::endl;
                    std::cout<<"Ingrese la cantidad de nodos que desea que tenga la Red: ";
                    int numNodes;
                    double probability = 2;
                    std::cin>>numNodes;

                    while(probability < 0 || probability > 1){
                        std::cout<<"Ingrese la probabilidad con la que deseaque se generen enlaces, debe ser un numero entre (0-1): ";
                        std::cin>>probability;

                        if(probability <= 1 && probability > 0){
                            red.set_n_nodes(numNodes);
                            red.create_matrix(red.N_nodes);
                            red.aleatory(numNodes,probability);
                            red.crear_objetos(red.matrix, red.nodes);
                            break;
                        }
                        else{
                            std::cout<<"Ingrese una probabilidad valida, recuerde que es entre 0-1"<<std::endl;
                            std::cout<<std::endl;
                        }
                    }
            }

            int opt2 = 1;
            while(opt2 !=0){
                std::cout<<"Seleccione una de las opciones: "<<std::endl<<"1 para mostrar la matriz de adyacencia de la red"<<std::endl;
                std::cout<<"2 para mostrar la tabla de enrutamiento de un enrutador"<<std::endl;
                std::cout<<"3 para modificar el costo de un enlace"<<std::endl;
                std::cout<<"4 para agregar un enrutador"<<std::endl;
                std::cout<<"5 para desconectar un enrutador"<<std::endl;
                std::cout<<"6 para conocer el costo de enviar un paquete de un enrutador a otro"<<std::endl;
                std::cout<<"7 para conocer el mejor camino para enviar un paquete de un enrutador a otro"<<std::endl;
                std::cout<<"0 para salir"<<std::endl;
                std::cin>>opt2;

                switch(opt2){
                case 0: std::cout<<"Saliste de la red"<<std::endl;
                    break;

                case 1: std::cout<<"Matriz de adyacencia de la red"<<std::endl<<std::endl;
                    {
                        red.display_matrix();
                        std::cout<<std::endl;
                    }
                    break;
                case 2: std::cout<<"Tabla de enrutamiento de un enrutador"<<std::endl<<std::endl;
                    {
                        char pos;
                        std::string enr;
                        std::cout<<"Ingrese el nombre del enrutador: ";
                        std::cin>> pos;
                        std::cout<<std::endl;
                        enr = std::string(1,pos);
                        int va = pos - int('A');
                        if(va >= 0 && va < red.N_nodes )
                        {
                            std::cout<<"Tabla de enrutamiento: "<<std::endl;
                            red.objetos[enr].imprimir_enlaces_y_costos();
                        }
                        else {std::cout<<std::endl<<"El objeto no existe "<<std::endl;}
                        std::cout<<std::endl;

                    }
                    break;
                case 3: std::cout<<"Modificar el costo de un enlace"<<std::endl;
                    {
                        std::vector<std::string> new_cost;
                        std::string E1, E2, C;
                        char K1, K2;
                        std::cout<<"Ingrese nombre del primer enrutador: ";
                        std::cin>>K1;
                        std::cout<<"Ingrese nombre del segundo enrutador: ";
                        std::cin>>K2;
                        std::cout<<"Ingrese costo del enlace: ";
                        std::cin>>C;
                        std::cout<<std::endl;
                        int va1 = K1 - int('A');
                        int va2 = K2 - int('A');
                        if(va1 >= 0 && va1 < red.N_nodes && va2 >= 0 && va2 < red.N_nodes )
                        {
                            new_cost.push_back(std::string(1,K1));
                            new_cost.push_back(std::string(1,K2));
                            new_cost.push_back(C);
                            red.change_cost(red, new_cost);
                            red.crear_objetos(red.matrix, red.nodes);
                            std::cout<<std::endl;
                            std::cout<<"El enlace realizado tiene un costo nuevo de: "<<C<<std::endl;
                            std::cout<<std::endl;
                        }
                        else
                        {std::cout<<"Ingresaste parametros invalidos "<<std::endl;}
                        std::cout<<std::endl;

                    }
                    break;
                case 4: std::cout<<"Agregar un enrutador"<<std::endl;
                    {
                        std::vector<int> new_node;
                        for (int i = 0; i < red.N_nodes;i++)
                        {
                            int nd = 0;
                            std::cout<<"Ingrese el costo del enlace con el enrutador: "<< char(int('A') + i)<<std::endl;
                            std::cout<<"Ingrese -1 si no existe conexion: ";
                            std::cin>>nd;
                            new_node.push_back(nd);
                        }
                        std::cout<<std::endl;
                        new_node.push_back(0);
                        red.add_node(red,new_node);
                        red.crear_objetos(red.matrix, red.nodes);
                        std::cout<<"El enrutador creado fue "<< char(int('A') + red.N_nodes -1)<<std::endl;
                        std::cout<<std::endl;
                    }
                    break;
                case 5: std::cout<<"Desconectar un enrutador"<<std::endl;
                    {
                        char enr;
                        std::cout<<"Ingrese el nombre del enrutador: ";
                        std::cin>> enr;

                        red.disc_node(enr);
                        red.crear_objetos(red.matrix, red.nodes);
                        std::cout<<std::endl;
                    }
                    break;
                case 6: std::cout<<"Costo de enviar un paquete"<<std::endl;
                    {
                        char E1, E2;
                        std::cout<<"Ingrese nombre del primer enrutador: ";
                        std::cin>>E1;
                        std::cout<<"Ingrese nombre del segundo enrutador: ";
                        std::cin>>E2;
                        std::cout<<std::endl;
                        int va1 = E1 - int('A');
                        int va2 = E2 - int('A');

                        if(va1 >= 0 && va1 < red.N_nodes && va2 >= 0 && va2 < red.N_nodes )
                        {
                            std::cout<<"El costo de enviar un paquete del enrutador: " <<E1;
                            std::cout<<" al enrutador: "<<E2<<" es: ";
                            int cost = red.dijkstra(red.matrix, E1, E2);
                            if (E1 == E2)
                            {
                                std::cout<<0<<std::endl;
                            }

                            else if (cost ==-1)
                            {
                                std::cout<<"No hay camino disponible"<<std::endl;
                            }
                            else
                            {
                                std::cout<<cost<<std::endl;
                            }
                            std::cout<<std::endl;
                        }
                        else
                        {std::cout<<"Ingresaste parametros invalidos "<<std::endl;}
                        std::cout<<std::endl;
                    }
                    break;
                case 7: std::cout<<"Mejor camino entre dos enrutadores"<<std::endl;
                    {
                        char E1, E2;
                        std::cout<<"Ingrese nombre del primer enrutador: ";
                        std::cin>>E1;
                        std::cout<<"Ingrese nombre del segundo enrutador: ";
                        std::cin>>E2;
                        std::cout<<std::endl;
                        int va1 = E1 - int('A');
                        int va2 = E2 - int('A');

                        if(va1 >= 0 && va1 < red.N_nodes && va2 >= 0 && va2 < red.N_nodes )
                        {
                            std::vector<int> b_way = red.d_path(red.matrix, E1, E2);

                            std::cout<<"El mejor camino para enviar un paquete del enrutador: " <<E1;
                            std::cout<<" al enrutador: "<<E2<<" es: ";

                            if(E1 == E2)
                            {std::cout<<E1<<std::endl;}

                            else if (b_way[0] == 0 && int(b_way.size()) <= 1){
                                std::cout<<"No hay un camino disponible "<<std::endl;
                            }

                            else
                            {
                                for (int i = 0; i < int(b_way.size()); i++)
                                {
                                    std::cout<<char(b_way[i] + int('A'));

                                    if (i != int(b_way.size()) -1)
                                    {
                                        std::cout<<" -> ";
                                    }
                                }
                            }
                            std::cout<<std::endl;
                        }
                        else
                        {std::cout<<"Ingresaste parametros invalidos "<<std::endl;}

                        std::cout<<std::endl;
                    }
                    break;
                }
            }
        }
    }
    return 0;
}
