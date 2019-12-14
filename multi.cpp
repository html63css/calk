#include "alphabet.h"
bool multi(char* A, int lengthA, char* B, int lengthB, char* result, int NS)
{
	if (lengthA + lengthB >= 99) return 0;
	int bufer[100] = {0};
	int flage;
	char* a;
	char* b = B;
	int* buf = &bufer[99];
	int i = 0;
		while (b != B - lengthB)
		{
			int iB = alphabet[*b];
			buf = &bufer[99 - i];
			a = A;
			flage = 0;
				while (a != A - lengthA)
				{
					int iA = alphabet[*a];
					int bufe = *buf;
					*buf = bufe + iA * iB + flage < NS ? bufe + iA * iB + flage : (bufe + iA * iB + flage) - ((bufe + iA * iB + flage) / NS) * NS;
					flage = bufe + iA * iB + flage >= NS ? ((bufe + iA * iB + flage) / NS) : 0 ;
					--buf;
					--a;
				}
			*buf = flage;
			--b;
			++i;
		}
	//*buf = flage;
	i = 99;
		for (;i != 99 - lengthA - lengthB;)
		{
			*result = alphabet2[bufer[i]];
			--i;
			--result;
		}
	return 1;
}