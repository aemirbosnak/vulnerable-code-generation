//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Node structure
typedef struct node {
    int value;
    struct node *next;
} node;

// Circuit structure
typedef struct circuit {
    int num_nodes;
    int num_inputs;
    int num_outputs;
    node **nodes;
    int *inputs;
    int *outputs;
} circuit;

// Create a new circuit
circuit *create_circuit(int num_nodes, int num_inputs, int num_outputs) {
    circuit *c = malloc(sizeof(circuit));
    c->num_nodes = num_nodes;
    c->num_inputs = num_inputs;
    c->num_outputs = num_outputs;
    c->nodes = malloc(sizeof(node *) * num_nodes);
    c->inputs = malloc(sizeof(int) * num_inputs);
    c->outputs = malloc(sizeof(int) * num_outputs);
    for (int i = 0; i < num_nodes; i++) {
        c->nodes[i] = NULL;
    }
    for (int i = 0; i < num_inputs; i++) {
        c->inputs[i] = 0;
    }
    for (int i = 0; i < num_outputs; i++) {
        c->outputs[i] = 0;
    }
    return c;
}

// Free a circuit
void free_circuit(circuit *c) {
    for (int i = 0; i < c->num_nodes; i++) {
        node *n = c->nodes[i];
        while (n != NULL) {
            node *next = n->next;
            free(n);
            n = next;
        }
    }
    free(c->nodes);
    free(c->inputs);
    free(c->outputs);
    free(c);
}

// Add a node to a circuit
void add_node(circuit *c, int value) {
    node *n = malloc(sizeof(node));
    n->value = value;
    n->next = NULL;
    c->nodes[c->num_nodes++] = n;
}

// Add an input to a circuit
void add_input(circuit *c, int input) {
    c->inputs[c->num_inputs++] = input;
}

// Add an output to a circuit
void add_output(circuit *c, int output) {
    c->outputs[c->num_outputs++] = output;
}

// Connect two nodes in a circuit
void connect_nodes(circuit *c, int node1, int node2) {
    node *n1 = c->nodes[node1];
    node *n2 = c->nodes[node2];
    while (n1->next != NULL) {
        n1 = n1->next;
    }
    n1->next = n2;
}

// Evaluate a circuit
void evaluate_circuit(circuit *c) {
    for (int i = 0; i < c->num_nodes; i++) {
        node *n = c->nodes[i];
        int value = n->value;
        while (n->next != NULL) {
            n = n->next;
            value = value && n->value;
        }
        c->outputs[i] = value;
    }
}

// Print a circuit
void print_circuit(circuit *c) {
    for (int i = 0; i < c->num_nodes; i++) {
        node *n = c->nodes[i];
        printf("Node %d: %d", i, n->value);
        while (n->next != NULL) {
            n = n->next;
            printf(" -> %d", n->value);
        }
        printf("\n");
    }
    for (int i = 0; i < c->num_inputs; i++) {
        printf("Input %d: %d\n", i, c->inputs[i]);
    }
    for (int i = 0; i < c->num_outputs; i++) {
        printf("Output %d: %d\n", i, c->outputs[i]);
    }
}

// Main function
int main() {
    // Create a circuit
    circuit *c = create_circuit(4, 2, 1);

    // Add nodes to the circuit
    add_node(c, 0);
    add_node(c, 0);
    add_node(c, 0);
    add_node(c, 0);

    // Add inputs to the circuit
    add_input(c, 0);
    add_input(c, 0);

    // Add outputs to the circuit
    add_output(c, 0);

    // Connect the nodes in the circuit
    connect_nodes(c, 0, 1);
    connect_nodes(c, 1, 2);
    connect_nodes(c, 2, 3);

    // Evaluate the circuit
    evaluate_circuit(c);

    // Print the circuit
    print_circuit(c);

    // Free the circuit
    free_circuit(c);

    return 0;
}