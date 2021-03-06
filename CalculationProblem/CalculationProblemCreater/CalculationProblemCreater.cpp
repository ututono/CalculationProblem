// CalculationProblemCreater.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"

int RB = 0, LB = 0;					//左右括号数量
int OPNUM_MAX = 3;				//最大运算符数
int ZEROTag = 0;
int EMPTY = 0;		//空题标志

void Help()
{
	printf("***********************\n");
	printf("可用参数如下：\n");
	printf("-r  <题目的数字最大值>\n");
	printf("-n <题目的数量>\n");
	printf("-e <题目文件位置>\n");
	printf("-a <答题卡文件位置>\n");
	printf("-h  \"帮助\"\n");
	printf("***********************\n");
}

int main(int argc, char *argv[])
{
	//srand((unsigned)time(NULL));
	int tag = 0;
	int r = 50,pnum = 0;
	int Count = 10000;				//初始题目数量
	char *calproblem;
	char *outCalproblem;
	char *p;								//存放题目序号的数组
	FILE *fp;
	char qFile[] = "Question.txt";
	char test[] = "test.txt";
	
	Element *e;
	char *exercisefile;
	char *answerfile;
	exercisefile = qFile;
	answerfile=test;

	for (int i = 0; i < argc; i++)					//$Funktion:过滤输入过界条件
	{
		if (!strcmp(argv[i], "-r"))
		{
			r = atoi(argv[i + 1]);
		}
		if (!strcmp(argv[i], "-n"))
		{
			Count = atoi(argv[i + 1]);
		}
		if (!strcmp(argv[i], "-e"))
		{
			tag = 1;
			exercisefile =(char*) calloc(1+strlen(argv[i+1]), sizeof(char));
			strcpy_s(exercisefile, strlen(argv[i + 1]) + 1, argv[i + 1]);
		}
		if (!strcmp(argv[i], "-a"))
		{
			answerfile = (char*)calloc(1 + strlen(argv[i + 1]), sizeof(char));
			strcpy_s(answerfile, strlen(argv[i + 1]) + 1, argv[i + 1]);
		}
		if(!strcmp(argv[i],"-h"))
		{
			Help();
		}
		else;
	}

	pnum = (int)log10(r) + 1;
	p = (char*)calloc(pnum, sizeof(char));

	if (tag == 0)
	{
		if ((fp = fopen("Question.txt", "wb")) == NULL)
		{
			printf("cannot open file\n");
			return 0;
		}
		for (int t = 0; t < Count; t++) {				//创建表达式
			int num = Creater(r);
			calproblem = CalProblem(num, (int)log10(r) + 1);
			DelBracket(calproblem);				//	删除多余的括号
			realloc(calproblem, (strlen(calproblem) + 2) * sizeof(char));
			strcat(calproblem, "=");
			Element temp;				//判断计算结果是否违规，如出现负数，分母为零
			temp = f_AnAnswer(calproblem);
			if (ZEROTag == 1)
			{
				t--;
				ZEROTag = 0;
				continue;
			}
			if (temp.denominator < 0 || temp.numerator < 0)
			{
				t--;
				continue;
			}
			_itoa(t + 1, p, 10);
			strcat(p, ".\t");
			if (fwrite(p, strlen(p), 1, fp) != 1)
				printf("write error\n");
			if (fwrite(calproblem, strlen(calproblem), 1, fp) != 1)
				printf("write error\n");
			if (fputs("\r\n", fp) == EOF)
				printf("write error\n");
			memset(calproblem, 0, strlen(calproblem));
		}

		calproblem = NULL;
		free(calproblem);
		fclose(fp);
		printf("Questions are all output.\n");
		OpenFileAndGiveTheAnswer(qFile, Count);
		printf("Answers are all output.\n");
		CompareAnswerAndGiveTheGrade(exercisefile, answerfile, Count);
	}
	else CompareAnswerAndGiveTheGrade(exercisefile,answerfile, Count);
	//getchar();
	return 0;
}

