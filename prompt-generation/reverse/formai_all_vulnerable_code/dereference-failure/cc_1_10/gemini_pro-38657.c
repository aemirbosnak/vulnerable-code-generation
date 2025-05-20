//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum number of nodes and edges in the circuit
#define MAX_NODES 100
#define MAX_EDGES 1000

// Define the data structure for a node in the circuit
typedef struct node {
    int id;
    bool value;
    int num_edges;
    int* edges;
} node;

// Define the data structure for a circuit
typedef struct circuit {
    int num_nodes;
    int num_edges;
    node nodes[MAX_NODES];
    int edges[MAX_EDGES][2];
} circuit;

// Create a new circuit
circuit* create_circuit() {
    circuit* c = malloc(sizeof(circuit));
    c->num_nodes = 0;
    c->num_edges = 0;
    return c;
}

// Add a node to the circuit
void add_node(circuit* c, int id, bool value) {
    c->nodes[c->num_nodes].id = id;
    c->nodes[c->num_nodes].value = value;
    c->nodes[c->num_nodes].num_edges = 0;
    c->nodes[c->num_nodes].edges = NULL;
    c->num_nodes++;
}

// Add an edge to the circuit
void add_edge(circuit* c, int node1, int node2) {
    c->edges[c->num_edges][0] = node1;
    c->edges[c->num_edges][1] = node2;
    c->num_edges++;
}

// Simulate the circuit
void simulate_circuit(circuit* c) {
    // Initialize the node values
    for (int i = 0; i < c->num_nodes; i++) {
        c->nodes[i].value = false;
    }

    // Iterate over the edges and update the node values
    for (int i = 0; i < c->num_edges; i++) {
        int node1 = c->edges[i][0];
        int node2 = c->edges[i][1];
        c->nodes[node2].value = c->nodes[node1].value;
    }
}

// Print the circuit
void print_circuit(circuit* c) {
    printf("Circuit:\n");
    for (int i = 0; i < c->num_nodes; i++) {
        printf("Node %d: %d\n", c->nodes[i].id, c->nodes[i].value);
    }
    for (int i = 0; i < c->num_edges; i++) {
        printf("Edge: %d -> %d\n", c->edges[i][0], c->edges[i][1]);
    }
}

// Free the memory allocated for the circuit
void free_circuit(circuit* c) {
    for (int i = 0; i < c->num_nodes; i++) {
        free(c->nodes[i].edges);
    }
    free(c);
}

// Main function
int main() {
    // Create a new circuit
    circuit* c = create_circuit();

    // Add nodes to the circuit
    add_node(c, 0, false);
    add_node(c, 1, false);
    add_node(c, 2, false);

    // Add edges to the circuit
    add_edge(c, 0, 1);
    add_edge(c, 1, 2);

    // Simulate the circuit
    simulate_circuit(c);

    // Print the circuit
    print_circuit(c);

    // Free the memory allocated for the circuit
    free_circuit(c);

    return 0;
}