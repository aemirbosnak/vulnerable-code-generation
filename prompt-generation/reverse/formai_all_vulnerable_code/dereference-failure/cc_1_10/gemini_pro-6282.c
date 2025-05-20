//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int value;
    struct node *next;
} node;

// Circuit structure
typedef struct circuit {
    node *inputs;
    node *outputs;
} circuit;

// Create a new node
node *create_node(int value) {
    node *new_node = malloc(sizeof(node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

// Create a new circuit
circuit *create_circuit(int num_inputs, int num_outputs) {
    circuit *new_circuit = malloc(sizeof(circuit));
    new_circuit->inputs = create_node(0);
    new_circuit->outputs = create_node(0);
    for (int i = 1; i < num_inputs; i++) {
        new_circuit->inputs = create_node(0);
    }
    for (int i = 1; i < num_outputs; i++) {
        new_circuit->outputs = create_node(0);
    }
    return new_circuit;
}

// Connect two nodes
void connect_nodes(node *node1, node *node2) {
    node1->next = node2;
}

// Evaluate a circuit
void evaluate_circuit(circuit *circuit) {
    node *current_node = circuit->inputs;
    while (current_node != NULL) {
        current_node->value = rand() % 2;
        current_node = current_node->next;
    }
    current_node = circuit->outputs;
    while (current_node != NULL) {
        current_node->value = (current_node->value + current_node->next->value) % 2;
        current_node = current_node->next;
    }
}

// Print a circuit
void print_circuit(circuit *circuit) {
    node *current_node = circuit->inputs;
    while (current_node != NULL) {
        printf("%d ", current_node->value);
        current_node = current_node->next;
    }
    printf("\n");
    current_node = circuit->outputs;
    while (current_node != NULL) {
        printf("%d ", current_node->value);
        current_node = current_node->next;
    }
    printf("\n");
}

// Free a circuit
void free_circuit(circuit *circuit) {
    node *current_node = circuit->inputs;
    while (current_node != NULL) {
        node *next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
    current_node = circuit->outputs;
    while (current_node != NULL) {
        node *next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
    free(circuit);
}

int main() {
    // Create a circuit
    circuit *circuit = create_circuit(3, 2);

    // Connect the nodes
    connect_nodes(circuit->inputs, circuit->outputs);
    connect_nodes(circuit->inputs->next, circuit->outputs);
    connect_nodes(circuit->inputs->next->next, circuit->outputs);

    // Evaluate the circuit
    evaluate_circuit(circuit);

    // Print the circuit
    print_circuit(circuit);

    // Free the circuit
    free_circuit(circuit);

    return 0;
}