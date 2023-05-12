// to implement list using array and perform insertion
#include<stdio.h>
int i;
int arr[10];
int size;
int search(int a){
	for(i=0;i<size;i++){
     if(arr[i]==a){
     	printf("The element %d found at index:%d\n",arr[i],i+1);
     return(i);
	}
}
}
 void traverse(){
 	printf("The array is as follows:");
	for(i=0;i<size;i++){
		printf("%d\n",arr[i]);

	}
}
	void insert(int ele,int pos){
		traverse();
		size++;
     for(i=size-1;i>=pos-1;i--){
     	arr[i+1]=arr[i];
     }
     arr[pos-1]=ele;
     printf("The array after insertion is as follows:\n");
     for(i=0;i<size;i++){
     	printf("%d\n",arr[i]);
     }

	}
	void delete(int d){
		int index;
		traverse();
		index=search(d);
		for(i=index;i<size;i++){
			arr[i]=arr[i+1];
		}
       size--;
       traverse();

	}

void main(){ int ch;int ele;int pos;
	printf("Enter the size of array:\n");
	scanf("%d",&size);
	if(size>10){
		printf("Array cannot be created\n");
	}
	else{
	printf("Please enter the elements of the array:\n");
	for(i=0;i<size;i++)
	scanf("%d",&arr[i]);
while(1){
    printf("CHOOSE FROM THE FOLLOWING OPTION:\n");
    printf("1. Traverse\n2. Search\n3. Insertion\n4. Deletion\n ");
    scanf("%d",&ch);
    switch (ch){
    case 1:
    	traverse();
    	break;
    case 2:
    	printf("Enter the element you want to search:\n");
    	scanf("%d",&ele);
        search(ele);
        break;
    case 3:
       printf("Enter the element you want to insert:\n");
       scanf("%d",&ele);
       printf("Enter the position you want to insert the element:\n");
       scanf("%d",&pos);
       insert(ele,pos);
       break;
   case 4:
   	traverse();
   	printf("Enter the element you want to delete:\n");
   	scanf("%d",&ele);
   	delete(ele);
   	break;
}
}
}
}