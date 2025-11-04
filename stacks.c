#include<stdio.h>
#include<stdlib.h>
#define size 5
int stack[size];
int top=-1;
void push(int);
int pop();
void display();
int peek();
/*int isEmpty();
int isEmpty()
{
	if(top==-1)
	{
		return 1;
	}
	else
	return 0;
}*/
void push(int n)
{
	if(top==size-1)
	{
		printf("\nStack is overflow");
		return;
	}
	else
	{
		top++;
		stack[top]=n;
		printf("\nElement is pushed in the stack");
	}
}
int pop()
{
	int x;
	if(top==-1)
	{
		printf("\nUnderflow");
		return;
	}
	else
	{
		x=stack[top];
		top--;
	}
	return x;
}
int peek()
{
	int x;
	if(top==-1)
	{
		printf("\nStack Underflow");
		return;
	}
	else
	{
		return stack[top];	
	}
}
void display()
{
	int i;
	if(top==-1)
	{
		printf("\nStack Underflow");
		return;
	}
	printf("Th elements of the stack are:\n");
		for(i=top;i>=0;i--)
		{
			printf("\n%d",stack[i]);
		}
}
int main()
{
	int x,data;
	while(1)
	{
		printf("\n**MENU**");
		printf("\n1.push\n2.pop\n3.peek\n4.display\n5.Roll NO\n6.exit");
		printf("\nEnter your choice:");
		scanf("%d",&x);
		switch(x)
		{
			case 1:printf("\nEnter data to push:");
					scanf("%d",&data);
					push(data);
					break;
			case 2:
				printf("THE POPPED ELEMENT IS %d",pop());
				break;
			case 3:
				printf("The element at the top is %d",peek());
				break;
			case 4:
				display();
				break;
			case 5:printf("\nRoll No:24B11CS487");break;
			case 6:exit(0);
			default:printf("\nInvalid operator");
		}
	}
}

