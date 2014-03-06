#include "Header.h"
#include "Tests.h"		// Clase que maneja los test

int main(int argc, char* argv[]) {

	Tests t;
	int test, gr;

	// PARÁMETROS
	cout << "\n\n\t\t\t TEST ";
	cout << "\n\n\t ************************************ ";
	cout << "\n\t Numero de Pruebas por Grado: \t";
	cin >> test;
	cout << "\t Grado de los polinomios: \t";
	cin >> gr;
	t.prueba(test, gr);

	// GUARDAR EN FICHERO
	string file = "salida.txt";				// Nombre del archivo de la cinta de salida
	//cout << "\t\t Nombre del Fichero: \t";
	//cin >> file;
	ofstream out;
	out.open(file.c_str(), ofstream::out | ofstream::trunc);
	(out) ? t.write(out) : cout << "\n\n\t\t Error al leer escribir en el fichero.";
	out.close();

	cout << "\n\n\t\t Fin del Programa. \n";
	
	// IMPRIMIR TEST POR PANTALLA
	//cout << t;

	cin.ignore();
	cin.get();
	return 0;
}