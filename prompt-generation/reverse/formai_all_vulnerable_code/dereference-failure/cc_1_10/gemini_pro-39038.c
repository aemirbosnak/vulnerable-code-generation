//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>


// Define the structure of a CatNode
typedef struct _CatNode {
	char *name;
	int age;
	struct _CatNode *next;
} CatNode;

// Create a new CatNode
CatNode *create_catnode(char *name, int age) {
	CatNode *node = malloc(sizeof(CatNode));
	node->name = name;
	node->age = age;
	node->next = NULL;
	return node;
}

// Insert a new CatNode into a linked list
void insert_catnode(CatNode **head, CatNode *new_node) {
	if (*head == NULL) {
		*head = new_node;
		return;
	}
	CatNode *current = *head;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = new_node;
}

// Delete a CatNode from a linked list
void delete_catnode(CatNode **head, CatNode *node_to_delete) {
	if (*head == node_to_delete) {
		*head = (*head)->next;
		free(node_to_delete);
		return;
	}
	CatNode *current = *head;
	while (current->next != node_to_delete) {
		current = current->next;
	}
	current->next = node_to_delete->next;
	free(node_to_delete);
}

// Print a CatNode
void print_catnode(CatNode *node) {
	printf("Name: %s, Age: %d\n", node->name, node->age);
}


// --- Main logic starts here ---

int main(int argc, char **argv) {
	
	// Create a linked list of cats
	CatNode *head = NULL;
	insert_catnode(&head, create_catnode("Kitty", 1));
	insert_catnode(&head, create_catnode("Fluffy", 2));
	insert_catnode(&head, create_catnode("Whiskers", 3));
	
	// Print the linked list of cats
	CatNode *current = head;
	while (current != NULL) {
		print_catnode(current);
		current = current->next;
	}
	
	// Delete a CatNode from the linked list
	delete_catnode(&head, head->next);
	
	// Print the linked list of cats
	current = head;
	while (current != NULL) {
		print_catnode(current);
		current = current->next;
	}
	
	// Free the memory allocated for the linked list of cats
	while (head != NULL) {
		CatNode *next = head->next;
		free(head);
		head = next;
	}
	
	return 0;
}