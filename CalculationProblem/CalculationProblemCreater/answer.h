#pragma once



typedef struct {             //分数结构体，分母默认为1，即整数        
	int numerator = 0;      //分子
	int denominator = 1;    //分母			
}Element;                   //计算项结构体

typedef struct {
	char question[40] = { 0 };
	Element answer;
}Equation;

typedef struct stack1 {      // 项栈
	Element e[10];
	int top;
}NumberStack;

typedef struct stack2 {       //符号栈
	char op[10];
	int top;
}OpStack;

char CompareOp(char op1, char op2);   //优先级判断
Element GetNumberFromStr(char s[]);	 //从含单个数的字符数组中得出相应的值 
int GetGreatestCommonFactor(int a, int b); //返回最大公因数


Element f_AnAnswer(char s[40]); //计算得出答案项
Element AnAnswer(char s[40]); //计算得出答案项
Equation *OpenAndSave(char c[800], int n);  //打开文件并将题目存入问题结构体数组,n为题数

Element *ReadTheAnswer(char AnsFile[800], int n);//打开文件并将答案存入分数结构体数组

void OutputFile(Equation *ep, char c[], int n);   //将Equation结构中的answer输出到文件
void OpenFileAndGiveTheAnswer(char *filename, int n);	//传入文件名和题目数


void CompareAnswerAndGiveTheGrade(char QFile[800], char AnsFile[800], int n); //读取文件，保存答案，分别对比