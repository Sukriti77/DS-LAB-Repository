#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 20
char operators[SIZE];

int top=-1;
char prefix[SIZE];
int j=0;
void assign(char t){
	
	prefix[j++]=t;
}

void push(char ch){
	if(top==SIZE-1)
		printf("OVERFLOW\n");
	else{
		operators[++top]=ch;
	}
}
char pop(){
	if(top==-1){
		printf("UNDERFLOW\n");
		return 0;
	}
	else{
		return operators[top--];
	}
}
int priority(char x){
	if(x=='*'||x=='/')
		return 2;
	if(x=='+'||x=='-')
		return 1;
	if(x=='^')
		return 3;
	return 0;
}
void main(){
	char exp[SIZE];int i;
	char p;
	printf("Enter the infix expression to be converted into prefix:\n");
	gets(exp);
   for(i=strlen(exp);i>=0;i--){
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
   case 'a':
   case 'b':
   case 'c':
       assign(exp[i]);
       break;
   case '*':
   case '/':
   case '+':
   case '-':
   case '^':
   	if(top==-1)
   		push(exp[i]);
   	else if(priority(operators[top])>=priority(exp[i])){
   			assign(pop());
   		push(exp[i]);
	   	}
   		else
   			push(exp[i]);
   	
     break;
case ')':
	push(exp[i]);
	break;
case '(':
	while((p=pop())!=')'){
		assign(p);
   }
   break;
}
}
while(top!=-1){
	assign(pop());
}
printf("The prefix expression is:\n");
printf("%s",strrev(prefix));
}