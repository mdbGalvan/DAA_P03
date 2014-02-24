#include "Polinomio.h"


Polinomio::Polinomio()
{
	gr_ = 10;
	ter_ = 0;
	m_ = new Monomio[gr_ + 2];
}

Polinomio::Polinomio(int g)
{
	gr_ = g;
	ter_ = 0;
	m_ = new Monomio[gr_ + 2];
}


Polinomio::~Polinomio()
{
}
