#include "TestScurt.h"
#include "TestExtins.h"
#include <iostream>

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

int main()
{
	testAll();
	testAllExtins();
	
	if ( _CrtDumpMemoryLeaks() )
		std::cout << "Memory leaks!";
	else
		std::cout << "No memory leaks!";
	return 0;
}
