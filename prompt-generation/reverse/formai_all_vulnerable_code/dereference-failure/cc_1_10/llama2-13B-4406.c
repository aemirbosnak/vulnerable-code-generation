//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a node in the graph
typedef struct {
    int label; // Label of the node
    struct node* next; // Next node in the graph
    struct node* prev; // Previous node in the graph
} node_t;

// Function to create a new node
node_t* new_node(int label) {
    node_t* node = (node_t*) malloc(sizeof(node_t));
    node->label = label;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

// Function to add a node to the graph
void add_node(node_t** head_ref, int label) {
    node_t* node = new_node(label);
    if (*head_ref == NULL) {
        *head_ref = node;
    } else {
        (*head_ref)->next = node;
        node->prev = *head_ref;
        *head_ref = node;
    }
}

// Function to traverse the graph
void traverse(node_t* head) {
    while (head != NULL) {
        printf("%d ", head->label);
        head = head->next;
    }
    printf("\n");
}

int main() {
    node_t* head = NULL;

    // Add nodes to the graph
    add_node(&head, 1);
    add_node(&head, 2);
    add_node(&head, 3);
    add_node(&head, 4);
    add_node(&head, 5);

    // Traverse the graph
    traverse(head);

    return 0;
}