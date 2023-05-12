#include<stdio.h>
#include<stdlib.h>
#define SIZE 50
int queque[SIZE];
int front=0;
int rear=0;
int i;
void enqueque(int x){
	if(rear==SIZE-1){
		printf("QUEQUE OVERFLOW\n");
	}
	else{
		queque[rear++]=x;
	}
}
void display(){
	if(rear==front){
		printf("UNDERFLOW\n");
	}
	else{
		for(i=front;i<rear;i++)
		printf("%d\t",queque[i]);
	}

}
int isempty(){
	if(front==rear)
		return 1;
	return 0;
}
int dequeque(){
	if(isempty()){
		printf("UNDERFLOW\n");
		return 0;
	}
	else{
      int element;
      element=queque[front];
      for(i=front+1;i<rear;i++)
      	queque[i-1]=queque[i];
        rear--;
      return element;
	}
}
	void search(int val){
		for(i=front;i<rear;i++){
			if(queque[i]==val){
				printf("The value %d found at %d\n",queque[i],i+1);
			}
		
		else
			printf("Value not found\n");
	}
}


void main(){
	int ch;int t;int val;while(1){
	printf("\n1. to enqueque an element\n2. to display the queque\n3. to dequeque the queque\n4. to search an element\n");
	printf("Enter your choice:\n");
	scanf("%d",&ch);
	switch(ch){
	case 1:
    printf("Enter the element you want to enqueque:\n");
    scanf("%d",&t);
    enqueque(t);
    break;
    case 2:
    	printf("Displaying the queque:\n");
    	display();
        break;
    case 3:
    	printf("the deleted element is:%d\n",dequeque());
    	break;
    case 4:
    	printf("Enter the value you wish to search:\n");
    	scanf("%d",&val);
    	search(val);
    	break;
	}

}
}

