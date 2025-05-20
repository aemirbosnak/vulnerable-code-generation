//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

// Define a node struct for the circuit
typedef struct Node {
    int value;
    struct Node* next;
} Node;

// Define a function to create a new node with a starting value
Node* create_node(int value) {
    Node* node = malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}

// Define a function to add a node to the end of a circuit
void add_node(Node* circuit, int value) {
    Node* current = circuit;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = create_node(value);
}

// Define a function to calculate the output of a circuit
int calculate_output(Node* circuit) {
    int output = 0;
    Node* current = circuit;
    while (current != NULL) {
        output += current->value;
        current = current->next;
    }
    return output;
}

int main() {
    // Create a circuit with three nodes
    Node* circuit = create_node(1);
    add_node(circuit, 0);
    add_node(circuit, 1);

    // Calculate the initial output of the circuit
    int output = calculate_output(circuit);
    printf("Initial output: %d\n", output);

    // Change the value of the second node and recalculate the output
    circuit->next->value = 1;
    output = calculate_output(circuit);
    printf("Updated output: %d\n", output);

    // Clean up the circuit by deleting all nodes
    Node* current = circuit;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}