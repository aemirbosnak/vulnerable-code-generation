//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a node in the graph
struct Node {
    int data; // data stored in the node
    struct Node* next; // pointer to the next node in the list
};

// Define a function to create a new node
struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Define a function to print the graph
void printGraph(struct Node* head) {
    if (head == NULL) {
        printf("The graph is empty.\n");
        return;
    }

    printf("The graph contains the following nodes:\n");

    struct Node* current = head;
    while (current != NULL) {
        printf("    %d\n", current->data);
        current = current->next;
    }
}

// Define a function to traverse the graph
void traverseGraph(struct Node* head) {
    if (head == NULL) {
        printf("The graph is empty.\n");
        return;
    }

    struct Node* current = head;
    while (current != NULL) {
        printf("Visiting node %d\n", current->data);
        current = current->next;
    }
}

int main() {
    // Create a new node with data 1
    struct Node* node1 = newNode(1);

    // Create a new node with data 2
    struct Node* node2 = newNode(2);

    // Create a new node with data 3
    struct Node* node3 = newNode(3);

    // Set the next node of node1 to node2
    node1->next = node2;

    // Set the next node of node2 to node3
    node2->next = node3;

    // Print the graph
    printGraph(node1);

    // Traverse the graph
    traverseGraph(node1);

    return 0;
}