#pragma once
#include "Header.h"

#ifndef Monomio_H
#define Monomio_H

class Monomio {										// coef_ * x ^ exp_
	private:
		int coef_;									// Coeficiente del monomio
		int exp_;									// Exponente de la parte literal
	public:
		Monomio();									// Constructor por Defecto
		Monomio(int coef, int exp);					// Constructor con Coeficiente y Exponente
		Monomio(const Monomio &s);					// Constructor copia
		int Evaluar(int x) const;					// Evalua un monomio en un punto
		int getCoef() const;						// Devuelve el Coeficiente
		int getExp() const;							// Devuelve el Exponente
		void setCoef(int c);						// Asigna un valor al Coeficiente
		void setExp(int e);							// Asigna un valor al Exponente
		// Operadores de inserción y extracción
		friend ostream& operator<<(ostream &sout, const Monomio&s);
		friend istream& operator>>(istream &sin, Monomio &r);
		// Operadores +, -, *, /
		Monomio operator=(const Monomio &m);
		friend Monomio operator+(const Monomio &m1, const Monomio &m2);
		friend Monomio operator-(const Monomio &m1, const Monomio &m2);
		friend Monomio operator*(const Monomio &m1, const Monomio &m2);
		friend Monomio operator*(const Monomio &m, const int c);
		friend Monomio operator*(const int c, const Monomio &m);
		//friend Monomio operator/(const Monomio &m1, const Monomio &m2);			// No tiene sentido éste operador puesto que el coef es int
		~Monomio();									// Destructor
};

#endif
