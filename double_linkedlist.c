#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *prev,*next;
	int data;
};
struct node *head=NULL,*end=NULL;
int count=0;
struct node* create_node()
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	int info;
	if(newnode==NULL)
	{
		printf("\nCant allocate memory");
		return;
	}
	printf("\nEnter data into node");
	scanf("%d",&info);
	newnode->data=info;
	newnode->next=NULL;
	newnode->prev=NULL;
	return newnode;
}
void create_list()
{
	struct node*newnode=create_node();
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
	count++;
	printf("\nNode is created");	
}
void display()
{
	struct node *temp;
	temp=head;
	if(head==NULL)
	{
		printf("\nList is empty");
		return;
	}
	printf("\n");
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
}
void insert_beg()
{
	struct node *newnode=create_node();
	if(head==NULL)
	{
		head=end=newnode;
	}
	else
	{
		head->prev=newnode;
		newnode->next=head;
		head=newnode;	
	}
	count++;
	printf("\nNode is inserted at beinning");
}
void insert_end()
{
	struct node *newnode=create_node();
	if(head==NULL)
	{
		end=head=newnode;
	}
	else
	{
		end->next=newnode;
		newnode->prev=end;
		end=newnode;	
	}
	count++;
	printf("\nNode is created at end");
}
void reverse_display()
{
	struct node *temp;
	temp=end;
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->prev;
	}printf(" NULL");
}
void insert_any()
{
	struct node *newnode;
	struct node *temp,*curr;
	int pos,i;
	temp=head;
	printf("\nEnter posistion to be inserted:");
	scanf("%d",&pos);
	if(pos<1||pos>count+1)
	{
		printf("\nInvalid posistion");
		return;
	}
	if(pos==1)
	{
		insert_beg();
		return;
	}
	else if(pos==count+1)
	{
		insert_end();	
		return;
	}
	newnode=create_node();
	for(i=1;i<pos;i++)
	{
		curr=temp;
		temp=temp->next;
	}
	curr->next=newnode;
	newnode->prev=curr;
	newnode->next=temp;
	temp->prev=newnode;
	count++;
	printf("\nNode is created at %d posisition",pos);
}
void delete_beg()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("\nList is empty");
		return;
	}
	temp=head;
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
	count--;
	printf("\nNode is deleted at begginning");
}
void delete_end()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("\nList is empty");
		return;
	}
	temp=end;
	end=end->prev;
	if(end==NULL)
	{
		head=NULL;
	}
	else
	{
		end->next=NULL;
	}
	free(temp);
	count--;
	printf("\nNode is deleted at end");
}
void delete_any()
{
	struct node *temp,*curr;
	int i,pos;
	printf("enter posistion:");
	scanf("%d",&pos);
	if(pos<1||pos>count)
	{
		printf("\nCan'ot insert");
		return;
	}
	if(pos==1)
	{
		delete_beg();
		return;
	}
	if(pos==count)
	{
		delete_end();
		return;
	}
	else
	{
		curr=head;
		for(i=1;i<pos;i++)
		{
			temp=curr;
			curr=curr->next;
		}
		temp->next=curr->next;
		curr->next->prev=temp;
		free(curr);
	}
	count--;
	printf("\nNode is deleted at %d",pos);
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
			case 3:reverse_display();break;
			case 4:insert_beg();break;
			case 5:insert_end();break;
			case 6:insert_any();break;
			case 7:delete_beg();break;
			case 8:delete_end();break;
			case 9:delete_any();break;
			case 10:exit(0);
		}	
	}
}
