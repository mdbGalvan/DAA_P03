#pragma once
#include "Header.h"

//#ifndef Tests_H
//#define Tests_H

class Tests {
	private:
		int *avg_;					// El tiempo medio de ejecuci�n del c�digo en seg por grado desde 0 hasta N
		//int minGr_;				// N� m�nimo de N
		int maxGr_;					// N� m�ximo de N para la evaluaci�n del producto de Polinomios
		int nTest_;					// N� de tests por cada grado distinto del producto de polinomios

		void nulo();				// Convierte todos los coeficientes a 0 de avg_
		void liberar();				// Liberar memoria para avg_
		void reservar(int tam);		// Reservar memoria para avg_ 
	public:
		Tests();					// Constructor por defecto

		int getAvg(int item) const;	// Devuelve el coeficiente item de los seg. por valor de N (grado resultado del producto de polinomios)
		//int getMinGr() const;		// Devuelve el valor m�nimo del grado del producto de polinomio
		int getMaxGr() const;		// Devuelve el valor m�ximo del grado del producto de polinomio
		int getNTest() const;		// Devuelve el n� de test a ejecutar por valor de N
		void setAvg(int item, int value);	// Modifica el valor de los tiempos de ejecuci�n
		void setMaxGr(int maxGr);	// Modifica el valor de grado m�ximo del producto
		//void setMinGr(int minGr);	// Modifica el valor de grado m�nimo del producto
		void setNTest(int nTest);	// Modifica el n� de tests a realizar por grado

		void prueba(int nTest, int maxGr);	// Ejecuci�n de las pruebas con los datos de los atributos para el producto de polinomios

		friend ostream& operator<<(ostream &sout, const Tests&p);

		~Tests();
};

//#endif