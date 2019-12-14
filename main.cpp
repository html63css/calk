#include <iostream>

#include "input.h"
#include "interface.h"
#include "alphabet.h"

int main()
{
	setlocale(0,"");
	input();
	alphbt(NS);
	alphbt2(NS);
	interface();
	return 0;
}