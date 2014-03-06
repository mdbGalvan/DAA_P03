#include "Header.h"
#include "Tests.h"		// Clase que maneja los test

int main(int argc, char* argv[]) {

	Tests t;
	t.prueba(1, 500);
	cout << t;

	cin.ignore();
	cin.get();
	return 0;
}