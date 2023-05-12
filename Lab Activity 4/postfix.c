#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#define SIZE 50
int stack[SIZE];
int top=-1;
void push(int a){
	top++;
	stack[top]=a;
}
int pop(){
	int b;
	b=stack[top];
	top--;
	return (b);

}
void main(){int d1;int d2;int t;int i,z;char exp[SIZE];
while(1){
	printf("Enter the postfix expression to be evaluated:\n");
	gets(exp);
	for(i=0;i<=strlen(exp);i++){
		z=exp[i];
		switch(exp[i]){
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case '0':
		
			push(exp[i]-48);
			break;
		case '+':
			d2=pop();
			d1=pop();
			t=d1+d2;
			push(t);
			break;
		case '-':
			d2=pop();
			d1=pop();
			t=d1-d2;
			push(t);
			break;
		case '*':
			d2=pop();
			d1=pop();
			t=d1*d2;
			push(t);
			break;
		case '/':
			d2=pop();
			d1=pop();
			t=d1/d2;
			push(t);
			break;

		}
	}

	printf("The final answer is:%d\n",pop());
}
}