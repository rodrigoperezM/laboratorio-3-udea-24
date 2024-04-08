#ifndef CODIGO_H
#define CODIGO_H
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Función para codificar el mensaje
string codificar(const string& mensaje, const string& codigo) {
    string mje_cod;
    for (size_t i = 0; i < mensaje.length(); ++i) {
        char caracter = mensaje[i];
        size_t pos = codigo.find(caracter);
        if (pos != string::npos) {
            if (pos + 1 < codigo.length()) {
                mje_cod += codigo[pos + 1];
            } else {
                mje_cod += caracter; // Mantener caracteres no codificados
            }
        } else {
            mje_cod += caracter; // Mantener caracteres no codificados
        }
    }
    return mje_cod;
}

// Función para decodificar el mensaje
string decodificar(const string& mensajeCodificado, const string& codigo) {
    string mje_deco;
    for (size_t i = 0; i < mensajeCodificado.length(); ++i) {
        char caracter = mensajeCodificado[i];
        bool encontrado = false;
        for (size_t j = 0; j < codigo.length(); ++j) {
            if (codigo[j] == caracter) {
                if (j - 1 >= 0) {
                    mje_deco += codigo[j - 1];
                } else {
                    mje_deco += caracter;
                }
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            mje_deco += caracter; // Mantener caracteres no decodificados
        }
    }
    return mje_deco;
}

// Función para leer un archivo
string leerArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo.c_str()); // Convertir el nombre del archivo a const char*
    string contenido;
    if (archivo.is_open()) {
        getline(archivo, contenido); // Leer el contenido del archivo y guardarlo en 'contenido'
        archivo.close(); // Cerrar el archivo
    } else {
        cout << "No se pudo abrir el archivo: " << nombreArchivo << endl;
    }
    return contenido; // Retornar el contenido del archivo
}


// Función para escribir en un archivo
bool escribirArchivo(const string& nombreArchivo, const string& contenido) {
    ofstream archivo(nombreArchivo.c_str());
    //string contenido;);
    if (archivo.is_open()) {
        archivo << contenido;
        archivo.close();
        return true;
    }
    return false;
}
#endif /* CODIGO_H */
