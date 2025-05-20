//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to store a node in the search graph
typedef struct node {
    int data;
    struct node* next;
} node_t;

// Function to create a new node
node_t* new_node(int data) {
    node_t* node = malloc(sizeof(node_t));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to search for a given target in the graph
node_t* search(node_t* head, int target) {
    // Initialize the current node to the head of the graph
    node_t* current = head;

    // Loop until the current node has no next node or the target is found
    while (current->next != NULL && current->next->data != target) {
        // If the current node has no next node, return failure
        if (current->next == NULL) {
            return NULL;
        }

        // Move to the next node in the graph
        current = current->next;
    }

    // If the target is found, return the current node
    if (current->next->data == target) {
        return current->next;
    }

    // If the target is not found, return failure
    return NULL;
}

int main() {
    // Create a list of nodes with the following data: 1, 2, 3, 4, 5, 6, 7, 8
    node_t* head = new_node(1);
    head->next = new_node(2);
    head->next->next = new_node(3);
    head->next->next->next = new_node(4);
    head->next->next->next->next = new_node(5);
    head->next->next->next->next->next = new_node(6);
    head->next->next->next->next->next->next = new_node(7);
    head->next->next->next->next->next->next->next = new_node(8);

    // Search for the target node with data 4
    node_t* result = search(head, 4);

    // Print the result
    if (result != NULL) {
        printf("Found node with data %d\n", result->data);
    } else {
        printf("Node not found\n");
    }

    return 0;
}