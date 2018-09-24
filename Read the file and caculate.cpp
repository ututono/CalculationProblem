# include <stdio.h>
# include <stdlib.h>
# include <string.h>



typedef struct{             //分数结构体，分母默认为1，即整数        
	int numerator = 0;      //分子
	int denominator = 1;    //分母			
}Element;                   //计算项结构体

typedef struct{
	char question[40];
	Element answer;
}Equation;

typedef struct stack1{      // 项栈
	Element e[10];
	int top;
}NumberStack;

typedef struct stack2{       //符号栈
	char op[10];
	int top;
}OpStack;


//两个栈的初始化操作
void InitNumberStack(NumberStack *numberstack){
	numberstack->top = -1;
}

void InitOpStack(OpStack *opstack){
	opstack->top = -1;
}


//两个栈的PUSH操作
int PushNumberStack(NumberStack *numberstack, Element e){
	if(numberstack->top == 99 ){
		printf("数字超出\n");
		return -1;
	}
	numberstack->top++;
	numberstack->e[numberstack->top] = e;
	return 0;
}

int PushOpStack(OpStack *opstack, char c){
	if(opstack->top == 99){
		printf("符号超出\n");
		return -1;
	}
	opstack->top++;
	opstack->op[opstack->top] = c;
	return 0;
}


//两个栈的POP操作
Element PopNumberStack(NumberStack *numberstack){
	Element e;
	e =  numberstack->e[numberstack->top];
	numberstack->top--;
	return e;
}

char PopOpstack(OpStack *opstack){
	char c;
	c = opstack->op[opstack->top];
	opstack->top--;
	return c;
}


int JudgeOp(char c){                //判断是否为运算符
	if (c == '+'||c == '-'||c == -62||c == '*'|| c == '('||c == ')'||c == '='||c == '\n'){    //-62
		return 1;
	} 
	else return 0;
}

char CompareOp(char op1,char op2){    //优先级判断
	char c;
	switch(op2){
		case '+':
		case '-':{
			if(op1 == '('||op1 == '=') c = '<';
			else c = '>';
			break;
		}
		case '*':
		case -62:{
			if(op1 == '*'||op1 == -62||op1 == ')') c = '>';
			else c = '<';
            break;			
		}
		case '(':{
			if(op1 == ')'){
				printf("错误输入\n");
				return -1;
			}
			else c = '<';
            break;			
		}
		case ')':{
			switch(op1){
				case '(':{
					c = '=';
					break;
				}
				case '=':{
					printf("错误输入\n");
					return -1; 
				}
                default:c = '>';				
			}
			break;
		}
		case '=':{
			switch(op1){
				case '=':{
					c = '=';
					break;
				}
		    	case '(':{
				printf("错误输入\n");
				return -1;
			    }
			default: c = '>';
	    	}
	    }
    }
	return c;
}




Element GetNumberFromStr (char s[]){  //从含单个数的字符数组中得出相应的值 
	int flag = 0;
	int j = 0;
	int k = 0;
	char buff1[5];    //盛放分子的字符串
	char buff2[5];    //盛放分母的字符串
	Element TheNumber; 
	for(int i = 0;s[i] != '\0';i++){
		buff1[j] = s[i];
		j++;
		if (s[i] == '/') {
			buff1[j] = '\0';
			flag = 1;continue;
		}
		if(flag == 1){
			buff2[k] = s[i];
			k++;
		}	
	}
	buff2[k] = '\0';
	switch(flag){
		case 0:TheNumber.numerator = atoi(s);break;
		case 1:{
		TheNumber.numerator = atoi(buff1);
        TheNumber.denominator = atoi(buff2);		
		}
	}
	return TheNumber;
}


int GetGreatestCommonFactor(int a, int b){  //返回最大公因数
	int temp = 0;
	while(a!=0){
        temp = b % a; 
		b = a;  
		a = temp;
	}                                     
	return b;
}

//计算部分
Element Add(Element e1,Element e2){   //加法
	Element e3;
	int n = 0;
	int d = 0;
	n = e1.numerator * e2.denominator + e2.numerator * e1.denominator;
	d = e2.denominator * e1.denominator;
	int C = GetGreatestCommonFactor(n, d);   //求出分子和分母的最大公因数
	e3.numerator = n / C;
	e3.denominator = d / C;
	return e3;
}

Element minus(Element e1,Element e2){ //减法,前一个是被减数，后一个是减数
	Element e3;
	int n = 0;
	int d = 0;
	n = e1.numerator * e2.denominator - e2.numerator * e1.denominator;
	d = e2.denominator * e1.denominator;
	int C = GetGreatestCommonFactor(n, d);   
	e3.numerator = n / C;
	e3.denominator = d / C;
	return e3;
}

Element Multiply(Element e1,Element e2){
	Element e3;
	int n = 0;
	int d = 0;
	n = e1.numerator * e2.numerator;
	d = e2.denominator * e1.denominator;
	int C = GetGreatestCommonFactor(n, d);   //求出分子和分母的最大公因数
	e3.numerator = n / C;
	e3.denominator = d / C;
	return e3;
}

