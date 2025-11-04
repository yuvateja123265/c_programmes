//Circular Queue operations 
#include<stdio.h> 
#include<stdlib.h> 
#define MAX 5 
int Q[MAX],front=-1,rear=-1; 
void enque(); 
int deque(); 
void display(); 
void enque(int ele) 
{ 
	if(front==(rear+1)%MAX) 
	printf("Circular Queue is overflow.\n"); 
	else 
	{ 
		if(rear==-1) 
		{
			front=rear=0;	
		} 
  		else 
  		{
  			rear=(rear+1)%MAX;	
		} 
  		Q[rear]=ele;
 	} 
} 
int deque() 
{ 
	if(front==-1) 
	{
		printf("Circular Queue is underflow.\n"); 
		return -1;
	}
	else 
 	{ 
  		int x=Q[front];
  		if(front==rear) 
  			front=rear=-1; 
  		else 
  			front=(front+1)%MAX; 
  		return x;
 	} 
} 
void display() 
{ 
	if(front==-1) 
		printf("Circular Queue is empty.\n"); 
 	else 
 	{ 
  		int i=front; 
  		printf("\nCircular Queue is elements are\n"); 
  		/*while(i!=rear)
  		{ 
   			printf("%d\t",Q[i]); 
   			i=(i+1)%MAX; 
  		} 
  		printf("%d\n",Q[i]); */
  		do
  		{
  			printf("%d\t",Q[i]); 
   			i=(i+1)%MAX;	
		}while(i!=front);
 	} 
} 
int main() 
{ 
 	int ch,x; 
 	do 
 	{ 
  		printf("\n1.ENQUE\n2.DEQUE\n3.Display\nEnter your choice:"); 
  		scanf("%d",&ch); 
  		switch(ch) 
  		{ 
   			case 1:
			   printf("Enter data to insert:"); 
			   scanf("%d",&x);
			   enque(x);  
			   break; 
   			case 2:
			   x=deque(); 
			   if(x!=-1)
			   printf("%d is deleted",x);
			   break; 
   			case 3:
			   display();
			   break; 
   			default:exit(0); 
  		} 
 	}while(1); 
}
