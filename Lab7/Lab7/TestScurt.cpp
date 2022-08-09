#include "TestScurt.h"
#include "Multime.h"
#include <assert.h>
#include "IteratorMultime.h"

void testAll()
{ //apelam fiecare functie sa vedem daca exista
	int vverif[5];
	int iverif;
	TElem e;

	Multime m1;
	assert( m1.adauga( 5 ) == true );
	assert( m1.adauga( 1 ) == true );
	assert( m1.adauga( 10 ) == true );
	IteratorMultime im1 = m1.iterator();
	im1.prim();
	iverif = 0;
	e = im1.element();
	vverif[iverif++] = e;
	im1.urmator();
	while ( im1.valid() )
	{
		assert( rel( e, im1.element() ) );
		e = im1.element();
		vverif[iverif++] = e;
		im1.urmator();
	}
	assert( ( vverif[0] == 1 ) && ( vverif[1] == 5 ) && ( vverif[2] == 10 ) );

	
	Multime m;
	//return;
	assert( m.vida() == true );
	assert( m.dim() == 0 ); //adaug niste elemente
	assert( m.adauga( 5 ) == true );
	assert( m.adauga( 1 ) == true );
	assert( m.adauga( 10 ) == true );
	assert( m.adauga( 7 ) == true );
	assert( m.adauga( 1 ) == false );
	assert( m.adauga( 10 ) == false );
	assert( m.adauga( -3 ) == true );
	assert( m.dim() == 5 );
	assert( m.cauta( 10 ) == true );
	assert( m.cauta( 16 ) == false );
	assert( m.sterge( 1 ) == true );
	assert( m.sterge( 6 ) == false );
	assert( m.dim() == 4 );

	IteratorMultime im = m.iterator();
	iverif = 0;
	im.prim();
	e = im.element();
	vverif[iverif++] = e;
	im.urmator();
	while ( im.valid() )
	{
		assert( rel( e, im.element() ) );
		e = im.element();
		vverif[iverif++] = e;
		im.urmator();
	}
	assert( ( vverif[3] == 10 ) && ( vverif[2] == 7 ) && ( vverif[1] == 5 ) && ( vverif[0] == -3 ) );

	Multime A, B;
	A.adauga( 1 );
	A.adauga( 2 );
	A.adauga( 3 );
	B.adauga( 4 );
	B.adauga( 5 );
	B.adauga( 6 );
	A.reuniune( B );
	assert( A.dim() == 6 );
	IteratorMultime ir = A.iterator();
	TElem reuniune[6];
	int pos = 0;
	ir.prim();
	e = ir.element();
	reuniune[pos++] = e;
	ir.urmator();
	while ( ir.valid() )
	{
		assert( rel( e, ir.element() ) );
		e = ir.element();
		reuniune[pos++] = e;
		ir.urmator();
	}
	assert( ( reuniune[0] == 1 ) && ( reuniune[1] == 2 ) && ( reuniune[2] == 3 ) && ( reuniune[3] == 4 ) && ( reuniune[4] == 5 ) && ( reuniune[5] == 6 ) );
}
