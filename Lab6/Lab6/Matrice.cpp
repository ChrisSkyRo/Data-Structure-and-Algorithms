#include "Matrice.h"
//#include <utility>
#include <exception>

using std::pair;


Matrice::Matrice( int m, int n )
{
	// complexity theta(m)
	if ( m <= 0 || n <= 0 )
		throw std::exception();
	rows = m;
	cols = n;
	Matrix = nullptr;
	Matrix = new node*[m];
	for ( int i = 0; i < m; i++ )
		Matrix[i] = nullptr;
}



int Matrice::nrLinii() const
{
	// complexity theta(1)
	return rows;
}


int Matrice::nrColoane() const
{
	// complexity theta(1)
	return cols;
}

int Matrice::hashFunction( int key ) const
{
	// complexity theta(1)
	return key;
}

TElem Matrice::element( int i, int j ) const
{
	// best case complexity omega(1)
	// worst case complexity o(cols)
	// average case complexity o(cols)
	if ( i < 0 || i >= rows || j < 0 || j >= cols )
		throw std::exception();

	i = hashFunction( i );

	if ( Matrix[i] != nullptr )
	{
		node *current = Matrix[i];
		while ( current != nullptr )
		{
			if ( current->col == j )
				return current->value;
			current = current->next;
		}
	}
	return NULL_TELEMENT;
}



TElem Matrice::modifica( int i, int j, TElem e )
{
	// best case complexity omega(1)
	// worst case complexity o(cols)
	// average case complexity o(cols)
	if ( i < 0 || i >= rows || j < 0 || j >= cols )
		throw std::exception();

	TElem old_value = NULL_TELEMENT;
	i = hashFunction( i );

	// delete node
	if ( e == 0 )
	{
		if ( Matrix[i] != nullptr )
		{
			node *current = Matrix[i];
			while ( current->next != nullptr )
			{
				if ( current->next->col == j )
				{
					node *to_delete = current->next;
					current->next = current->next->next;
					delete to_delete;
					break;
				}
				current = current->next;
			}
		}
	}
	// add new node or modify already existing one
	else
	{
		// empty line
		if ( Matrix[i] == nullptr )
		{
			// element to add
			node *new_element = new node;
			new_element->value = e;
			new_element->col = j;
			new_element->row = i;
			new_element->next = nullptr;
			Matrix[i] = new_element;
		}
		// line is not empty
		else
		{
			if ( Matrix[i]->col == j )
			{
				old_value = Matrix[i]->value;
				Matrix[i]->value = e;
			}
			else
			{
				// search node
				node *current = Matrix[i];
				while ( current->next != nullptr )
				{
					// change value if node already exists
					if ( current->col == j )
					{
						old_value = current->value;
						current->value = e;
						break;
					}
					current = current->next;
				}
				// create node
				if ( old_value == NULL_TELEMENT )
				{
					// node to add
					node *new_element = new node;
					new_element->value = e;
					new_element->col = j;
					new_element->row = i;
					new_element->next = nullptr;
					current->next = new_element;
				}
			}
		}
	}

	return old_value;
}

/**
* Pseudocod:
* 
* subalgoritm positionOf( elem ):
*	pos <- (-1, 1)
*	pentru i<-0, rows-1 executa
*		hashPos <- hashFunction(i)
*		*current <- Matrix[i]
*		catTimp current != nullptr executa
*			daca current.value == elem atunci
*				pos.first <- current.row
*				pos.second <- current.col
*				positionOf <- pos
*			current <- (*current).next
*	positionOf <- pos
* sfarsitSubalgoritm
*/

pair<int, int> Matrice::positionOf( TElem elem ) const
{
	// best case complexity omega(1)
	// worst case complexity o(rows*cols)
	// average case complexity o(rows*cols)
	pair<int, int> pos( -1, 1 );
	for ( int i = 0; i < rows; i++ )
	{
		int hashPos = hashFunction( i );
		// search node
		node *current = Matrix[i];
		while ( current != nullptr )
		{
			if ( current->value == elem )
			{
				pos.first = current->row;
				pos.second = current->col;
				return pos;
			}
			current = current->next;
		}
	}
	return pos;
}

Matrice::~Matrice()
{
	// best case complexity omega(rows)
	// worst case complexity o(rows*cols)
	// average case complexity o(rows*cols)
	for ( int i = 0; i < rows; i++ )
	{
		node *current = Matrix[i];
		while ( current != nullptr )
		{
			node *to_delete = current;
			current = current->next;
			delete to_delete;
		}
	}
	delete[] Matrix;
}

