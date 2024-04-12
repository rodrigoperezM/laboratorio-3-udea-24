#ifndef PELICULA_H
#define PELICULA_H

#include <string>
#include <cstdio> //  para incluir la biblioteca cstdio

class Duracion {
private:
    int horas;
    int minutos;
    int segundos;

public:
    // Constructor
    Duracion(int horas, int minutos, int segundos);

    // Métodos para obtener los atributos
    int getHoras() const;
    int getMinutos() const;
    int getSegundos() const;
};

class Pelicula {
private:
    std::string nombre;
    std::string director;
    int lanzamiento;
    std::string genero;
    Duracion duracion;

public:
    // Constructor
    Pelicula(const std::string& nombre, const std::string& director, int anoLanzamiento, const std::string& genero, const Duracion& duracion);
 // Constructor por defecto
    Pelicula();
    // Métodos para obtener los atributos
    std::string getNombre() const;
    std::string getDirector() const;
    int getLanzamiento() const;
    std::string getGenero() const;
    Duracion getDuracion() const;

    // Métodos para establecer los atributos
    void setNombre(const std::string& nombre);
    void setDirector(const std::string& director);
    void setLanzamiento(int anoLanzamiento);
    void setGenero(const std::string& genero);
    void setDuracion(const Duracion& duracion);
};

// Implementación de la clase Duracion
Duracion::Duracion(int horas, int minutos, int segundos) : horas(horas), minutos(minutos), segundos(segundos) {}

int Duracion::getHoras() const {
    return horas;
}

int Duracion::getMinutos() const {
    return minutos;
}

int Duracion::getSegundos() const {
    return segundos;
}

// Implementación de la clase Pelicula
Pelicula::Pelicula() : nombre(""), director(""), lanzamiento(0), genero(""), duracion(0, 0, 0) {}
Pelicula::Pelicula(const std::string& nombre, const std::string& director, int anoLanzamiento, const std::string& genero, const Duracion& duracion)
    : nombre(nombre), director(director), lanzamiento(anoLanzamiento), genero(genero), duracion(duracion) {}

std::string Pelicula::getNombre() const {
    return nombre;
}

std::string Pelicula::getDirector() const {
    return director;
}

int Pelicula::getLanzamiento() const {
    return lanzamiento;
}

std::string Pelicula::getGenero() const {
    return genero;
}

Duracion Pelicula::getDuracion() const {
    return duracion;
}

void Pelicula::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}

void Pelicula::setDirector(const std::string& director) {
    this->director = director;
}

void Pelicula::setLanzamiento(int lanzamiento) {
    this->lanzamiento = lanzamiento;
}

void Pelicula::setGenero(const std::string& genero) {
    this->genero = genero;
}

void Pelicula::setDuracion(const Duracion& duracion) {
    this->duracion = duracion;
}

#endif // PELICULA_H
