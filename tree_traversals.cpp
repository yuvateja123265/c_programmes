/*coded by V.Nikhita*/
#include <stdio.h>
#include <stdlib.h>
// Node structure
struct node 
{
    struct node *left;
    int data;
    struct node *right;
};
typedef struct node NODE;
void insert(NODE*,NODE*);
NODE *root = NULL;
void create(int value) {
    NODE *newnode = (NODE*)malloc(sizeof(NODE));
    if (newnode == NULL) {
        printf("Memory not allocated\n");
        return;
    }
    newnode->data = value;
    newnode->left = newnode->right = NULL;

    if (root == NULL)
        root = newnode; // First node becomes root
    else
        insert(root, newnode); // Insert elsewhere
}

// Recursive insertion
void insert(NODE *root, NODE *newnode) {
    if (newnode->data < root->data) 
	{
        if (root->left == NULL)
            root->left = newnode;
        else
            insert(root->left, newnode);
    } 
	else 
	{
        if (root->right == NULL)
            root->right = newnode;
        else
            insert(root->right, newnode);
    }
}
void traverse(NODE *root) {
    if (root != NULL) {
        traverse(root->left);
        printf("%d\t", root->data);
        traverse(root->right);
    }
}
void preorder(NODE *root) 
{
    if (root != NULL) 
	{
    	printf("\n\t%d\t", root->data);
        traverse(root->left);
        traverse(root->right);
    }
}
void postorder(NODE *root) 
{
    if (root != NULL) 
	{
        traverse(root->left);
        traverse(root->right);
        printf("%d\t", root->data);
    }
}
int main()
{
    int ch, value;
    do {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert\n2. Traverse (In-Order)\n3. Traverse (Pre-Order)\n4. Traverse (Post-Order)\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &value);
                create(value);
                break;
            case 2:
                if (root == NULL)
                    printf("Tree is empty\n");
                else {
                    printf("In-Order Traversal: ");
                    traverse(root);
                    printf("\n");
                }
                break;
            case 3:
                if (root == NULL)
                    printf("Tree is empty\n");
                else {
                    printf("Preoreder traverse ");
                    preorder(root);
                    printf("\n");
                }
                break;
            case 4:
                if (root == NULL)
                    printf("Tree is empty\n");
                else {
                    printf("Postorder traverse ");
                    postorder(root);
                    printf("\n");
                }
                break;
            case 5:
            	printf("\nRoll no- 24B11CS487");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (1);
}
