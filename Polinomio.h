#pragma once
#include "Header.h"

#ifndef Polinomio_H
#define Polinomio_H

class Polinomio {
	private:
		int gr_;								// Grado del Polinomio
		int ter_;								// Número de términos máximo en el polinomio
		int *coef_;								// Array de coeficientes

		void reservar(int n);					// Reservar memoria para coef_
		void liberar();							// Liberar memoria para coef_
	public:
		Polinomio();							// Constructor por defecto, gr = 10
		Polinomio(int ter = 10);				// Constructor fijando el grado
		Polinomio(int coef[], const int tam);	// Constructor con vector de coeficientes
		Polinomio(const Polinomio &p);			// Constructor copia

		void setCoef(int i, int valor);			// Establecer el valor del coef_ de grado i
		int Evaluar(int x) const;				// Evalua un monomio en un punto

		~Polinomio();
};

#endif