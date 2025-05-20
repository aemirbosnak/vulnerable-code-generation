//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct {
    int id;
    int value;
    int fanout;
    int* fanout_nodes;
} Node;

typedef struct {
    int id;
    int source;
    int destination;
    int weight;
} Edge;

typedef struct {
    int num_nodes;
    int num_edges;
    Node nodes[MAX_NODES];
    Edge edges[MAX_EDGES];
} Circuit;

Circuit* create_circuit(int num_nodes, int num_edges) {
    Circuit* circuit = malloc(sizeof(Circuit));
    circuit->num_nodes = num_nodes;
    circuit->num_edges = num_edges;

    for (int i = 0; i < num_nodes; i++) {
        circuit->nodes[i].id = i;
        circuit->nodes[i].value = 0;
        circuit->nodes[i].fanout = 0;
        circuit->nodes[i].fanout_nodes = NULL;
    }

    for (int i = 0; i < num_edges; i++) {
        circuit->edges[i].id = i;
        circuit->edges[i].source = 0;
        circuit->edges[i].destination = 0;
        circuit->edges[i].weight = 0;
    }

    return circuit;
}

void destroy_circuit(Circuit* circuit) {
    for (int i = 0; i < circuit->num_nodes; i++) {
        free(circuit->nodes[i].fanout_nodes);
    }

    free(circuit);
}

void add_node(Circuit* circuit, int id) {
    if (id >= circuit->num_nodes) {
        fprintf(stderr, "Error: Invalid node ID %d\n", id);
        return;
    }

    circuit->nodes[id].id = id;
}

void add_edge(Circuit* circuit, int source, int destination, int weight) {
    if (source >= circuit->num_nodes || destination >= circuit->num_nodes) {
        fprintf(stderr, "Error: Invalid node IDs %d and %d\n", source, destination);
        return;
    }

    circuit->edges[circuit->num_edges].id = circuit->num_edges;
    circuit->edges[circuit->num_edges].source = source;
    circuit->edges[circuit->num_edges].destination = destination;
    circuit->edges[circuit->num_edges].weight = weight;

    circuit->num_edges++;
}

void simulate_circuit(Circuit* circuit) {
    // Initialize the circuit
    for (int i = 0; i < circuit->num_nodes; i++) {
        circuit->nodes[i].value = 0;
    }

    // Simulate the circuit
    for (int i = 0; i < circuit->num_edges; i++) {
        int source = circuit->edges[i].source;
        int destination = circuit->edges[i].destination;
        int weight = circuit->edges[i].weight;

        circuit->nodes[destination].value += weight * circuit->nodes[source].value;
    }
}

void print_circuit(Circuit* circuit) {
    printf("Nodes:\n");
    for (int i = 0; i < circuit->num_nodes; i++) {
        printf("  Node %d: value = %d\n", circuit->nodes[i].id, circuit->nodes[i].value);
    }

    printf("Edges:\n");
    for (int i = 0; i < circuit->num_edges; i++) {
        printf("  Edge %d: source = %d, destination = %d, weight = %d\n", circuit->edges[i].id, circuit->edges[i].source, circuit->edges[i].destination, circuit->edges[i].weight);
    }
}

int main() {
    // Create a circuit
    Circuit* circuit = create_circuit(10, 20);

    // Add nodes to the circuit
    for (int i = 0; i < 10; i++) {
        add_node(circuit, i);
    }

    // Add edges to the circuit
    add_edge(circuit, 0, 1, 1);
    add_edge(circuit, 1, 2, 2);
    add_edge(circuit, 2, 3, 3);
    add_edge(circuit, 3, 4, 4);
    add_edge(circuit, 4, 5, 5);
    add_edge(circuit, 5, 6, 6);
    add_edge(circuit, 6, 7, 7);
    add_edge(circuit, 7, 8, 8);
    add_edge(circuit, 8, 9, 9);

    // Simulate the circuit
    simulate_circuit(circuit);

    // Print the circuit
    print_circuit(circuit);

    // Destroy the circuit
    destroy_circuit(circuit);

    return 0;
}