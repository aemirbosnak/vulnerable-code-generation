//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
typedef struct node {
    int value;
    struct node *next;
} node_t;

// Circuit structure
typedef struct circuit {
    int num_nodes;
    node_t *nodes;
} circuit_t;

// Create a new node
node_t *create_node(int value) {
    node_t *node = malloc(sizeof(node_t));
    node->value = value;
    node->next = NULL;
    return node;
}

// Create a new circuit
circuit_t *create_circuit(int num_nodes) {
    circuit_t *circuit = malloc(sizeof(circuit_t));
    circuit->num_nodes = num_nodes;
    circuit->nodes = malloc(sizeof(node_t) * num_nodes);
    return circuit;
}

// Add a node to a circuit
void add_node(circuit_t *circuit, int node_index, int value) {
    circuit->nodes[node_index] = *create_node(value);
}

// Connect two nodes in a circuit
void connect_nodes(circuit_t *circuit, int node_index1, int node_index2) {
    circuit->nodes[node_index1].next = &circuit->nodes[node_index2];
}

// Print a circuit
void print_circuit(circuit_t *circuit) {
    for (int i = 0; i < circuit->num_nodes; i++) {
        printf("Node %d: %d\n", i, circuit->nodes[i].value);
        node_t *next_node = circuit->nodes[i].next;
        while (next_node != NULL) {
            printf("  - Connected to node %d\n", next_node - circuit->nodes);
            next_node = next_node->next;
        }
    }
}

// Simulate a circuit
void simulate_circuit(circuit_t *circuit) {
    // Initialize the circuit state
    int *state = malloc(sizeof(int) * circuit->num_nodes);
    for (int i = 0; i < circuit->num_nodes; i++) {
        state[i] = 0;
    }

    // Iterate over the circuit nodes
    for (int i = 0; i < circuit->num_nodes; i++) {
        // If the node is an input, set its state to the input value
        if (circuit->nodes[i].next == NULL) {
            state[i] = circuit->nodes[i].value;
        }
        // Otherwise, calculate the node's state based on its inputs
        else {
            int input1 = state[circuit->nodes[i].next - circuit->nodes];
            int input2 = state[circuit->nodes[i].next->next - circuit->nodes];
            state[i] = input1 & input2;
        }
    }

    // Print the circuit state
    for (int i = 0; i < circuit->num_nodes; i++) {
        printf("Node %d: %d\n", i, state[i]);
    }

    // Free the circuit state
    free(state);
}

// Main function
int main() {
    // Create a new circuit
    circuit_t *circuit = create_circuit(4);

    // Add nodes to the circuit
    add_node(circuit, 0, 1);
    add_node(circuit, 1, 0);
    add_node(circuit, 2, 1);
    add_node(circuit, 3, 0);

    // Connect the nodes in the circuit
    connect_nodes(circuit, 0, 1);
    connect_nodes(circuit, 1, 2);
    connect_nodes(circuit, 2, 3);

    // Print the circuit
    print_circuit(circuit);

    // Simulate the circuit
    simulate_circuit(circuit);

    // Free the circuit
    free(circuit);

    return 0;
}