//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a graph node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new graph node
struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node into the graph
void insertNode(struct Node** head_ref, int data) {
    struct Node* new_node = newNode(data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        (*head_ref)->next = new_node;
    }
    (*head_ref) = new_node;
}

// Function to traverse the graph in a recursive style
void traverse(struct Node* node) {
    if (node == NULL) {
        return;
    }
    printf("Visiting node with data: %d\n", node->data);
    traverse(node->next);
}

int main() {
    struct Node* head = NULL;

    // Insert some nodes into the graph
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);

    // Traverse the graph in a recursive style
    traverse(head);

    return 0;
}