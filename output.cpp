#include <stdio.h>

#include "input.h"

void output(char* out, int e = 49) {
	int i = 0;
	int flage = 1;
	for (int j = 0; j <= e; j++)
	{
		if ((out[j] == '0' || out[j] == 0) && flage == 1)
		{
			out[j] = 0;
		}
		else
		{
			++i;
			flage = 0;
		}
	}
	for (int j = e + 1 - i; j <= e; j++)
	{
		printf("%c",out[j]);
	}

	if ( i == 0)
	{
		printf("0");
		out[e] = '0';
	}
}