
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include "input.h"
#pragma warning(disable: 4996)
#define ESC 27
#define RIGHT 77
#define LEFT 75
#define UP 72
#define DOWN 80
int changeNS(int oldNS) {
	int position = 0;
	int error = 0;
	char ch;
	char* a = inputNS;
	inputNS[0] = 48 + (NS / 10);
	inputNS[1] = 48 + (NS % 10);
	inputNS[0] = lengthNS == 1 ? '0' : inputNS[0];
	lengthNS = 2;
	system("cls");
	do {
		for (int i = 0; i < lengthNS; i++)
		{
			if (position == i)
			{
				printf("|");
			}
			else printf(" ");
		}
		printf("\n");
		int i = 0;
		while (i < 2)
		{
			printf("%c",inputNS[i]);
			i++;
		}
		ch = error == 4 ? DOWN : getch();
		error = 0;
		switch (ch) {
		case(LEFT):
			if (position > 0) position--;
			break;
		case(RIGHT):
			if (position < lengthNS - 1) position++;
			break;
		case(UP):
			if (position == 0)
			{
				if (inputNS[0] != '3')	NS += 10;
			}
			if (position == 1)
			{
				if (inputNS[1] != '9')	NS += 1;
			}
			break;
		case(DOWN):
			if (position == 0)
			{
				if (inputNS[0] != '0')	NS -= 10;
			}
			if (position == 1)
			{
				if (inputNS[1] != '0')	NS -= 1;
			}
			break;
		case(ESC):
			break;
		}
		system("cls");
		NS = NS > 36 ? 36 : NS;
		NS = NS < 2 ? 2 : NS;
		inputNS[0] = 48 + (NS / 10);
		inputNS[1] = 48 + (NS % 10);
	} while (ch != ESC);

	return NS;
}