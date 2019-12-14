#include "alphabet.h"
bool dif(char* A, char* B, char* result, int NS)
{
	int lengthA = 0;
	int lengthB = 0;
	char* a = A;
	char* b = B;
	while (*a != 0)
	{
		if (!(*(a - 1) == 0 && *a == '0'))
		{
			lengthA++;
		}
		a--;
	}
	while (*b != 0)
	{
		if (!(*(b - 1) == 0 && *b == '0'))
		{
			lengthB++;
		}
		b--;
	}
	a = A - lengthA + 1;
	b = B - lengthB + 1;
	if (lengthA < lengthB)
	{
		return 0;
	}
	if (lengthA == lengthB)
	{
		for (; *a != '\0' ;)
		{
			if (*a < *b) return 0;
			a++;
			b++;
		}
		//*result = '0';
	}

	char fz = '0';
	int i = 0;
	while (*(A - i) != 0 || *(B - i) != 0)
	{
		if (alphabet[*(A - i)] - alphabet[fz]  - alphabet[*(B - i)] < 0)
		{
			*result = alphabet2[alphabet[*(A - i)] - alphabet[fz] - alphabet[*(B - i)] + NS];
			result--;
			fz = '1';
		}
		else
		{
			*result = alphabet2[alphabet[*(A - i)] - alphabet[fz] - alphabet[*(B - i)]];
			result--;
			fz = '0';
		}
		++i;
	}
	if (fz!='0') *result = fz;
	return 1 ;
}