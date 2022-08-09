#include "IteratorLP.h"
#include "Lista.h"
#include <exception>

IteratorLP::IteratorLP( const Lista &l ) :lista( l )
{
	//complexity = theta(1)
	current = l.head;
}

void IteratorLP::prim()
{
	//complexity = theta(1)
	current = lista.head;
}

void IteratorLP::urmator()
{
	//complexity = theta(1)

	if ( !valid() )
		throw std::exception();
	current = current->next;
}

/**
* Pseudocod:
*
* subalgoritm anterior():
* 
*	daca valid() == false atunci
*		arunca exceptie()
*	sfDaca
*	
*	daca lista.head == current atunci
*		current <- nullptr
*	altfel
		node *previous <- lista.head
		cat timp (*previous).next != current executa
			previous <- (*previous).next
		sfCatTimp
*	sfDaca
* 
* sfSubalgoritm
*/
void IteratorLP::anterior()
{
	//complexity = theta(n), unde n este pozitia elementului current
	if ( !valid() )
		throw std::exception();

	if ( lista.head == current )
		current = nullptr;
	else
	{
		node *previous = lista.head;
		while ( previous->next != current )
			previous = previous->next;
		current = previous;
	}
}

bool IteratorLP::valid() const
{
	//complexity = theta(1)
	return current != nullptr;
}

TElem IteratorLP::element() const
{
	//complexity = theta(1)
	if ( !valid() )
		throw std::exception();
	return current->value;
}


