//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct node {
    int id;
    char *name;
    int num_edges;
    int *edges;
} node_t;

typedef struct edge {
    int id;
    node_t *node1;
    node_t *node2;
} edge_t;

typedef struct circuit {
    int num_nodes;
    node_t *nodes;
    int num_edges;
    edge_t *edges;
} circuit_t;

void print_circuit(circuit_t *circuit) {
    printf("Circuit:\n");
    for (int i = 0; i < circuit->num_nodes; i++) {
        node_t *node = &circuit->nodes[i];
        printf("Node %d: %s\n", node->id, node->name);
        for (int j = 0; j < node->num_edges; j++) {
            edge_t *edge = &circuit->edges[node->edges[j]];
            printf("  Edge %d: %d -> %d\n", edge->id, edge->node1->id, edge->node2->id);
        }
    }
}

int main() {
    circuit_t *circuit = malloc(sizeof(circuit_t));
    circuit->num_nodes = 3;
    circuit->nodes = malloc(sizeof(node_t) * circuit->num_nodes);
    circuit->nodes[0].id = 0;
    circuit->nodes[0].name = "Input A";
    circuit->nodes[0].num_edges = 1;
    circuit->nodes[0].edges = malloc(sizeof(int) * circuit->nodes[0].num_edges);
    circuit->nodes[0].edges[0] = 0;
    circuit->nodes[1].id = 1;
    circuit->nodes[1].name = "Input B";
    circuit->nodes[1].num_edges = 1;
    circuit->nodes[1].edges = malloc(sizeof(int) * circuit->nodes[1].num_edges);
    circuit->nodes[1].edges[0] = 1;
    circuit->nodes[2].id = 2;
    circuit->nodes[2].name = "Output";
    circuit->nodes[2].num_edges = 0;
    circuit->nodes[2].edges = NULL;

    circuit->num_edges = 2;
    circuit->edges = malloc(sizeof(edge_t) * circuit->num_edges);
    circuit->edges[0].id = 0;
    circuit->edges[0].node1 = &circuit->nodes[0];
    circuit->edges[0].node2 = &circuit->nodes[2];
    circuit->edges[1].id = 1;
    circuit->edges[1].node1 = &circuit->nodes[1];
    circuit->edges[1].node2 = &circuit->nodes[2];

    print_circuit(circuit);

    return 0;
}