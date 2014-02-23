#pragma once
#include "Header.h"

class Monomio {										// coef_ * x ^ exp_
	private:
		int coef_;									
		int exp_;
	public:
		Monomio();									// Constructor por Defecto
		Monomio(int coef, int exp);					// Constructor con Coeficiente y Exponente
		int Evaluar(int x) const;					// Evalua un monomio en un punto
		int getCoef() const;						// Devuelve el Coeficiente
		int getExp() const;							// Devuelve el Exponente
		void setCoef(int c);						// Asigna un valor al Coeficiente
		void setExp(int e);							// Asigna un valor al Exponente
		// Operadores de inserción y extracción
		friend ostream& operator<<(ostream &sout, const Monomio&s);
		//friend istream& operator>>(istream &sin, Monomio &r);

		~Monomio();									// Destructor
};
