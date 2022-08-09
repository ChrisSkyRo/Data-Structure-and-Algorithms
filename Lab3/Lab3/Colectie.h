#pragma once

#define NULL_TELEM -1
typedef int TElem;

class IteratorColectie;

struct element
{
	TElem value;
	int frequency;
};

class Colectie
{
	friend class IteratorColectie;

private:
	/* aici e reprezentarea */
	int len;
	int maxSize, usedSize;
	element *head;
	int *next;
	int first;
	//node *head;

public:
	//constructorul implicit
	Colectie();

	void resize();

	int firstEmpty();

	int elementeCuFrecventaData( int frecventa ) const;

	//adauga un element in colectie
	void adauga( TElem e );

	//sterge o aparitie a unui element din colectie
	//returneaza adevarat daca s-a putut sterge
	bool sterge( TElem e );

	//verifica daca un element se afla in colectie
	bool cauta( TElem elem ) const;

	//returneaza numar de aparitii ale unui element in colectie
	int nrAparitii( TElem elem ) const;


	//intoarce numarul de elemente din colectie;
	int dim() const;

	//verifica daca colectia e vida;
	bool vida() const;

	//returneaza un iterator pe colectie
	IteratorColectie iterator() const;

	// destructorul colectiei
	~Colectie();

};

