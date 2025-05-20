//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the structure for the nodes of the search graph
typedef struct node {
    int data; // data stored in each node
    struct node* next; // pointer to the next node in the graph
} Node;

// Define a function to create a new node
Node* newNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Define a function to search for a specific value in the graph
Node* search(Node* head, int target) {
    // Initialize the current node to the head of the graph
    Node* current = head;

    // Keep searching until we find the target value or reach a null pointer
    while (current != NULL && current->data != target) {
        // If the current node has no next node, we've reached a dead end
        if (current->next == NULL) {
            return NULL;
        }

        // Move to the next node in the graph
        current = current->next;
    }

    // If we found the target value, return the current node
    return current;
}

int main() {
    // Create a list of nodes representing a graph
    Node* head = NULL;
    head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);

    // Search for the value 3 in the graph
    Node* result = search(head, 3);

    // Print the result (or lack thereof)
    if (result != NULL) {
        printf("Found value 3 at node %d\n", result->data);
    } else {
        printf("Value 3 not found\n");
    }

    return 0;
}