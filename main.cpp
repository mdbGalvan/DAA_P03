#include "Header.h"
#include "Polinomio.h"	// Clase que maneja los polinomio


int main(int argc, char* argv[]) {
	const int tam = 3;
	int o[tam] = { 0, 1, 2 };
	Polinomio p(o, tam);
	cout << p;



	cin.get();
	return 0;
}