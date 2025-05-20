//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct {
    int num_nodes;
    int num_edges;
    int nodes[MAX_NODES];
    int edges[MAX_EDGES][2];
    double weights[MAX_EDGES];
} circuit;

circuit* create_circuit(int num_nodes, int num_edges) {
    circuit* c = (circuit*)malloc(sizeof(circuit));
    c->num_nodes = num_nodes;
    c->num_edges = num_edges;
    for (int i = 0; i < num_nodes; i++) {
        c->nodes[i] = i;
    }
    for (int i = 0; i < num_edges; i++) {
        c->edges[i][0] = 0;
        c->edges[i][1] = 0;
        c->weights[i] = 0.0;
    }
    return c;
}

void destroy_circuit(circuit* c) {
    free(c);
}

void print_circuit(circuit* c) {
    printf("Circuit:\n");
    printf("Number of nodes: %d\n", c->num_nodes);
    printf("Number of edges: %d\n", c->num_edges);
    for (int i = 0; i < c->num_nodes; i++) {
        printf("Node %d:\n", c->nodes[i]);
    }
    for (int i = 0; i < c->num_edges; i++) {
        printf("Edge %d: %d -> %d (weight: %f)\n", i, c->edges[i][0], c->edges[i][1], c->weights[i]);
    }
}

int main() {
    circuit* c = create_circuit(3, 2);
    c->edges[0][0] = 0;
    c->edges[0][1] = 1;
    c->weights[0] = 1.0;
    c->edges[1][0] = 1;
    c->edges[1][1] = 2;
    c->weights[1] = 1.0;
    print_circuit(c);
    destroy_circuit(c);
    return 0;
}