#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}N;
int count=0;
N *head=NULL,*end=NULL;
struct node* create_node()
{
	N *newnode=(N*)malloc(sizeof(N));
	if(newnode==NULL)
	{
		printf("\nOverflow");
		return;
	}
	int data;
	printf("\nEnter data into newnode:");
	scanf("%d",&data);
	newnode->data=data;
	newnode->next=NULL;
	newnode->prev=NULL;
	return newnode; 
}
void create_list()
{
	N *newnode=create_node();
	if(head==NULL)
	{
		head=end=newnode;
	}
	else
	{
		end->next=newnode;
		newnode->prev=end;
		end=newnode;
	}
	printf("\nNode is inserted");
	count++;
}
void insert_beg()
{
	N *newnode=create_node();
	if(head==NULL)
	{
		head=end=newnode;
	}
	else
	{
		//newnode->next=head;
		//head->prev=newnode;
		head->prev=newnode;
		newnode->next=head;
		head=newnode;
	}
	printf("\nNewnode is inserted at begg");
	count++;
}
void insert_end()
{
	N *newnode=create_node();
	if(head==NULL)
	{
		head=end=newnode;
	}
	else
	{
		end->next=newnode;
		newnode->prev=end;
		end=newnode;
	}
	printf("\nNewnode is inserted at ending");
	count++;
}
void insert_pos()
{
	int i,pos;
	printf("\nEnter posistion:");
	scanf("%d",&pos);
	if(pos<1||pos>count+1)
	{
		printf("\nCan't insert ");
		return;
	}
	else if(pos==1)
	{
		insert_beg();
		return;
	}
	else if(pos==count+1)
	{
		insert_end();
		return;
	}
	else
	{
		N *newnode=create_node();
		N *temp,*curr;
		temp=head;
		for(i=1;i<pos;i++)
		{
			curr=temp;
			temp=temp->next;
		}
		curr->next=newnode;
		newnode->prev=curr;
		newnode->next=temp;
		temp->prev=newnode;
	}
	printf("\nNewnode is inserted at %d",pos);
	count++;
}
void delete_beg()
{
	if(head==NULL)
	{
		printf("\nList is empty");
		return;
	}
	else
	{
		N *temp=head;
		head=head->next;
		if(head==NULL)
		{
			end=NULL;
		}
		else
		{
			head->prev=NULL;	
		}
		free(temp);
	}
	count--;
	printf("\nNewnode is deleted at begginning");
}
void delete_end()
{
	if(head==NULL)
	{
		printf("\nList is empty");
		return;	
	}
	N *temp=end;
	end=end->prev;
	if(end==NULL)
	{
		head=NULL;
	}
	else
	end->next=NULL;
	free(temp);
	count--;
	printf("\nNode is deleted at end");
}
void delete_any()
{
	int i,pos;
	printf("\nEnter posistion:");
	scanf("%d",&pos);
	if(pos<1||pos>count)
	{
		printf("\nCan't delete");
		return;
	}
	else if(pos==1)
	{
		delete_beg();
		return;
	}
	else if(pos==count)
	{
		delete_end();
		return;
	}
	else
	{
		N *temp=head,*curr;
		for(i=1;i<pos;i++)
		{
			curr=temp;
			temp=temp->next;
		}
		curr->next=temp->next;
		temp->next->prev=curr;
		free(temp);
	}
	count--;
	printf("\nNode is deleted at %d",pos);
}
void display()
{
	if(head==NULL)
	{
		printf("\nList is empty");
		return;
	}
	else
	{
		N *temp=head;
		while(temp!=NULL)
		{
			printf("%d->",temp->data);
			temp=temp->next;
		}	
	}
}
int main()
{
	int n;
	while(1)
	{
		printf("\n**MENU**\n");
		printf("\n1.create node\n2.display\n3.reversing display\n4.insert at begging");
		printf("\n5.insert at end\n6.insert at any\n7.delete begginning");
		printf("\n8.Delete at end\n9.Deletin at any\n10.exit");
		printf("\nEnter your choice:");
		scanf("%d",&n);
		switch(n)
		{
			case 1:create_list();break;
			case 2:display();break;
			case 4:insert_beg();break;
			case 5:insert_end();break;
			case 6:insert_pos();break;
			case 7:delete_beg();break;
			case 8:delete_end();break;
			case 9:delete_any();break;
			case 10:exit(0);
			default:printf("\nInvalid operator");
		}	
	}
}
