#include "Header.h"
#include "Tests.h"		// Clase que maneja los test

int main(int argc, char* argv[]) {


	Polinomio p(2, 0, 10), q(3, 10, 100);
	//cin >> p >> q;
	cout << "p: " << p << endl;
	cout << "q: " << q << endl << endl;
	cout << "p + q: " << (p + q) << endl << endl;
	cout << "p * q: " << (p * q) << endl << endl;
	cout << "p(2): " << (p.Evaluar(2)) << endl << endl;
	cout << "q(2): " << (q.Evaluar(2)) << endl << endl;


	cin.ignore();
	cin.get();
	return 0;
}