//both insertion and deletion takes from top end
#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
	int data;
	struct stack *next;
}sta;
sta *top=NULL;
int count=0;
void push(int x)
{
	sta *newnode=(sta*)malloc(sizeof(sta));
	if(newnode==NULL)
	{
		printf("\nMemory is not created");
		return;
	}
	newnode->data=x;
	newnode->next=NULL;
	if(top==NULL)
	{
		top=newnode;
	}
	else
	{
		newnode->next=top;
		top=newnode;
	}
	count++;
	printf("%d is pushed to stack",x);
}
int pop()
{
	sta *temp;
	int x;
	if(top==NULL)
	{
		printf("\nstack underflow");
		return -1;
	}
	else
	{
		temp=top;
		x=top->data;
		top=top->next;
		free(temp);
		count--;
		return x;
	}
}
int peek()
{
	if(top==NULL)
	{
		printf("\nstack underflow");
		return -1;
	}
	else
	return top->data;
}
void display()
{
	sta *temp=top;
	if(top==NULL)
	{
		printf("\nstack underflow");
		return;
	}
	while(temp!=NULL)
	{
		printf("\t%d\n",temp->data);
		temp=temp->next;
	}
}
int main()
{
	int x,data;
	while(1)
	{
		printf("\n**MENU**");
		printf("\n1.push\n2.pop\n3.peek\n4.display\n5.exit");
		printf("\nEnter your choice:");
		scanf("%d",&x);
		switch(x)
		{
			case 1:printf("\nEnter data to push:");
					scanf("%d",&data);
					push(data);
					printf("\nElement is pushed in the stack");
					break;
			case 2:
				x=pop();
				if(x!=-1)
				printf("THE POPPED ELEMENT IS %d",x);
				break;
			case 3:
				x=peek();
				if(x!=-1)
				printf("The element at the top is %d",x);
				break;
			case 4:
				printf("\nSTACK ELEMENGTS ARE:\n");
				display();
				break;
			case 5:printf("\nRoll no:24B11CS487");
				exit(0);
			default:printf("\nInvalid operator");
		}
	}
}
