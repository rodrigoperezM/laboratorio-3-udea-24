#include<iostream>
#include<stdlib.h>
#include<fstream>

using namespace std;

class Archivos {
public:
    void escribir() {
        ofstream escritura;
        escritura.open("Ejercicio 2 laboratorio 3.txt", ios::out);

        if (escritura.fail()) {
            cout << "Archivo no existe" << endl;
            exit(1);
        }

        string escrito;
        cout << "Escriba para guardar en el archivo: ";
        getline(cin, escrito);

        while (true) {
            char letra;
            cout << "Desea escribir algo más s/n? ";
            cin >> letra;
            cin.ignore();
            escritura << escrito << endl; // Guarda el texto antes de obtener la próxima entrada

            if (letra == 's') {
                cout << "Escriba para guardar en el archivo: ";
                getline(cin, escrito);
            } else {
                cout << "adios" << endl;
                break;
            }
        }
        escritura.close();
    }
};

int main() {
    Archivos archivos;
    archivos.escribir();
    return 0;
}
