//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

// Create a new node
struct node *create_node(int data) {
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

// Insert a node at the beginning of the linked list
void insert_at_beginning(struct node **head, int data) {
	struct node *new_node = create_node(data);
	new_node->next = *head;
	*head = new_node;
}

// Insert a node at the end of the linked list
void insert_at_end(struct node **head, int data) {
	struct node *new_node = create_node(data);
	if (*head == NULL) {
		*head = new_node;
		return;
	}
	struct node *temp = *head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = new_node;
}

// Insert a node after a given node
void insert_after(struct node *prev_node, int data) {
	if (prev_node == NULL) {
		printf("Previous node cannot be NULL\n");
		return;
	}
	struct node *new_node = create_node(data);
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}

// Delete a node from the beginning of the linked list
void delete_from_beginning(struct node **head) {
	if (*head == NULL) {
		printf("Linked list is empty\n");
		return;
	}
	struct node *temp = *head;
	*head = (*head)->next;
	free(temp);
}

// Delete a node from the end of the linked list
void delete_from_end(struct node **head) {
	if (*head == NULL) {
		printf("Linked list is empty\n");
		return;
	}
	struct node *temp = *head;
	struct node *prev = NULL;
	while (temp->next != NULL) {
		prev = temp;
		temp = temp->next;
	}
	if (prev == NULL) {
		*head = NULL;
	} else {
		prev->next = NULL;
	}
	free(temp);
}

// Delete a node after a given node
void delete_after(struct node *prev_node) {
	if (prev_node == NULL) {
		printf("Previous node cannot be NULL\n");
		return;
	}
	if (prev_node->next == NULL) {
		printf("Node to be deleted does not exist\n");
		return;
	}
	struct node *temp = prev_node->next;
	prev_node->next = temp->next;
	free(temp);
}

// Search for a node in the linked list
struct node *search(struct node *head, int data) {
	struct node *temp = head;
	while (temp != NULL) {
		if (temp->data == data) {
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}

// Reverse the linked list
void reverse(struct node **head) {
	struct node *prev = NULL;
	struct node *current = *head;
	struct node *next;
	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
}

// Print the linked list
void print_list(struct node *head) {
	struct node *temp = head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

// Main function
int main() {
	struct node *head = NULL;
	insert_at_beginning(&head, 10);
	insert_at_end(&head, 20);
	insert_at_end(&head, 30);
	insert_after(head->next, 15);
	printf("Linked list: ");
	print_list(head);
	printf("Searching for node with data 15: ");
	struct node *result = search(head, 15);
	if (result == NULL) {
		printf("Node not found\n");
	} else {
		printf("Node found\n");
	}
	delete_from_beginning(&head);
	printf("Linked list after deleting from beginning: ");
	print_list(head);
	delete_from_end(&head);
	printf("Linked list after deleting from end: ");
	print_list(head);
	delete_after(head);
	printf("Linked list after deleting after head: ");
	print_list(head);
	reverse(&head);
	printf("Reversed linked list: ");
	print_list(head);
	return 0;
}