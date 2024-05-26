#include "net.h"

net::net()
{
    name = "";
    folder = "";
    path = "";
    is_named = false;
    separator = ' ';
}

net::net(std::string name, std::string path, std::string folder)
{
    set_net_name(name);
    set_net_folder(folder);
    set_net_path(path);
    separator = ' ';
}

void net::set_net_name(std::string name)
{
    this->name = name;
    is_named = true;
}

void net::set_net_path(std::string path)
{
    this->path = path;
}

void net::set_net_folder(std::string folder)
{
    this->folder = folder;
}

void net::set_net_binary(bool binary)
{
    is_binary = binary;
}

bool net::is_read_available()
{
    std::fstream file;
    bool correct;
    file.open(concat_net_name(),std::ios::app);
    correct = file.is_open();
    file.close();
    return correct;
}

std::vector<std::string> net::get_net_rows()
{
    std::vector<std::string> total_info;
    std::string info;
    std::fstream file;

    if(!is_binary) file.open(concat_net_name(), std::ios::in);
    else file.open(concat_net_name(), std::ios::in | std::ios::binary);

    if(file.is_open()){
        while(!file.eof()){
            std::getline(file,info);
            total_info.push_back(info);
        }
    }
    else throw 0;

    return total_info;
}

void net::set_net_separator(char separator)
{
    this->separator = separator;
}

std::vector<std::string> net::get_net_columns()
{
    std::vector<std::string> rows, columns, final;
    unsigned int size;

    try{
        rows = get_net_rows();

        for(unsigned int i = 0; i < rows.size(); i++){

            columns = split(rows[i]);
            size = final.size();

            for(unsigned int j = 0; j < columns.size() && size == 0; j++){
                final.push_back("");
            }
            for(unsigned int j = 0; j < columns.size(); j++){
                final[j] += columns[j] + row_separator;
            }
        }
    }
    catch(int){
        throw 0;
    }

    return final;
}


std::string net::concat_net_name()
{
    std::string net_name = "";

    if(is_named && path == "" && folder == "") net_name = name;
    else if(is_named && path == "") net_name = folder + "/" + name;
    else if(is_named && folder == "") net_name = path + "/" + name;
    else net_name = path + "/" + folder + "/" + name;

    create_folder();

    return net_name;
}

std::vector<std::string> net::split(std::string row)
{
    int pos = 1;
    std::vector<std::string> splitted;

    for(unsigned int i=0;i<row.length() && pos>=0;i=pos+1){
        pos = row.find(separator,i);
        splitted.push_back(row.substr(i,pos-i));
    }

    return splitted;
}

void net::create_folder()
{
    mkdir(concat_folder_name().c_str());
}

std::string net::concat_folder_name()
{
    std::string folder_name;

    if(path == "" && folder != "") folder_name = folder;
    else if(folder != "") folder_name = path + '/' +folder;

    return folder_name;
}

std::vector<std::string> net::get_nodes(const std::string &str1, const std::string &str2)
{
    std::string strCombinado = str1 + str2;

    // Utilizar un conjunto para almacenar letras únicas
    std::set<char> letrasSet;

    // Recorrer el string combinado y agregar letras al conjunto
    for (char letra : strCombinado) {
        if (std::isalpha(letra)) { // Verificar si es una letra
            letrasSet.insert(letra);
        }
    }

    // Convertir el conjunto en un vector de strings
    std::vector<std::string> letrasUnicasVector;
    for (char letra : letrasSet) {
        letrasUnicasVector.push_back(std::string(1, letra)); // Convierte char a string
    }

    return letrasUnicasVector;
}

void net::create_matrix(int size)
{
    matrix.assign(size, std::vector<int>(size, -1));

    for (int i = 0; i < size; i++) { //Hace los valores de la diagonal 0
        matrix[i][i] = 0;
    }
}

