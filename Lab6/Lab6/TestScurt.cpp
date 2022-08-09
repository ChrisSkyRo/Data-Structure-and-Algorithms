#include "TestScurt.h"
#include <assert.h>
#include "Matrice.h"
#include <iostream>
#include <utility>

using namespace std;

void testAll()
{ //apelam fiecare functie sa vedem daca exista
	Matrice m( 4, 4 );
	assert( m.nrLinii() == 4 );
	assert( m.nrColoane() == 4 );
	//adaug niste elemente
	m.modifica( 1, 1, 5 );
	assert( m.element( 1, 1 ) == 5 );
	m.modifica( 1, 1, 6 );
	assert( m.element( 1, 2 ) == NULL_TELEMENT );
	// positionOf tests
	pair<int, int> p = m.positionOf( 6 );
	assert( p.first == 1 && p.second == 1 );
	p = m.positionOf( 5 );
	assert( p.first == -1 && p.second == 1 );
}
