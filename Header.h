#include <stdio.h>		// Cabecera que contendr� el procedimiento sprintf
#include <iostream>		// Cabecera que tendr� la E/S mediante flujo
#include <math.h>       /* pow */
#include <fstream>		// Cabecera que tendr� la E/S por ficheros
#include <string>		// Cabecera para manejar cadenas
#include <dos.h>        // necesario para _argc y argv
#include <vector>		// Cabecera para manejar un vector
#include <conio.h>
#include <ctype.h>		// Cabecera que me dejar� utilizar las funciones toupper y tolower
#include "Monomio.h"	// Clase que maneja los monomios


//========================================================================================
// Definici�n de tipos
//========================================================================================

typedef int item;						/** Tipo de dato que almacenar� cada elemento de la matriz. */
typedef unsigned short int index;		/** Tipo de dato para �ndices de la matriz. */

using namespace std;