void net::display_matrix()
{
    for (int i = 0; i < int(matrix.size()); i++) {
        for (int j = 0; j < int(matrix[i].size()); j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void net::set_n_nodes(int size)
{
    this->N_nodes = size;
}

void net::node_conection(std::vector<std::string> str_in)
{
    int pc_1 = str_in[0][0] - int('A');
    int pc_2 = str_in[1][0] - int('A');
    int cost = std::stoi(str_in[2]);

    matrix[pc_1][pc_2] = cost;
    matrix[pc_2][pc_1] = cost;

}

void net::add_node_col(const std::vector<int> &col)
{
    for (size_t i = 0; i < matrix.size(); i++) {
        if (i < col.size()) {
            matrix[i].push_back(col[i]);
        } else {
            matrix[i].push_back(-1); // Rellenar con ceros si la nueva columna es más corta
        }
    }
}

void net::add_node_row(const std::vector<int> &row)
{
    matrix.push_back(row);
}

void net::del_node_col(int col)
{
    if (col >= 0 && !matrix.empty() && col < int(matrix[0].size())) {
        for (int i = 0; i < int(matrix.size()); i++) {
            matrix[i].erase(matrix[i].begin() + col);
        }
    } else {
        std::cout << "Columna no válida." << std::endl;
    }
}

void net::del_node_row(int row)
{
    if (row >= 0 && row < int(matrix.size())) {
        matrix.erase(matrix.begin() + row);
    } else {
        std::cout << "Fila no válida." << std::endl;
    }

}

int net::dijkstra(const std::vector<std::vector<int> > &matr, char Origen, char Destino)
{
    int orig = Origen - int('A');
    int dest = Destino - int('A');
    int numNodos = N_nodes;

    std::vector<int> distancias(numNodos, std::numeric_limits<int>::max());
    std::vector<bool> visitado(numNodos, false);

    if (matrix[orig][orig] == -1 || matrix[dest][dest]== -1)
    {
        return -1;
    }

    distancias[orig] = 0;

    for (int i = 0; i < numNodos - 1; ++i) {
        int nodoMinimo = -1;
        for (int nodo = 0; nodo < numNodos; ++nodo) {
            if (!visitado[nodo] && (nodoMinimo == -1 || distancias[nodo] < distancias[nodoMinimo])) {
                nodoMinimo = nodo;
            }
        }

        visitado[nodoMinimo] = true;

        for (int nodo = 0; nodo < numNodos; ++nodo) {
            if (!visitado[nodo] && matr[nodoMinimo][nodo] != -1) {
                int nuevaDistancia = distancias[nodoMinimo] + matr[nodoMinimo][nodo];
                if (nuevaDistancia < distancias[nodo]) {
                    distancias[nodo] = nuevaDistancia;
                }
            }
        }
    }

    if (distancias[dest] == std::numeric_limits<int>::max()) {
        return -1; // No hay ruta al nodo de destino
    } else {
        return distancias[dest];
    }
}

std::vector<int> net::d_path(const std::vector<std::vector<int> > &matr, char Origen, char Destino)
{
    int orig = Origen - int('A');
    int dest = Destino - int('A');
    int numNodos = N_nodes;

    std::vector<int> distancias(numNodos, std::numeric_limits<int>::max());
    std::vector<int> padre(numNodos, -1); // Vector que almacena el nodo previo en el camino
    std::vector<bool> visitado(numNodos, false);


    if (matrix[orig][orig] == -1 || matrix[dest][dest]== -1)
    {
        std::vector<int> camino;
        camino.push_back(orig);
        return camino;
    }


    distancias[orig] = 0;

    for (int i = 0; i < numNodos - 1; ++i) {
        int nodoMinimo = -1;
        for (int nodo = 0; nodo < numNodos; ++nodo) {
            if (!visitado[nodo] && (nodoMinimo == -1 || distancias[nodo] < distancias[nodoMinimo])) {
                nodoMinimo = nodo;
            }
        }

        visitado[nodoMinimo] = true;

        for (int nodo = 0; nodo < numNodos; ++nodo) {
            if (!visitado[nodo] && matr[nodoMinimo][nodo] != -1) {
                int nuevaDistancia = distancias[nodoMinimo] + matr[nodoMinimo][nodo];
                if (nuevaDistancia < distancias[nodo]) {
                    distancias[nodo] = nuevaDistancia;
                    padre[nodo] = nodoMinimo; // Almacenar el nodo previo en el camino
                }
            }
        }
    }

    if (distancias[dest] == std::numeric_limits<int>::max()) {
        return std::vector<int>(); // No hay ruta al nodo de destino
    } else {
        std::vector<int> camino;
        int nodoActual = dest;
        while (nodoActual != -1) {
            camino.push_back(nodoActual);
            nodoActual = padre[nodoActual];
        }
        std::reverse(camino.begin(), camino.end()); // Invertir el camino
        return camino;
    }

}


void net::net_connect(net &red)
{
        std::string line;

        for(int i = 0; i < int(red.get_net_rows().size()) ; i++)
        {
            line = red.get_net_rows()[i];
        red.node_conection(split(line));
        }
}

void net::add_node(net &red, const std::vector<int> &connection)
{
    red.add_node_col(connection);
    red.add_node_row(connection);
    this->N_nodes = N_nodes + 1;

    char n_l = int('A') + (N_nodes - 1);

    std::string let = std::string(1, n_l);

    nodes.push_back(let);
    /*
    objetos[let]= node(let);
    for (auto cost: connection){
        objetos[let].añadir_enlace(let,cost);
    }
    */
}

void net::del_node(net &red, char node)
{
    int var = node - int('A');

    if (var >= 0 && var < int(nodes.size())) {

        std::string nombre = std::string(1,node);
        red.del_node_col(var);
        red.del_node_row(var);
        nodes.erase(nodes.begin() + var);

        objetos[nombre].borrar_enlace(nombre);
        objetos.erase(nombre);

        this->N_nodes = N_nodes - 1;

    }
    else {std::cout<<"Ingresaste un valor invalido"<<std::endl;}
}



void net::change_cost(net &red, std::vector<std::string> line)
{   
    red.node_conection(line);
}

void net::set_nodes(net &red)
{
    this->nodes = get_nodes(red.get_net_columns()[0],red.get_net_columns()[1]);
}

void net::disc_node(char node)
{
    int var = node - int('A');

    if (var >= 0 && var < int(nodes.size())) {

        for(int i = 0; i < int(nodes.size()); i++)
        {
            matrix[i][var] = -1;
            matrix[var][i] = -1;
        }
        std::cout<<std::endl;
        std::cout<<"Se ha desconectado el enrutador: " <<node<<std::endl;

    }
    else {std::cout<<"El objeto no existe"<<std::endl;}
}


void net::crear_objetos(std::vector<std::vector<int> > &matriz, std::vector<std::string> &nodos)
{
    std::vector<std::string>::iterator it;
    std::vector<std::string>::iterator it1;
    it1=nodos.begin();

    for (const auto& colum : matriz){
        std::vector<int> vect_aux = colum;
        it = nodos.begin();
        objetos[*it1]= node(*it1);
        for (auto elemento :vect_aux){
            if (elemento == 0 || elemento == -1 ){

            }
            else{
                objetos[*it1].añadir_enlace(*it,elemento);
            }
            it++;
        }
        it1++;
    }
}

void net::aleatory(int numNodes, double probability){

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(0.0, 1.0);
    std::uniform_int_distribution<int> costDis(0, 100);

    for (int u = 0; u < numNodes; u++) {
        std::string nodo= std::string(1,char(65+u));
        nodes.push_back(nodo);

        for (int v = u + 1; v < numNodes; v++) {
            double Prob = dis(gen);
            if (Prob<probability){
                if (u != v) {
                    int cost = costDis(gen);

                    matrix[v][u]= cost;
                    matrix[u][v]= cost;
                }
                else{
                    matrix[v][u]= 0;
                    matrix[u][v]= 0;

                }
            }
            else{
                matrix[v][u]= -1;
                matrix[u][v]= -1;
            }
        }
    }
}
