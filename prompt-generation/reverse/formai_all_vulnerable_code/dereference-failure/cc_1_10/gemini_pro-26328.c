//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int value;
    struct node *next;
} node;

// Circuit structure
typedef struct circuit {
    node *head;
    node *tail;
} circuit;

// Create a new node
node *create_node(int value) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

// Create a new circuit
circuit *create_circuit() {
    circuit *new_circuit = (circuit *)malloc(sizeof(circuit));
    new_circuit->head = NULL;
    new_circuit->tail = NULL;
    return new_circuit;
}

// Add a node to the circuit
void add_node(circuit *circuit, int value) {
    node *new_node = create_node(value);
    if (circuit->head == NULL) {
        circuit->head = new_node;
        circuit->tail = new_node;
    } else {
        circuit->tail->next = new_node;
        circuit->tail = new_node;
    }
}

// Print the circuit
void print_circuit(circuit *circuit) {
    node *current_node = circuit->head;
    while (current_node != NULL) {
        printf("%d ", current_node->value);
        current_node = current_node->next;
    }
    printf("\n");
}

// Simulate the circuit
void simulate_circuit(circuit *circuit) {
    node *current_node = circuit->head;
    while (current_node != NULL) {
        if (current_node->value == 1) {
            printf("The circuit is closed.\n");
            return;
        }
        current_node = current_node->next;
    }
    printf("The circuit is open.\n");
}

// Free the circuit
void free_circuit(circuit *circuit) {
    node *current_node = circuit->head;
    while (current_node != NULL) {
        node *next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
    free(circuit);
}

int main() {
    // Create a new circuit
    circuit *circuit = create_circuit();

    // Add nodes to the circuit
    add_node(circuit, 0);
    add_node(circuit, 1);
    add_node(circuit, 0);
    add_node(circuit, 1);

    // Print the circuit
    print_circuit(circuit);

    // Simulate the circuit
    simulate_circuit(circuit);

    // Free the circuit
    free_circuit(circuit);

    return 0;
}