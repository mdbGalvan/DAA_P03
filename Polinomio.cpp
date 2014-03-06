#include "Polinomio.h"


// Liberar memoria para coef_
void Polinomio::nulo(){
	for (int i = 0; i < gr_ + 1; i++)
		coef_[i] = 0;
}

// Reservar memoria para coef_
void Polinomio::reservar(int n){
	coef_ = new (nothrow)int[n];
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

// Constructor Copia
Polinomio::Polinomio(const Polinomio &p)
{
	gr_ = p.gr_;
	reservar(gr_ + 1);

	for (int i = 0; i < gr_ + 1; i++) coef_[i] = p.coef_[i];
}

// Constructor con vector de coeficientes
Polinomio::Polinomio(int coef[], const int tam)
{
	gr_ = tam - 1;
	reservar(tam);

	for (int i = 0; i < tam; i++)
		coef_[i] = coef[i];
}

int Polinomio::Evaluar(int x) const
{
	int aux = 0;							// Almacenará x^exp
	Monomio m;

	for (int i = 0; i < gr_ + 1; i++) {
		m.setCoef(coef_[i]);
		m.setExp(i);
		aux += m.Evaluar(x);
	}

	return aux;
}

// Operadores de inserción y extracción
ostream& operator<<(ostream &sout, const Polinomio&p)
{
	Monomio m;

	for (int i = 0; i < p.gr_ + 1; i++){
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
	p.reservar(p.gr_ + 1);

	for (int i = 0; i < p.gr_ + 1; i++) {
		cout << "\tP[" << i << "]: ";
		sin >> aux;
		p.coef_[i] = aux;
	}

	return sin;
}

// Operadores sobrecargados
Polinomio Polinomio::operator+(const Polinomio &p) {
	int maxGr = 0;

	(this->gr_ > p.gr_) ? maxGr = this->gr_ : maxGr = p.gr_;
	Polinomio aux(maxGr);

	for (int i = 0; i < maxGr + 1; i++) {
		if ((i < this->gr_ + 1) && (i < p.gr_ + 1))
			aux.coef_[i] = this->coef_[i] + p.coef_[i];
		else if (i < p.gr_ + 1)
			aux.coef_[i] = p.coef_[i];
		else
			aux.coef_[i] = this->coef_[i];
	}

	return aux;
}

Polinomio Polinomio::operator*(const Polinomio &p) {
	Polinomio aux(this->gr_ + p.gr_);			// Polinomio donde el término mayor es un x^(gr1 + gr2)
	aux.nulo();									// Iniciamos como 0 los valores del polinomio resultante

	int a, b, c;
	for (int i = 0; i < this->gr_ + 1; i++)		// Recorro el polinomio this
	for (int j = 0; j < p.gr_ + 1; j++) {		// Vamos a multiplicar cada término del p
		aux.coef_[i + j] += this->coef_[i] * p.coef_[j];
	}

	return aux;
}

// DESTRUCTOR
Polinomio::~Polinomio()
{
	gr_ = 0;
	liberar();
}