Element Divide(Element e1,Element e2){ //除法，前一个是被除数，后一个是除数
	Element e3;
	int n = 0;
	int d = 0;
	n = e1.numerator * e2.denominator;
	d = e1.denominator * e2.numerator;
	int C = GetGreatestCommonFactor(n, d);   
	e3.numerator = n / C;
	e3.denominator = d / C;
	return e3;
}


Element CaculateOneOp(Element e1, char op, Element e2){
	Element result;
	switch(op){
		case '+':{
			result = Add(e1, e2);
			break;
		}
		case '-':{
			result = minus(e1, e2);
			break;
		}
        case '*':{
			result = Multiply(e1, e2);
			break;
		}		
		case -62:{
			if(e2.numerator == 0) printf("不能除以0\n");
			else result = Divide(e1, e2);
		}
	}
	return result;
}


Element AnAnswer(char s[40]){     //计算得出答案项
	NumberStack numberstack;
	OpStack opstack;
	Element num1,num2,result,num;
	char c,sign;
	char *str = NULL;
	int count = 0;
	
	InitNumberStack(&numberstack);
	InitOpStack(&opstack);
	
	PushOpStack(&opstack, '=');
	int j = 0;
	while(s[j] != '\t') j++;
	int i = j; 
	j = 0; 
	c = s[i];
	while((c != '=')||opstack.op[opstack.top] != '='){
		if(JudgeOp(c) == 0){
			str = (char*)malloc(sizeof(char)*12);
			do{
				*str = c;
				str++;
				count++;
				i++;
				c = s[i];
			}while(JudgeOp(c) == 0); 
			*str = '\0';
			str = str - count;
			num = GetNumberFromStr(str);
			PushNumberStack(&numberstack, num);
			str = NULL;
			count = 0;
		}
		else{    //wei 
			switch(CompareOp(opstack.op[opstack.top], c)){
				case '<':{
					PushOpStack(&opstack, c);
					i++;
					c = s[i];
					break;
				}
				case '=':{
					sign = PopOpstack(&opstack);
					i++;
					c = s[i];
					break;
				}
                case '>':{
					sign = PopOpstack(&opstack);
					num2 = PopNumberStack(&numberstack);
					num1 = PopNumberStack(&numberstack);
					result = CaculateOneOp(num1, sign, num2);
					PushNumberStack(&numberstack, result);
					break;
				}					
				
			}
		}
	}
	result = numberstack.e[numberstack.top];
	return result;
}




Equation *OpenAndSave(char c[800], int n){    //打开文件并将题目存入问题结构体数组,n为题数
	FILE *fp;
	Equation *qu;
	char buff[40];                           
	int len;
	int count = 0;
	qu = (Equation*)malloc(sizeof(Equation) * n);
	if ((fp = fopen(c,"r")) == NULL){
		printf("The file doesn't exist!\n");
		exit(0);
	}
	int j = 0;
	while(fgets(buff,50,fp) != NULL){
	    len = strlen(buff); 
		buff[len-1] = '\0';            //去掉换行符
		strcpy(qu->question , buff);     
        qu++;
        count++;		
	}
	fclose(fp);
	qu = qu - count;
	return qu;
}              

char *OutputElement(Element e){               //将项转为字符串
	char *str;
	char buff1[5];
	char buff2[5];
	char c[2] = {'/', ' '};
	itoa(e.numerator , buff1 , 10);
	itoa(e.denominator , buff2 , 10);
	str = (char*)malloc(sizeof(char)*12);
	strcpy(str , buff1);
	if(e.denominator != 1){
		strcat(str , c);
		strcat(str , buff2);
	}
	return str;
}

void SaveAnswers(Equation *ep, int n) {    //计算出答案并保存到Equation结构的answer中,n为题数
	int count = 0;
	int i = 0; 
	for(i ; i < n; i++){
		ep->answer = AnAnswer(ep->question);
		ep++;
		count++;
	}
	ep = ep - count;
}

void OutputFile(Equation *ep, char c[800], int n){   //将Equation结构中的answer输出到文件
	FILE * fp;
	int i = 0;
	int count = 0;
	if ((fp = fopen(c,"w")) == NULL){
		printf("Can not open this file!\n");
		exit(0);
	}
	for(i; i < n; i++){
		char buff[6];
		char buff1[2] = {'.','	'};
		itoa(i, buff, 10);
		strcat(buff, buff1);
	    fputs(buff, fp);
		fputs( OutputElement ( ep->answer ), fp);
		fputs("\n",fp);
		ep++;
		count++;
	}
	ep = ep - count;
	fclose(fp);
	
}

void OpenFileAndGiveTheAnswer(char filename[800], int n){  //传入文件名和题目数
	Equation* ep;
	ep = (Equation*)malloc(sizeof(Equation) * n);
	ep = OpenAndSave(filename, n);
	SaveAnswers(ep, n);
	OutputFile(ep, "Answers.txt", n);
	ep = NULL;
}




int main(){
	OpenFileAndGiveTheAnswer("e:\\Question1.txt", 10000);
    return 0;	
}
