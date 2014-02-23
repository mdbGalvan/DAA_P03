#include "Monomio.h"

Monomio::Monomio() :
	coef_(0),
	exp_(0)
{}

// Constructor con Coeficiente y Exponente
Monomio::Monomio(int coef, int exp) :
	coef_(coef),
	exp_(exp)
{}


// Evalua un monomio en un punto
int Monomio::Evaluar(int x) const
{
	//return pow(getCoef() * x, getExp());

	int aux = 1;

	if (exp_ > 0)
	for (int i = 0; i < getExp(); i++)
		aux *= getCoef() * x;
	else
		aux = 0;

	return aux;
}


// Devuelve el Coeficiente
int Monomio::getCoef() const
{
	return coef_;
}


// Devuelve el Exponente
int Monomio::getExp() const
{
	return exp_;
}


// Asigna un valor al Coeficiente
void Monomio::setCoef(int c)
{
	coef_ = c;
}


// Asigna un valor al Exponente
void Monomio::setExp(int e)
{
	exp_ = e;
}

// Operadores de inserción y extracción
ostream& operator<<(ostream &sout, const Monomio&s)
{
	sout << (s.coef_ > 0) ? "+" : "-";
	if (s.exp_ == 1)
		sout << "x";
	else
		sout << s.coef_ << "x^" << s.exp_;

	return sout;
}

// Destructor
Monomio::~Monomio()
{
	coef_ = 0;
	exp_ = 0;
}