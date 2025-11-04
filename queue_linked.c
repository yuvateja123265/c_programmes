#include<stdio.h>
#include<stdlib.h>
typedef struct queue
{
	int data;
	struct queue *next;
}q;
q *rear=NULL,*front=NULL;
int count=0;
void enqueue(int ele)
{
	q *newnode=(q*)malloc(sizeof(q));
	if(newnode==NULL)
	{
		printf("\nCan't allocate memory");
		return;
	}
	newnode->data=ele;
	newnode->next=NULL;
	if(rear==NULL)
	{
		rear=front=newnode;
	}
	else
	{
		rear->next=newnode;
		rear=newnode;
	}
	printf("%d is inserted",ele);
	count++;
}
int dequeue()
{
	int x;
	if(front==NULL)
	{
		printf("\nQueue is empty");
		return -1;
	}
	q *temp;
	temp=front;
	front=front->next;
	x=temp->data;
	if(front==NULL)
	{
		rear=NULL;
	}
	free(temp);
	return x;
	count--;
}
int peek()
{
	if(front==NULL)
	{
		printf("\nStack underflow");
		return -1;
	}
	else
	{
		int x=front->data;
		return x;
	}
}
void display()
{
	q *temp;
	if(front==NULL)
	{
		printf("\nQueue is empty");
		return;
	}
	temp=front;
	printf("\nThe queue elements are:\n");
	while(temp!=NULL)
	{
		printf("\t%d\n",temp->data);
		temp=temp->next;
	}
}
int main()
{
	int i,n,x;
	while(1)
	{
		printf("\n**Menu**");
		printf("\n1.enqueue\n2.dequeue\n3.display\n4.peek\n5.exit");
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
		case 5:
			printf("\nRoll no:24B11CS487");
			exit(0);
		case 4:
			x=peek();
			if(x!=-1)
			printf("\nTop most element is %d",x);
			break;	
		default:printf("\nInvali operator");
		}
	}
}
