#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}N;
struct node *head=NULL,*end=NULL;
int count=0;
struct node* create_nodes()
{
	int info;
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("Overflow");
		return;
	}
	printf("\nEnter data into a node:");
	scanf("%d",&info);
	newnode->data=info;
	newnode->next=NULL;
	return newnode;
}
void create_list()
{
	struct node *newnode=create_nodes();
	if(head==NULL)
	{
		head=end=newnode;
	}
	else
	{
		end->next=newnode;
		end=newnode;
	}
	count++;
}	
void insert_beg()
{
	struct  node *newnode=create_nodes();
	if(head==NULL)
	{
		head=end=newnode;
		return;
	}
	else
	{
		newnode->next=head;
		head=newnode;
	}
	printf("\nNode is inserted at begginning");
	count++;
}
void insert_end()
{
	/*struct node *newnode=create_nodes();
	if(head==NULL)
	{
		head=end=newnode;
		return;
	}
	else
	{
		end->next=newnode;
		end=newnode;
	}
	printf("\nNode is inserted at end");*/
	create_list();
	count++;
}
void insert_any()
{
	int p,i;//p=posistion
	printf("\nEnter posistion");
	scanf("%d",&p);
	if(p<1||p>count+1)
	{
		printf("Can't insert a node at the %d posistion",p);
		return;
	}
	if(p==1)
	{
		insert_beg();
		return;
	}
	/*if(p==count+1)
	{
		insert_end();
		return;
	}*/
	N *newnode=create_nodes();
	N *temp=head;
	for(i=1;i<p-1;i++)
	{
		temp=temp->next;
	}
	newnode->next=temp->next;
	temp->next=newnode;
	count++;
	printf("\nNode is inserted at %d",p);
}
void delete_beg()
{
	if(head==NULL)
	{
		printf("\nList is empty");
		return;
	}
	N *temp;
	temp=head;
	head=head->next;
	if(head==NULL)
	{
		end=NULL;
	}
	free(temp);
	count--;
	printf("\nNode is deleted at begginning");
}
void delete_end()
{
	N *temp,*curr;
	if(head==NULL)
	{
		printf("\nList is empty");
		return;
	}
	else if(head->next==NULL)
	{
		head=end=NULL;
		free(head);
	}
	else
	{
		temp=head;
	 	while (temp->next != NULL) 
		{ 
			curr=temp;
        	temp = temp->next; 
    	} 
    	curr->next=NULL;
    	end=curr;
		free(temp);	
	}
    count--;
    printf("\nNode is deleted at end");
}
void delete_any()
{
	int i,pos;
	printf("\nEnter posistion");
	scanf("%d",&pos);
	if(pos<1||pos>count)
	{
		printf("\nCan't delete a node at %d posistion",pos);
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
	N *temp,*prev;
	temp=head;
	for(i=1;i<pos;i++)
	{
		prev=temp;
		temp=temp->next;
	}
	prev->next=temp->next;
	free(temp);
	count--;
	printf("Node id deleted at %d posistion",pos);
}
void display()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("list is empty");
		return ;
	}
	temp=head;
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
}//end of display
void reverse()
{
	struct node *next1,*prev,*curr;
	if(head==NULL)
	{
		printf("\nlIST IS EMPTY");
		return;
	}
	prev=NULL;
	next1=NULL;
	curr=head;
	end=head;
	while(curr!=NULL)
	{
		next1=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next1;
	}
	head=prev;
	printf("Elements are reversed");
}
int main()
{
	int ch;
	while(1)
	{
		printf("\n***Menu***");
		printf("\n1.create\n2.Display\n3.Size of  list\n4.reverse\n5.insert at beg\n6.insert at end");
		printf("\n7.delete at beg\n8.delete at end\n9.Insert at any\n10.delete at any\n11.exit");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:create_list();break;
			case 2:display();break;
			case 3:printf("\nNo of nodes are:%d",count);break;
			case 4:reverse();break;
			case 5:insert_beg();break;
			case 6:insert_end();break;
			case 7:delete_beg();break;
			case 8:delete_end();break;
			case 9:insert_any();break;
			case 10:delete_any();break;
			case 11:exit(0);
			case 12:
				printf("\nhead=%d",head);
				printf("\nhead->next=%d",head->next);
				printf("\nhead->data=%d",head->data);
				printf("\nend->next=%d",end->next);
				printf("\nend->data=%d",end->data);
				break;
			default:printf("\nInvalid operator");
		}
	}
	return 0;	
}
