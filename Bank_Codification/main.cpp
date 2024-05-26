#include <iostream>
#include <fstream>
#include <string>
#include <archivos.h>

using namespace std;


int main() {

    int opt = 1;
    while(opt !=0){
        cout<<"Seleccione una de las opciones: "<<endl<<"1 para codificacion 1"<<endl<<"2 para codificacion 2"<<endl;
        cout<<"3 para decodificacion 1"<<endl<<"4 para decodificacion 2"<<endl<<"5 para opciones de banco"<<endl;
        cout<<"0 para salir"<<endl;
        cin>>opt;

        switch(opt){
            case 0: cout<<"Saliste exitosamente"<<endl;
                break;

            case 1: cout<<"Codificacion 1"<<endl;{
                    int seed;

                    cout<<"Ingrese la semilla de codificacion: ";
                    cin>>seed;

                    string nombreArchivo = "C:/QtProjects/Repositorio/Info-2/P3_Entrega/OutFiles/Test1.txt";
                    int numLineas = 0;
                    string* lineas = read_file(nombreArchivo, numLineas);

                    string binres = line2bin(lineas, numLineas);
                    delete[] lineas;

                    string archcod = codarch1(binres,seed);

                    cout<<binres<<endl;
                    write_file("bin1.dat","C:/QtProjects/Repositorio/Info-2/P3_Entrega/OutFiles",archcod);
                    cout<<"Codificacion Exitosa"<<endl;
                }
                break;
            case 2: cout<<"Codificacion 2"<<endl;{
                    int seed;

                    cout<<"Ingrese la semilla de codificacion: ";
                    cin>>seed;

                    string nombreArchivo = "C:/QtProjects/Repositorio/Info-2/P3_Entrega/OutFiles/Test2.txt";
                    int numLineas;
                    string* lineas = read_file(nombreArchivo, numLineas);

                    string binres = line2bin(lineas, numLineas);
                    delete[] lineas;

                    string archcod = codarch2(binres,seed);

                    write_file("bin2.dat","C:/QtProjects/Repositorio/Info-2/P3_Entrega/OutFiles",archcod);
                    cout<<"Codificacion Exitosa"<<endl;
                }
                break;
            case 3: cout<<"Decodificacion 1"<<endl;{
                    int seed;

                    cout<<"Ingrese la semilla de codificacion: ";
                    cin>>seed;

                    string nombreArchivo = "C:/QtProjects/Repositorio/Info-2/P3_Entrega/OutFiles/M1S17.dat";

                    string bin = readFileAsBinary(nombreArchivo);

                    string archdecod = decode1(bin,seed);

                    string decod = b2txt(archdecod);

                    write_file("M1S17.txt","C:/QtProjects/Repositorio/Info-2/P3_Entrega/OutFiles",decod);

                    cout<<"Decodificacion Exitosa"<<endl;
                }
                break;
            case 4: cout<<"Decodificacion 2"<<endl;{
                    int seed;

                    cout<<"Ingrese la semilla de codificacion: ";
                    cin>>seed;

                    string nombreArchivo = "C:/QtProjects/Repositorio/Info-2/P3_Entrega/OutFiles/M2S13.dat";

                    string bin = readFileAsBinary(nombreArchivo);

                    string archdecod = decode2(bin,seed);

                    string decod = b2txt(archdecod);

                    write_file("M2S13.txt","C:/QtProjects/Repositorio/Info-2/P3_Entrega/OutFiles",decod);

                    cout<<"Decodificacion Exitosa"<<endl;
                }
                break;
            case 5: cout<<"Opciones de Banco"<<endl;{
                    int optbk = 1;

                    /* Archivo de usarios a array*/
                    int seed = 4 ;
                    string nombreArchivo = "C:/QtProjects/Repositorio/Info-2/P3_Entrega/OutFiles/usuario.dat";
                    int numLineas;
                    string* lineas = read_file(nombreArchivo, numLineas);

                    string bin = lineas[0];
                    delete[] lineas;

                    string archdecod = decode1(bin,seed);

                    string decod = b2txt(archdecod);

                    string* arr_dat;
                    int nl;

                    str2arr(decod,arr_dat,nl);

                    while(optbk !=0){
                        cout<<"Seleccione una de las opciones de banco: "<<endl<<"1 para opciones de administrador"<<endl;
                        cout<<"2 para opciones de usuario"<<endl;
                        cout<<"0 para salir"<<endl;
                        cin>>optbk;

                        switch(optbk){
                            case 1: cout<<"Opciones de Administrador"<<endl;{
                                string usr,pwd;
                                cout<<"Ingrese el usuario: ";
                                cin>>usr;
                                cout<<"Ingrese la contrasena: ";
                                cin>>pwd;
                                bool val = verifadmin(usr,pwd);
                                while (val){
                                    int optadm;
                                    cout<<"Seleccione una de las opciones de administrador: "<<endl<<"1 para agregar usuarios"<<endl;
                                    cout<<"0 para salir"<<endl;
                                    cin>>optadm;
                                    switch (optadm) {
                                        case 1: cout<<"Creacion de usuario"<<endl;{

                                                string usr,pwd,saldo;
                                                cout<<"Ingrese el usuario: ";
                                                cin>>usr;
                                                cout<<"Ingrese la contrasena: ";
                                                cin>>pwd;
                                                cout<<"Ingrese el saldo: ";
                                                cin>>saldo;

                                                add_usr(usr,pwd, saldo, arr_dat, nl);
                                            }
                                            break;
                                        case 0: cout<<"Saliste de las opciones de administrador"<<endl;
                                            val = false;
                                            break;
                                            /*Codificar de nuevo la información luego de salir del cajero*/
                                            string binbank = line2bin(arr_dat, nl);
                                            string archbank = codarch1(binbank,seed);
                                            write_file("usuario.dat","C:/QtProjects/Repositorio/Info-2/P3_Entrega/OutFiles",archbank);
                                        }
                                    }
                                }
                                break;
                            case 2: cout<<"Opciones de Usuario"<<endl;{
                                //Función de opciones de administrador
                                    string usr,pwd;
                                    cout<<"Ingrese el usuario: ";
                                    cin>>usr;
                                    cout<<"Ingrese la contrasena: ";
                                    cin>>pwd;
                                    int k = verif_usr(usr, pwd, arr_dat, nl); //Verificar usuario
                                    if (k >=0){cout<<"Ingreso exitoso"<<endl;}

                                    while (k >= 0){                                       
                                        int optusr;
                                        cout<<"Seleccione una de usuario: "<<endl<<"1 para consultar saldo"<<endl;
                                        cout<<"2 para retirar"<<endl<<"0 para salir"<<endl;
                                        cin>>optusr;
                                        switch (optusr) {
                                        case 1: cout<<"Consulta de Saldo"<<endl;{
                                                string s_act = cons_saldo(k,arr_dat);
                                                arr_dat[k+2] = s_act;
                                                cout<<"Saldo actual: "<<s_act<<endl;
                                            }
                                            break;
                                        case 2: cout<<"Retiros"<<endl;{
                                                string s_act = retiro(k,arr_dat);
                                                arr_dat[k+2] = s_act;
                                                cout<<"Saldo actual: "<<s_act<<endl;
                                            }
                                            break;
                                        case 0: cout<<"Saliste de las opciones de usuario"<<endl;
                                            k = -1;
                                            break;
                                            /*Codificar de nuevo la información luego de salir del cajero*/
                                            string binbank = line2bin(arr_dat, nl);
                                            string archbank = codarch1(binbank,seed);
                                            write_file("usuario.dat","C:/QtProjects/Repositorio/Info-2/P3_Entrega/OutFiles",archbank);
                                        }
                                    }
                                }
                                break;
                            case 0: cout<<"Saliste de las opciones de Banco"<<endl;

                                /*Codificar de nuevo la información luego de salir del cajero*/
                                string binbank = line2bin(arr_dat, nl);
                                string archbank = codarch1(binbank,seed);
                                write_file("usuario.dat","C:/QtProjects/Repositorio/Info-2/P3_Entrega/OutFiles",archbank);

                                delete[] arr_dat; //Libera el arreglo dinámico del usuario
                                break;
                        }
                    }
                }
                break;
        }
    }

    return 0;
}
