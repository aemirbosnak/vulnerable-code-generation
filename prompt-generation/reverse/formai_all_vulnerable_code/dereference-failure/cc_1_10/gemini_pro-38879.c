//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Circuit structure
typedef struct circuit {
    int num_nodes;
    node_t **nodes;
} circuit_t;

// Create a new node
node_t *create_node(int data) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Create a new circuit
circuit_t *create_circuit(int num_nodes) {
    circuit_t *new_circuit = malloc(sizeof(circuit_t));
    new_circuit->num_nodes = num_nodes;
    new_circuit->nodes = malloc(sizeof(node_t *) * num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        new_circuit->nodes[i] = NULL;
    }
    return new_circuit;
}

// Add a new node to a circuit
void add_node(circuit_t *circuit, int node_index, int data) {
    node_t *new_node = create_node(data);
    new_node->next = circuit->nodes[node_index];
    circuit->nodes[node_index] = new_node;
}

// Print a circuit
void print_circuit(circuit_t *circuit) {
    for (int i = 0; i < circuit->num_nodes; i++) {
        node_t *node = circuit->nodes[i];
        printf("Node %d: ", i);
        while (node != NULL) {
            printf("%d -> ", node->data);
            node = node->next;
        }
        printf("NULL\n");
    }
}

// Free a circuit
void free_circuit(circuit_t *circuit) {
    for (int i = 0; i < circuit->num_nodes; i++) {
        node_t *node = circuit->nodes[i];
        while (node != NULL) {
            node_t *next_node = node->next;
            free(node);
            node = next_node;
        }
    }
    free(circuit->nodes);
    free(circuit);
}

int main() {
    // Create a new circuit
    circuit_t *circuit = create_circuit(5);

    // Add some nodes to the circuit
    add_node(circuit, 0, 1);
    add_node(circuit, 0, 2);
    add_node(circuit, 1, 3);
    add_node(circuit, 1, 4);
    add_node(circuit, 2, 5);

    // Print the circuit
    print_circuit(circuit);

    // Free the circuit
    free_circuit(circuit);

    return 0;
}