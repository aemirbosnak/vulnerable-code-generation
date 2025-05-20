//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a node in the search graph
typedef struct node {
    int data; // Data stored in the node
    struct node* next; // Next node in the list
} node_t;

// Function to create a new node
node_t* new_node(int data) {
    node_t* node = malloc(sizeof(node_t));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to search for a specific value in a linked list
node_t* search(node_t* head, int target) {
    // Start at the beginning of the list
    node_t* current = head;

    // Keep searching until we find the target or reach the end of the list
    while (current != NULL && current->data != target) {
        // If we reach a node with a next pointer, follow the next pointer
        if (current->next != NULL) {
            current = current->next;
        } else {
            // If we reach the end of the list, return NULL
            return NULL;
        }
    }

    // If we find the target, return the current node
    return current;
}

int main() {
    // Create a list of nodes
    node_t* head = NULL;
    head = new_node(1);
    head->next = new_node(2);
    head->next->next = new_node(3);
    head->next->next->next = new_node(4);

    // Search for the value 3
    node_t* result = search(head, 3);

    // Print the result
    if (result != NULL) {
        printf("Found value %d at index %d\n", result->data, result->next == NULL ? 0 : 1);
    } else {
        printf("Value not found\n");
    }

    return 0;
}