#include "Colectie.h"
#include "IteratorColectie.h"
#include <exception>
#include <iostream>

using namespace std;


Colectie::Colectie()
{
	// complexity = theta(1)
	len = 0;
	usedSize = 0;
	maxSize = 2;
	head = new element[2];
	next = new int[2];
	first = 0;
	head[0].frequency = 0;
	head[1].frequency = 0;
}

void Colectie::resize()
{
	// complexity = theta(maxSize)
	maxSize *= 2;
	int *new_next = new int[maxSize];
	for ( int i = 0; i < maxSize / 2; i++ )
		new_next[i] = next[i];
	delete[] next;
	next = new_next;
	element *e = new element[maxSize];
	for ( int i = 0; i < maxSize / 2; i++ )
		e[i] = head[i];
	for ( int i = maxSize / 2; i < maxSize; i++ )
		e[i].frequency = 0;
	delete[] head;
	head = e;
}

int Colectie::firstEmpty()
{
	// best case complexity omega(1)
	// worst case complexity O(usedSize)
	// average complexity O(usedSize)
	int pos = 0;
	while ( head[pos].frequency != 0 )
		pos++;
	return pos;
}

void Colectie::adauga( TElem elem )
{
	// best case complexity omega(1)
	// worse case complexity O(usedSize)
	// average case complexity O(usedSize)
	
	// empty
	if ( vida() )
	{
		head[first].value = elem;
		head[first].frequency = 1;
		next[first] = -1;
		usedSize++;
	}
	// elem is on head
	else if ( head[first].value == elem )
		head[first].frequency++;
	// search for elem
	else
	{
		int pos = first;

		while ( next[pos] != -1)
		{
			if ( head[next[pos]].value == elem )
			{
				head[next[pos]].frequency++;
				break;
			}

			pos = next[pos];
		}
		// if next[pos] is -1 it iterated through the entire list and it didn't find elem
		// add elem to the end of the list
		if ( next[pos] == -1 )
		{
			if ( usedSize == maxSize )
				resize();

			int addpos = firstEmpty();
			next[pos] = addpos;
			head[addpos].value = elem;
			head[addpos].frequency = 1;
			next[addpos] = -1;
			usedSize++;
		}
	}

	len++;
}


bool Colectie::sterge( TElem elem )
{
	// best case complexity omega(1)
	// worse case complexity O(usedSize)
	// average case complexity O(usedSize)

	// empty
	if ( vida() )
		return false;
	// elem is on head
	else if ( head[first].value == elem )
	{
		head[first].frequency--;
		if ( !head[first].frequency )
			first = next[first] == -1 ? 0 : next[first];
		len--;
		return true;
	}
	// search for elem
	else
	{
		int pos = first;

		while ( next[pos] != -1 )
		{
			if ( head[next[pos]].value == elem )
			{
				head[next[pos]].frequency--;
				if ( !head[next[pos]].frequency )
					next[pos] = next[next[pos]];
				len--;
				return true;
			}

			pos = next[pos];
		}
	}
	
	return false;
}

/**
* Pseudocod:
* 
* subalgoritm elementeCuFrecventaData( frecventa ):
* 
*	daca frecventa <= 0 atunci
*		arunca exceptie
*	sfDaca
* 
*	daca vida() = true atunci
*		elementeCuFrecventaData <- 0
*	sfDaca
* 
*	count <- 0
*	pos <- first
*	catTimp pos != -1 executa
*		daca head[pos].frequency = frecventa atunci
*			count <- count + 1
*		sfDaca
*	sfCatTimp
* 
*	elementeCuFrecventaData <- count
* 
* sfarsitSubalgoritm
*/

int Colectie::elementeCuFrecventaData( int frecventa ) const
{
	// best case complexity omega(1)
	// worse case complexity O(usedSize)
	// average case complexity O(usedSize)

	if ( frecventa <= 0 )
		throw std::exception();

	if ( vida() )
		return 0;

	int count = 0;
	
	int pos = first;
	while ( pos != -1 )
	{
		if ( head[pos].frequency == frecventa )
			count++;
		pos = next[pos];
	}

	return count;
}

bool Colectie::cauta( TElem elem ) const
{
	// best case complexity omega(1)
	// worse case complexity O(usedSize)
	// average case complexity O(usedSize)

	if ( vida() )
		return false;

	int pos = first;
	while ( pos != -1 )
	{
		if ( head[pos].value == elem )
			return true;
		pos = next[pos];
	}

	return false;
}

int Colectie::nrAparitii( TElem elem ) const
{
	// best case complexity omega(1)
	// worse case complexity O(usedSize)
	// average case complexity O(usedSize)

	if ( vida() )
		return false;

	int pos = first;
	while ( pos != -1 )
	{
		if ( head[pos].value == elem )
			return head[pos].frequency;
		pos = next[pos];
	}
	
	return 0;
}


int Colectie::dim() const
{
	// complexity theta(1)
	return len;
}


bool Colectie::vida() const
{
	// complexity theta(1)
	return head[first].frequency == 0;
}

IteratorColectie Colectie::iterator() const
{
	// complexity theta(1)
	return  IteratorColectie( *this );
}


Colectie::~Colectie()
{
	// complexity theta(1)
	delete[] head;
	delete[] next;
}


