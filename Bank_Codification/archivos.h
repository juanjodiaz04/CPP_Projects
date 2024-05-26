#ifndef ARCHIVOS_H
#define ARCHIVOS_H

using namespace std;

#include<fstream>
#include<string>

void create_file(string name, string path);
void write_file(string name, string path, string info);
void append_file(string name, string path, string info);
string* read_file(const string& nombreArchivo, int& numLineas);
string char2bin(char c);
string line2bin(string* lineas, int numLineas);
string codarch1(const string& archbin, int n);
void rollCircular(string& str);
string codarch2(string cadena, int n);
string decode1(const string& archbin, int n);
string bin2Char(const string& byteBinario);
string b2txt(const string& cad);
void rollCircularinv(string& str);
string decode2(const string& archbin, int n);
string quitarCaracteresVacios(const string& entrada);
bool verifadmin(const string &user, const string &pwd);
void str2arr(const string& texto, string*& lineas, int& numLineas);
int verif_usr(const string &user, const string &pwd, string* arr_dat, const int nl);
string cons_saldo(const int k, string* arr_dat);
string retiro(const int k, string* arr_dat);
void add_usr(const string &user, const string &pwd, const string &saldo, string* arr_dat, int& nl);
string readFileAsBinary(const string& filePath);

#endif // ARCHIVOS_H
