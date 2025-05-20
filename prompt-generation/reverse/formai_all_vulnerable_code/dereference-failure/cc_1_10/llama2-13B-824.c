//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Graph structure definition
typedef struct Node {
    int label;
    struct Node* next;
} Node;

// Graph type definition
typedef struct Graph {
    Node* nodes;
    int num_nodes;
} Graph;

// Function to create a new graph
Graph* new_graph(int n) {
    Graph* g = (Graph*) malloc(sizeof(Graph));
    g->nodes = (Node*) malloc(n * sizeof(Node));
    g->num_nodes = n;
    return g;
}

// Function to add a node to the graph
void add_node(Graph* g, int label) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->label = label;
    new_node->next = NULL;
    if (g->num_nodes == 0) {
        g->nodes = new_node;
    } else {
        g->nodes->next = new_node;
    }
    g->num_nodes++;
}

// Function to traverse the graph
void traverse(Graph* g) {
    for (int i = 0; i < g->num_nodes; i++) {
        Node* curr = g->nodes;
        printf("%d ", curr->label);
        if (curr->next != NULL) {
            traverse(curr->next);
        }
    }
    printf("\n");
}

int main() {
    Graph* g = new_graph(5);
    add_node(g, 1);
    add_node(g, 2);
    add_node(g, 3);
    add_node(g, 4);
    add_node(g, 5);
    traverse(g);
    return 0;
}