#include<stdio.h>
#include<stdlib.h>
#define size 6
int queue[size];
int rear=-1,front=-1;
void enqueue(int ele)
{
	if(rear==size-1)
	{
		printf("Queue is full");
		return;
	}
	else
	{
		if(rear==-1)
		{
			front=rear=0;
		}
		else
		{
			rear++;	
		}
		queue[rear]=ele;
	}
	printf("%d is inserted",ele);
	return;
}
int dequeue()
{
	int x;
	if(front==-1||front>rear)
	{
		printf("\nQueue is empty");
		return -1;
	}
	else
	{
		x=queue[front];
		/*front++;
		if(front>rear)
		{
			front=rear=-1;
		}*/
		if(front==rear)
		{
			front=rear=-1;
		}
		else
			front++;
		return x;
	}
}
void display()
{
	
	int i;
	if(front==-1||front>rear)
	{
		printf("\nqueue is empty");
		return;
	}
	printf("The elements in the queue are:\n");
	for(i=front;i<=rear;i++)
	{
		printf("\t%d\n",queue[i]);
	}
}
int main()
{
	int i,n,x;
	while(1)
	{
		printf("\n**Menu**");
		printf("\n1.enqueue\n2.dequeue\n3.display\n4.exit");
		printf("\nEnter your choice:");
		scanf("%d",&i);
		switch(i)
		{
		case 1:
			printf("\nenter element to insert:");
			scanf("%d",&n);	
			enqueue(n);
			break;
		case 2:
			x=dequeue();
			if(x!=-1)
			printf("\n%d is deleted",x);
			break;
		case 3:
			display();
			break;
		case 4:
			printf("\nRoll no:24B11CS487");
			exit(0);
		default:printf("\nInvali operator");
		}
	}
}
