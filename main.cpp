#include "Header.h"
#include "Tests.h"		// Clase que maneja los test

int main(int argc, char* argv[]) {

	srand(time(NULL));

	// N = 4, N - 1 = 3
	Polinomio p(3, 0, 5), q(3, 0, 5);
	cout << "p: " << p << endl;
	cout << "q: " << q << endl;

	cout << "\n\tp * q = " << (p*q) << endl;

	int *r = mult(p.getCoef(), q.getCoef(), p.getGr() + 1);

	cout << "\n\tRESULTADO:\n";
	for (int i = 0; i < 7; i++)
		cout << " " << r[i];

	cout << "\n\tRESULTADO:\n";
	cout << "\n\tp * q = " << mult(p, q, p.getGr() + 1);

	cout << "\n\tRESULTADO:\n";
	cout << "\n\tp * q = " << p.mult(q, p.getGr() + 1);

	cin.ignore();
	cin.get();
	return 0;
}