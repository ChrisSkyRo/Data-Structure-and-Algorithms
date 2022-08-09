
#include <exception>

#include "IteratorLP.h"
#include "Lista.h"

Lista::Lista()
{
	//complexity theta(1)
	len = 0;
	head = nullptr;
	tail = nullptr;
}

int Lista::dim() const
{
	//complexity theta(1)
	return len;
}


bool Lista::vida() const
{
	//complexity = theta(1)
	return head == nullptr;
}

IteratorLP Lista::prim() const
{
	//complexity = theta(1)
	IteratorLP it = IteratorLP( *this );
	it.current = head;
	return it;
}

TElem Lista::element( IteratorLP poz ) const
{
	//complexity = theta(1)
	if ( !poz.valid() )
		throw std::exception();
	return poz.element();
}

TElem Lista::sterge( IteratorLP &poz )
{
	//complexity = theta(n), n = nr de elem din lista
	if ( !poz.valid() )
		throw std::exception();

	IteratorLP it = IteratorLP( *this );
	TElem e = poz.element();
	it.prim();

	if ( poz.current == head )
	{
		head = head->next;
	}
	else
	{
		while ( it.current->next != poz.current )
			it.urmator();
		it.current->next = poz.current->next;
	}
	if ( poz.current == tail )
		tail = it.current;
	delete poz.current;
	len--;
	return e;
}

IteratorLP Lista::cauta( TElem e ) const
{
	//complexity = O(n), n = nr de elem din lista
	IteratorLP it = IteratorLP( *this );
	it.prim();
	while ( it.valid() && it.element() != e )
		it.urmator();

	return it;
}

TElem Lista::modifica( IteratorLP poz, TElem e )
{
	//complexity = theta(1)
	if ( !poz.valid() )
		throw std::exception();

	TElem el = poz.element();
	poz.current->value = e;

	return el;
}

void Lista::adauga( IteratorLP &poz, TElem e )
{
	//complexity = theta(1)
	if ( !poz.valid() )
		throw std::exception();
	len++;
	node *new_node = new node;
	new_node->next = poz.current->next;
	new_node->value = e;

	if ( tail == poz.current )
		tail = new_node;

	poz.current->next = new_node;
	poz.urmator();
}

void Lista::adaugaInceput( TElem e )
{
	//complexity = theta(1)
	len++;
	node *new_node = new node;
	new_node->value = e;
	new_node->next = nullptr;

	if ( vida() )
	{
		head = new_node;
		tail = head;
	}
	else
	{
		new_node->next = head;
		head = new_node;
	}
}

void Lista::adaugaSfarsit( TElem e )
{
	//complexity = theta(1)
	len++;
	node *new_node = new node;
	new_node->value = e;
	new_node->next = nullptr;

	if ( vida() )
	{
		head = new_node;
		tail = head;
	}
	else
	{
		tail->next = new_node;
		tail = new_node;
	}
}

Lista::~Lista()
{
	//complexity = theta(n), n = nr de elem din lista
	while ( head != nullptr )
	{
		node *e = head;
		head = head->next;
		delete e;
	}
}
