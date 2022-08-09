#include <iostream>


#include "TestScurt.h"
#include "TestExtins.h"

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#include "Lista.h"
#include "IteratorLP.h"
#include <assert.h>

int main()
{
    testAll();
    testAllExtins();

    // Teste anterior()
    {
        Lista lista = Lista();
        lista.adaugaInceput( 1 );
        lista.adaugaInceput( 2 );
        lista.adaugaInceput( 3 );
        IteratorLP it = lista.cauta( 2 );
        assert( it.element() == 2 );
        it.anterior();
        assert( it.element() == 3 );
        it.anterior();
        assert( !it.valid() );
    }

    std::cout << "Finished LP Tests!" << '\n';
    if ( _CrtDumpMemoryLeaks() )
        std::cout << "Memory leaks!";
    else
        std::cout << "No memory leaks!";
    return 0;
}
