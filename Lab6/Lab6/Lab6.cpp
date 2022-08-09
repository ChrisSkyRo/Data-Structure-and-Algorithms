#include <iostream>
#include "Matrice.h"
#include "TestExtins.h"
#include "TestScurt.h"

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

int main()
{

	testAll();
	testAllExtins();

	std::cout << "End" << '\n';
	if ( _CrtDumpMemoryLeaks() )
		std::cout << "Memory leaks!";
	else
		std::cout << "No memory leaks!";
	return 0;
}
