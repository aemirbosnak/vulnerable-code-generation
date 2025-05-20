//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

// Node structure
typedef struct node {
    int data;
    int degree;
    struct node* neighbors[MAX_EDGES];
} node;

// Graph structure
typedef struct graph {
    node* nodes[MAX_NODES];
    int num_nodes;
} graph;

// Function to create a new graph
graph* new_graph(void) {
    graph* g = (graph*) malloc(sizeof(graph));
    g->num_nodes = 0;
    return g;
}

// Function to create a new node
node* new_node(int data) {
    node* n = (node*) malloc(sizeof(node));
    n->data = data;
    n->degree = 0;
    return n;
}

// Function to add an edge to a graph
void add_edge(graph* g, int v, int w) {
    g->nodes[v]->neighbors[g->nodes[v]->degree] = g->nodes[w];
    g->nodes[w]->degree++;
}

// Function to traverse a graph
void traverse(graph* g) {
    for (int i = 0; i < g->num_nodes; i++) {
        node* n = g->nodes[i];
        printf("%d: %d\n", i, n->data);
        for (int j = 0; j < n->degree; j++) {
            node* m = n->neighbors[j];
            traverse(m);
        }
    }
}

int main(void) {
    srand(time(NULL));

    // Create a new graph
    graph* g = new_graph();

    // Add some nodes and edges
    for (int i = 0; i < 10; i++) {
        node* n = new_node(rand() % 100);
        add_edge(g, n, n + 1);
    }

    // Traverse the graph
    traverse(g);

    // Free the graph memory
    for (int i = 0; i < g->num_nodes; i++) {
        free(g->nodes[i]);
    }
    free(g);

    return 0;
}