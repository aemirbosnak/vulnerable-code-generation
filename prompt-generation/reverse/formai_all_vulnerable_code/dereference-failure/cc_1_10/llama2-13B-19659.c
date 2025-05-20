//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a node in the graph
typedef struct node {
    char *name; // name of the function
    struct node *next; // next node in the list
    struct node *prev; // previous node in the list
} node_t;

// Function to create a new node
node_t *new_node(char *name) {
    node_t *n = malloc(sizeof(node_t));
    n->name = name;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

// Function to add a node to the graph
void add_node(node_t **head_ref, char *name) {
    node_t *n = new_node(name);
    if (*head_ref == NULL) {
        *head_ref = n;
    } else {
        (*head_ref)->next = n;
        n->prev = *head_ref;
        *head_ref = n;
    }
}

// Function to add an edge between two nodes
void add_edge(node_t *a, node_t *b) {
    a->next = b;
    b->prev = a;
}

// Function to print the graph
void print_graph(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("%s -> ", current->name);
        current = current->next;
    }
    printf("\n");
}

int main() {
    node_t *head = NULL;

    // Add nodes to the graph
    add_node(&head, "f1");
    add_node(&head, "f2");
    add_node(&head, "f3");
    add_node(&head, "f4");
    add_node(&head, "f5");

    // Add edges between nodes
    add_edge(head, head->next);
    add_edge(head->next, head->next->next);
    add_edge(head->next->next, head->next->prev);
    add_edge(head->next->prev, head);

    // Print the graph
    print_graph(head);

    return 0;
}