//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Represent a graph node
struct Node {
    int data; // Data stored in the node
    struct Node *next; // Pointer to the next node in the list
};

// Represent a graph
struct Graph {
    struct Node *nodes; // List of all nodes in the graph
    int num_nodes; // Number of nodes in the graph
};

// Function to create a new graph
struct Graph *new_graph(void) {
    struct Graph *g = malloc(sizeof(struct Graph));
    g->nodes = NULL;
    g->num_nodes = 0;
    return g;
}

// Function to add a node to the graph
void add_node(struct Graph *g, int data) {
    struct Node *n = malloc(sizeof(struct Node));
    n->data = data;
    n->next = NULL;
    if (g->num_nodes == 0) {
        g->nodes = n;
    } else {
        g->nodes->next = n;
    }
    g->num_nodes++;
}

// Function to traverse the graph
void traverse(struct Graph *g) {
    struct Node *current = g->nodes;
    while (current != NULL) {
        printf("Visiting node with data %d\n", current->data);
        current = current->next;
    }
}

int main(void) {
    struct Graph *g = new_graph();
    add_node(g, 1);
    add_node(g, 2);
    add_node(g, 3);
    add_node(g, 4);
    add_node(g, 5);
    traverse(g);
    return 0;
}