//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct _node {
    int id;
    int num_edges;
    int *edges;
} node;

typedef struct _circuit {
    int num_nodes;
    int num_edges;
    node *nodes;
} circuit;

circuit *create_circuit(int num_nodes, int num_edges) {
    circuit *c = (circuit *)malloc(sizeof(circuit));
    c->num_nodes = num_nodes;
    c->num_edges = num_edges;
    c->nodes = (node *)malloc(sizeof(node) * num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        c->nodes[i].id = i;
        c->nodes[i].num_edges = 0;
        c->nodes[i].edges = NULL;
    }
    return c;
}

void destroy_circuit(circuit *c) {
    for (int i = 0; i < c->num_nodes; i++) {
        free(c->nodes[i].edges);
    }
    free(c->nodes);
    free(c);
}

void add_edge(circuit *c, int node1, int node2) {
    c->nodes[node1].num_edges++;
    c->nodes[node1].edges = (int *)realloc(c->nodes[node1].edges, sizeof(int) * c->nodes[node1].num_edges);
    c->nodes[node1].edges[c->nodes[node1].num_edges - 1] = node2;
    c->nodes[node2].num_edges++;
    c->nodes[node2].edges = (int *)realloc(c->nodes[node2].edges, sizeof(int) * c->nodes[node2].num_edges);
    c->nodes[node2].edges[c->nodes[node2].num_edges - 1] = node1;
}

void print_circuit(circuit *c) {
    for (int i = 0; i < c->num_nodes; i++) {
        printf("Node %d: ", i);
        for (int j = 0; j < c->nodes[i].num_edges; j++) {
            printf("%d ", c->nodes[i].edges[j]);
        }
        printf("\n");
    }
}

int main() {
    circuit *c = create_circuit(4, 5);
    add_edge(c, 0, 1);
    add_edge(c, 0, 2);
    add_edge(c, 1, 2);
    add_edge(c, 2, 3);
    add_edge(c, 3, 0);
    print_circuit(c);
    destroy_circuit(c);
    return 0;
}