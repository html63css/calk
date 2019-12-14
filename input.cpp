#include <stdio.h>
#include <conio.h>
#include <iostream>
#define ENTER 13
#pragma warning(disable: 4996)

char A[50], B[50];
int lengthA, lengthB;

int NS;
char inputNS[2];
int lengthNS;

void input() {
	char* a;
	char* b;
	char* ins;
	int error;
	char ch;
	char limit1 = '0';
	char limit2;
	do {
		ins = inputNS;
		error = 0;
		lengthNS = 0;

		printf("¬ведите ——(ввести можно только 1-2 цифры):\n");
		do
		{
			ch = getch();
			if (ch >= '0' && ch <= '9') printf("%c", ch);
			switch ((ch >= '0') && (ch <= '9') && (ins != &inputNS[2]))
			{
			case(true):
				*ins = ch;
				ins++;
				++lengthNS;
				break;
			case(false):
				if (ch == ENTER && ins != inputNS) { error = 3; }
				else error = 1;
				break;
			}
		} while (error != 1 && error != 3);
		if (error == 1)
		{
			system("cls");
			printf("ќшибка. ¬ведите снова\n");
		}

		if (error == 3) {
			for (int i = 0; i < lengthNS; i++)
			{
				NS *= 10;
				NS += (inputNS[i] - (int)'0');
			}
			if (NS < 2 || NS>36) {
				system("cls");
				printf("„исло должно быть меньше 36 и больше 2\n");
				NS = 0;
				error = 1;
			}
		}

	} while (error != 3);

	if (NS > 10) {
		limit2 = NS - 11 + 'A';
	}
	else {
		limit2 = (NS - 1) + '0';
	}

	system("cls");
	do {
		a = &A[49];
		error = 0;
		printf("¬ведите первое число(цифры от 0 до %c):\n", limit2);
		do
		{
			ch = getch();
			if (toupper(ch) >= limit1 && toupper(ch) <= limit2)
			{
				for (int j = 49 - lengthA; j <= 49; j++)
				{
					char* x = &A[j];
					char x2 = *x;
					*x = *(x + 1);
					*(x + 1) = x2;				
				}
			}
			printf("%c", toupper(ch));
			if (ch < '0' || ch>'9') ch = toupper(ch);
			switch (ch >= limit1 && ch <= limit2 && lengthA < 50)
			{
			case(true):
				*a = ch;
				++lengthA;
				break;
			case(false):
				if (ch == ENTER && A[49] != 0) 
				{ 
					error = 3; 
				}
				else
				{
					for (int j = 49; j >= 0; j--)
					{
						A[j] = 0;
					}
					error = 1;
					lengthA = 0;
				}
				break;
			}
		} while (error != 1 && error != 3);
		if (error == 1)
		{

			system("cls");
			printf("ќшибка. ¬ведите снова\n");
			for (int i = 0; i <= 49; i++)
			{
				A[i] = 0;
			}
		}
	} while (error != 3);
	system("cls");
	do {
		b = &B[49];
		error = 0;
		printf("¬ведите второе число(цифры от 0 до %c):\n", limit2);
		do
		{
			ch = getch();
			if (toupper(ch) >= limit1 && toupper(ch) <= limit2)
			{
				for (int j = 49 - lengthB; j <= 49; j++)
				{
					char* x = &B[j];
					char x2 = *x;
					*x = *(x + 1);
					*(x + 1) = x2;
				}
			}
			printf("%c", toupper(ch));
			if (ch < '0' || ch>'9') ch = toupper(ch);
			switch (ch >= limit1 && ch <= limit2 && lengthB < 50)
			{
			case(true):
				*b = ch;
				++lengthB;
				break;
			case(false):
				if (ch == ENTER && B[49] != 0) 
				{ 
					error = 3; 
				}
				else
				{
					for (int j = 49; j >= 0; j--)
					{
						B[j] = 0;
					}
					error = 1;
					lengthB = 0;
				}
				break;
			}
		} while (error != 1 && error != 3);
		if (error == 1)
		{
			system("cls");
			printf("ќшибка. ¬ведите снова\n");
		}
	} while (error != 3);
	printf("\n");
}
