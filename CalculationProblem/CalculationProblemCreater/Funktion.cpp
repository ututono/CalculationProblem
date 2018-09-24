#include "pch.h"
#include "Funktion.h"

#define OVERFLOW -1

struct Variable m_VarStruct[4];

//
//int InitStack_Sq(VarSq & S, int size, int inc)
//{
//	S.elem = (char *)malloc(sizeof(char)*size);
//	if (NULL == S.elem) return OVERFLOW;
//	S.to
//	return 0;
//}

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
		m_VarStruct[x].val = (char*)calloc(10,sizeof(char));
		_itoa(rand() % r + 1, m_VarStruct[x].val, 10);
		m_VarStruct[x].size = strlen(m_VarStruct[x].val);
		m_VarStruct[x].ator = 0;
	}

		break;
	case 1:				//分数
	{
		m_VarStruct[x].ator = 1;
		char *temp1, *temp2;
		int numerator = rand() % r + 1, denominator = rand() % r + 1;
		temp1 = (char*)calloc(10,sizeof(char) );				//仅支持十位
		temp2 = (char*)calloc(10, sizeof(char));
		if (numerator > denominator)
		{
			int temp = 0;
			temp = numerator;
			numerator = denominator;
			denominator = temp;
		}
		if (numerator == 0) numerator++;
		_itoa(numerator, temp1, 10);
		_itoa(denominator, temp2, 10);
		m_VarStruct[x].val = (char*)malloc(sizeof(char) *  (r *3));
		strcpy_s(m_VarStruct[x].val, strlen(temp1)+sizeof("\0"), temp1);
		strcat_s(m_VarStruct[x].val, strlen(temp1)+sizeof("/") + sizeof("\0"), "/");
		strcat_s(m_VarStruct[x].val, strlen(temp1) + sizeof("/") + sizeof("\0") +strlen(temp2), temp2);
		m_VarStruct[x].size = strlen(m_VarStruct[x].val);
		free(temp1);
		free(temp2);
	}
		break;
	default:
		break;
	}
}

int Creater(int r)
{
	//char op = OperationalCreater();
	int atornum = rand() %3+2;			//2-4之间的整数
	for (int n = 0; n < atornum; n++)
	{
		NumCreater(r, m_VarStruct, n);
	}
	return atornum;
}
//
//BOOL BracketCreater(char *calproblem,int x,int num)					//-1为不能再生成任何括号，0为概率上无括号产生
//{
//	extern int RB, LB;
//	if (RB >= 2 && LB >= 2) return -1;
//	else if (LB > RB)					//全括号均有概率生成
//	{
//		if (LB < 2)
//		{
//			switch (rand() % 3)
//			{
//			case 0:
//			{
//				if ((num - x) >= 2)
//				{
//					strcat_s(calproblem, strlen(calproblem) + strlen("(") + sizeof("\0"), "(");
//					LB++;
//					m_VarStruct[x].left = 1;
//					return 1;
//				}
//			}
//			break;
//			case 1:
//			{
//				if (!m_VarStruct[x].left&&calproblem[strlen(calproblem) - 1] != '*'
//					&& (int)calproblem[strlen(calproblem) - 1] != -62&&calproblem[strlen(calproblem) - 1] != '-'
//					&&calproblem[strlen(calproblem) - 1] != '+')
//				{
//					strcat_s(calproblem, strlen(calproblem) +strlen("(")+ sizeof("\0"), ")");
//					RB++;
//					m_VarStruct[x].right = 1;
//					return 1;
//				}
//			}
//			break;
//			case 2:
//			{
//				if (!m_VarStruct[x].left&&LB == 2 && RB == 0 && calproblem[strlen(calproblem) - 1] != '*'
//					&& (int)calproblem[strlen(calproblem) - 1] != -62&&calproblem[strlen(calproblem) - 1] != '-'
//					&&calproblem[strlen(calproblem) - 1] != '+')
//				{
//					strcat_s(calproblem, strlen(calproblem) + 2 * sizeof(char) + 1, "))");
//					RB = 2;
//					m_VarStruct[x].right = 2;
//					return 1;
//				}
//			}
//			break;
//			default:
//				break;
//			}
//		}
//		if (LB == 2)
//		{
//			switch (rand() % 2)
//			{
//			case 0:
//			{
//				if (calproblem[strlen(calproblem) - 1] != '*'
//					&&(int)calproblem[strlen(calproblem) - 1] != -62&&calproblem[strlen(calproblem) - 1] != '-'
//					&&calproblem[strlen(calproblem) - 1] != '+')
//				{
//					strcat_s(calproblem, strlen(calproblem) + sizeof(char) + 1, ")");
//					RB++;
//					m_VarStruct[x].right = 1;
//					return 1;
//				}
//
//			}
//			break;
//			default:
//				break;
//			}
//		}
//	}
//	if (LB <= RB)//仅有左括号(有概率生成
//	{
//		switch (rand()%4)
//		{
//		case 0:
//		{
//			if ((num-x)>=2)
//			{
//				strcat_s(calproblem, strlen(calproblem) + sizeof(char) + 1, "(");
//				LB++;
//				m_VarStruct[x].left = 1;
//				return 1;
//			}
//
//		}
//			break;
//		case 2:
//		{
//			if (LB == 0&&(num-x>=3))
//			{
//				strcat_s(calproblem, strlen(calproblem) + 2 * sizeof(char)+1, "((");
//				LB=2;
//				m_VarStruct[x].left = 2;
//				return 1;
//			}
//		}
//			break;
//		default:
//			break;
//		}
//	}
//	return 0;
//}

