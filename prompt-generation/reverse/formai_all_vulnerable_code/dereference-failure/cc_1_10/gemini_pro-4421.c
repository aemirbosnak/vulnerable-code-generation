//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 100

typedef struct node {
    int id;
    int value;
    int num_edges;
    int edges[MAX_EDGES];
} node;

typedef struct edge {
    int from;
    int to;
    int weight;
} edge;

typedef struct circuit {
    int num_nodes;
    int num_edges;
    node nodes[MAX_NODES];
    edge edges[MAX_EDGES];
} circuit;

circuit* create_circuit(int num_nodes, int num_edges) {
    circuit* c = malloc(sizeof(circuit));
    c->num_nodes = num_nodes;
    c->num_edges = num_edges;
    for (int i = 0; i < num_nodes; i++) {
        c->nodes[i].id = i;
        c->nodes[i].value = 0;
        c->nodes[i].num_edges = 0;
        for (int j = 0; j < MAX_EDGES; j++) {
            c->nodes[i].edges[j] = -1;
        }
    }
    for (int i = 0; i < num_edges; i++) {
        c->edges[i].from = -1;
        c->edges[i].to = -1;
        c->edges[i].weight = 0;
    }
    return c;
}

void free_circuit(circuit* c) {
    free(c);
}

void add_edge(circuit* c, int from, int to, int weight) {
    c->edges[c->num_edges].from = from;
    c->edges[c->num_edges].to = to;
    c->edges[c->num_edges].weight = weight;
    c->nodes[from].edges[c->nodes[from].num_edges] = c->num_edges;
    c->nodes[from].num_edges++;
    c->num_edges++;
}

void print_circuit(circuit* c) {
    for (int i = 0; i < c->num_nodes; i++) {
        printf("Node %d: ", c->nodes[i].id);
        for (int j = 0; j < c->nodes[i].num_edges; j++) {
            printf("%d ", c->edges[c->nodes[i].edges[j]].to);
        }
        printf("\n");
    }
}

void simulate_circuit(circuit* c) {
    for (int i = 0; i < c->num_nodes; i++) {
        int value = 0;
        for (int j = 0; j < c->nodes[i].num_edges; j++) {
            value += c->edges[c->nodes[i].edges[j]].weight * c->nodes[c->edges[c->nodes[i].edges[j]].from].value;
        }
        c->nodes[i].value = value;
    }
}

int main() {
    circuit* c = create_circuit(5, 4);
    add_edge(c, 0, 1, 1);
    add_edge(c, 1, 2, 2);
    add_edge(c, 2, 3, 3);
    add_edge(c, 3, 4, 4);
    print_circuit(c);
    simulate_circuit(c);
    for (int i = 0; i < c->num_nodes; i++) {
        printf("Node %d: %d\n", c->nodes[i].id, c->nodes[i].value);
    }
    free_circuit(c);
    return 0;
}