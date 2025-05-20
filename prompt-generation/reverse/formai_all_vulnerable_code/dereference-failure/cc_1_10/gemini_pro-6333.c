//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node {
	int data;
	struct node *next;
} node;

node *create_node(int data) {
	node *new_node = malloc(sizeof(node));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

void insert_at_head(node **head, int data) {
	node *new_node = create_node(data);
	new_node->next = *head;
	*head = new_node;
}

void insert_at_tail(node **head, int data) {
	node *new_node = create_node(data);
	if (*head == NULL) {
		*head = new_node;
	} else {
		node *last_node = *head;
		while (last_node->next != NULL) {
			last_node = last_node->next;
		}
		last_node->next = new_node;
	}
}

void insert_at_index(node **head, int index, int data) {
	if (index == 0) {
		insert_at_head(head, data);
	} else {
		node *new_node = create_node(data);
		node *current_node = *head;
		for (int i = 0; i < index - 1; i++) {
			current_node = current_node->next;
		}
		new_node->next = current_node->next;
		current_node->next = new_node;
	}
}

void delete_node(node **head, int data) {
	if (*head == NULL) {
		return;
	} else if ((*head)->data == data) {
		node *temp = *head;
		*head = (*head)->next;
		free(temp);
	} else {
		node *current_node = *head;
		node *previous_node = NULL;
		while (current_node != NULL) {
			if (current_node->data == data) {
				previous_node->next = current_node->next;
				free(current_node);
				break;
			}
			previous_node = current_node;
			current_node = current_node->next;
		}
	}
}

void print_list(node *head) {
	printf("Linked list: ");
	while (head != NULL) {
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

int main() {
	node *head = NULL;

	insert_at_head(&head, 1);
	insert_at_tail(&head, 2);
	insert_at_index(&head, 1, 3);
	print_list(head);

	delete_node(&head, 2);
	print_list(head);

	return 0;
}