//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a node in the search graph
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

// Function to search for a specific data in the graph
node_t* search_node(node_t* head, int data) {
    // Initialize the current node to the head of the graph
    node_t* current = head;

    // Loop through the graph until we find the desired data or reach a null pointer
    while (current != NULL && current->data != data) {
        // If the current node has no next node, we have reached a dead end
        if (current->next == NULL) {
            break;
        }

        // Move to the next node in the graph
        current = current->next;
    }

    // If we found the desired data, return the corresponding node
    if (current != NULL && current->data == data) {
        return current;
    }

    // If we reached a null pointer, return NULL
    return NULL;
}

int main() {
    // Create a list of nodes representing the search graph
    node_t* head = NULL;
    head = new_node(1);
    head->next = new_node(2);
    head->next->next = new_node(3);
    head->next->next->next = new_node(4);

    // Search for the node with data 3
    node_t* found = search_node(head, 3);

    // Print the result
    if (found != NULL) {
        printf("Found node with data %d\n", found->data);
    } else {
        printf("Node not found\n");
    }

    return 0;
}