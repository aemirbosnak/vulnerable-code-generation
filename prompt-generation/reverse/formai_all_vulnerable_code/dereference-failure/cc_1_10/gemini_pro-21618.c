//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Define a happy node structure
typedef struct happy_node {
    int data;
    struct happy_node *next;
} happy_node;

// Create a happy linked list
happy_node *create_happy_list() {
    happy_node *head = NULL;
    happy_node *current = NULL;

    // Create the first node
    happy_node *node = (happy_node *)malloc(sizeof(happy_node));
    node->data = 1;
    node->next = NULL;
    head = node;
    current = node;

    // Create the rest of the nodes
    for (int i = 2; i <= 10; i++) {
        node = (happy_node *)malloc(sizeof(happy_node));
        node->data = i;
        node->next = NULL;
        current->next = node;
        current = node;
    }

    return head;
}

// Print a happy linked list
void print_happy_list(happy_node *head) {
    happy_node *current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

// Free a happy linked list
void free_happy_list(happy_node *head) {
    happy_node *current = head;

    while (current != NULL) {
        happy_node *next = current->next;
        free(current);
        current = next;
    }
}

// Main function
int main() {
    // Create a happy linked list
    happy_node *head = create_happy_list();

    // Print the happy linked list
    print_happy_list(head);

    // Free the happy linked list
    free_happy_list(head);

    return 0;
}