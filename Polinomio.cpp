#include "Polinomio.h"


// Liberar memoria para coef_
void Polinomio::nulo(){
	for (int i = 0; i < getTam(); i++)
		coef_[i] = 0;
}

void Polinomio::aleatorio(const int min, const int max){
	srand(time(0));
	for (int i = 0; i < getTam(); i++)
		// variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
		coef_[i] = min + rand() % (max + 1 - min);
}

// Reservar memoria para coef_
void Polinomio::reservar(int tam){
	gr_ = tam - 1;
	coef_ = new (nothrow)int[tam];
	if (!coef_) {
		cerr << "Error: no hay memoria";
		exit(1);
	}
}

// Liberar memoria para coef_
void Polinomio::liberar(){
	delete[] coef_;
}

// CONSTRUCTORES
Polinomio::Polinomio()
{
	gr_ = 0;
	reservar(gr_ + 1);
	nulo();
}

Polinomio::Polinomio(const int gr)
{
	gr_ = gr;
	reservar(gr_ + 1);
	nulo();
}

Polinomio::Polinomio(const int gr, const int min, const int max)
{
	gr_ = gr;
	reservar(gr_ + 1);
	aleatorio(min, max);
}

// Constructor Copia
Polinomio::Polinomio(const Polinomio &p)
{
	gr_ = p.gr_;
	reservar(getTam());

	for (int i = 0; i < getTam(); i++) coef_[i] = p.coef_[i];
}

// Constructor con vector de coeficientes
Polinomio::Polinomio(int coef[], const int tam)
{
	gr_ = tam - 1;
	reservar(tam);

	for (int i = 0; i < tam; i++)
		coef_[i] = coef[i];
}

// MÉTODOS GET's Y SET's

int *Polinomio::getCoef(void) const
{
	return coef_;
}

int Polinomio::getGr(void) const
{
	return gr_;
}

int Polinomio::getTam(void) const
{
	return gr_ + 1;
}

int Polinomio::Evaluar(int x) const
{
	int aux = 0;							// Almacenará x^exp
	Monomio m;

	for (int i = 0; i < getTam(); i++) {
		m.setCoef(coef_[i]);
		m.setExp(i);
		aux += m.Evaluar(x);
	}

	return aux;
}

// OPERADORES

// Operadores de inserción y extracción
ostream& operator<<(ostream &sout, const Polinomio&p)
{
	Monomio m;

	for (int i = 0; i < p.getTam(); i++){
		m.setCoef(p.coef_[i]);
		m.setExp(i);
		sout << m;
	}

	return sout;
}

istream& operator>>(istream &sin, Polinomio &p)
{
	int aux;

	cout << "\tGrado: ";
	sin >> p.gr_;
	p.liberar();
	p.reservar(p.getTam());

	for (int i = 0; i < p.getTam(); i++) {
		cout << "\tP[" << i << "]: ";
		sin >> aux;
		p.coef_[i] = aux;
	}

	return sin;
}

// Operadores sobrecargados
Polinomio Polinomio::operator=(const Polinomio &p) {

	this->liberar();
	this->reservar(p.getTam());
	this->gr_ = p.gr_;

	for (int i = 0; i < getTam(); i++)
		this->coef_[i] = p.coef_[i];

	return *this;
}

Polinomio Polinomio::operator+(const Polinomio &p) {
	int maxGr = 0;

	(this->gr_ > p.gr_) ? maxGr = this->gr_ : maxGr = p.gr_;
	Polinomio aux(maxGr);

	for (int i = 0; i < maxGr + 1; i++) {
		if ((i < this->getTam()) && (i < p.getTam()))
			aux.coef_[i] = this->coef_[i] + p.coef_[i];
		else if (i < p.getTam())
			aux.coef_[i] = p.coef_[i];
		else
			aux.coef_[i] = this->coef_[i];
	}

	return aux;
}

//Polinomio Polinomio::operator*(const Polinomio &p) {
//	Polinomio aux(this->gr_ + p.gr_);			// Polinomio donde el término mayor es un x^(gr1 + gr2)
//	aux.nulo();									// Iniciamos como 0 los valores del polinomio resultante
//
//	for (int i = 0; i < this->getTam(); i++)		// Recorro el polinomio this
//	for (int j = 0; j < p.getTam(); j++) {		// Vamos a multiplicar cada término del p
//		aux.coef_[i + j] += this->coef_[i] * p.coef_[j];
//	}
//
//	return aux;
//}

// Algoritmo Clásico
Polinomio Polinomio::operator*(const Polinomio &p) {
	Polinomio aux(this->gr_ + p.gr_);			// Polinomio donde el término mayor es un x^(gr1 + gr2)
	aux.nulo();									// Iniciamos como 0 los valores del polinomio resultante

	for (int i = 0; i < aux.getTam(); i++)					// Sumatorio de i = 0 hasta 2N
	for (int j = 0; j <= i && j < this->getTam(); j++) {	// Sumatorio de j = 0 hasta i, j < gr1
		if ((i - j) < p.getTam())							// Si (i - j) < gr2
			aux.coef_[i] += this->coef_[j] * p.coef_[i - j];// aux[i] = p[j]*q[i - j]
	}

	return aux;
}

// DESTRUCTOR
Polinomio::~Polinomio()
{
	gr_ = 0;
	liberar();
}
