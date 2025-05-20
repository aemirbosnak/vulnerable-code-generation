//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum number of nodes in the circuit
#define MAX_NODES 100

// Define the types of nodes in the circuit
typedef enum {
    NODE_TYPE_INPUT,
    NODE_TYPE_OUTPUT,
    NODE_TYPE_AND,
    NODE_TYPE_OR,
    NODE_TYPE_NOT
} node_type_t;

// Define the structure of a node in the circuit
typedef struct {
    node_type_t type;
    int num_inputs;
    int *inputs;
    int output;
} node_t;

// Define the structure of the circuit
typedef struct {
    int num_nodes;
    node_t *nodes;
} circuit_t;

// Create a new circuit
circuit_t *create_circuit() {
    circuit_t *circuit = malloc(sizeof(circuit_t));
    circuit->num_nodes = 0;
    circuit->nodes = malloc(sizeof(node_t) * MAX_NODES);
    return circuit;
}

// Destroy a circuit
void destroy_circuit(circuit_t *circuit) {
    free(circuit->nodes);
    free(circuit);
}

// Add a node to the circuit
void add_node(circuit_t *circuit, node_type_t type, int num_inputs, int *inputs, int output) {
    node_t *node = &circuit->nodes[circuit->num_nodes];
    node->type = type;
    node->num_inputs = num_inputs;
    node->inputs = inputs;
    node->output = output;
    circuit->num_nodes++;
}

// Evaluate the circuit
void evaluate_circuit(circuit_t *circuit) {
    for (int i = 0; i < circuit->num_nodes; i++) {
        node_t *node = &circuit->nodes[i];
        switch (node->type) {
            case NODE_TYPE_INPUT:
                // Input nodes have no inputs, so their output is simply their value
                node->output = node->inputs[0];
                break;
            case NODE_TYPE_OUTPUT:
                // Output nodes have no outputs, so their value is simply the value of their input
                node->output = node->inputs[0];
                break;
            case NODE_TYPE_AND:
                // AND nodes output a 1 if all of their inputs are 1, and a 0 otherwise
                node->output = 1;
                for (int j = 0; j < node->num_inputs; j++) {
                    if (node->inputs[j] == 0) {
                        node->output = 0;
                        break;
                    }
                }
                break;
            case NODE_TYPE_OR:
                // OR nodes output a 1 if any of their inputs are 1, and a 0 otherwise
                node->output = 0;
                for (int j = 0; j < node->num_inputs; j++) {
                    if (node->inputs[j] == 1) {
                        node->output = 1;
                        break;
                    }
                }
                break;
            case NODE_TYPE_NOT:
                // NOT nodes output a 1 if their input is 0, and a 0 otherwise
                node->output = !node->inputs[0];
                break;
        }
    }
}

// Print the circuit
void print_circuit(circuit_t *circuit) {
    for (int i = 0; i < circuit->num_nodes; i++) {
        node_t *node = &circuit->nodes[i];
        printf("Node %d: ", i);
        switch (node->type) {
            case NODE_TYPE_INPUT:
                printf("INPUT\n");
                break;
            case NODE_TYPE_OUTPUT:
                printf("OUTPUT\n");
                break;
            case NODE_TYPE_AND:
                printf("AND");
                for (int j = 0; j < node->num_inputs; j++) {
                    printf(" %d", node->inputs[j]);
                }
                printf("\n");
                break;
            case NODE_TYPE_OR:
                printf("OR");
                for (int j = 0; j < node->num_inputs; j++) {
                    printf(" %d", node->inputs[j]);
                }
                printf("\n");
                break;
            case NODE_TYPE_NOT:
                printf("NOT %d\n", node->inputs[0]);
                break;
        }
    }
}

// Main function
int main() {
    // Create a new circuit
    circuit_t *circuit = create_circuit();

    // Add nodes to the circuit
    add_node(circuit, NODE_TYPE_INPUT, 0, NULL, 0);
    add_node(circuit, NODE_TYPE_INPUT, 0, NULL, 1);
    add_node(circuit, NODE_TYPE_AND, 2, (int []){0, 1}, 2);
    add_node(circuit, NODE_TYPE_OUTPUT, 1, (int []){2}, 3);

    // Evaluate the circuit
    evaluate_circuit(circuit);

    // Print the circuit
    print_circuit(circuit);

    // Destroy the circuit
    destroy_circuit(circuit);

    return 0;
}