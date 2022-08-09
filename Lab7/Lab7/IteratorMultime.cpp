#include "IteratorMultime.h"
#include "Multime.h"
#include <exception>

IteratorMultime::IteratorMultime( const Multime &m ) : mult( m )
{
	// complexity O(h)
	current = m.root;

	if ( !current )
		return;

	while ( current->left != nullptr )
		current = current->left;
}

TElem IteratorMultime::element() const
{
	// complexity theta(1)
	if ( !valid() )
		throw std::exception();
	return current->e;
}

bool IteratorMultime::valid() const
{
	// complexity theta(1)
	return current != nullptr;
}

void IteratorMultime::urmator()
{
	// complexity O(h)
	if ( !valid() )
		throw std::exception();

	if ( current->right != nullptr )
	{
		current = current->right;
		while ( current->left != nullptr )
			current = current->left;
	}
	else
	{
		node *p = current->parent;
		while ( p != nullptr && p->right == current )
		{
			current = p;
			p = p->parent;
		}
		current = p;
	}
}

void IteratorMultime::prim()
{
	// complexity O(h)
	current = mult.root;
	
	if ( !current )
		return;

	while ( current->left != nullptr )
		current = current->left;
}

