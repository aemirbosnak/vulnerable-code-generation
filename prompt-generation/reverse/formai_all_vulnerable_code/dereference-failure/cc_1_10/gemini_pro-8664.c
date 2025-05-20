//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Solar Flare RPC
typedef struct Node {
	char *name;
	char *code;
	struct Node *left;
	struct Node *right;
} Node;

// Gamma Ray Sentinel
void add_node(Node **head, char *name, char *code) {
	Node *temp = malloc(sizeof(Node));
	temp->name = malloc(strlen(name) + 1);
	strcpy(temp->name, name);
	temp->code = malloc(strlen(code) + 1);
	strcpy(temp->code, code);
	temp->left = NULL;
	temp->right = NULL;
	if (*head == NULL) {
		*head = temp;
	} else {
		if (strcmp(code, (*head)->code) < 0) {
			add_node(&(*head)->left, name, code);
		} else {
			add_node(&(*head)->right, name, code);
		}
	}
}

// Quantum Entanglement
void print_node(Node *head) {
	if (head == NULL) {
		return;
	}
	printf("%s: %s\n", head->name, head->code);
	print_node(head->left);
	print_node(head->right);
}

// Supernova Core
void free_node(Node *head) {
	if (head == NULL) {
		return;
	}
	free_node(head->left);
	free_node(head->right);
	free(head->name);
	free(head->code);
	free(head);
}

// Cosmic Ray Burst
int main() {
	Node *head = NULL;
	add_node(&head, "A", "00");
	add_node(&head, "B", "01");
	add_node(&head, "C", "100");
	add_node(&head, "D", "101");
	add_node(&head, "E", "1100");
	add_node(&head, "F", "1101");
	add_node(&head, "G", "1110");
	add_node(&head, "H", "1111");
	print_node(head);
	free_node(head);
	return 0;
}