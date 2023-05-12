#include<stdio.h>
#include<stdlib.h>
#include<string.h>
# define SIZE 50
char stack[SIZE];
int top=-1;
void push(char);
char pop();
int check(char[]);
int match(char,char);
int main(){ while(1){
	int valid;
	char input[SIZE];
	printf("Please enter the algebraic expression:");
	gets(input);
	valid=check(input);
	if(valid==1){
		printf("The expression is valid\n");
	}
	else{
		printf("The expression entered is invalid\n");
	}
	printf("\n");
}
	return 0;
}
int check(char input[])
{
	int i;
	char temp;
	for(i=0;i<strlen(input);i++){
		if(input[i]=='['||input[i]=='('||input[i]=='{')
			push(input[i]);
		if(input[i]==']'||input[i]==')'||input[i]=='}')
		
			if(top==-1){
				printf("Right parenthesis are more than left ones\n");
			    return 0;}
			else{
				temp=pop();
					if(!match(temp,input[i])){
						printf("The mismatched parenthesis are:\n");
						printf("%c and %c\n",temp,input[i]);
						return 0;
					}
					
				}
			}
		
	
	if(top==-1){
		printf("Balanced Parenthesis\n");
		return 1;
	}
	else{
		printf("Left parenthesis are more than right ones\n");
		return 0;
	}
}
int match(char a,char b){
	if(a=='{'&&b=='}')
		return 1;
	if(a=='['&&b==']')
		return 1;
	if(a=='('&&b==')')
		return 1;
    return 0;
}
void push(char element){
if(top==SIZE-1){
	printf("STACK OVERFLOW\n");
    exit(1);}
else{
	top++;
	stack[top]=element;
}
}
char pop(){
if(top==-1){
	printf("STACK UNDERFLOW\n");
    exit(1);}
return (stack[top--]);
}