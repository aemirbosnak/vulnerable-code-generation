//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node {
    int val;
    struct _node *next;
} node;

typedef struct _circuit {
    int num_inputs;
    int num_outputs;
    node **inputs;
    node **outputs;
} circuit;

node *create_node(int val) {
    node *new_node = malloc(sizeof(node));
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}

circuit *create_circuit(int num_inputs, int num_outputs) {
    circuit *new_circuit = malloc(sizeof(circuit));
    new_circuit->num_inputs = num_inputs;
    new_circuit->num_outputs = num_outputs;
    new_circuit->inputs = malloc(sizeof(node *) * num_inputs);
    new_circuit->outputs = malloc(sizeof(node *) * num_outputs);
    for (int i = 0; i < num_inputs; i++) {
        new_circuit->inputs[i] = create_node(0);
    }
    for (int i = 0; i < num_outputs; i++) {
        new_circuit->outputs[i] = create_node(0);
    }
    return new_circuit;
}

void free_circuit(circuit *circuit) {
    for (int i = 0; i < circuit->num_inputs; i++) {
        node *current_node = circuit->inputs[i];
        while (current_node != NULL) {
            node *next_node = current_node->next;
            free(current_node);
            current_node = next_node;
        }
    }
    for (int i = 0; i < circuit->num_outputs; i++) {
        node *current_node = circuit->outputs[i];
        while (current_node != NULL) {
            node *next_node = current_node->next;
            free(current_node);
            current_node = next_node;
        }
    }
    free(circuit->inputs);
    free(circuit->outputs);
    free(circuit);
}

void add_input(circuit *circuit, int input_index, int val) {
    node *new_node = create_node(val);
    new_node->next = circuit->inputs[input_index];
    circuit->inputs[input_index] = new_node;
}

int get_output(circuit *circuit, int output_index) {
    return circuit->outputs[output_index]->val;
}

void simulate_circuit(circuit *circuit) {
    // TODO: Implement the circuit simulation here.
}

int main() {
    circuit *circuit = create_circuit(2, 1);

    add_input(circuit, 0, 1);
    add_input(circuit, 1, 0);

    simulate_circuit(circuit);

    int output = get_output(circuit, 0);

    printf("Output: %d\n", output);

    free_circuit(circuit);

    return 0;
}