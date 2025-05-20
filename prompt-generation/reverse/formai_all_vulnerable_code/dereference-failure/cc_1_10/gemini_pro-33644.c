//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node types
typedef enum {
    NODE_INPUT,
    NODE_OUTPUT,
    NODE_AND,
    NODE_OR,
    NODE_NOT
} NodeType;

// Node struct
typedef struct Node {
    NodeType type;
    int num_inputs;
    int* inputs;
    int output;
} Node;

// Circuit struct
typedef struct Circuit {
    int num_nodes;
    Node* nodes;
} Circuit;

// Create a new circuit
Circuit* create_circuit(int num_nodes) {
    Circuit* circuit = malloc(sizeof(Circuit));
    circuit->num_nodes = num_nodes;
    circuit->nodes = malloc(sizeof(Node) * num_nodes);
    return circuit;
}

// Destroy a circuit
void destroy_circuit(Circuit* circuit) {
    for (int i = 0; i < circuit->num_nodes; i++) {
        free(circuit->nodes[i].inputs);
    }
    free(circuit->nodes);
    free(circuit);
}

// Add a node to a circuit
void add_node(Circuit* circuit, NodeType type, int num_inputs, int* inputs) {
    Node* node = &circuit->nodes[circuit->num_nodes++];
    node->type = type;
    node->num_inputs = num_inputs;
    node->inputs = malloc(sizeof(int) * num_inputs);
    memcpy(node->inputs, inputs, sizeof(int) * num_inputs);
}

// Evaluate a circuit
void evaluate_circuit(Circuit* circuit) {
    for (int i = 0; i < circuit->num_nodes; i++) {
        Node* node = &circuit->nodes[i];
        switch (node->type) {
            case NODE_INPUT:
                break;
            case NODE_OUTPUT:
                node->output = node->inputs[0];
                break;
            case NODE_AND:
                node->output = 1;
                for (int j = 0; j < node->num_inputs; j++) {
                    node->output &= circuit->nodes[node->inputs[j]].output;
                }
                break;
            case NODE_OR:
                node->output = 0;
                for (int j = 0; j < node->num_inputs; j++) {
                    node->output |= circuit->nodes[node->inputs[j]].output;
                }
                break;
            case NODE_NOT:
                node->output = !circuit->nodes[node->inputs[0]].output;
                break;
        }
    }
}

// Print a circuit
void print_circuit(Circuit* circuit) {
    for (int i = 0; i < circuit->num_nodes; i++) {
        Node* node = &circuit->nodes[i];
        printf("Node %d: ", i);
        switch (node->type) {
            case NODE_INPUT:
                printf("input");
                break;
            case NODE_OUTPUT:
                printf("output");
                break;
            case NODE_AND:
                printf("and");
                break;
            case NODE_OR:
                printf("or");
                break;
            case NODE_NOT:
                printf("not");
                break;
        }
        printf(" (");
        for (int j = 0; j < node->num_inputs; j++) {
            printf("%d ", node->inputs[j]);
        }
        printf(")\n");
    }
}

// Main function
int main() {
    // Create a circuit
    Circuit* circuit = create_circuit(5);

    // Add nodes to the circuit
    add_node(circuit, NODE_INPUT, 0, NULL);
    add_node(circuit, NODE_INPUT, 0, NULL);
    add_node(circuit, NODE_AND, 2, (int[]) {0, 1});
    add_node(circuit, NODE_NOT, 1, (int[]) {2});
    add_node(circuit, NODE_OUTPUT, 1, (int[]) {3});

    // Evaluate the circuit
    evaluate_circuit(circuit);

    // Print the circuit
    print_circuit(circuit);

    // Destroy the circuit
    destroy_circuit(circuit);

    return 0;
}