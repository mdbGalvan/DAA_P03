#include "Polinomio.h"

// CONSTRUCTORES
Polinomio::Polinomio()
{
	gr_ = 0;
	ter_ = 0;	
}

Polinomio::Polinomio(const int ter)
{
	gr_ = 0;
	ter_ = ter;
	m_[ter_];
}

// Constructor Copia
Polinomio::Polinomio(const Polinomio &p)
{
	gr_ = p.gr_;
	ter_ = p.ter_;
	m_[ter_];

	for (int i = 0; i < ter_; i++) m_[i] = p.m_[i];
}

// Constructor con vector de coeficientes
Polinomio::Polinomio(int coef[], const int tam)
{
	Monomio m; 

	gr_ = tam;
	ter_ = tam;
	m_[ter_];

	for (int i = 0; i < tam; i++) {
		m.setCoef(coef[i]);
		m.setExp(i);
		m_[i] = m;
	}
}

int Polinomio::Evaluar(int x) const
{
	int aux = 0;							// Almacenará x^exp

	for (int i = 0; i < ter_; i++)
		aux += m_[i].Evaluar(x);

	return aux;
}

// DESTRUCTOR
Polinomio::~Polinomio()
{
	ter_ = 0;
	gr_ = 0;
}
