//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: complete
#include <stdio.h>
#include <stdlib.h>

/* Structure for a single node in a linked list */
struct Node 
{ 
	int data; 
	struct Node *next; 
}; 

/* Function to create a new node with the given data */
struct Node* newNode(int data) 
{ 
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
	temp->data = data; 
	temp->next = NULL; 
	return temp; 
} 

/* Function to display the elements of a linked list */
void display(struct Node* head) 
{ 
	struct Node* current = head; 
	while (current!= NULL) 
	{ 
		printf("%d ", current->data); 
		current = current->next; 
	} 
	printf("\n"); 
} 

/* Function to insert a new node at the beginning of a linked list */
void push(struct Node** head_ref, int new_data) 
{ 
	struct Node* new_node = newNode(new_data); 
	new_node->next = (*head_ref); 
	(*head_ref) = new_node; 
} 

/* Function to remove and return the first node in a linked list */
struct Node* pop(struct Node** head_ref) 
{ 
	struct Node* temp = *head_ref; 
	if (*head_ref == NULL) 
		return NULL; 
	*head_ref = (*head_ref)->next; 
	free(temp); 
	return temp; 
} 

/* Function to reverse a linked list */
void reverse(struct Node** head_ref) 
{ 
	struct Node* prev = NULL; 
	struct Node* current = *head_ref; 
	struct Node* next; 
	
	while (current!= NULL) 
	{ 
		next = current->next; 
		current->next = prev; 
		prev = current; 
		current = next; 
	} 
	*head_ref = prev; 
} 

/* Function to return the length of a linked list */
int length(struct Node* head) 
{ 
	int count = 0; 
	struct Node* temp = head; 
	
	while (temp!= NULL) 
	{ 
		count++; 
		temp = temp->next; 
	} 
	return count; 
} 

/* Driver code */
int main() 
{ 
	struct Node* head = NULL; 
	push(&head, 1); 
	push(&head, 2); 
	push(&head, 3); 
	push(&head, 4); 
	
	display(head); 
	
	pop(&head); 
	display(head); 
	
	reverse(&head); 
	display(head); 
	
	printf("\nLength of the linked list is %d", length(head)); 
	
	return 0; 
}