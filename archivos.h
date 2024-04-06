// Archivos.h

#ifndef ARCHIVOS_H
#define ARCHIVOS_H


#include <iostream>
#include <fstream>

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
        cout << "Escriba el nombre para guardar en el archivo: ";
        getline(cin, escrito);

        while (true) {
            char letra;
            cout << "Desea escribir algo mas s/n? ";
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
    
    void leer()
    {
    	ifstream lectura;
    	string contenido;
    	lectura.open("Ejercicio 2 laboratorio 3.txt",ios::in);//abrir archivo para leer
    	
    	if (lectura.fail()) {
            cout << "No se puede abrir el archivo" << endl;
            exit(1);
        }
        
        while(!lectura.eof())//eof()- funcion que recorre todo el archivo
        {
        	getline(lectura,contenido);
        	cout<<contenido<<endl;
		}
		lectura.close();
	}
};
// Archivos.h

#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#endif // ARCHIVOS_H


#include <iostream>
#include <fstream>

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
        cout << "Escriba el nombre para guardar en el archivo: ";
        getline(cin, escrito);

        while (true) {
            char letra;
            cout << "Desea escribir algo mas s/n? ";
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
    
    void leer()
    {
    	ifstream lectura;
    	string contenido;
    	lectura.open("Ejercicio 2 laboratorio 3.txt",ios::in);//abrir archivo para leer
    	
    	if (lectura.fail()) {
            cout << "No se puede abrir el archivo" << endl;
            exit(1);
        }
        
        while(!lectura.eof())//eof()- funcion que recorre todo el archivo
        {
        	getline(lectura,contenido);
        	cout<<contenido<<endl;
		}
		lectura.close();
	}
};
// Archivos.h

#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#endif // ARCHIVOS_H


#include <iostream>
#include <fstream>

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
        cout << "Escriba el nombre para guardar en el archivo: ";
        getline(cin, escrito);

        while (true) {
            char letra;
            cout << "Desea escribir algo mas s/n? ";
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
    
    void leer()
    {
    	ifstream lectura;
    	string contenido;
    	lectura.open("Ejercicio 2 laboratorio 3.txt",ios::in);//abrir archivo para leer
    	
    	if (lectura.fail()) {
            cout << "No se puede abrir el archivo" << endl;
            exit(1);
        }
        
        while(!lectura.eof())//eof()- funcion que recorre todo el archivo
        {
        	getline(lectura,contenido);
        	cout<<contenido<<endl;
		}
		lectura.close();
	}
};

