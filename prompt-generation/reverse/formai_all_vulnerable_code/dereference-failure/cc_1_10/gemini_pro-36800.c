//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for a linked list
typedef struct node {
    char *name;
    char *number;
    struct node *next;
} node_t;

// Function to create a new node
node_t *create_node(char *name, char *number) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->name = strdup(name);
    new_node->number = strdup(number);
    new_node->next = NULL;
    return new_node;
}

// Function to add a node to the end of a linked list
void append_node(node_t **head, node_t *new_node) {
    if (*head == NULL) {
        *head = new_node;
    } else {
        node_t *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Function to print a linked list
void print_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("%s (%s)\n", current->name, current->number);
        current = current->next;
    }
}

// Function to free a linked list
void free_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        node_t *next = current->next;
        free(current->name);
        free(current->number);
        free(current);
        current = next;
    }
}

// Main function
int main() {
    // Create a new phone book
    node_t *head = NULL;

    // Add some contacts to the phone book
    append_node(&head, create_node("Alice", "555-1212"));
    append_node(&head, create_node("Bob", "555-1213"));
    append_node(&head, create_node("Carol", "555-1214"));

    // Print the phone book
    print_list(head);

    // Free the phone book
    free_list(head);

    return 0;
}