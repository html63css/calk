#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

#include "input.h"
#include "translation.h"
#include "sum.h"
#include "output.h"
#include "dif.h"
#include "multi.h"
#include "changeA.h"
#include "changeNS.h"
#pragma warning(disable: 4996)

#define DOWN 80
#define UP 72

char SUM[50];
char DIF[50];
char MULTI[100];
char DIV[50];

void interface()
{	
	char ch;
	int position = 0;
	system("cls");

	do {
		for (int i = 0; i <= 49; i++)
		{
			MULTI[i] = 0;
			DIV[i] = 0;
			SUM[i] = 0;
			DIF[i] = 0;
		}
		dif(&A[49], &B[49], &DIF[49], NS);
		printf("������� ���������:%d ", NS);
		printf("\n");
		
		printf("������ �����: ");
		output(A);
		if (NS != 10 && ceil(log(NS)/log(10))*lengthA < 20 )
		{
			translation(&A[49],lengthA,inputNS,NS);
		}
		printf("\n");
		
		printf("������ �����: ");
		output(B);
		if (NS != 10 && (ceil(log(NS) / log(10))+1) * lengthB < 20)
		{
			//translation(&B[49 - lengthB + 1], lengthB, NS);
		}
		printf("\n");

		printf("\t\t����� "); if (position == 0) printf("<--");
		printf("\n");
		printf("\t\t�������� "); if (position == 1) printf("<--");
		printf("\n");
		printf("\t\t������������ "); if (position == 2) printf("<--");
		printf("\n");
		printf("\t\t������� "); if (position == 3) printf("<--");
		printf("\n");
		printf("\t\t�������� ��"); if (position == 4) printf("<--");
		printf("\n");
		printf("\t\t�������� ����� �"); if (position == 5) printf("<--");
		printf("\n");
		switch (position)
		{
		case(0):
			sum(&A[49], &B[49], &SUM[49], NS);
			output(SUM);
			break;
		case(1):
			if (dif(&A[49], &B[49], &DIF[49], NS))
			{
				output(DIF);
			}
			else
			{
				printf("������������� �����");
			}
			break;
		case(2):

			if (multi(&A[49], lengthA, &B[49], lengthB, &MULTI[99], NS))
			{
				output(MULTI,99);
			}
			else
			{
				printf("� ����� ������ 100 ����");
			}
			break;
		case(3):
			break;
		case(4):
			NS = changeNS(NS);
			++position;
			continue;
			break;
			//---------------------------------------------------------������� �� ��� A � B-----------------------------------------------------------
		case(5):
			changeA(A,NS);
			position = 0;
			continue;
			break;
		}

		do {
			ch = getch();
			switch (ch)
			{
			case (DOWN):
				if (position < 5) position += 1;
				system("cls");
				break;
			case(UP):
				if (position > 0) position -= 1;
				system("cls");
				break;
			}
		} while (ch != UP && ch != DOWN);
	} while (1);

}

