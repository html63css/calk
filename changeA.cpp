#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#include "input.h"
#include "sum.h"
#include "dif.h"
#include "output.h"
#include "alphabet.h"

#pragma warning(disable: 4996)
#define ESC 27
#define RIGHT 77
#define LEFT 75
#define UP 72
#define DOWN 80
#define ENTER 13
#define BS 8

char operand2[50];
char _operand2 [50]; 
int _lengthOPERAND2;
char SUMOPERAND2[50];
char DIFOPERAND2[50];
int lengthOPERAND2;
int lengthDIFOPERAND2;
int lengthSUMOPERAND2;
int flage = 0;
void add(int position,char* a)
{
	int i = 0 ;
	while ( i != 49 - position)
	{
		char e = *(a + i) == 0 ? '0' : *(a + i);
		*(a + i) = *(a + i + 1);
		*(a + i + 1) = e;
		i++;
	}
	++lengthA;
	i = 0;
	while (*(a + i) == '0')
	{
		*(a + i) = 0;
		i++;
	}
}

void remove(int position, char* a)
{

	int i = 49 - lengthA + 1 + position;
	*(a + i) = 0;
	while (i != 1)
	{
		char e = *(a + i) //== 0 ? '0' : *(a + i)
			;
		*(a + i) = *(a + i - 1);
		*(a + i - 1) = e;
		i--;
	}
	while (*(a + i) == '0')
	{
		*(a + i) = 0;
		i++;
	}
	lengthA--;
}

void changeA(char* A,int NS)
{
	int position = 0;
	int i;
	int error = 0;
	char ch;
	char* a = A;
	system("cls");
	do {
		for (int i = 0; i <= 49; i++)
		{
			SUMOPERAND2[i] = 0;
			DIFOPERAND2[i] = 0;
		}
		for (int i = 0; i < lengthA; i++) 
		{
			if (position == i)
			{
				printf("|");
			}
			else printf(" ");
		}
		printf("\n");
		for (int i = 49 - lengthA + 1; i < 50 ; i++) 
		{
			if (A[i] != 0 ) printf("%c", A[i]);
		}
		ch = error == 4 ? DOWN : getch();
		error = 0;
		switch (ch) {
		case(LEFT):
			if (position > 0) position--;
			break;
		case(RIGHT):
			if (position < lengthA - 1) position++;
			break;
		case(UP):
			if (lengthA < 50 )
			{
				if (A[49 - lengthA + 1] == alphabet2[NS-1]) flage = 1;
				for (int i = 49 - lengthSUMOPERAND2 + 1; i < 50; i++)
				{
					SUMOPERAND2[i] = 0;
				}
				lengthSUMOPERAND2 = lengthA + 1;
				lengthOPERAND2 = lengthA - position;
				for (int i = 49 - lengthOPERAND2 + 1; i < 50; i++)
				{
					operand2[i] = '0';
				}
				operand2[50 - lengthOPERAND2] = '1';
				sum(&A[49], &operand2[49], &SUMOPERAND2[49], NS);
				i = 0;
				while ( ( SUMOPERAND2[i] == '0' || SUMOPERAND2[i] == 0 ) && i < 49)
				{
					if (SUMOPERAND2[i] == '0') --lengthSUMOPERAND2;
					SUMOPERAND2[i] = 0;
					i++;
				}
				for (int i = 0 ; i < 50 ; i++)
				{
					A[i] = 0;
				}
				i = 49;
				while (SUMOPERAND2[i] != 0)
				{
					A[i] = SUMOPERAND2[i];
					i--;
				}
				operand2[50 - lengthOPERAND2] = 0;
				if (A[50 - lengthA] == '0' && flage == 1)
				{
					++lengthA;
					if (lengthA >= 50) error = 4;
				}
				else flage = 0;
			}
			break;
		case(DOWN):
		if (lengthA > 1 || A[49] != '1' && A[49] != '0' )
		{

			lengthDIFOPERAND2 = lengthA ;
			_lengthOPERAND2 = lengthA - position;
			for (int i = 50 - _lengthOPERAND2; i < 50; i++)
			{
				_operand2[i] = '0';
			}
			_operand2[50 - _lengthOPERAND2] = '1';
			dif(&A[49], &_operand2[49], &DIFOPERAND2[49], NS);
			i = 0;
			while ((DIFOPERAND2[i] == '0' || DIFOPERAND2[i] == 0) && i < 49)
			{
				DIFOPERAND2[i] = 0;
				i++;
			}
			lengthA = 0;
			while ( i < 50)
			{
				if ( DIFOPERAND2[i] != 0 )	++lengthA;
				++i;
			}
			for (i = 0; i < 50; i++)
			{
				A[i] = 0;
			}
			i = 49;
			while (DIFOPERAND2[i] != 0)
			{
				A[i] = DIFOPERAND2[i];
				i--;
			}
			_operand2[50 - _lengthOPERAND2] = 0; 

		}
			break;
		case(ENTER):
			if (lengthA < 50 )
			{
				add(lengthA - position - 1, A);
			}
			break;
		case(BS):
			if (lengthA > 1)
			{
			remove(position, A);
			position == 0 ? position : position--;
			}
		case(ESC):
			break;
		}
		system("cls");
		i = 0;

		while ( ( A[i] == '0' || A[i] == 0 ) && i < 49)
		{
				if (A[i] == '0') --lengthA;
				A[i] = 0;
				i++;
		}
		if (lengthA == 0 || lengthA == 1 && A[49] == 0)
		{
			if (lengthA == 0) ++lengthA;
			A[49] = '0';
		}
	} while (ch != ESC);
}
