//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
node *new_node(int value) {
    node *new = malloc(sizeof(node));
    new->value = value;
    new->next = NULL;
    return new;
}

// Create a new circuit
circuit *new_circuit() {
    circuit *new = malloc(sizeof(circuit));
    new->head = NULL;
    new->tail = NULL;
    return new;
}

// Add a node to the circuit
void add_node(circuit *c, int value) {
    node *new = new_node(value);
    if (c->head == NULL) {
        c->head = new;
        c->tail = new;
    } else {
        c->tail->next = new;
        c->tail = new;
    }
}

// Simulate the circuit
void simulate(circuit *c) {
    node *current = c->head;
    while (current != NULL) {
        // Do something with the node's value
        printf("%d\n", current->value);
        current = current->next;
    }
}

// Free the circuit
void free_circuit(circuit *c) {
    node *current = c->head;
    while (current != NULL) {
        node *next = current->next;
        free(current);
        current = next;
    }
    free(c);
}

int main() {
    // Create a new circuit
    circuit *c = new_circuit();

    // Add some nodes to the circuit
    add_node(c, 1);
    add_node(c, 2);
    add_node(c, 3);

    // Simulate the circuit
    simulate(c);

    // Free the circuit
    free_circuit(c);

    return 0;
}