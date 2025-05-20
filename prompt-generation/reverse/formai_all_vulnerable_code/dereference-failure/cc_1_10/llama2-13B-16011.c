//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for a node in the graph
struct Node {
    int data;  // Data stored in the node
    struct Node* next; // Pointer to the next node in the list
};

// Define a function to create a new node
struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Define a function to insert a node into the graph
void insertNode(struct Node** head_ref, int data) {
    struct Node* new_node = newNode(data);
    struct Node* current = *head_ref;

    // If the graph is empty, set the new node as the head
    if (!current) {
        *head_ref = new_node;
        return;
    }

    // Otherwise, link the new node to the current node
    while (current->next) {
        current = current->next;
    }
    current->next = new_node;
}

// Define a function to traverse the graph
void traverse(struct Node* node) {
    if (node) {
        printf("Data: %d\n", node->data);
        traverse(node->next);
    }
}

int main() {
    struct Node* head = NULL;

    // Insert nodes into the graph
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);

    // Traverse the graph
    traverse(head);

    return 0;
}