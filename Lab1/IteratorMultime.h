#ifndef ITERATORMULTIME_H_

#define ITERATORMULTIME_H_

class Multime;
typedef int TElem;

class IteratorMultime
{
	friend class Multime;
private:

	//constructorul primeste o referinta catre Container
	//iteratorul va referi primul element din container
	IteratorMultime( const Multime& m );

	//contine o referinta catre containerul pe care il itereaza
	const Multime& multime;
	/* aici e reprezentarea  specifica a iteratorului */
	int current;

public:

	//reseteaza pozitia iteratorului la inceputul containerului
	void prim();

	//muta iteratorul in container
	// arunca exceptie daca iteratorul nu e valid
	void urmator();

	//verifica daca iteratorul e valid (indica un element al containerului)
	bool valid() const;

	//returneaza valoarea elementului din container referit de iterator
	//arunca exceptie daca iteratorul nu e valid
	TElem element() const;
};
#endif
