#include <iostream>
#include <fstream>
#include <string>
#include "codigo.h" // Incluimos el archivo de encabezado




int main() 
{
    string Archivo_Entrada, Archivo_Salida, opcion, codigo;

    cout << "Ingrese la ubicacion y nombre del archivo de origen: ";
    cin >> Archivo_Entrada;

    cout << "Ingrese la ubicacion y nombre del archivo final: ";
    cin >> Archivo_Salida;

    cout << " quiere codificar o decodificar el mensaje? (c) o (d) : ";
    cin >> opcion;

    string mensaje = leerArchivo(Archivo_Entrada);// Leer el mensaje del archivo de entrada
    if (mensaje.empty()) 
	{
        cout << "No se pudo leer el archivo de entrada." << endl;
        return 1;
    }

    cout << "¿Quiere seleccionar el codigo por documento (s/n)?: ";
    cin >> opcion;

    // Si se selecciona codificación o decodificación por documento, solicitar la ubicación y nombre del documento
    if (opcion == "s" || opcion == "S") {
        string archivoCodigo;
        cout << "Ingrese la ubicacion y nombre del documento con el codigo: ";
        cin >> archivoCodigo;

        // Leer el archivo de código
        codigo = leerArchivo(archivoCodigo);
        if (codigo.empty()) {
            cout << "No se pudo leer el archivo de codigo." << endl;
            return 1;
        }
    } else {
        // Código predefinido
        codigo = "uvwxyzabcdefghijklmnopqrst"; // se puede agregar mas caracteres según sea necesario
       
    }

    // Codificar o decodificar el mensaje según la opción seleccionada
    string resultado;
    if (opcion == "c" || opcion == "C") {
        resultado = codificar(mensaje, codigo);
    } else if (opcion == "d" || opcion == "D") {
        resultado = decodificar(mensaje, codigo);
    } else {
        cout << "Opción no válida." << endl;
        return 1;
    }

    // Escribir el mensaje codificado o decodificado en el archivo de salida
    if (!escribirArchivo(Archivo_Salida, resultado)) 
	{
        cout << "No se pudo abrir el archivo de salida." << endl;
        return 1;
    }

    cout << "Mensaje procesado correctamente." << endl;

    return 0;
}
