#pragma once

typedef int TElem;

typedef bool( *Relatie )( TElem, TElem );

//in implementarea operatiilor se va folosi functia (relatia) rel (de ex, pentru <=)
// va fi declarata in .h si implementata in .cpp ca functie externa colectiei
bool rel( TElem, TElem );

class IteratorMultime;

struct node
{
	TElem e;
	node *left, *right, *parent;
};

class Multime
{

	friend class IteratorMultime;

private:
	node *root;
	int len;

public:
	//constructorul implicit
	Multime();

	//adauga un element in multime
	//returneaza adevarat daca elementul a fost adaugat (nu exista deja in multime)
	bool adauga( TElem e );

	//sterge un element din multime
	//returneaza adevarat daca elementul a existat si a fost sters
	bool sterge( TElem e );

	//verifica daca un element se afla in multime
	bool cauta( TElem elem ) const;

	// adauga toate elementele din multimea b in multimea curenta
	void reuniune( const Multime &b );

	//intoarce numarul de elemente din multime;
	int dim() const;

	//verifica daca multimea e vida;
	bool vida() const;

	//returneaza un iterator pe multime
	IteratorMultime iterator() const;

	// destructorul multimii
	~Multime();

};

