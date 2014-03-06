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

Monomio::Monomio(const Monomio &s)
{
	coef_ = s.getCoef();
	exp_ = s.getExp();
}

// Evalua un monomio en un punto
int Monomio::Evaluar(int x) const
{
	//return getCoef() * pow(x, getExp());

	int aux = 1;							// Almacenará x^exp

	if (exp_ > 0)
		for (int i = 0; i < getExp(); i++)
			aux *= x;						

	return getCoef() * aux;
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
	if (s.getCoef() >= 0) sout << "+";
	if (s.getExp() == 1)				// Si es x
		sout << s.getCoef() << "x";
	else if (s.getExp() == 0)			// Si es el termino independiente
		sout << s.getCoef();
	else								// Si es x elevado a un nº distinto de 1
		sout << s.getCoef() << "x^" << s.getExp();

	return sout;
}

istream& operator>>(istream &sin, Monomio &r)
{
	int aux;
	cout << "\tCoeficiente: ";
	sin >> aux;
	r.setCoef(aux);
	cout << "\tExponente: ";
	sin >> aux;
	r.setExp(aux);

	return sin;
}

// Operadores +, -, *, /
Monomio  Monomio::operator=(const Monomio &m)
{
	this->coef_ = m.coef_;
	this->exp_ = m.exp_;

	return *this;
}

Monomio operator+(const Monomio &m1, const Monomio &m2)
{
	Monomio aux;

	if (m1.getExp() == m2.getExp()) {			// Son semejantes
		aux.setExp(m1.getExp());
		aux.setCoef(m1.getCoef() + m2.getCoef());
	} else
		cout << "\255Error! No son semejantes.";

	return aux;
}

Monomio operator-(const Monomio &m1, const Monomio &m2)
{
	Monomio aux;

	if (m1.getExp() == m2.getExp()) {			// Son semejantes
		aux.setExp(m1.getExp());
		aux.setCoef(m1.getCoef() - m2.getCoef());
	} else
		cout << "\255Error! No son semejantes.";

	return aux;
}

Monomio operator*(const Monomio &m1, const Monomio &m2)
{
	Monomio aux;

	aux.setExp(m1.getExp() + m2.getExp());
	aux.setCoef(m1.getCoef() * m2.getCoef());

	return aux;
}

Monomio operator*(const Monomio &m, const int c)
{
	Monomio aux;

	aux.setExp(m.getExp());
	aux.setCoef(m.getCoef() * c);

	return aux;
}

Monomio operator*(const int c, const Monomio &m)
{
	Monomio aux;

	aux.setExp(m.getExp());
	aux.setCoef(m.getCoef() * c);

	return aux;
}

// Destructor
Monomio::~Monomio()
{
	coef_ = 0;
	exp_ = 0;
}
