//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the graph
struct Node {
    int label; // label of the node
    struct Node* next; // pointer to the next node in the graph
    struct Node* prev; // pointer to the previous node in the graph
};

// Function to create a new node
struct Node* newNode(int label) {
    struct Node* node = malloc(sizeof(struct Node));
    node->label = label;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

// Function to add a node to the graph
void addNode(struct Node** head_ref, int label) {
    struct Node* new_node = newNode(label);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        (*head_ref)->next = new_node;
        new_node->prev = *head_ref;
        *head_ref = new_node;
    }
}

// Function to traverse the graph in a recursive manner
void traverse(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->label);
    traverse(root->next);
    traverse(root->prev);
}

int main() {
    struct Node* root = NULL;
    addNode(&root, 1);
    addNode(&root, 2);
    addNode(&root, 3);
    addNode(&root, 4);
    addNode(&root, 5);
    traverse(root);
    return 0;
}