//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a node in a linked list
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Define a function to create a new node with a given value
node_t *new_node(int data) {
    node_t *node = malloc(sizeof(node_t));
    node->data = data;
    node->next = NULL;
    return node;
}

// Define a function to print the linked list
void print_list(node_t *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Define a function to free the memory of a node
void free_node(node_t *node) {
    free(node);
}

int main() {
    // Create a new node with value 1
    node_t *head = new_node(1);

    // Create two more nodes with values 2 and 3
    node_t *node2 = new_node(2);
    node_t *node3 = new_node(3);

    // Link the nodes together in a list
    head->next = node2;
    node2->next = node3;

    // Print the linked list
    print_list(head);

    // Free the memory of the nodes
    free_node(head);
    free_node(node2);
    free_node(node3);

    return 0;
}