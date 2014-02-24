#include "Polinomio.h"

// Reservar memoria para coef_
void Polinomio::reservar(int n){
	coef_ = new (nothrow)int[n];
	if (!coef_) {
		cerr << "Error: no hay memoria";
		exit(1);
	}
}// Liberar memoria para coef_void Polinomio::liberar(){
	delete[] coef_;
}
// CONSTRUCTORES
Polinomio::Polinomio()
{
	gr_ = 0;
	ter_ = 10;
	coef_ = new int[ter_ + 1];
	
}

Polinomio::Polinomio(int ter)
{
	gr_ = 0;
	ter_ = ter;
	coef_ = new int[ter_ + 1];
}

Polinomio::Polinomio(const Polinomio &p)
{
	gr_ = p.gr_;
	ter_ = p.ter_;
	coef_ = new int[ter_ + 2];

	for (register int i = 0; i < gr_ + 1; i++) coef_[i] = p.coef_[i];
}

// Establecer el valor del coef_ de grado i
void Polinomio::setCoef(int i, int valor)
{
	if (i<0 && i>ter_) {			// Si es mayor que el grado máximo o menor que 0 devuelve error
		cerr << "Error: grado incorrecto";
		exit(1);
	}
	coef_[i] = valor;
	if (i > gr_)					// Si el grado es mayor que el del polinomio se restablece
		gr_ = i;
}

int Polinomio::Evaluar(int x) const
{
	int aux = 1;							// Almacenará x^exp

	if (exp_ > 0)
	for (int i = 0; i < getExp(); i++)
		aux *= x;

	return getCoef() * aux;
}

// DESTRUCTOR
Polinomio::~Polinomio()
{
	liberar();
}
