#include<iostream>
#include<fstream>
#include<string>
#include<archivos.h>
#include<bitset>

using namespace std;




void create_file(string name, string path){
    fstream file;
    file.open(path+"/"+name,ios::out);
    file.close();
}

void write_file(string name, string path, string info){
    fstream file;
    file.open(path+"/"+name, ios::out);

    if (!file) {
        cerr << "No se pudo abrir el archivo." << endl;
        return;
    }

    file<<info;
    file.close();
}

void append_file(string name, string path, string info){
    fstream file;
    file.open(path+"/"+name, ios::app);
    file<<info<<endl;
    file.close();

}

// Función para leer un archivo de texto y almacenar sus líneas en un array dinámico de tipo string
string* read_file(const string& nombreArchivo, int& numLineas) {

    ifstream archivo(nombreArchivo);

    if (!archivo) {
        cerr << "No se pudo abrir el archivo." << endl;
        return nullptr;
    }

    string* lineas = nullptr; // Puntero para almacenar las líneas
    numLineas = 0; // Contador de líneas
    string linea;

    //Contar las líneas
    while (getline(archivo, linea)) {
        numLineas++;
    }

    archivo.close();

    // Almacenarlas en el array dinámico
    archivo.open(nombreArchivo);

    if (!archivo) {
        cerr << "No se pudo abrir el archivo." << endl;
        return nullptr;
    }

    lineas = new string[numLineas]; // Crea un array dinámico de strings con el tamaño necesario

    int i = 0;
    while (getline(archivo, linea)) {
        lineas[i] = linea; // Almacena cada línea en el array dinámico
        i++;
    }

    archivo.close(); // Cierra el archivo nuevamente

    return lineas;
}

string char2bin(char c) {
    return bitset<8>(c).to_string(); //Convierte de caracter a un byte binario usando bitset
}

// Función para procesar y convertir todas las líneas a binario
string line2bin(string* lineas, int numLineas) {

    string resultado;
    for (int i = 0; i < numLineas; i++) { //Itera por todas las lineas
        string lineaActual = lineas[i];
        for (char c : lineaActual) {
            resultado += char2bin(c); // Convierte cada carácter a binario y agrega al resultado
        }
        resultado += string("00001010"); //Añade un salto de linea cada que acaba de leerla
    }

    return resultado;
}

string codarch1(const string& archbin, int n) {

    string archcod = archbin;

    int lenbin = int(archbin.length());

    for (int i = 0; i < n && i < lenbin; i++) {
        archcod[i] = (archbin[i] == '1') ? '0' : '1'; // Cambiar el primer bloque (invierte 1s y 0s)
    }

    // Aplicar las reglas a los grupos siguientes
    for (int i = n; i < lenbin; i+=n) {
        int unos = 0, ceros = 0;

        // Contar unos y ceros en el grupo anterior
        for (int j = i - n; j < i; j++) {
            if (archbin[j] == '1') unos++;
            else ceros++;
        }

        // Aplicar las reglas según la cantidad de unos y ceros
        for(int k = i; k < i+ n; k++){
            if (unos == ceros) {
                archcod[k] = (archbin[k] == '1') ? '0' : '1';

            } else if (ceros > unos) {
                if ((k+1) % 2 == 0) {
                    archcod[k] = (archbin[k] == '1') ? '0' : '1';
                }
            } else { // unos > ceros
                if ((k+1) % 3 == 0) {
                    archcod[k] = (archbin[k] == '1') ? '0' : '1';
                }
            }
        }
    }

    return archcod;
}

void rollCircular(string& str) {
    char temp = str[str.length() - 1];
    for (int i = str.length() - 1; i > 0; i--) {
        str[i] = str[i - 1];
    }
    str[0] = temp;
}

// Función para separar un string en elementos de tamaño n y aplicar roll a cada elemento
string codarch2(const string cadena, int n) {

    int len = int(cadena.length());
    string resultado;

    for (int i = 0; i < len; i += n) {
        string elemento = cadena.substr(i,n); // Obtiene un elemento de tamaño n
        rollCircular(elemento); // Aplica un desplazamiento circular de una unidad
        resultado += elemento; // Agrega el elemento al resultado
    }

    return resultado;
}

string decode1(const string& archbin, int n){

    string archcod = archbin;

    int lenbin = int(archbin.length());

    for (int i = 0; i < n && i < lenbin; i++) {
        archcod[i] = (archbin[i] == '1') ? '0' : '1'; // Cambiar el primer bloque (invierte 1s y 0s)
    }

    // Aplicar las reglas a los grupos siguientes
    for (int i = n; i < lenbin; i+=n) {
        int unos = 0, ceros = 0;

        // Contar unos y ceros en el grupo anterior
        for (int j = i - n; j < i; j++) {
            if (archcod[j] == '1') unos++; //Cuenta los 1s y 0s del grupo anterior decodificado
            else ceros++;                   //Debido a que con esa parte se hizo la codificación
        }

        // Aplicar las reglas según la cantidad de unos y ceros
        for(int k = i; k < i+ n; k++){
            if (unos == ceros) {
                archcod[k] = (archbin[k] == '1') ? '0' : '1';

            } else if (ceros > unos) {
                if ((k+1) % 2 == 0) {
                    archcod[k] = (archbin[k] == '0') ? '1' : '0';
                }
            } else { // unos > ceros
                if ((k+1) % 3 == 0) {
                    archcod[k] = (archbin[k] == '0') ? '1' : '0';
                }
            }
        }
    }

    return archcod;
}

