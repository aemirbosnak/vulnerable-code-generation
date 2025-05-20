//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Structure to represent a node in the graph
struct node {
    char name[20];  // Name of the node
    int weight;    // Weight of the node
    struct node *next; // Next node in the list
};

// Function to create a new node
struct node* new_node(char *name, int weight) {
    struct node *node = malloc(sizeof(struct node));
    strcpy(node->name, name);
    node->weight = weight;
    node->next = NULL;
    return node;
}

// Function to add a node to the graph
void add_node(struct node **head_ref, char *name, int weight) {
    struct node *node = new_node(name, weight);
    if (*head_ref == NULL) {
        *head_ref = node;
    } else {
        (*head_ref)->next = node;
    }
    (*head_ref) = node;
}

// Function to traverse the graph
void traverse(struct node *head) {
    while (head != NULL) {
        printf("%s: %d\n", head->name, head->weight);
        head = head->next;
    }
}

int main() {
    struct node *head = NULL;

    // Add some nodes to the graph
    add_node(&head, "Alice", 5);
    add_node(&head, "Bob", 2);
    add_node(&head, "Charlie", 3);
    add_node(&head, "David", 1);

    // Traverse the graph
    traverse(head);

    return 0;
}