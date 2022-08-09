#include "IteratorColectie.h"
#include "Colectie.h"
#include <exception>

IteratorColectie::IteratorColectie( const Colectie &c ) : col( c )
{
	// complexity = theta(1)
	current = c.first;
	current_frequency = 1;
}

void IteratorColectie::prim()
{
	// complexity = theta(1)
	current = col.first;
	current_frequency = 1;
}


void IteratorColectie::urmator()
{
	// complexity = theta(1)
	if ( !valid() )
		throw std::exception();

	current_frequency++;
	if ( current_frequency > col.head[current].frequency )
	{
		current_frequency = 1;
		current = col.next[current];
	}
}


bool IteratorColectie::valid() const
{
	// complexity = theta(1)
	return current != -1 && col.head[current].frequency != 0;
}



TElem IteratorColectie::element() const
{
	// complexity = theta(1)
	if ( !valid() )
		throw std::exception();
	return col.head[current].value;
}
