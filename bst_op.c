#include <stdio.h>
#include <stdlib.h>
// Node structure
struct node {
    struct node *left;
    int data;
    struct node *right;
};
typedef struct node NODE;
NODE *root = NULL;

// Function declarations
void create(int);
void insert(NODE*, NODE*);
NODE* delete(NODE*,int);
int search(NODE*, int);
void traverse(NODE*);
NODE* find_max(NODE*);
void preorder(NODE*);
void postorder(NODE*);
// Function to create and insert a new node
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

// Search for a value in the BST
int search(NODE* root, int key) 
{
    if (root == NULL)
        return 0;
    if (root->data == key)
        return 1;
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}
// Find the maximum value node (used in deletion)
NODE* find_max(NODE* root) 
{
	//here root is the variable which has llife span in the max function only
    if (root == NULL)
        return NULL;
    while (root->right != NULL)
        root = root->right;
    	return root;
}
// Delete a node from the BST
NODE* delete(NODE *root, int value) 
{
    NODE *temp;
    if (root == NULL)
        return NULL;
    if (value < root->data)
        root->left = delete(root->left, value);
    else if (value > root->data)
        root->right = delete(root->right, value);
    else 
	{
        // Node to be deleted found==
        // Case 1: No children
        if (root->left == NULL && root->right == NULL) 
		{
            free(root);
            return NULL;
        }
        // Case 2: One child (right)
        else if (root->left == NULL) 
		{
            temp = root;
            root = root->right;
            free(temp);
        }
        // Case 3: One child (left)
        else if (root->right == NULL) 
		{
            temp = root;
            root = root->left;
            free(temp);
        }
        // Case 4: Two children
        else {
            temp = find_max(root->left); // Or use in-order successor
            //in oder preddesor==highest element/right most element in the left sub tree
            //inoder successor==lowerst element/left most element in the right sub tree
            root->data = temp->data;
            root->left = delete(root->left, temp->data);
        }
    }
    return root;
}

// In-order traversal of the BST
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
    	printf("%d\t", root->data);
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

// Main menu
int main() 
{
    int ch, value;
    do {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert\n2. Traverse (In-Order)\n3. Delete\n4. Search\n5. Traverse (Pre-Order)\n6. Traverse (Post-Order)\n7. Exit\n");
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
                printf("Enter value to delete: ");
                scanf("%d", &value);
                if (search(root, value)) 
				{
                    root = delete(root, value);
                    printf("Value %d deleted from the tree.\n", value);
                }
				 else 
				{
                    printf("Value %d not found in the tree.\n", value);
                }
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(root, value))
                    printf("Value %d found in the tree.\n", value);
                else
                    printf("Value %d not found in the tree.\n", value);
                break;
            case 5:
                if (root == NULL)
                    printf("Tree is empty\n");
                else {
                    printf("Preoreder traverse ");
                    preorder(root);
                    printf("\n");
                }
                break;
            case 6:
                if (root == NULL)
                    printf("Tree is empty\n");
                else {
                    printf("Postorder traverse ");
                    postorder(root);
                    printf("\n");
                }
                break;
            case 7:
            	printf("\nRoll no- 24B11CS487");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (1);
}