BOOL BCL(char *calproblem, int x, int num)					//nur after op
{
	extern int LB, RB;
		switch (rand() % 4)
		{
		case 0:
		{
			if (LB<2&&(num - x) >= 2)
			{
				strcat_s(calproblem, strlen(calproblem) + sizeof(char) + 1, "(");
				LB++;
				m_VarStruct[x].left = 1;
				return 1;
			}

		}
		break;
		case 2:
		{
			if (LB == 0 && (num - x >= 3))
			{
				strcat_s(calproblem, strlen(calproblem) + 2 * sizeof(char) + 1, "((");
				LB = 2;
				m_VarStruct[x].left = 2;
				return 1;
			}
		}
		break;
		default:
			break;
		}
	return 0;
}
BOOL BCR(char *calproblem, int x, int num)			//nur after Var
{
	extern int LB, RB;
	if (RB == 2 || LB==0) return 0;
	if (LB <= 2)
	{
		switch (rand() % 2)
		{
		case 1:
		{
			if (!m_VarStruct[x].left)
			{
				strcat_s(calproblem, strlen(calproblem) + strlen("(") + sizeof("\0"), ")");
				RB++;
				m_VarStruct[x].right = 1;
				return 1;
			}
		}
		break;
		case 0:
		{
			if (!m_VarStruct[x].left&&LB == 2 && RB == 0)
			{
				strcat_s(calproblem, strlen(calproblem) + 2 * sizeof(char) + 1, "))");
				RB = 2;
				m_VarStruct[x].right = 2;
				return 1;
			}
		}
		break;
		default:
			break;
		}
	}
	return 0;
}

char * CalProblem(int num)
{
	extern int RB, LB;
	int op = num - 1;
	int i = 0;
	BOOL BC = 0;
	char *calproblem;
	char opch[2];
	int temptest = 0;

	//内存分配
	memset(opch, 0, sizeof(opch));

	//calproblem = (char*)calloc(sizeof(char)*op*2 *4*8);
	calproblem = (char*)calloc(500,sizeof(char));
	if (calproblem==NULL)
	{
		return ERROR;
	}
	memset(calproblem, 0, sizeof(calproblem));
	//for (int n = 0; n < num; n++)
	//{
	//	if (NULL == realloc(calproblem, strlen(calproblem) * sizeof(char) + strlen(m_VarStruct[n].val)*sizeof(char)+sizeof(char)))
	//	{
	//		return ERROR;
	//	}
	//	memset(calproblem, 0, sizeof(calproblem));
	//}

	//
	if (num == 2)
		//if (true)
	{
		strcpy_s(calproblem, m_VarStruct[0].size+ sizeof("\0"), m_VarStruct[0].val);
		opch[0] =OperationalCreater();
		if (opch[0] == '/')
			strcat_s(calproblem, strlen(calproblem) + strlen(opch) + sizeof("\0"), "÷");
		else strcat_s(calproblem, strlen(calproblem)+strlen(opch)+sizeof("\0"), opch);
		strcat_s(calproblem, strlen(calproblem) + m_VarStruct[1].size+1, m_VarStruct[1].val);
		return calproblem;
	}
	else
	{
		while (i < num) 
		{
			BC = BCL(calproblem, i,num);
			if (!BC&&i==0)
			{
				strcpy_s(calproblem, m_VarStruct[i].size+ sizeof("\0"), m_VarStruct[i].val);
				opch[0] = OperationalCreater();
				if (opch[0] == '/') 
					strcat_s(calproblem, strlen(calproblem) + strlen(opch) + sizeof("\0"), "÷");
				else strcat_s(calproblem, strlen(calproblem) + strlen(opch) + sizeof("\0"), opch);
				i++;
				continue;
			}
			strcat_s(calproblem, strlen(calproblem) + strlen(m_VarStruct[i].val )+ sizeof("\0"), m_VarStruct[i].val);
			BC = BCR(calproblem, i, num);
			if ((++i) == num)
			{
				if(LB-RB==1) strcat_s(calproblem, strlen(calproblem) + sizeof(char) + sizeof("\0"), ")");
				if(LB-RB==2) strcat_s(calproblem, strlen(calproblem) + sizeof(char)*2 + sizeof("\0"), "))");
				break;
			}
			opch[0] = OperationalCreater();
			if(opch[0]=='/') strcat_s(calproblem, strlen(calproblem) + strlen(opch) + sizeof("\0"), "÷");
			else strcat_s(calproblem, strlen(calproblem) + strlen(opch) + sizeof("\0"), opch);
			BC = 0;
		}
		
	}
	RB = 0; LB = 0;
	return calproblem;
}
