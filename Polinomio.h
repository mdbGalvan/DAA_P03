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

		int *getCoef() const;					// Devuelve los coeficientes del polinomio
		int getGr() const;						// Devuelve el grado del polinomio
		int getTam() const;						// Devuelve el n� total de elementos del polinomio: gr + 1
		
		int Evaluar(int x) const;				// Evalua un polinomio en un punto

		friend ostream& operator<<(ostream &sout, const Polinomio&p);	// Operadores de inserci�n
		friend istream& operator>>(istream &sin, Polinomio &p);			// Operadores de extracci�n
		Polinomio operator+(const Polinomio &p);						// Operador +
		Polinomio operator*(const Polinomio &p);						// Operador *
		~Polinomio();
};

//#endif

