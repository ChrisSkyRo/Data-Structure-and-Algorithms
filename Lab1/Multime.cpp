#include "Multime.h"
#include "IteratorMultime.h"

#include <iostream>

Multime::Multime()
{
	// complexity = theta(1)
	len = 0;
	mini = 0;
	maxi = -1;
	reprezentare = NULL;
}

void Multime::Resize( TElem elem )
{
	// complexity = theta(maxi-mini)
	int new_mini, new_maxi;
	new_mini = elem < mini ? elem : mini;
	new_maxi = elem > maxi ? elem : maxi;
	bool *new_reprezentare = new bool[new_maxi - new_mini + 1]{};
	for ( int i = mini; i <= maxi; i++ )
		new_reprezentare[i - new_mini] = reprezentare[i - mini];
	mini = new_mini;
	maxi = new_maxi;
	if ( reprezentare )
		delete[] reprezentare;
	reprezentare = new_reprezentare;
}

bool Multime::adauga( TElem elem )
{
	// complexity = O(maxi-mini)
	if ( elem < mini || elem > maxi )
		Resize( elem );

	if ( !reprezentare[elem - mini] )
	{
		reprezentare[elem - mini] = true;
		len++;
		return true;
	}

	return false;
}


bool Multime::sterge( TElem elem )
{
	// complexity = theta(1)
	if (!vida() && cauta(elem))
	{
		reprezentare[elem - mini] = false;
		len--;
		return true;
	}
	return false;
}


bool Multime::cauta( TElem elem ) const
{
	// complexity = theta(1)
	if ( elem >= mini && elem <= maxi && reprezentare[elem - mini] )
		return true;
	return false;
}


int Multime::dim() const
{
	// complexity = theta(1)
	return len;
}

bool Multime::vida() const
{
	// complexity = theta(1)
	if (len == 0)
		return true;
	return false;
}

Multime::~Multime()
{
	// complexity = theta(1)
	if ( reprezentare )
		delete[] reprezentare;
}

IteratorMultime Multime::iterator() const
{
	// complexity = theta(1)
	return IteratorMultime( *this );
}

