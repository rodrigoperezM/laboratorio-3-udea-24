#include <iostream>/*Estas líneas incluyen las bibliotecas necesarias para manejar entrada/salida, trabajar con archivos, usar algoritmos estándar de C++, vectores y cadenas, así como el archivo de encabezado Pelicula.h que contiene las definiciones de clase necesarias.*/
#include <fstream>
#include <algorithm>
#include <sstream>
#include "Pelicula.h"

using namespace std;

int main() {
    const int MAX_PELICULAS = 100; // Tamaño máximo del arreglo de películas
    Pelicula peliculas[MAX_PELICULAS]; // Arreglo de películas
    int numPeliculas = 0; // Número actual de películas en el arreglo

    // Opción 1: Ingresar nueva película
    string nombre, director, genero;
    int lanzamiento, duracionHoras, duracionMinutos, duracionSegundos;
    cout << "Ingrese el nombre de la pelicula: ";
    cin >> nombre;
    cout << "Ingrese el director de la pelicula: ";
    cin >> director;
    cout << "Ingrese el año de lanzamiento de la pelicula: ";
    cin >> lanzamiento;
    cout << "Ingrese el genero de la película: ";
    cin >> genero;
    cout << "Ingrese la duracion de la pelicula en horas, minutos y segundos separados por espacios: ";
    cin >> duracionHoras >> duracionMinutos >> duracionSegundos;
    Duracion duracion(duracionHoras, duracionMinutos, duracionSegundos); // Crear un objeto Duracion
    Pelicula nuevaPelicula(nombre, director, lanzamiento, genero, duracion); // Usar el objeto Duracion creado
    peliculas[numPeliculas++] = nuevaPelicula; // Agregar la película al arreglo y aumentar el contador

    // Opción 2: Eliminar película
    string nombreEliminar;
    cout << "Ingrese el nombre de la pelicula a eliminar: ";
    cin >> nombreEliminar;
    int indiceEliminar = -1;
    for (int i = 0; i < numPeliculas; ++i) {
        if (peliculas[i].getNombre() == nombreEliminar) {
            indiceEliminar = i;
            break;
        }
    }
    if (indiceEliminar != -1) {
        for (int i = indiceEliminar; i < numPeliculas - 1; ++i) {
            peliculas[i] = peliculas[i + 1];
        }
        numPeliculas--;
        cout << "Pelicula eliminada exitosamente." << endl;
    } else {
        cout << "No se encontro ninguna película con ese nombre." << endl;
    }

    // Opción 3: Imprimir lista de películas
    cout << "Lista de peliculas:" << endl;
    for (int i = 0; i < numPeliculas; ++i) {
        cout << peliculas[i].getNombre() << " - " << peliculas[i].getDirector() << " - " << peliculas[i].getLanzamiento() << " - " << peliculas[i].getGenero() << " - Duración: "
             << peliculas[i].getDuracion().getHoras() << "h " << peliculas[i].getDuracion().getMinutos() << "m " << peliculas[i].getDuracion().getSegundos() << "s" << endl;
    }

    // Opción 4: Guardar información en archivo
    ofstream archivo("peliculas.txt");
    if (archivo.is_open()) {
        for (int i = 0; i < numPeliculas; ++i) {
            archivo << peliculas[i].getNombre() << ";" << peliculas[i].getDirector() << ";" << peliculas[i].getLanzamiento() << ";" << peliculas[i].getGenero() << ";"
                    << peliculas[i].getDuracion().getHoras() << ":" << peliculas[i].getDuracion().getMinutos() << ":" << peliculas[i].getDuracion().getSegundos() << endl;
        }
        cout << "Información de peliculas guardada en el archivo correctamente." << endl;
    } else {
        cerr << "No se pudo abrir el archivo para guardar la información." << endl;
    }

    // Opción 5: Cargar información desde archivo
    ifstream archivoCarga("peliculas.txt");
    if (archivoCarga.is_open()) {
        numPeliculas = 0; // Reiniciar el contador de películas
        string linea;
        while (getline(archivoCarga, linea) && numPeliculas < MAX_PELICULAS) {
            stringstream ss(linea);
            string nombre, director, genero, duracionStr;
            int lanzamiento, horas, minutos, segundos;
            getline(ss, nombre, ';');
            getline(ss, director, ';');
            ss >> lanzamiento;
            getline(ss, genero, ';');
            getline(ss, duracionStr, ';');
            sscanf(duracionStr.c_str(), "%d:%d:%d", &horas, &minutos, &segundos);
            Duracion duracionCargada(horas, minutos, segundos); // Crear un objeto Duracion
            Pelicula peliculaCargada(nombre, director, lanzamiento, genero, duracionCargada); // Usar el objeto Duracion creado
            peliculas[numPeliculas++] = peliculaCargada; // Agregar la película al arreglo y aumentar el contador
        }
        cout << "Información de peliculas cargada desde el archivo correctamente." << endl;
    } else {
        cerr << "No se pudo abrir el archivo para cargar la información." << endl;
    }

    return 0;
}
