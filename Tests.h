#pragma once
#include "Header.h"

//#ifndef Tests_H
//#define Tests_H

class Tests {
	private:
		int *avg_;					// El tiempo medio de ejecución del código en seg por grado desde 0 hasta N
		//int minGr_;				// Nº mínimo de N
		int maxGr_;					// Nº máximo de N para la evaluación del producto de Polinomios
		int nTest_;					// Nº de tests por cada grado distinto del producto de polinomios

		void nulo();				// Convierte todos los coeficientes a 0 de avg_
		void liberar();				// Liberar memoria para avg_
		void reservar(int tam);		// Reservar memoria para avg_ 
	public:
		Tests();					// Constructor por defecto

		int getAvg(int item) const;	// Devuelve el coeficiente item de los seg. por valor de N (grado resultado del producto de polinomios)
		//int getMinGr() const;		// Devuelve el valor mínimo del grado del producto de polinomio
		int getMaxGr() const;		// Devuelve el valor máximo del grado del producto de polinomio
		int getNTest() const;		// Devuelve el nº de test a ejecutar por valor de N
		void setAvg(int item, int value);	// Modifica el valor de los tiempos de ejecución
		void setMaxGr(int maxGr);	// Modifica el valor de grado máximo del producto
		//void setMinGr(int minGr);	// Modifica el valor de grado mínimo del producto
		void setNTest(int nTest);	// Modifica el nº de tests a realizar por grado

		void prueba(int nTest, int maxGr);	// Ejecución de las pruebas con los datos de los atributos para el producto de polinomios

		friend ostream& operator<<(ostream &sout, const Tests&p);

		~Tests();
};

//#endif