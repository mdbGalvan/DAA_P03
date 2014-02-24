#include "Polinomio.h"

void Polinomio::reservar(int n){
	m_ = new (nothrow)Monomio[n];
	if (!m_) {
		cerr << "Error: no hay memoria";
		exit(1);
	}
}void Polinomio::liberar(){
	delete[] m_;
}
// CONSTRUCTORES
Polinomio::Polinomio()
{
	ter_ = 10;
	m_ = new Monomio[ter_ + 2];
	
}

Polinomio::Polinomio(int ter)
{
	ter_ = 0;
	m_ = new Monomio[ter_ + 2];
}

Polinomio::Polinomio(const Polinomio &p)
{
	gr_ = p.gr_;
	m_ = new Monomio[gr_ + 2];

	for (register int i = 0; i < gr_ + 1; i++) m_[i] = p.m_[i];
}



// DESTRUCTOR
Polinomio::~Polinomio()
{
	liberar();
}
