#include "Header.h"
#include "Polinomio.h"	// Clase que maneja los polinomio


int main(int argc, char* argv[]) {


	Polinomio p, q;
	cin >> p >> q;
	cout << (p * q);


	cin.ignore();
	cin.get();
	return 0;
}