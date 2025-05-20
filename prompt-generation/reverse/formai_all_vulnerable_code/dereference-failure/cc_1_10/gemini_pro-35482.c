//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
typedef struct node {
    int data;
    struct node *next;
} node;

// Circuit structure
typedef struct circuit {
    int num_nodes;
    node **nodes;
} circuit;

// Create a new node
node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Create a new circuit
circuit *create_circuit(int num_nodes) {
    circuit *new_circuit = (circuit *)malloc(sizeof(circuit));
    new_circuit->num_nodes = num_nodes;
    new_circuit->nodes = (node **)malloc(sizeof(node *) * num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        new_circuit->nodes[i] = NULL;
    }
    return new_circuit;
}

// Add a new node to the circuit
void add_node(circuit *circuit, int node_num, int data) {
    node *new_node = create_node(data);
    new_node->next = circuit->nodes[node_num];
    circuit->nodes[node_num] = new_node;
}

// Print the circuit
void print_circuit(circuit *circuit) {
    for (int i = 0; i < circuit->num_nodes; i++) {
        node *current_node = circuit->nodes[i];
        printf("Node %d: ", i);
        while (current_node != NULL) {
            printf("%d ", current_node->data);
            current_node = current_node->next;
        }
        printf("\n");
    }
}

// Simulate the circuit
void simulate_circuit(circuit *circuit) {
    // Initialize the node values
    int *node_values = (int *)malloc(sizeof(int) * circuit->num_nodes);
    for (int i = 0; i < circuit->num_nodes; i++) {
        node_values[i] = 0;
    }

    // Iterate over the nodes
    for (int i = 0; i < circuit->num_nodes; i++) {
        node *current_node = circuit->nodes[i];

        // Update the node value
        int new_value = 0;
        while (current_node != NULL) {
            new_value += current_node->data;
            current_node = current_node->next;
        }
        node_values[i] = new_value;
    }

    // Print the node values
    printf("Node values:\n");
    for (int i = 0; i < circuit->num_nodes; i++) {
        printf("Node %d: %d\n", i, node_values[i]);
    }
}

// Free the circuit
void free_circuit(circuit *circuit) {
    for (int i = 0; i < circuit->num_nodes; i++) {
        node *current_node = circuit->nodes[i];
        while (current_node != NULL) {
            node *next_node = current_node->next;
            free(current_node);
            current_node = next_node;
        }
    }
    free(circuit->nodes);
    free(circuit);
}

int main() {
    // Create a new circuit
    circuit *circuit = create_circuit(5);

    // Add nodes to the circuit
    add_node(circuit, 0, 1);
    add_node(circuit, 0, 2);
    add_node(circuit, 1, 3);
    add_node(circuit, 1, 4);
    add_node(circuit, 2, 5);
    add_node(circuit, 2, 6);
    add_node(circuit, 3, 7);
    add_node(circuit, 3, 8);
    add_node(circuit, 4, 9);
    add_node(circuit, 4, 10);

    // Print the circuit
    print_circuit(circuit);

    // Simulate the circuit
    simulate_circuit(circuit);

    // Free the circuit
    free_circuit(circuit);

    return 0;
}