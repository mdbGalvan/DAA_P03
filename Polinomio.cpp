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
	gr_ = tam - 1;
	ter_ = tam;
	m_[tam];

	for (int i = 0; i < tam; i++) {
		if (coef[i] != 0) {					// Si coef = 0, entonces no lo ingreso
			m_[i].setExp(i);				// Exp. Monomio
			m_[i].setCoef(coef[i]);			// Coef. Monomio
		}
	}
}

int Polinomio::Evaluar(int x) const
{
	int aux = 0;							// Almacenará x^exp

	for (int i = 0; i < ter_; i++)
		aux += m_[i].Evaluar(x);

	return aux;
}

// Operadores de inserción y extracción
ostream& operator<<(ostream &sout, const Polinomio&p)
{
	for (int i = 0; i < p.ter_; i++)
		sout << p.m_[i];

	return sout;
}

istream& operator>>(istream &sin, Polinomio &p)
{
	int aux;
	p.gr_ = 0;
	cout << "\tN\247 de t\202rminos: ";
	sin >> p.ter_;
	for (int i = 0; i < p.ter_; i++) {
		cout << "\tCoeficiente [" << i << "]: ";
		sin >> aux;
		p.m_[i].setCoef(aux);
		cout << "\tExponente [" << i << "]: ";
		sin >> aux;
		p.m_[i].setExp(aux);
		if (p.m_[i].getExp() > p.gr_)
			p.gr_ = p.m_[i].getExp();
	}
	return sin;
}

// Operadores sobrecargados
Polinomio Polinomio::operator+(const Polinomio &p) {
	
	Polinomio aux;

	for (int i = 0; i < this->ter_; i++)
	for (int j = 0; j < this->ter_; j++) {
		if (this->m_[i].getExp() == p.m_[j].getExp())
			aux = 
	}


	return aux;
}

Polinomio Polinomio::operator-(const Polinomio &p) {

}

Polinomio Polinomio::operator*(const Polinomio &p) {

}

Polinomio Polinomio::operator*(const int c) {

}

// DESTRUCTOR
Polinomio::~Polinomio()
{
	ter_ = 0;
	gr_ = 0;
}
