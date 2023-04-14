#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int stack[SIZE];
int top=-1;
void push(){
	if(top==(SIZE-1)){
     printf("OVERFLOW");
	}
	else{
		top++;
		int element;
		printf("Enter the element:\n");
		scanf("%d",&element);
		stack[top]=element;
		printf("The elemnet is inserted successfully\n");

	}
}
void display(){
	if(top==-1){
		printf("UNDERFLOW");
	}
	else{
		for(int i=top;i>=0;i--){
			printf("%d",stack[i]);
			printf("\n");
		}
	}
}
void pop(){
	if(top==-1){
		printf("UNDERFLOW");
	}
	else{
		int item;
		item=stack[top];
		printf("Element removed successfully.\n");
		printf("Elemnet removed is %d", stack[top]);
		top--;
	}
}
void exit_function(){
	exit(0);
}
void main(){
	while(1){
		int choice;
		printf("PLEASE ENTER YOUR CHOICE");
		printf("\n");
		printf("1.Push\n2.Display\n3.Pop\n4.Exit");
		scanf("%d",&choice);
		switch (choice){
		case 1:
			push();
			break;
		case 2:
		    display();
		    break;
		case 3:
		    pop();
		    break;    
        case 4:
        	exit_function();
        	break;
        default :
         printf("INVALID INPUT");	
		
		}
			}
}