//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Node structure
typedef struct node {
    int value;
    struct node *next;
} node;

// Circuit structure
typedef struct circuit {
    int num_nodes;
    node **nodes;
} circuit;

// Create a new node
node *create_node(int value) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

// Create a new circuit
circuit *create_circuit(int num_nodes) {
    circuit *new_circuit = (circuit *)malloc(sizeof(circuit));
    new_circuit->num_nodes = num_nodes;
    new_circuit->nodes = (node **)malloc(num_nodes * sizeof(node *));
    for (int i = 0; i < num_nodes; i++) {
        new_circuit->nodes[i] = create_node(0);
    }
    return new_circuit;
}

// Free a node
void free_node(node *node) {
    free(node);
}

// Free a circuit
void free_circuit(circuit *circuit) {
    for (int i = 0; i < circuit->num_nodes; i++) {
        free_node(circuit->nodes[i]);
    }
    free(circuit->nodes);
    free(circuit);
}

// Print a node
void print_node(node *node) {
    printf("%d ", node->value);
}

// Print a circuit
void print_circuit(circuit *circuit) {
    for (int i = 0; i < circuit->num_nodes; i++) {
        print_node(circuit->nodes[i]);
    }
    printf("\n");
}

// Set the value of a node
void set_node_value(circuit *circuit, int node_index, int value) {
    circuit->nodes[node_index]->value = value;
}

// Get the value of a node
int get_node_value(circuit *circuit, int node_index) {
    return circuit->nodes[node_index]->value;
}

// Simulate a circuit
void simulate_circuit(circuit *circuit) {
    for (int i = 0; i < circuit->num_nodes; i++) {
        // Get the current node
        node *current_node = circuit->nodes[i];

        // If the current node is an input node, then skip it
        if (current_node->next == NULL) {
            continue;
        }

        // Get the next node
        node *next_node = current_node->next;

        // Calculate the new value of the next node
        int new_value = current_node->value;
        if (next_node->value == 1) {
            new_value = !new_value;
        }

        // Set the new value of the next node
        next_node->value = new_value;
    }
}

int main() {
    // Create a new circuit
    circuit *circuit = create_circuit(5);

    // Set the input values
    set_node_value(circuit, 0, 1);
    set_node_value(circuit, 1, 0);

    // Simulate the circuit
    simulate_circuit(circuit);

    // Print the output values
    print_circuit(circuit);

    // Free the circuit
    free_circuit(circuit);

    return 0;
}