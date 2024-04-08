#include<iostream>
#include<stdlib.h>
#include <fstream>
#include <string>

using namespace std;

class Salida 
{
	private:
	string archivo_1;
	public:
		Salida(string);
	
};
Salida::Salida(string Arch_1)
{archivo_1 = Arch_1;}

void leer(string archivo, char caracter, string secu)
{
	ifstream archivo_x;
	archivo_x.open(archivo.c_str(),ios::in);
	if (archivo_x.fail()) {
        cout << "No se puede abrir el archivo" << endl;
        exit(1);
    }

    ofstream archivo_salida("resultado.txt");
    if (!archivo_salida.is_open()) {
        cout << "No se puede abrir el archivo de salida" << endl;
        exit(1);
    }
    
    string texto;
    string linea;
    while (getline(archivo_x, linea)) 
	{
        texto = texto + linea;
    }
    
    int num_caracter = 0;
    size_t pos = texto.find(caracter);
    while (pos != string::npos) 
	{
        num_caracter++;
        pos = texto.find(caracter, pos + 1);
    }

    int num_secu = 0;
    pos = texto.find(secu);
    while (pos != string::npos) 
	{
        num_secu++;
        pos = texto.find(secu, pos + 1);
    }
    
    archivo_salida << "El carccter \'" << caracter << "\' se repite " << num_caracter << " veces en el texto." << endl;
    archivo_salida << "La secuencia \"" << secu << "\" se repite " << num_secu << " veces en el texto." << endl;

    archivo_x.close();
    archivo_salida.close();
}

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

	return 0;
}
