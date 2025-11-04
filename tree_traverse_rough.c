#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	struct node *left;
	int data;
	struct node *right;
}node;
node *root=NULL;
void insert(node*,node*);
void create(int ele)
{
	node *newnode;
	newnode=(node*)malloc(sizeof(node));
	if(newnode==NULL)
	{
		printf("memory notr allocated");
		return;
	}
	newnode->data=ele;
	newnode->left=newnode->right=NULL;
	if(root==NULL)
	{
		root=newnode;
	}
	else
	insert(root,newnode);
}
void insert(node *root,node *newnode)
{
	if(root->data>newnode->data)
	{
		if(root->left==NULL)
		{
			root->left=newnode;
		}
		else
		insert(root->left,newnode);
	}
	else
	{
		if(root->right==NULL)
		{
			root->right=newnode;
		}
		else
		insert(root->right,newnode);
	}
}
void inorder(node *root)
{
	if(root!=NULL)
	{
	inorder(root->left);
	printf("%d-\t",root->data);
	inorder(root->right);
	}
}
void preorder(node *root)
{
	if(root!=NULL)
	{
		printf("%d-\t",root->data);
		inorder(root->left);
		inorder(root->right);	
	}
}
void postorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		inorder(root->right);
		printf("%d-\t",root->data);	
	}
}
int main()
{
	create(20);
	create(10);
	create(30);
	inorder(root);
	preorder(root);
	postorder(root);
	return 0;
}
