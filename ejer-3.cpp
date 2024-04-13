#include <iostream>
#include "caracter-y-secuencia.h"
#include<stdlib.h>
#include <fstream>
#include <string>


int main()
{
	string nom_archivo;
	char caracter;
	string secuencia2;
	
	cout << "Ingrese el nombre del archivo: ";
	cin >> nom_archivo;
	cout << "Que caracter quier buscar: ";
	cin >> caracter;
	cout << "la secuencia de texto a buscar es : ";
	cin >> secuencia2;
	
	leer(nom_archivo, caracter, secuencia2);

	return 0;
}
