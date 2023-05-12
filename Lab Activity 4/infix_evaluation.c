#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
int numbers[50],tn=-1,to=-1;
char op[50];
void push_num(int n){
	numbers[++tn]=n;
}
void push_op(char ch){
	op[++to]=ch;
}
int pop_num(){
	return numbers[tn--];
}
char pop_op(){
	return op[to--];
}
int infix_eval(int numbers[50],char op[50]){
	int x,y;
	char ope;
	x=pop_num();
	y=pop_num();
	ope=pop_op();
	switch(ope){
	case '+':
		return x+y;
		break;
	case '-':
		return y-x;
		break;
	case '*':
		return x*y;
		break;
	case '/':
		return y/x;
		break;
	}

}
int is_operator(char ch){
	if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^')
		return 1;
}
int precedence(char c){
	switch(c){
	case '+':
		return 1;
		break;
	case '-':
		return 1;
		break;
	case '*':
		return 2;
		break;
	case '/':
		return 2;
		break;
	case '^':
		return 3;
		break;
	default :
		return -1;

	}
}
int eval(char exp[50]){
	int i,num,output,r;
	char c;
	for(i=0;exp[i]!=0;i++){
		c=exp[i];
		if(isdigit(c)){
			num=c-48;
			push_num(num);
		}
		else if(c=='('){
			push_op(c);
		}
		else if(c==')'){
			while(op[to]!='('){
				r=infix_eval(numbers,op);
				push_num(r);
			}
			pop_op();
		}
		else if(is_operator(c)){
			while(to!=-1 && precedence(c)<=precedence(op[to])){
				output=infix_eval(numbers,op);
				push_num(output);
			}
			push_op(c);
		}
	}
	while(to!=-1){
		output=infix_eval(numbers,op);
		push_num(output);
	}
	return pop_num();

}
void main(){
	char exp[50];
	printf("Enter the infix expression:\n");
	gets(exp);
	printf("%d",eval(exp));
}