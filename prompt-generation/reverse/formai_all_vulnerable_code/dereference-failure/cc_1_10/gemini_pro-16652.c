//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct {
    int id;
    char *name;
    int in_degree;
    int out_degree;
    int *in_edges;
    int *out_edges;
} Node;

typedef struct {
    int id;
    Node *source;
    Node *destination;
    int weight;
} Edge;

typedef struct {
    int num_nodes;
    int num_edges;
    Node nodes[MAX_NODES];
    Edge edges[MAX_EDGES];
} Circuit;

// Create a new circuit.
Circuit *create_circuit() {
    Circuit *circuit = malloc(sizeof(Circuit));
    circuit->num_nodes = 0;
    circuit->num_edges = 0;
    return circuit;
}

// Add a new node to the circuit.
void add_node(Circuit *circuit, char *name) {
    Node *node = &circuit->nodes[circuit->num_nodes++];
    node->id = circuit->num_nodes;
    node->name = strdup(name);
    node->in_degree = 0;
    node->out_degree = 0;
    node->in_edges = NULL;
    node->out_edges = NULL;
}

// Add a new edge to the circuit.
void add_edge(Circuit *circuit, Node *source, Node *destination, int weight) {
    Edge *edge = &circuit->edges[circuit->num_edges++];
    edge->id = circuit->num_edges;
    edge->source = source;
    edge->destination = destination;
    edge->weight = weight;
    source->out_degree++;
    destination->in_degree++;
}

// Print the circuit to the console.
void print_circuit(Circuit *circuit) {
    for (int i = 0; i < circuit->num_nodes; i++) {
        Node *node = &circuit->nodes[i];
        printf("Node %d: %s\n", node->id, node->name);
        printf("  In-degree: %d\n", node->in_degree);
        printf("  Out-degree: %d\n", node->out_degree);
        printf("  In-edges:\n");
        for (int j = 0; j < node->in_degree; j++) {
            printf("    %d\n", node->in_edges[j]);
        }
        printf("  Out-edges:\n");
        for (int j = 0; j < node->out_degree; j++) {
            printf("    %d\n", node->out_edges[j]);
        }
    }
}

// Free the memory allocated for the circuit.
void free_circuit(Circuit *circuit) {
    for (int i = 0; i < circuit->num_nodes; i++) {
        Node *node = &circuit->nodes[i];
        free(node->name);
        free(node->in_edges);
        free(node->out_edges);
    }
    free(circuit);
}

// Main function.
int main() {
    // Create a new circuit.
    Circuit *circuit = create_circuit();

    // Add nodes to the circuit.
    add_node(circuit, "Input 1");
    add_node(circuit, "Input 2");
    add_node(circuit, "Output");

    // Add edges to the circuit.
    add_edge(circuit, &circuit->nodes[0], &circuit->nodes[2], 1);
    add_edge(circuit, &circuit->nodes[1], &circuit->nodes[2], 1);

    // Print the circuit to the console.
    print_circuit(circuit);

    // Free the memory allocated for the circuit.
    free_circuit(circuit);

    return 0;
}