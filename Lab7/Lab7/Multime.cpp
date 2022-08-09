#include "Multime.h"
#include "IteratorMultime.h"
#include <iostream>

using namespace std;

//o posibila relatie
bool rel( TElem e1, TElem e2 )
{
	if ( e1 <= e2 )
	{
		return true;
	}
	else
	{
		return false;
	}
}

Multime::Multime()
{
	// complexity theta(1)
	root = nullptr;
	len = 0;
}


bool Multime::adauga( TElem elem )
{
	// complexity O(h)
	if ( vida() )
	{
		node *new_node = new node;
		new_node->e = elem;
		new_node->left = nullptr;
		new_node->right = nullptr;
		new_node->parent = nullptr;
		root = new_node;
	}
	else
	{
		node *current = root;
		bool inserted = false;
		while ( !inserted )
		{
			// if the value already exists it doesn't add it
			if ( current->e == elem )
				return false;
			// if the value is less than current try to add it to the left side
			else if ( rel( elem, current->e ) )
			{
				// if there is no node to the left, create one and add the value
				if ( !current->left )
				{
					node *new_node = new node;
					new_node->e = elem;
					new_node->left = nullptr;
					new_node->right = nullptr;
					new_node->parent = current;
					current->left = new_node;
					inserted = true;
				}
				else current = current->left;
			}
			// if the value is greater than current try to add it to the left side
			else
			{
				// if there is no node to the right, create one and add the value
				if ( !current->right )
				{
					node *new_node = new node;
					new_node->e = elem;
					new_node->left = nullptr;
					new_node->right = nullptr;
					new_node->parent = current;
					current->right = new_node;
					inserted = true;
				}
				else current = current->right;
			}
		}
	}

	len++;
	return true;
}


bool Multime::sterge( TElem elem )
{
	if ( !vida() )
	{
		// value to delete is on root
		if ( root->e == elem )
		{
			node *to_delete = root;
			// there is no right branch
			// the left branch becomes the root
			if ( root->right == nullptr )
			{
				// insert the left branch if valid
				if ( root->left != nullptr )
				{
					root->left->parent = nullptr;
					root = root->left;
				}
				else root = nullptr;
			}
			// the right branch exists and it replaces the deleted node
			else
			{
				// insert the left branch if valid
				if ( root->left != nullptr )
				{
					// search for the leftmost position in the right branch to insert the left branch there
					node *to_insert = root->right;
					while ( to_insert->left != nullptr )
						to_insert = to_insert->left;
					// insert the left branch
					to_insert->left = root->left;
					root->left->parent = to_insert;
				}
				// the right branch become the root
				root->right->parent = nullptr;
				root = root->right;
			}
			delete to_delete;
			len--;
			return true;
		}
		// search for the value to delete
		else
		{
			node *current = root;
			while ( current != nullptr )
			{
				if ( current->e == elem )
				{
					node *to_delete = current;
					bool right = false;
					// check whether the deleted node is on the left branch or the right branch relative to the parent
					if ( current->parent->right == current )
						right = true;
					// there is no right branch
					// the left branch becomes the root
					if ( current->right == nullptr )
					{
						// insert the left branch if valid
						if ( current->left != nullptr )
						{
							if ( right )
								current->parent->right = current->left;
							else current->parent->left = current->left;
							current->left->parent = current->parent;
						}
						else
						{
							if ( right )
								current->parent->right = nullptr;
							else current->parent->left = nullptr;
						}
					}
					// the right branch exists and it replaces the deleted node
					else
					{
						// insert the left branch if valid
						if ( current->left != nullptr )
						{
							// search for the leftmost position in the right branch to insert the left branch there
							node *to_insert = current->right;
							while ( to_insert->left != nullptr )
								to_insert = to_insert->left;
							// insert the left branch
							to_insert->left = current->left;
							current->left->parent = to_insert;
						}
						// the right branch replaces the deleted node
						current->right->parent = current->parent;
						if ( right )
							current->parent->right = current->right;
						else current->parent->left = current->right;
					}

					delete to_delete;
					len--;
					return true;
				}
				// search the left branch
				else if ( rel( elem, current->e ) )
					current = current->left;
				// search the right branch
				else current = current->right;
			}
		}
	}

	return false;
}


bool Multime::cauta( TElem elem ) const
{
	// complexity O(h)
	if ( !vida() )
	{
		node *current = root;
		while ( current != nullptr )
		{
			if ( current->e == elem )
				return true;
			// search the left branch
			else if ( rel( elem, current->e ) )
				current = current->left;
			// search the right branch
			else current = current->right;
		}
	}

	return false;
}
/*
	Pseudocod:

	subalgoritm reuniune( b ):
		it <- b.iterator()
		it.prim()
		catTimp it.valid() executa:
			adauga( it.element() )
			it.urmator()
		sfCatTimp
	sfarsitSubalgoritm
*/
void Multime::reuniune( const Multime &b )
{
	// complexity O(h*b.len)
	IteratorMultime it = b.iterator();
	it.prim();
	while ( it.valid() )
	{
		adauga( it.element() );
		it.urmator();
	}
}


int Multime::dim() const
{
	// complexity theta(1)
	return len;
}



bool Multime::vida() const
{
	// complexity theta(1)
	return root == nullptr;
}

IteratorMultime Multime::iterator() const
{
	// complexity O(h)
	return IteratorMultime( *this );
}


Multime::~Multime()
{
	// complexity O((len+1)*h)
	IteratorMultime it = iterator();
	it.prim();
	int loc = 0;
	node **to_delete = new node*[len+1];
	while ( it.valid() )
	{
		to_delete[loc++] = it.current;
		it.urmator();
	}
	while ( loc )
	{
		loc--;
		delete to_delete[loc];
	}
	delete[] to_delete;
}






