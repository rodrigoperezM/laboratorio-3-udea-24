#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class C_c {
	private://Atributos
		string nombre;
		string apellido;
		string direccion;
		string tel;
		double sal;
		
		public://Metodos
		C_c (string,string,string,string, double); //constructor
		void saldo();
		void retirar();
		void ingresar();
		void consultar();
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

// inicializa los atributos
C_c::C_c (string nom,string ape,string dir,string tele,double sald){
	nombre= nom; apellido= ape; direccion= dir; tel= tele; sal=sald;
}

void C_c::consultar(){
	cout << " su nombre es: " << getNombre() << " " << getApellido() << endl;
	cout << "su direccion es: " << getDireccion() << endl;
	cout << "su telefonoes: " << getTelefono() << endl;
	cout << " su saldo es : " << sal << endl;
}

void C_c::retirar(){
	double total;
	cout << "cuanto quiere retirar: " << endl;
	cin >> total;
	if(sal < total) {
		cout << "saldo insuficiente";
	}
	else {
		sal = sal - total;
		cout << "retiro exitoso" << endl;
	}
}

void C_c::ingresar(){
	double total;
    cout << "valor a consignar: ";
    cin >> total;
    if (total <= 0) {
        cout << "Ingreso inválido" << endl;
        return;
    }
    sal= sal + total;
    cout << "consignacion exitosa" << endl;
}

void C_c::sin_saldo() {
    if (sal <= 0) {
        cout << "fondos insuficientes" << endl;
    } else {
        cout << "sus fondos son suficientes" << endl;
    }
}

int main() {
	char op;
	string nombre, apellido, direccion, telefono;
    double saldo_inicial;
	
    cout << "Elija 1 para ingresar los datos de su cuenta." << endl;
    cout << "Elija 2 para crear una cuenta." << endl;
    cout << "Elegir numero: ";
    cin >> op;
    
    C_c cuenta("NombreDefinida", "ApellidoDefinido", "DireccionDefinida", "TelefonoDefinido", 0.0); // Cuenta predeterminada);
    
   switch (op) {
    case '1':
    cout << "Ingrese el nombre: ";
    cin >> nombre;
    cuenta.setNombre(nombre);

    cout << "Ingrese el apellido: ";
    cin >> apellido;
    cuenta.setApellido(apellido);

    cout << "Ingrese la dirección: ";
    cin >> direccion;
    cuenta.setDireccion(direccion);

    cout << "Ingrese el teléfono: ";
    cin >> telefono;
    cuenta.setTelefono(telefono);

    cout << "Ingrese el saldo inicial: ";
    cin >> saldo_inicial;
    cuenta.ingresar(); // No se pasa ningún argumento
    break;

    case '2':
        //  datos predeterminados  establecidos
        break;

    default:
        cout << "Opción no valida.." << endl;
        return 0;
    }

    do {
        cout << endl << "Menu de opciones:" << endl;
        cout << "1. Consultar datos de la cuenta." << endl;
        cout << "2. Retirar ." << endl;
        cout << "3. consignar." << endl;
        cout << "4. Verificar saldo en rojo." << endl;
        cout << "5. Salir." << endl;
        cout << "Seleccione una opción: ";
        cin >> op;

        switch (op) {
        case '1':
            cuenta.consultar();
            break;

        case '2':
            cuenta.retirar();
            break;

        case '3':
            cuenta.ingresar();
            break;

        case '4':
            cuenta.sin_saldo();
            break;

        case '5':
            cout << "Hasta luego" << endl;
            break;

        default:
            cout << "Opcion no valida." << endl;
        }
    } while (op != '5');

    return 0;
}
