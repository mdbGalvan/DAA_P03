#pragma once
#include "Header.h"

#ifndef Polinomio_H
#define Polinomio_H

class Polinomio {
	private:
		int gr_;								// Grado del Polinomio
		int ter_;								// Número de términos en el polinomio
		Monomio *m_;							// Array de monomios

		void reservar(int n);					// Reservar memoria para m_
		void liberar();							// Liberar memoria para m_
	public:
		Polinomio();							// Constructor por defecto, gr = 10
		Polinomio(int g);						// Constructor fijando el grado
		Polinomio(int coef[], const int tam);	// Constructor con vector de coeficientes
		Polinomio(const Polinomio &p);			// Constructor copia
		~Polinomio();
};

#endif