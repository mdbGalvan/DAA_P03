#include "Polinomio.h"


// Liberar memoria para coef_
void Polinomio::nulo(){
	for (int i = 0; i < getTam(); i++)
		coef_[i] = 0;
}

void Polinomio::aleatorio(const int min, const int max){
	//srand(time(NULL));
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

int Polinomio::getCoef(int item) const
{
	return coef_[item];
}

int Polinomio::getGr(void) const
{
	return gr_;
}

int Polinomio::getTam(void) const
{
	return gr_ + 1;
}

void Polinomio::setCoef(int item, int value)
{
	coef_[item] = value;
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

Polinomio Polinomio::mult(Polinomio q, int N)
{
	Polinomio pl(N / 2), ql(N / 2), ph(N / 2), qh(N / 2);
	Polinomio aux1(N / 2), aux2(N / 2);
	Polinomio r(2 * N - 2);							
	Polinomio rl(N), rm(N), rh(N);
	int i;

	if (N == 1)												// Si ya no se puede dividir más devolvemos r = p * q
	{
		r.setCoef(0, getCoef(0) * q.getCoef(0));
		return r;
	}

	for (i = 0; i < N / 2; i++)								// pl = p, i = 0, ..., n/2 - 1
	{
		pl.setCoef(i, getCoef(i));
		ql.setCoef(i, q.getCoef(i));
	}

	for (i = N / 2; i < N; i++)								// ph*x^n/2 = p, i = n/2, ..., n - 1
	{
		ph.setCoef(i - N / 2, getCoef(i));
		qh.setCoef(i - N / 2, q.getCoef(i));
	}

	for (i = 0; i < N / 2; i++) aux1.setCoef(i, pl.getCoef(i) + ph.getCoef(i));	
	for (i = 0; i < N / 2; i++) aux2.setCoef(i, ql.getCoef(i) + qh.getCoef(i));	

	rm = aux1.mult(aux2, N / 2);								// rm = rm = (pl + qh)(ql + ph) = aux1 * aux2
	rl = pl.mult(ql, N / 2);									// rl = pl * ql
	rh = ph.mult(qh, N / 2);									// rh = ph * qh 

	for (i = 0; i < N - 1; i++) r.setCoef(i, rl.getCoef(i));				// r; i = 0, ..., N - 2
	r.setCoef(N - 1, 0);
	for (i = 0; i < N - 1; i++) r.setCoef(N + i, rh.getCoef(i));			// r; i = N, ..., 
	for (i = 0; i < N - 1; i++) r.setCoef(N / 2 + i, r.getCoef(N / 2 + i) + rm.getCoef(i) - (rl.getCoef(i) + rh.getCoef(i)));

	return r;
}

Polinomio mult(Polinomio p, Polinomio q, int N)
{
	// p = p0 + p1x + ... + p(n-1)x^(n-1)
	int *pl = new int[N / 2], *ql = new int[N / 2], *ph = new int[N / 2], *qh = new int[N / 2];
	int *aux1 = new int[N / 2], *aux2 = new int[N / 2];		// aux1 = (pl + qh), aux2 = (ql + ph)
	Polinomio r(2 * N - 2);									// Resultado del producto
	int *rl = new int[N], *rm = new int[N], *rh = new int[N];	// rl = pl * ql, rh = ph * qh, rm = (pl + qh)(ql + ph)
	int i;

	if (N == 1)												// Si ya no se puede dividir más devolvemos r = p * q
	{
		r.setCoef(0, p.getCoef(0) * q.getCoef(0));
		return r;
	}

	for (i = 0; i < N / 2; i++)								// pl = p, i = 0, ..., n/2 - 1
	{
		pl[i] = p.getCoef(i);
		ql[i] = q.getCoef(i);
	}

	for (i = N / 2; i < N; i++)								// ph*x^n/2 = p, i = n/2, ..., n - 1
	{
		ph[i - N / 2] = p.getCoef(i);
		qh[i - N / 2] = q.getCoef(i);
	}

	for (i = 0; i < N / 2; i++) aux1[i] = pl[i] + ph[i];	// rm = aux1 * aux2, t1 = (pl + ph)
	for (i = 0; i < N / 2; i++) aux2[i] = ql[i] + qh[i];	// rm = aux1 * aux2, aux2 = (ql + qh)

	rm = mult(aux1, aux2, N / 2);							// rm = rm = (pl + qh)(ql + ph) = aux1 * aux2
	rl = mult(pl, ql, N / 2);								// rl = pl * ql
	rh = mult(ph, qh, N / 2);								// rh = ph * qh 

	for (i = 0; i < N - 1; i++) r.setCoef(i, rl[i]);				// r; i = 0, ..., N - 2
	r.setCoef(N - 1, 0);
	for (i = 0; i < N - 1; i++) r.setCoef(N + i, rh[i]);			// r; i = N, ..., 
	for (i = 0; i < N - 1; i++) r.setCoef(N / 2 + i, r.getCoef(N/2+i) + rm[i] - (rl[i] + rh[i]));

	return r;
}

int* mult(int p[], int q[], int N)		// N - 1 = grado
{
 														// p = p0 + p1x + ... + p(n-1)x^(n-1)
	int *pl = new int[N / 2], *ql = new int[N / 2], *ph = new int[N / 2], *qh = new int[N / 2];
	int *aux1 = new int[N / 2], *aux2 = new int[N / 2];		// aux1 = (pl + qh), aux2 = (ql + ph)
	int *r = new int[2 * N - 2];							// Resultado del producto
	int *rl = new int[N], *rm = new int[N], *rh = new int[N];	// rl = pl * ql, rh = ph * qh, rm = (pl + qh)(ql + ph)
	int i;

	if (N == 1)												// Si ya no se puede dividir más devolvemos r = p * q
	{
		r[0] = p[0] * q[0];
		return r;
	}

	for (i = 0; i < N / 2; i++)								// pl = p, i = 0, ..., n/2 - 1
	{
		pl[i] = p[i];
		ql[i] = q[i];
	}

	for (i = N / 2; i < N; i++)								// ph*x^n/2 = p, i = n/2, ..., n - 1
	{
		ph[i - N / 2] = p[i];
		qh[i - N / 2] = q[i];
	}

	for (i = 0; i < N / 2; i++) aux1[i] = pl[i] + ph[i];	// rm = aux1 * aux2, t1 = (pl + ph)
	for (i = 0; i < N / 2; i++) aux2[i] = ql[i] + qh[i];	// rm = aux1 * aux2, aux2 = (ql + qh)

	rm = mult(aux1, aux2, N / 2);							// rm = rm = (pl + qh)(ql + ph) = aux1 * aux2
	rl = mult(pl, ql, N / 2);								// rl = pl * ql
	rh = mult(ph, qh, N / 2);								// rh = ph * qh 

	for (i = 0; i < N - 1; i++) r[i] = rl[i];				// r; i = 0, ..., N - 2
	r[N - 1] = 0;
	for (i = 0; i < N - 1; i++) r[N + i] = rh[i];			// r; i = N, ..., 
	for (i = 0; i < N - 1; i++) r[N / 2 + i] += rm[i] - (rl[i] + rh[i]);

	return r;
}

// DESTRUCTOR
Polinomio::~Polinomio()
{
	gr_ = 0;
	liberar();
}
