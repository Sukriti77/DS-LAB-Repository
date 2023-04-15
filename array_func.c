#include<stdio.h>
int insert(int*,int);
int deletion(int*,int);
int linearSearch(int*,int);
void main()
{
        int arr[100]={0};
        int i,n;
        int ch;
        printf("Enter the size of array ");
        scanf("%d",&n);
        printf("Enter the elements of array ");
        for(i=0;i<n;i++)
                scanf("%d",&arr[i]);
        printf("Choose the function you want to perform:\n1.Insertion\n2.Deletion\n3.Linear search\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            insert(arr,n);
            break;
        case 2:
            deletion(arr,n);
            break;
        case 3:
            linearSearch(arr,n);
            break;
        default:
            printf("Enter a valid choice");
        }
}
int insert(int arr[],int n)
{
        int i,pos,x;
        printf("Enter the element you want to insert ");
        scanf("%d",&x);
        printf("Enter the position ");
        scanf("%d",&pos);
        n++;
        for(i=n-1;i>=pos;i--)
                arr[i]=arr[i-1];
        arr[pos-1]=x;
        printf("The updated array is:\n");
        for(i=0;i<n;i++)
                printf("%d ",arr[i]);
        return 0;
}
int deletion(int arr[],int n)
{
        int i,pos,x;
        printf("Enter the element you want to delete ");
        scanf("%d",&x);
        for(i=0;i<n;i++)
        {
                if(arr[i]==x)
                {
                        pos=i;
                        break;
                }
        }
        for(i=pos;i<n-1;i++)
                arr[i]=arr[i+1];
        n--;
        printf("The updated array is:\n");
        for(i=0;i<n;i++)
                printf("%d ",arr[i]);
        return 1;
}
int linearSearch(int arr[],int n)
{
        int i,x,pos;
        printf("Enter the element you want to search ");
        scanf("%d",&x);
        for(i=0;i<n;i++)
        {
                if(arr[i]==x)
                {
                        pos=i;
                        break;
                }
        }
        printf("The element %d is found at %d index ",x,pos);
}
