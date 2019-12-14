#include "alphabet.h"
void sum(char* A, char* B,char* result,int NS)
{
	char fz = '0';
	int i=0;
	while ( *(A - i) != 0 || *(B - i) != 0 )
	{
		if (alphabet[fz] + alphabet[*(A - i)] + alphabet[*(B - i)] < NS)
		{
			*result = alphabet2[ alphabet[fz] + alphabet[*(A - i)] + alphabet[*(B - i)] ];
			result--;
			fz = '0';
		}
		else
		{
			*result =  alphabet2[ alphabet[fz] + alphabet[*(A - i)] + alphabet[*(B - i)] - NS ];
			result--;
			fz = '1';
		}
		++i;
	}
	if (fz != '0') *result = fz;
}