#include "pch.h"
#include "Funktion.h"

struct Variable m_VarStruct[4];

char OperationalCreater()
{
	switch (rand()%4)
	{
	case 0:
		return '+';
	case 1:
		return '-';
	case 2:
		return '*';
	case 3:
		return '/';
	default:
		return ERROR;
		break;
	}
	
}

void NumCreater(int r, struct Variable m_VarStruct[],int x)			//随机生成整数和真分数
{
	switch (rand()%2)
	{
	case 0:				//整数
	{
		m_VarStruct[x].val = (char*)malloc(sizeof(char)*r+2);
		_itoa(rand() % r + 1, m_VarStruct[x].val, 10);
		m_VarStruct[x].ator = 0;
	}

		break;
	case 1:				//分数
	{
		m_VarStruct[x].ator = 1;
		char *temp1, *temp2;
		int numerator = rand() % r + 1, denominator = rand() % r + 1;
		temp1 = (char*)malloc(sizeof(char) * r);
		temp2 = (char*)malloc(sizeof(char) * r);
		if (numerator > denominator)
		{
			int temp = 0;
			temp = numerator;
			numerator = denominator;
			denominator = temp;
		}
		_itoa(numerator, temp1, 10);
		_itoa(denominator, temp2, 10);
		m_VarStruct[x].val = (char*)malloc(sizeof(char) *  (r *3));
		strcpy_s(m_VarStruct[x].val, sizeof(temp1), temp1);
		strcat_s(m_VarStruct[x].val, strlen(temp1)+sizeof("/"), "/");
		strcat_s(m_VarStruct[x].val, strlen(temp1) + sizeof("/")+strlen(temp2), temp2);
		free(temp1);
		free(temp2);
	}
		break;
	default:
		break;
	}
	/*float numerator=rand()%r;
	float denominator=rand() %r;
	float n=0;
	switch (rand()%2)
	{
	case 0:

		n = numerator / denominator;
		n = ((float)((int)((n + 0.005) * 100))) / 100;
		break;
	case 1:
		n = rand() % r;
		break;
	default:
		break;
	}
	return n;*/
}

void Creater(int r)
{
	//char op = OperationalCreater();
	int atornum = rand() %3+2;			//2-4之间的整数
	for (int n = 0; n < atornum; n++)
	{
		NumCreater(r, m_VarStruct, n);
		printf("%s\n", m_VarStruct[n].val);
	}

}
