# include <stdio.h>
# include <stdlib.h>

typedef struct{             //分数结构体，分母默认为1，即整数        
	int numerator = 0;      //分子
	int denominator = 1;    //分母			
}Element;                   //计算项结构体

FILE *questions = NULL;
questions = fopen( "Exercises.txt", "r" );

char questions_list[ ][30]
for(int i = 0;i < 188 ; i++){  //xiu
	char buff[30]; 
	fgets(buff, 40, (FILE*)questions);
	questions_list[i] = buff;      //可能会释放 
}

	
	

Element GetNumberFromStr (char a[5]){  //从含单个数的字符数组中得出相应的值 
	int flag = 0;
	int j = 0;
	int k = 0;
	char buff1[5];    //盛放分子的字符串
	char buff2[5];    //盛放分母的字符串
	Element TheNumber; 
	for(int i = 0;i < 5;i++){
		buff1[j] = a[i];
		j++;
		if (a[i] == '/') {
			flag = 1;continue;
		}
		if(flag == 1){
			buff2[k] = a[i];
			k++;
		}
	}
	switch(flag){
		case 0:TheNumber.numerator = atoi(a);break;
		case 1:{
		TheNumber.numerator = atoi(buff1);
        TheNumber.denominator = atoi(buff2);break;		
		}
		default: return ERROR;
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


Element AnAnswer(char s[30]){   //得出一道题目的答案
	Element e[4];   //结构体数组可能无法生成
	char buff[5];
	int OperatorCharacters[7];
	int flag = 0;
	int j = 0;
	int k = 0; 
	int l = 0;
	for(int i = 2; s[i] != '=';i++){
		if (s[i] == '('){
			OperatorCharacters[l] = 0;
			l++;
		}
		else if (s[i] == ')'){
			OperatorCharacters[l] = 1;
			l++;
		}    
		else if (s[i] >= 49 and s[i] <= 57 or s[i] == '/'){ //一个多位数（字符数组）开始 逐个放入buff 
			 flag = 1;
			 buff[j] = s[i];
			 j++;  
		}
		else if(flag == 1 and (s[i] < 49 or s[i] > 57)){ //一个 多位数（字符数组）结束 buff字符串通过GetNumberFromStr()得出项,存入e[]中，将buff清空 
			flag = 0;
			j = 0;
			e[k] = GetNumberFromStr(buff);
			k++; 
		}
		else if(s[i] == '+'){
			OperatorCharacters[l] = 2;
			l++;
		}
		else if(s[i] == '-'){
			OperatorCharacters[l] = 3;
			l++;
	    }
	    else if(s[i] == '×'){
			OperatorCharacters[l] = 4;
			l++;
	   }
	    else if(s[i] == '÷'){
			OperatorCharacters[l] = 5;
			l++;
	   }
	}  //得出项e[0]、e[1]、e[2]、e[3] 以及运算编号OperatorCharacters[] 接下来是算法
	
}




int *TheAnswers(char a[][30], int n) {   //通过字符串和题数得出答案数组 
	int i = 0;
	for(i; i <n; i++){
		
	}
}
//fclose(questions);
