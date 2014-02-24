#include "Header.h"

int main(int argc, char* argv[]) {

	Monomio m1(-2,3);
	Monomio m2(m1);

	cout << "m1 =" << m1 << endl;
	cout << "m2 =" << m2 << endl;
	cout << "m1 * m2 =" << (m1 * m2) << endl;
	cout << "m1 * 3 =" << (m1 * 3) << endl;
	cout << "2 * m2 =" << (2 * m2) << endl;
	cout << "m1 + m2 =" << (m1 + m2) << endl;
	cout << "m1 - m2 =" << (m1 - m2) << endl;

	cin >> m1;

	cin.get();
	return 0;
}