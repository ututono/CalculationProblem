#pragma once

struct Variable
{
	char *val;
	int left = 0;			//1：变量有左侧有左括号
	int ator = 0;		//1：变量为分数
};

char OperationalCreater();				//	运算符生成函数
void NumCreater(int r, Variable m_VarStruct, int x);					// 变量生成函数，r为范围参数，x为结构体数组编号
void Creater(int r);