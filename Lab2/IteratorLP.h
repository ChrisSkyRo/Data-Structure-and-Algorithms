#ifndef ITERATORLP_H_

#define ITERATORLP_H_

#include "Lista.h"

class IteratorLP
{
	friend class Lista;
private:

	//constructorul primeste o referinta catre Container
	//iteratorul va referi primul element din container

	IteratorLP( const Lista &lista );

	//contine o referinta catre containerul pe care il itereaza
	const Lista &lista;

	/* aici e reprezentarea  specifica a iteratorului */
	node *current;

public:

	//reseteaza pozitia iteratorului la inceputul containerului
	void prim();

	//muta iteratorul in container
	// arunca exceptie daca iteratorul nu e valid
	void urmator();

	//modifica elementul curent referit de iterator la elementul anterior, sau, in cazul in care elementul
	//curent a fost primul, transforma iteratorul in unul nevalid
	//arunca excepte in cazul in care iteratorul nu este valid
	void anterior();

	//verifica daca iteratorul e valid (indica un element al containerului)
	bool valid() const;

	//returneaza valoarea elementului din container referit de iterator
	//arunca exceptie daca iteratorul nu e valid
	TElem element() const;

};

#endif
