#include <iostream> /*Estas líneas incluyen las bibliotecas necesarias para manejar entrada/salida, trabajar con archivos, usar algoritmos estándar de C++, vectores y cadenas, así como el archivo de encabezado Pelicula.h que contiene las definiciones de clase necesarias.*/
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>
#include "Pelicula.h"

using namespace std;

struct NombreIgual {
    string nombre;
    NombreIgual(const string& nombre) : nombre(nombre) {}
    bool operator()(const Pelicula& pelicula) const {
        return pelicula.getNombre() == nombre;
    }
};

int main() {
    vector<Pelicula> peliculas;//Declara un vector llamado peliculas que almacenará objetos de la clase Pelicula.

    // Opción 1: Ingresar nueva película
    string nombre, director, genero;
    int lanzamiento, duracionHoras, duracionMinutos, duracionSegundos;
    cout << "Ingrese el nombre de la pelicula: ";
    cin >> nombre;
    cout << "Ingrese el director de la pelicula: ";
    cin >> director;
    cout << "Ingrese el año de lanzamiento de la pelicula: ";
    cin >> lanzamiento;
    cout << "Ingrese el género de la pelicula: ";
    cin >> genero;
    cout << "Ingrese la duracion de la pelicula en horas, minutos y segundos separados por espacios: ";
    cin >> duracionHoras >> duracionMinutos >> duracionSegundos;
    Pelicula nuevaPelicula(nombre, director, lanzamiento, genero, Duracion(duracionHoras, duracionMinutos, duracionSegundos));
    peliculas.push_back(nuevaPelicula);

    // Opción 2: Eliminar película
    string nombreEliminar;
    cout << "Ingrese el nombre de la pelicula a eliminar: ";
    cin >> nombreEliminar;
    vector<Pelicula>::iterator it = find_if(peliculas.begin(), peliculas.end(), NombreIgual(nombreEliminar));
    if (it != peliculas.end()) {
        peliculas.erase(it);
        cout << "Película eliminada exitosamente." << endl;
    } else {
        cout << "No se encontro ninguna pelicula con ese nombre." << endl;
    }

    // Opción 3: Imprimir lista de películas
    cout << "Lista de peliculas:" << endl;
    for (vector<Pelicula>::const_iterator pelicula = peliculas.begin(); pelicula != peliculas.end(); ++pelicula) {
        cout << pelicula->getNombre() << " - " << pelicula->getDirector() << " - " << pelicula->getLanzamiento() << " - " << pelicula->getGenero() << " - Duración: "
             << pelicula->getDuracion().getHoras() << "h " << pelicula->getDuracion().getMinutos() << "m " << pelicula->getDuracion().getSegundos() << "s" << endl;
    }

    // Opción 4: Guardar información en archivo
    ofstream archivo("peliculas.txt");
    if (archivo.is_open()) {
        for (vector<Pelicula>::const_iterator pelicula = peliculas.begin(); pelicula != peliculas.end(); ++pelicula) {
            archivo << pelicula->getNombre() << ";" << pelicula->getDirector() << ";" << pelicula->getLanzamiento() << ";" << pelicula->getGenero() << ";"
                    << pelicula->getDuracion().getHoras() << ":" << pelicula->getDuracion().getMinutos() << ":" << pelicula->getDuracion().getSegundos() << endl;
        }
        cout << "Informacion de peliculas guardada en el archivo correctamente." << endl;
    } else {
        cerr << "No se pudo abrir el archivo para guardar la informacion." << endl;
    }

    // Opción 5: Cargar información desde archivo
    ifstream archivoCarga("peliculas.txt");
    if (archivoCarga.is_open()) {
        peliculas.clear();
        string linea;
        while (getline(archivoCarga, linea)) {
            stringstream ss(linea);
            string nombre, director, genero, duracionStr;
            int lanzamiento, horas, minutos, segundos;
            getline(ss, nombre, ';');
            getline(ss, director, ';');
            ss >> lanzamiento;
            getline(ss, genero, ';');
            getline(ss, duracionStr, ';');
            sscanf(duracionStr.c_str(), "%d:%d:%d", &horas, &minutos, &segundos);
            peliculas.push_back(Pelicula(nombre, director, lanzamiento, genero, Duracion(horas, minutos, segundos)));
        }
        cout << "Informacion de peliculas cargada desde el archivo correctamente." << endl;
    } else {
        cerr << "No se pudo abrir el archivo para cargar la informacion." << endl;
    }

    return 0;
}
