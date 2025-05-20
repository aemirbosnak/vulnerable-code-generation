//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char *name;
    int weight;
    node_t *node1;
    node_t *node2;
} edge_t;

typedef struct circuit {
    int num_nodes;
    int num_edges;
    node_t *nodes;
    edge_t *edges;
} circuit_t;

// Create a new circuit
circuit_t *circuit_new() {
    circuit_t *circuit = malloc(sizeof(circuit_t));
    circuit->num_nodes = 0;
    circuit->num_edges = 0;
    circuit->nodes = NULL;
    circuit->edges = NULL;
    return circuit;
}

// Add a node to a circuit
void circuit_add_node(circuit_t *circuit, char *name) {
    node_t *node = malloc(sizeof(node_t));
    node->id = circuit->num_nodes++;
    node->name = strdup(name);
    node->num_edges = 0;
    node->edges = NULL;
    circuit->nodes = realloc(circuit->nodes, circuit->num_nodes * sizeof(node_t));
    circuit->nodes[circuit->num_nodes - 1] = *node;
}

// Add an edge to a circuit
void circuit_add_edge(circuit_t *circuit, char *name, int weight, node_t *node1, node_t *node2) {
    edge_t *edge = malloc(sizeof(edge_t));
    edge->id = circuit->num_edges++;
    edge->name = strdup(name);
    edge->weight = weight;
    edge->node1 = node1;
    edge->node2 = node2;
    circuit->edges = realloc(circuit->edges, circuit->num_edges * sizeof(edge_t));
    circuit->edges[circuit->num_edges - 1] = *edge;
}

// Print a circuit
void circuit_print(circuit_t *circuit) {
    printf("Circuit:\n");
    for (int i = 0; i < circuit->num_nodes; i++) {
        printf("  Node %d: %s\n", circuit->nodes[i].id, circuit->nodes[i].name);
    }
    for (int i = 0; i < circuit->num_edges; i++) {
        printf("  Edge %d: %s (weight %d) from %s to %s\n", circuit->edges[i].id, circuit->edges[i].name, circuit->edges[i].weight, circuit->edges[i].node1->name, circuit->edges[i].node2->name);
    }
}

// Free a circuit
void circuit_free(circuit_t *circuit) {
    for (int i = 0; i < circuit->num_nodes; i++) {
        free(circuit->nodes[i].name);
        free(circuit->nodes[i].edges);
    }
    free(circuit->nodes);
    for (int i = 0; i < circuit->num_edges; i++) {
        free(circuit->edges[i].name);
    }
    free(circuit->edges);
    free(circuit);
}

int main() {
    // Create a new circuit
    circuit_t *circuit = circuit_new();

    // Add nodes to the circuit
    circuit_add_node(circuit, "Node 1");
    circuit_add_node(circuit, "Node 2");
    circuit_add_node(circuit, "Node 3");
    circuit_add_node(circuit, "Node 4");
    circuit_add_node(circuit, "Node 5");

    // Add edges to the circuit
    circuit_add_edge(circuit, "Edge 1", 10, &circuit->nodes[0], &circuit->nodes[1]);
    circuit_add_edge(circuit, "Edge 2", 20, &circuit->nodes[1], &circuit->nodes[2]);
    circuit_add_edge(circuit, "Edge 3", 30, &circuit->nodes[2], &circuit->nodes[3]);
    circuit_add_edge(circuit, "Edge 4", 40, &circuit->nodes[3], &circuit->nodes[4]);
    circuit_add_edge(circuit, "Edge 5", 50, &circuit->nodes[4], &circuit->nodes[0]);

    // Print the circuit
    circuit_print(circuit);

    // Free the circuit
    circuit_free(circuit);

    return 0;
}