#include<stdio.h>
#include<stdlib.h>
// Define the structure for a node
typedef struct node
{
	int data;
	struct node *next;
} N;
// Global pointers for head and end of the list
struct node *head = NULL;
struct node *end = NULL; // 'end' will point to the last node
// Global variable to keep track of the number of nodes
int count = 0;
// Function to create a new node
struct node* create_nodes()
{
	int info;
	struct node *newnode;
	// Allocate memory for the new node
	newnode = (struct node*)malloc(sizeof(struct node));
	// Check if memory allocation was successful
	if(newnode == NULL)
	{
		printf("Overflow: Memory allocation failed\n");
		return ; // Return NULL on failure
	}
	// Get data from the user
	printf("\nEnter data into a node: ");
	scanf("%d", &info);
	// Assign data to the new node
	newnode->data = info;
	newnode->next = NULL; // Initially, next is NULL
	return newnode;
}
// Function to create the initial circular linked list
void create_list()
{
	struct node *newnode = create_nodes();
	// If create_nodes failed, return
	if (newnode == NULL) {
		return;
	}
	// If the list is empty
	if(head == NULL)
	{
		head = end = newnode;
		end->next = head; // Make it circular
	}
	else // If list is not empty, add to the end
	{
		end->next = newnode;
		end = newnode;
		end->next = head; // Maintain circularity
	}
	count++;
	printf("\nNode created and added to the list.\n");
}
// Function to insert a node at the beginning
void insert_beg()
{
	struct node *newnode = create_nodes();
	// If create_nodes failed, return
	if (newnode == NULL) {
		return;
	}
	// If the list is empty
	if(head == NULL)
	{
		head = end = newnode;
		end->next = head; // Make it circular
	}
	else // If list is not empty
	{
		newnode->next = head; // New node points to the current head
		head = newnode;       // New node becomes the head
		end->next = head;     // Last node points to the new head
	}
	count++;
	printf("\nNode is inserted at beginning.\n");
}
// Function to insert a node at the end
void insert_end()
{
	/*// We can reuse the create_list logic for adding to the end
	create_list();
	// Note: create_list already increments count and prints message*/
	N *newnode =create_nodes();
	if(newnode==NULL)
	{
		head=end=newnode;
		newnode->next=head;
	}
	else
	{
		end->next=newnode;
		end=newnode;
		end->next=head;
	}
	count++;
	printf("Node is inserted at end");
}
// Function to insert a node at any specified position
void insert_any()
{
	int p, i; // p = position
	printf("\nEnter position to insert: ");
	scanf("%d", &p);
	// Validate the position
	if(p < 1 || p > count + 1)
	{
		printf("Can't insert a node at position %d", p);
		return;
	}
	// If inserting at the beginning
	if(p == 1)
	{
		insert_beg();
		return;
	}

	// If inserting at the end (position count + 1)
	if(p == count + 1)
	{
		insert_end();
		return;
	}
	// Insert at an intermediate position
	N *newnode = create_nodes();
	// If create_nodes failed, return
	if (newnode == NULL) {
		return;
	}
	N *temp = head;
	// Traverse to the node before the desired position
	for(i = 1; i < p - 1; i++)
	{
		temp = temp->next;
	}
	// Adjust pointers for insertion
	newnode->next = temp->next;
	temp->next = newnode;
	count++;
	printf("\nNode is inserted at position %d.\n", p);
}
// Function to delete a node from the beginning
void delete_beg()
{
	// Check if the list is empty
	if(head == NULL)
	{
		printf("\nList is empty. Cannot delete.\n");
		return;
	}
	N *temp = head;
	// If there is only one node
	if(head == end)
	{
		head = NULL;
		end = NULL;
	}
	else // If there are multiple nodes
	{
		head = head->next; // Move head to the next node
		end->next = head;  // Last node points to the new head
	}
	free(temp); // Free the memory of the old head
	count--;
	printf("\nNode is deleted from the beginning.\n");
}

