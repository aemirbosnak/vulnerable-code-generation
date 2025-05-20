//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to represent a node in the search graph
typedef struct node {
    int value;
    struct node *next;
} node_t;

// Function to create a new node
node_t *new_node(int value) {
    node_t *node = (node_t *) malloc(sizeof(node_t));
    node->value = value;
    node->next = NULL;
    return node;
}

// Function to search for a value in a linked list
int search(node_t *head, int value) {
    // Start at the beginning of the list
    node_t *current = head;

    // Loop until we find the value or reach the end of the list
    while (current != NULL && current->value != value) {
        // If we reach the end of the list, return failure
        if (current->next == NULL) {
            return 0;
        }

        // Move on to the next node
        current = current->next;
    }

    // If we found the value, return its index
    return current != NULL ? current->value : -1;
}

// Example usage:
int main() {
    // Create a list of integers
    node_t *head = NULL;
    head = new_node(1);
    head->next = new_node(2);
    head->next->next = new_node(3);
    head->next->next->next = new_node(4);

    // Search for the value 2
    int result = search(head, 2);

    // Print the result
    if (result != -1) {
        printf("Value found at index %d\n", result);
    } else {
        printf("Value not found\n");
    }

    return 0;
}