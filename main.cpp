#include <iostream>
#include "codigo.h"
#include "cuenta-corriente.h"
#include "archivos.h"
#include "pelicula.h"
#include "caracter-y-secuencia.h"
#include <string>

using namespace std;

int main() {
    int opcion;
    cout << "Elija que clase desea utilizar:" << endl;
    cout << "1. Clase de Codigo" << endl;
    cout << "2. Clase de Cuenta Corriente" << endl;
    cout << "3. Clase de Archivos" << endl;
    cout << "4. Clase de Pelicula" << endl;
    cout << "5. Clase de Caracter y Secuencia" << endl;
    cout << "Ingrese el numero de la opcion deseada: ";
    cin >> opcion;

    switch (opcion) {
        case 1: {
            // Utilizar la clase de Código
            //
            //codigo objetoCodigo;
            // Llamar a los métodos de la clase código si es necesario
            break;
        }
        case 2: {
            // Utilizar la clase de Cuenta Corriente
            C_c objetoC_c;
            //objetoC_c.C_c();
            // Llamar a los métodos de la clase cuenta_corriente si es necesario
            break;
        }
        case 3: {
            // Utilizar la clase de Archivos
            Archivos objetoArchivos;
            // Llamar a los métodos de la clase Archivos si es necesario
            objetoArchivos.escribir(); // Llamada a  método de la clase Archivos
            objetoArchivos.leer(); // Llamada a otro método de la clase Archivos
            break;
        }
        case 4: {
            // Utilizar la clase de Película
            Pelicula objetoPelicula;
            // Llamar a los métodos de la clase Pelicula si es necesario
            objetoPelicula;
            break;
        }
        case 5: {
            // Utilizar la clase de Caracter y Secuencia
            //CaracterYSecuencia objetoCaracterYSecuencia;
            // Llamar a los métodos de la clase CaracterYSecuencia si es necesario
            break;
        }
        default:
            cout << "Opcion no valida." << endl;
            break;
    }

    return 0;
}
