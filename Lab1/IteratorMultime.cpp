#include <iostream>
#include <exception>
#include "IteratorMultime.h"
#include "Multime.h"


IteratorMultime::IteratorMultime( const Multime& m ) : multime( m )
{
	// complexity = theta(1)
	current = 0;
	prim();
}


void IteratorMultime::prim()
{
	// complexity = O(multime.maxi-multime.mini)
	current = 0;
	while ( !valid() && current < multime.maxi - multime.mini + 1 )
		current++;
}


void IteratorMultime::urmator()
{
	// complexity = O(multime.maxi-multime.mini)
	if ( !valid() )
		throw std::exception();
	current++;
	while (!valid() && current < multime.maxi - multime.mini + 1)
		current++;
}


TElem IteratorMultime::element() const
{
	// complexity = theta(1)
	if (!valid())
		throw std::exception();
	return current + multime.mini;
}

bool IteratorMultime::valid() const
{
	// complexity = theta(1)
	if (current < multime.maxi - multime.mini + 1 && multime.reprezentare[current])
		return true;
	return false;
}
