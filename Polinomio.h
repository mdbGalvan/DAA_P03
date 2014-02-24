#pragma once
#include "Header.h"


//#ifndef Polinomio_H
//#define Polinomio_H

class Polinomio {
	private:
		int gr_;								// Grado del Polinomio
		int ter_;								// Número de términos en el polinomio
		Monomio m_[];							// Array de coeficientes
	public:
		Polinomio();							// Constructor por defecto, gr = 10
		Polinomio(const int ter);				// Constructor fijando el grado
		Polinomio(int coef[], const int tam);	// Constructor con vector de coeficientes
		Polinomio(const Polinomio &p);			// Constructor copia

		int Evaluar(int x) const;				// Evalua un monomio en un punto

		// Operadores de inserción y extracción
		friend ostream& operator<<(ostream &sout, const Polinomio&p);
		friend istream& operator>>(istream &sin, Polinomio &p);
		// Operadores +, -, *, /
		friend Polinomio operator+(const Polinomio &m1, const Polinomio &m2);
		friend Polinomio operator-(const Polinomio &m1, const Polinomio &m2);
		friend Polinomio operator*(const Polinomio &m1, const Polinomio &m2);
		friend Polinomio operator*(const Polinomio &m, const int c);
		friend Polinomio operator*(const int c, const Polinomio &m);

		~Polinomio();
};

//#endif

