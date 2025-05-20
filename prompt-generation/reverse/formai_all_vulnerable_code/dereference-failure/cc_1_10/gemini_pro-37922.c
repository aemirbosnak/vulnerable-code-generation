//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
typedef struct node {
    int value;
    struct node *next;
} node;

// Circuit structure
typedef struct circuit {
    int num_nodes;
    int num_edges;
    node **nodes;
    int **edges;
} circuit;

// Create a new circuit
circuit *new_circuit(int num_nodes, int num_edges) {
    circuit *c = malloc(sizeof(circuit));
    c->num_nodes = num_nodes;
    c->num_edges = num_edges;
    c->nodes = malloc(sizeof(node *) * num_nodes);
    c->edges = malloc(sizeof(int *) * num_edges);
    for (int i = 0; i < num_nodes; i++) {
        c->nodes[i] = malloc(sizeof(node));
        c->nodes[i]->value = 0;
        c->nodes[i]->next = NULL;
    }
    for (int i = 0; i < num_edges; i++) {
        c->edges[i] = malloc(sizeof(int) * 2);
    }
    return c;
}

// Free a circuit
void free_circuit(circuit *c) {
    for (int i = 0; i < c->num_nodes; i++) {
        free(c->nodes[i]);
    }
    for (int i = 0; i < c->num_edges; i++) {
        free(c->edges[i]);
    }
    free(c->nodes);
    free(c->edges);
    free(c);
}

// Add an edge to a circuit
void add_edge(circuit *c, int node1, int node2) {
    c->edges[c->num_edges][0] = node1;
    c->edges[c->num_edges][1] = node2;
    c->num_edges++;
}

// Set the value of a node
void set_value(circuit *c, int node, int value) {
    c->nodes[node]->value = value;
}

// Get the value of a node
int get_value(circuit *c, int node) {
    return c->nodes[node]->value;
}

// Simulate a circuit
void simulate(circuit *c) {
    for (int i = 0; i < c->num_edges; i++) {
        int node1 = c->edges[i][0];
        int node2 = c->edges[i][1];
        if (get_value(c, node1) && get_value(c, node2)) {
            set_value(c, node1, 0);
            set_value(c, node2, 0);
        }
    }
}

// Print a circuit
void print_circuit(circuit *c) {
    for (int i = 0; i < c->num_nodes; i++) {
        printf("Node %d: %d\n", i, get_value(c, i));
    }
    for (int i = 0; i < c->num_edges; i++) {
        printf("Edge %d: %d -> %d\n", i, c->edges[i][0], c->edges[i][1]);
    }
}

int main() {
    // Create a new circuit
    circuit *c = new_circuit(4, 4);

    // Add edges to the circuit
    add_edge(c, 0, 1);
    add_edge(c, 1, 2);
    add_edge(c, 2, 3);
    add_edge(c, 3, 0);

    // Set the value of a node
    set_value(c, 0, 1);

    // Simulate the circuit
    simulate(c);

    // Print the circuit
    print_circuit(c);

    // Free the circuit
    free_circuit(c);

    return 0;
}