string bin2Char(const string& byteBinario) {
    bitset<8> bits(byteBinario); // Convierte el byte binario a bits
    unsigned long valor = bits.to_ulong(); // Convierte los bits a un valor entero
    return string(1, static_cast<char>(valor));
}

string b2txt(const string& cad){

    int lenstr = int(cad.length());

    string result;

    for(int i = 0; i < lenstr; i+=8){
        result += bin2Char(cad.substr(i,8));
    }

    return result;
}

void rollCircularinv(string& str) {
    char temp = str[0];
    int longitud = str.length();
    for (int i = 0; i < longitud - 1; i++) {
        str[i] = str[i + 1];
    }
    str[longitud - 1] = temp;
}

string decode2(const string& archbin, int n){
    int len = int(archbin.length());
    string resultado;

    for (int i = 0; i < len; i += n) {
        string elemento = archbin.substr(i,n); // Obtiene un elemento de tamaño n
        rollCircularinv(elemento); // Aplica un desplazamiento circular de una unidad
        resultado += elemento; // Agrega el elemento al resultado
    }

    return resultado;
}

string quitarCaracteresVacios(const string& entrada) {
    string resultado;
    for (char c : entrada) {
        if (c != char(10)) {
            resultado += c;
        }
    }
    return resultado;
}

bool verifadmin(const string &user, const string &pwd){

    int seed = 4;
    string info = user + ":" + pwd;
    string nombreArchivo = "C:/QtProjects/Repositorio/Info-2/P3_Entrega/OutFiles/sudo.dat";

    /* Verificar el contenido del archivo.dat*/
    int numLineas;
    string* adm = read_file(nombreArchivo, numLineas);

    string binadm = adm[0];
    delete[] adm;

    string archdecod = decode1(binadm,seed);

    string admdecod = b2txt(archdecod);

    admdecod = quitarCaracteresVacios(admdecod);

    return info == admdecod;
}


void str2arr(const string& texto, string*& lineas, int& numLineas) {
    // Contar la cantidad de saltos de línea para determinar el tamaño del arreglo
    numLineas = 0;
    for (char c : texto) {
        if (c == char(10)) {
            numLineas++;
        }
    }

    // Inicializar el arreglo dinámico
    lineas = new string[numLineas + 20]; // Si hacen falta más usuarios se puede añadir más memoria aquí.(Max 5 usuarios por operación)

    size_t inicio = 0;
    size_t fin = 0;
    int i = 0;

    // Dividir el string en líneas y almacenarlas en el arreglo
    while ((fin = texto.find(char(10), inicio)) != string::npos) {
        lineas[i] = quitarCaracteresVacios(texto.substr(inicio, fin - inicio));
        inicio = fin + 1;
        i++;
    }

    // Agregar la última línea
    lineas[i] = texto.substr(inicio);
}

int verif_usr(const string &user, const string &pwd, string* arr_dat, const int nl){
    for(int i =  0; i < nl ; i+=4){
        if(user == arr_dat[i]){
            if(pwd == arr_dat[i+1]){
                return i;
            }
        }
    }
    return -1;
}

string cons_saldo(const int k, string* arr_dat){
    int sald = stoi(arr_dat[k+2]);
    sald-=1000;
    string sald_act = to_string(sald);
    return sald_act;
}


string retiro(const int k, string* arr_dat){
    int monto;
    cout<<"Ingrese el monto a retirar: ";
    cin>>monto;

    int sald = stoi(arr_dat[k+2]);

    if (sald >= monto){
        sald-=monto;
        cout<<"Retiro realizado"<<endl;
    }
    else{
        cout<<"No tiene fondos suficientes"<<endl;
    }
    string sald_act = to_string(sald);

    return sald_act;
}

void add_usr(const string &user, const string &pwd, const string &saldo, string* arr_dat, int& nl){

    arr_dat[nl+1] = user;
    arr_dat[nl+2] = pwd;
    arr_dat[nl+3] = saldo;

    nl+=4;

}


string b2tt(const string& cad){

    int lenstr = int(cad.length());

    string result;

    for(int i = 0; i < lenstr; i+=8){
        result += bin2Char(cad.substr(i,8));
    }

    return result;
}

string readFileAsBinary(const string& filePath) {
    ifstream inputFile(filePath, ios::binary);
    if (!inputFile) {
        cerr << "Error al abrir el archivo: " << filePath << endl;
        return "";
    }

    string binaryData;
    char c;
    while (inputFile.get(c)) {
        // Convertir el carácter a su representación binaria de 8 bits
        binaryData += bitset<8>(c).to_string();
    }

    return binaryData;
}
