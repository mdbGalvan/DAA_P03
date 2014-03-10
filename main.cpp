#include "Header.h"
#include "Tests.h"		// Clase que maneja los test

int main(int argc, char* argv[]) {

	srand(time(NULL));

	Tests t;
	int test, gr, opcion;

	// PARÁMETROS
	cout << "\n\n\t\t\t TEST ";
	cout << "\n\n\t ************************************ ";
	cout << "\n\t Numero de Pruebas por Grado: \t";
	cin >> test;
	cout << "\t Grado de polinomios (Gr*100): \t";
	cin >> gr;
	cout << "\n\t Test:\n";
	cout << "\n\t 1. Alg.Clasico.";
	cout << "\n\t 2. Divide y venceras: \t";
	cin >> opcion;

	if ((opcion != 2) && (opcion != 1))
		cout << "\n\t No es una opcion correcta. \n";
	else {
		if (opcion == 1) t.prueba1(test, gr);
		else t.prueba2(test, gr);

		// GUARDAR EN FICHERO
		string file = "salida.txt";		// Nombre del archivo de la cinta de salida
		cout << "\n\t Nombre del Fichero: \t";
		cin >> file;
		ofstream out;
		out.open(file.c_str(), ofstream::out | ofstream::trunc);
		if (out) {
			if (opcion == 1) out << "Algoritmo Clásico" << endl;
			else if (opcion == 2) out << "Divide y Vencerás" << endl;
			t.write(out);
		}
		else
			cout << "\n\n\t\t Error al leer escribir en el fichero.";

		out.close();

		cout << "\n\n\t\t Fin del Programa. \n";
	}


	// IMPRIMIR TEST POR PANTALLA
	//cout << t;

	cin.ignore();
	cin.get();
	return 0;
}