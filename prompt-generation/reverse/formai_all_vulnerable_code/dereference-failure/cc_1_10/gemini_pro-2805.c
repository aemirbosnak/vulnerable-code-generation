//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Node structure
typedef struct Node {
    int id;
    char type;  // 'I' for input, 'O' for output, 'G' for gate
    int num_inputs;
    int *inputs;
    int output;
    char gate_type;  // 'A' for AND, 'O' for OR, 'N' for NOT
} Node;

// Circuit structure
typedef struct Circuit {
    int num_nodes;
    Node *nodes;
} Circuit;

// Create a new circuit
Circuit *new_circuit() {
    Circuit *circuit = malloc(sizeof(Circuit));
    circuit->num_nodes = 0;
    circuit->nodes = NULL;
    return circuit;
}

// Add a new node to the circuit
void add_node(Circuit *circuit, Node node) {
    circuit->num_nodes++;
    circuit->nodes = realloc(circuit->nodes, circuit->num_nodes * sizeof(Node));
    circuit->nodes[circuit->num_nodes - 1] = node;
}

// Get the output of a node
int get_output(Circuit *circuit, int node_id) {
    Node node = circuit->nodes[node_id];
    if (node.type == 'I') {
        return node.output;
    } else if (node.type == 'O') {
        return 0;
    } else if (node.type == 'G') {
        int output = 0;
        for (int i = 0; i < node.num_inputs; i++) {
            if (node.gate_type == 'A') {
                output &= get_output(circuit, node.inputs[i]);
            } else if (node.gate_type == 'O') {
                output |= get_output(circuit, node.inputs[i]);
            } else if (node.gate_type == 'N') {
                output = !get_output(circuit, node.inputs[i]);
            }
        }
        return output;
    } else {
        return -1;
    }
}

// Print the circuit
void print_circuit(Circuit *circuit) {
    for (int i = 0; i < circuit->num_nodes; i++) {
        Node node = circuit->nodes[i];
        printf("Node %d: type %c, output %d\n", node.id, node.type, node.output);
    }
}

// Free the circuit
void free_circuit(Circuit *circuit) {
    for (int i = 0; i < circuit->num_nodes; i++) {
        free(circuit->nodes[i].inputs);
    }
    free(circuit->nodes);
    free(circuit);
}

// Example main function
int main() {
    // Create a new circuit
    Circuit *circuit = new_circuit();

    // Add input nodes
    Node input_node1 = {1, 'I', 0, NULL, 0, 0};
    add_node(circuit, input_node1);
    Node input_node2 = {2, 'I', 0, NULL, 0, 0};
    add_node(circuit, input_node2);

    // Add AND gate node
    Node and_gate_node = {3, 'G', 2, malloc(2 * sizeof(int)), 0, 'A'};
    and_gate_node.inputs[0] = input_node1.id;
    and_gate_node.inputs[1] = input_node2.id;
    add_node(circuit, and_gate_node);

    // Add output node
    Node output_node = {4, 'O', 1, &and_gate_node.id, 0, 0};
    add_node(circuit, output_node);

    // Print the circuit
    print_circuit(circuit);

    // Set the input values
    input_node1.output = 1;
    input_node2.output = 1;

    // Get the output of the circuit
    int output = get_output(circuit, output_node.id);
    printf("Output: %d\n", output);

    // Free the circuit
    free_circuit(circuit);

    return 0;
}