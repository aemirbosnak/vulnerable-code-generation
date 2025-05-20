//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node{
	int data;
	struct Node* next;
};

// Function to add a node to the beginning of the list
void push(struct Node** head_ref, int new_data){
	// Allocate memory for new node
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	
	// Initialize the fields of the new node
	new_node->data = new_data;
	new_node->next = (*head_ref);
	
	// Move the old head pointer to point to the new node
	(*head_ref) = new_node;
}

// Function to add a node to the end of the list
void append(struct Node** head_ref, int new_data){
	// Create a new node and initialize its fields
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	
	// Traverse the list until the last node is reached
	struct Node* current = *head_ref;
	while (current->next!= NULL) {
		current = current->next;
	}
	
	// Make the new node point to the previous node
	new_node->next = current->next;
	
	// Update the previous node's next pointer to point to the new node
	current->next = new_node;
}

// Function to display the linked list
void display(struct Node* head){
	struct Node* current = head;
	while (current!= NULL){
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

// Function to remove the first node from the list
void pop(struct Node** head_ref){
	// If the list is empty, return
	if (*head_ref == NULL){
		printf("List is empty.\n");
		return;
	}
	
	// Move the head pointer to point to the next node
	struct Node* temp = (*head_ref);
	(*head_ref) = (*head_ref)->next;
	
	// Free the memory occupied by the removed node
	free(temp);
}

// Function to remove the last node from the list
void removeLast(struct Node** head_ref){
	// If the list is empty, return
	if (*head_ref == NULL){
		printf("List is empty.\n");
		return;
	}
	
	// If the list has only one node, remove it
	if ((*head_ref)->next == NULL){
		*head_ref = NULL;
		return;
	}
	
	// Traverse the list until the second last node is reached
	struct Node* current = *head_ref;
	while (current->next->next!= NULL){
		current = current->next;
	}
	
	// Make the next pointer of the second last node point to NULL
	current->next = NULL;
}

// Function to remove a node with a given value
void removeNode(struct Node** head_ref, int value){
	// If the list is empty, return
	if (*head_ref == NULL){
		printf("List is empty.\n");
		return;
	}
	
	// Traverse the list until the node with the given value is found or the end of the list is reached
	struct Node* current = *head_ref;
	while (current!= NULL && current->data!= value){
		current = current->next;
	}
	
	// If the node with the given value is found, remove it
	if (current!= NULL){
		if (current->next == NULL){
			*head_ref = NULL;
		} else {
			// Move the head pointer to point to the next node after the removed node
			struct Node* temp = current->next;
			(*head_ref) = temp;
			
			// Free the memory occupied by the removed node
			free(current);
		}
	}
}

int main(){
	struct Node* head = NULL;
	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	
	display(head);
	
	pop(&head);
	display(head);
	
	append(&head, 5);
	append(&head, 6);
	append(&head, 7);
	
	display(head);
	
	removeLast(&head);
	display(head);
	
	removeNode(&head, 5);
	display(head);
	
	return 0;
}