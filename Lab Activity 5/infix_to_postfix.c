#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 10
int top=-1;
char prefix[SIZE];
void push(char ele){
	if(top==SIZE-1){
		printf("OVERFLOW\n");
	}
	else{
	top++;
	prefix[top]=ele;
}
}
char pop(){
	if(top==-1){
		printf("UNDERFLOW\n");
	}
	else
	return prefix[top--];
}
int priority(char x){
	if(x=='(')
		return 0;
	if(x=='+'||x=='-')
		return 1;
	if(x=='*'||x=='/')
		return 2;
	return 0;
}
void main(){
   char exp[SIZE];
   int i,j;
   char x;
   printf("Enter the infix expression to be converted into postfix:\n");
   gets(exp);
   for(i=0;i<=strlen(exp);i++){
   if(isalnum(exp[i]))
   	printf("%c",exp[i]);
   else if(exp[i]=='(')
   	push(exp[i]);
   else if(exp[i]==')'){
   	while((x=pop())!='('){
   		printf("%c",x);
   	}
   }
   else{
   	while(priority(prefix[top])>=priority(exp[i]))
   		printf("%c",pop());
   	push(exp[i]);
   }

   }
   while(top>=0)
   	printf("%c",pop());
}