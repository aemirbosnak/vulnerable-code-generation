//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure to represent a graph node
struct Node {
    int data;  // data stored in each node
    struct Node* next; // pointer to next node in the list
    struct Node* prev; // pointer to previous node in the list
};

// Graph structure to represent the graph
struct Graph {
    int num_nodes; // number of nodes in the graph
    struct Node** nodes; // array of nodes
};

// Function to create a new graph
struct Graph* new_graph(int num_nodes) {
    struct Graph* g = malloc(sizeof(struct Graph));
    g->num_nodes = num_nodes;
    g->nodes = malloc(num_nodes * sizeof(struct Node*));
    for (int i = 0; i < num_nodes; i++) {
        g->nodes[i] = NULL;
    }
    return g;
}

// Function to add a node to the graph
void add_node(struct Graph* g, int data) {
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    if (g->num_nodes == 0) {
        g->nodes[0] = new_node;
    } else {
        g->nodes[g->num_nodes - 1]->next = new_node;
        new_node->prev = g->nodes[g->num_nodes - 1];
        g->nodes[g->num_nodes - 1] = new_node;
    }
    g->num_nodes++;
}

// Function to traverse the graph
void traverse(struct Graph* g) {
    for (int i = 0; i < g->num_nodes; i++) {
        struct Node* current = g->nodes[i];
        printf("Node %d: %d\n", i, current->data);
        if (current->next != NULL) {
            traverse(current->next);
        }
    }
}

int main() {
    struct Graph* g = new_graph(5);
    add_node(g, 1);
    add_node(g, 2);
    add_node(g, 3);
    add_node(g, 4);
    add_node(g, 5);
    traverse(g);
    return 0;
}