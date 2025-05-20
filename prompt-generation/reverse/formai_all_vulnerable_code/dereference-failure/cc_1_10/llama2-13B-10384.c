//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define GRAPH_MAX_NODES 100
#define GRAPH_MAX_EDGES 200

// Graph structure
typedef struct node {
    int data; // data stored in each node
    int neighbors[GRAPH_MAX_NODES]; // list of neighbors for each node
} Graph;

// Function to create a new graph
Graph* new_graph(void) {
    Graph* g = (Graph*) malloc(sizeof(Graph));
    g->data = 0;
    g->neighbors[0] = -1; // special value to indicate absence of neighbors
    return g;
}

// Function to add a node to the graph
void add_node(Graph* g, int data) {
    int i = g->data++; // increment data counter
    g->neighbors[i] = -1; // set all neighbors to -1 initially
    g->neighbors[data] = i; // connect node to itself
    return;
}

// Function to add an edge to the graph
void add_edge(Graph* g, int from, int to) {
    int i = from, j = to;
    while (g->neighbors[i] != -1) { // find an available neighbor
        if (g->neighbors[i] == j) { // avoid self-loops
            break;
        }
        i = g->neighbors[i];
    }
    g->neighbors[i] = j; // connect nodes
    return;
}

// Function to print the graph
void print_graph(Graph* g) {
    int i, j;
    for (i = 0; i < g->data; i++) {
        printf("Node %d: ", i);
        for (j = 0; j < g->data; j++) {
            if (g->neighbors[i] == j) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
    return;
}

int main(void) {
    srand(time(NULL)); // seed random number generator
    Graph* g = new_graph();
    for (int i = 0; i < 10; i++) {
        int data = rand() % 10; // generate random data
        add_node(g, data);
        for (int j = 0; j < i; j++) {
            add_edge(g, data, rand() % g->data); // connect to a random node
        }
    }
    print_graph(g);
    return 0;
}