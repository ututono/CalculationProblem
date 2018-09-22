#pragma once
typedef int BOOL;
struct Variable
{
	char *val;
	int left = 0;			//1：变量有左侧有左括号
	int right = 0;
	int ator = 0;		//1：变量为分数
	int size = 0;
};

struct VarSq
{
	char *elem;
	int front;
	int rear;
	int maxSize;
};

//队列操作
//int InitStack_Sq(VarSq &S, int size, int inc);

char OperationalCreater();				//	运算符生成函数
void NumCreater(int r, struct Variable m_VarStruct[], int x);	// 变量生成函数，r为范围参数，x为结构体数组编号
int Creater(int r);
BOOL BracketCreater(char *,int,int);		//生成括号,返回值0无法生成括号
char *CalProblem(int num);