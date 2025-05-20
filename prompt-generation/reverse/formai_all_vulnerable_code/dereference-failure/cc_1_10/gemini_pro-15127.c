//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
typedef struct node {
    int value;
    struct node *next;
} node;

// Circuit structure
typedef struct circuit {
    node *inputs;
    node *outputs;
    int num_inputs;
    int num_outputs;
} circuit;

// Create a new circuit
circuit *create_circuit(int num_inputs, int num_outputs) {
    circuit *c = malloc(sizeof(circuit));
    c->num_inputs = num_inputs;
    c->num_outputs = num_outputs;
    c->inputs = malloc(sizeof(node) * num_inputs);
    c->outputs = malloc(sizeof(node) * num_outputs);
    return c;
}

// Free a circuit
void free_circuit(circuit *c) {
    free(c->inputs);
    free(c->outputs);
    free(c);
}

// Set the value of an input node
void set_input(circuit *c, int input_index, int value) {
    c->inputs[input_index].value = value;
}

// Get the value of an output node
int get_output(circuit *c, int output_index) {
    return c->outputs[output_index].value;
}

// Connect two nodes
void connect(node *from, node *to) {
    to->next = from;
}

// Create a new node
node *create_node(int value) {
    node *n = malloc(sizeof(node));
    n->value = value;
    n->next = NULL;
    return n;
}

// Evaluate a circuit
void evaluate(circuit *c) {
    // Initialize the output values
    for (int i = 0; i < c->num_outputs; i++) {
        c->outputs[i].value = 0;
    }

    // Iterate over the output nodes
    for (int i = 0; i < c->num_outputs; i++) {
        node *n = c->outputs[i].next;

        // Iterate over the input nodes connected to the output node
        while (n != NULL) {
            // Update the output value based on the input value
            c->outputs[i].value |= n->value;

            // Move to the next input node
            n = n->next;
        }
    }
}

// Print the circuit
void print_circuit(circuit *c) {
    printf("Inputs:\n");
    for (int i = 0; i < c->num_inputs; i++) {
        printf("  %d: %d\n", i, c->inputs[i].value);
    }

    printf("Outputs:\n");
    for (int i = 0; i < c->num_outputs; i++) {
        printf("  %d: %d\n", i, c->outputs[i].value);
    }
}

int main() {
    // Create a circuit with 2 inputs and 1 output
    circuit *c = create_circuit(2, 1);

    // Create the input nodes
    node *input1 = create_node(0);
    node *input2 = create_node(1);

    // Create the output node
    node *output = create_node(-1);

    // Connect the input nodes to the output node
    connect(input1, output);
    connect(input2, output);

    // Set the input values
    set_input(c, 0, 1);
    set_input(c, 1, 0);

    // Evaluate the circuit
    evaluate(c);

    // Print the circuit
    print_circuit(c);

    // Free the circuit
    free_circuit(c);

    return 0;
}