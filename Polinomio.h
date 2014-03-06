#pragma once
#include "Header.h"


//#ifndef Polinomio_H
//#define Polinomio_H

class Polinomio {
	private:
		int gr_;								// Grado del Polinomio
		int *coef_;								// Array de coeficientes

		void nulo();							// Convierte todos los coeficientes a 0
		void liberar();							// Liberar memoria para m_
		void reservar(int n);					// Reservar memoria para coef_ 
	public:
		Polinomio();							// Constructor por defecto, gr = 10
		Polinomio(const int gr);				// Constructor fijando el grado
		Polinomio(int coef[], const int tam);	// Constructor con vector de coeficientes
		Polinomio(const Polinomio &p);			// Constructor copia

		int Evaluar(int x) const;				// Evalua un polinomio en un punto

		// Operadores de inserción y extracción
		friend ostream& operator<<(ostream &sout, const Polinomio&p);
		friend istream& operator>>(istream &sin, Polinomio &p);
		// Operadores +, -, *, /
		Polinomio operator+(const Polinomio &p);
		Polinomio operator*(const Polinomio &p);
		~Polinomio();
};

//#endif

