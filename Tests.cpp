#include "Tests.h"

// Liberar memoria para coef_
void Tests::nulo(){
	for (int i = 0; i < maxGr_ + 1; i++)
		avg_[i] = 0;
}

// Reservar memoria para coef_
void Tests::reservar(int tam){
	maxGr_ = tam - 1;
	avg_ = new (nothrow)int[tam];
	if (!avg_) {
		cerr << "Error: no hay memoria";
		exit(1);
	}
}

// Liberar memoria para coef_
void Tests::liberar(){
	delete[] avg_;
}

// Constructor por defecto
Tests::Tests()
{
	nTest_ = 0;
	maxGr_ = 0;
	//minGr_ = 0;
	reservar(maxGr_ + 1);
	nulo();
}

// Métodos Get's y Set's

int Tests::getAvg(int item) const { 
	return avg_[item]; 
}
int Tests::getMaxGr() const { 
	return maxGr_; 
}
//int Tests::getMinGr() const {
//	return minGr_;
//}
int Tests::getNTest() const { 
	return nTest_; 
}
void Tests::setAvg(int item, int value) { 
	avg_[item] = value;
}
void Tests::setMaxGr(int maxGr) { 
	liberar();
	reservar(maxGr + 1);
	nulo();
	maxGr_ = maxGr;
}
//void Tests::setMinGr(int minGr) {
//	minGr_ = minGr;
//}
void Tests::setNTest(int nTest) {
	nTest_ = nTest;
} 

// Pruebas
void Tests::prueba(int nTest, int maxGr) {
	setNTest(nTest);
	//setMinGr(minGr);
	setMaxGr(maxGr);

	Polinomio p, q;										// Creo los polinomios que se multiplicarán
	clock_t t_ini, t_fin;
	double secs;

	for (int i = 0; i <= maxGr_; i++) {			// Por cada grado hasta el máximo, N
		p.liberar();
		q.liberar();	
		p.reservar(i + 1); 
		q.reservar(i + 1); 
		for (long int j = 1; j <= nTest_; j++) {			// Repetición de nTest veces por el producto con pol. de gr. i
			p.aleatorio(0, 10);	
			q.aleatorio(0, 10); 

			t_ini = clock();
			(p * q);
			t_fin = clock();

			secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
			avg_[i] += secs*1000.0;
		}
		avg_[i] = avg_[i] / nTest_;
	}
}

ostream& operator<<(ostream &sout, const Tests&p)
{
	cout << "N \t Miliseg." << endl;
	cout << "*************" << endl;
	for (int i = 0; i < p.maxGr_ + 1; i++)
		cout << i << "\t  " << p.avg_[i] << endl;
	//printf("Segundos Transcurridos: %f s\n", difftime(final, comienzo));

	return sout;
}

// Destructor
Tests::~Tests()
{
	nTest_ = 0;
	maxGr_ = 0;
	liberar();
}
