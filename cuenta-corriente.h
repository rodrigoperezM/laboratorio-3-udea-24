#ifndef CUENTA_CORRIENTE_H
#define CUENTA_CORRIENTE_H

#include <iostream>
#include <string>

using namespace std;

class C_c {
private:
    string nombre;
    string apellido;
    string direccion;
    string tel;
    double sal;

public:
    C_c(string, string, string, string, double);
    void consultar();
    void retirar();
    void ingresar();
    void sin_saldo();
    
    // Métodos set y get
    void setNombre(string nom) { nombre = nom; }
    string getNombre() const { return nombre; }
    
    void setApellido(string ape) { apellido = ape; }
    string getApellido() const { return apellido; }
    
    void setDireccion(string dir) { direccion = dir; }
    string getDireccion() const { return direccion; }
    
    void setTelefono(string tele) { tel = tele; }
    string getTelefono() const { return tel; }
};

#endif // CUENTA_CORRIENTE_H
