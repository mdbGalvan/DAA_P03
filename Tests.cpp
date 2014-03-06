#include "Tests.h"

// Liberar memoria para coef_
void Tests::nulo(){
	for (int i = 0; i < maxGr_; i++)
		avg_[i] = 0;
}

// Reservar memoria para coef_
void Tests::reservar(int tam){
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
	reservar(maxGr_ + 1);
	nulo();
}


Tests::~Tests()
{
	nTest_ = 0;
	maxGr_ = 0;
	liberar();
}
