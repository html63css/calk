#include <iostream>

#include "alphabet.h"
#include "multi.h"
#include "sum.h"

#pragma warning(disable: 4996)

void translation(char* number, int lengthNumber, char inputNS[], int NS)
{
//	char bufernumb10[100];
//	char cloneNumb10[100];
	char numb10[100];
	char cNumber[2];
	int iArr[100] = { 0 };
	int j = 0;
	int i = 1;
		for (int i = 0; i < 49; ++i)
		{
			iArr[99 - j] = alphabet[*(number - i)];
			++j;
		}
	itoa(iArr[99],cNumber,10);

}