// Function to delete a node from the end
void delete_end()
{
	N *temp = head;
	N *curr = NULL; // Pointer to the node before the last node
	// Check if the list is empty
	if(head == NULL)
	{
		printf("\nList is empty. Cannot delete.\n");
		return;
	}
	// If there is only one node
	if(head == end)
	{
		head = NULL;
		end = NULL;
	}
	else // If there are multiple nodes
	{
		// Traverse to the second last node
		while (temp != end)
		{
			curr=temp;
			temp = temp->next;
		}
		// 'temp' is now the second last node
		curr->next = head; // Second last node points to head
		end = curr;        // Second last node becomes the new end
	}
	free(temp);
	count--;
	printf("\nNode is deleted from the end.\n");
}

// Function to delete a node from any specified position
void delete_any()
{
	int i, pos;
	printf("\nEnter position to delete: ");
	scanf("%d", &pos);

	// Validate the position
	if(pos < 1 || pos > count)
	{
		printf("\nCan't delete a node at position %d. Position must be between 1 and %d.\n", pos, count);
		return;
	}

	// If deleting the first node
	if(pos == 1)
	{
		delete_beg();
		return;
	}

	// If deleting the last node
	if(pos == count)
	{
		delete_end();
		return;
	}

	// Delete at an intermediate position
	N *temp = head;
	N *prev = NULL; // Pointer to the node before the one to be deleted

	// Traverse to the node to be deleted
	for(i = 1; i < pos; i++)
	{
		prev = temp;
		temp = temp->next;
	}
	// Adjust pointers to bypass the node to be deleted
	prev->next = temp->next;
	free(temp); // Free the memory of the deleted node

	count--;
	printf("Node is deleted at position %d.\n", pos);
}

// Function to display the elements of the circular linked list
void display()
{
	struct node *temp;

	// Check if the list is empty
	if(head == NULL)
	{
		printf("List is empty.\n");
		return ;
	}

	temp = head;

	// Traverse and print elements until we reach the head again
	do
	{
		printf("%d -> ", temp->data);
		temp = temp->next;
	} while(temp != head);
	printf(" (back to head)\n"); // Indicate the circular nature
}

// Function to reverse the circular linked list
void reverse()
{
	struct node *next_node = NULL;
	struct node *prev_node = NULL;
	struct node *curr = head;

	// Check if the list is empty
	if(head == NULL)
	{
		printf("\nList is empty. Cannot reverse.\n");
		return;
	}

	// If there is only one node, no need to reverse
	if (head->next == head) {
		printf("\nOnly one node in the list. No reversal needed.\n");
		return;
	}

	// Perform reversal similar to a linear list
	while(curr != end) // Iterate until the current node is the original 'end'
	{
		next_node = curr->next; // Store the next node
		curr->next = prev_node; // Reverse the current node's pointer
		prev_node = curr;       // Move prev_node to the current node
		curr = next_node;       // Move curr to the next node
	}

	// After the loop, 'curr' is the original 'end' node
	// Reverse the pointer of the original 'end' node
	curr->next = prev_node;

	// Update head and end pointers
	// The original 'end' becomes the new head
	head = curr;
	// The original 'head' becomes the new end
	end = next_node; // next_node holds the original head after the loop finishes

	// Make the list circular again by connecting the new end to the new head
	end->next = head;


	printf("Elements are reversed.\n");
}

int main()
{
	int ch;
	while(1)
	{
		printf("\n***Circular Single Linked List Menu***");
		printf("\n1. Create List\n2. Display\n3. Size of List\n4. Reverse\n5. Insert at Beginning\n6. Insert at End");
		printf("\n7. Delete at Beginning\n8. Delete at End\n9. Insert at Any Position\n10. Delete at Any Position\n11. Exit");
		printf("\nEnter your choice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: create_list(); break;
			case 2: display(); break;
			case 3: printf("\nNumber of nodes are: %d\n", count); break;
			case 4: reverse(); break;
			case 5: insert_beg(); break;
			case 6: insert_end(); break;
			case 7: delete_beg(); break;
			case 8: delete_end(); break;
			case 9: insert_any(); break;
			case 10: delete_any(); break;
			case 11: exit(0);

			default: printf("\nInvalid choice. Please enter a number between 1 and 11.\n");
		}
	}
	return 0;
}
