//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: careful
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
    int num_nodes;
    node **nodes;
} circuit;

// Create a new circuit
circuit *create_circuit(int num_nodes) {
    circuit *c = malloc(sizeof(circuit));
    c->num_nodes = num_nodes;
    c->nodes = malloc(sizeof(node *) * num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        c->nodes[i] = NULL;
    }
    return c;
}

// Add a node to a circuit
void add_node(circuit *c, int value) {
    node *n = malloc(sizeof(node));
    n->value = value;
    n->next = NULL;
    c->nodes[c->num_nodes++] = n;
}

// Connect two nodes in a circuit
void connect_nodes(circuit *c, int node1, int node2) {
    node *n1 = c->nodes[node1];
    node *n2 = c->nodes[node2];
    n1->next = n2;
}

// Print a circuit
void print_circuit(circuit *c) {
    for (int i = 0; i < c->num_nodes; i++) {
        node *n = c->nodes[i];
        printf("Node %d: ", i);
        while (n != NULL) {
            printf("%d ", n->value);
            n = n->next;
        }
        printf("\n");
    }
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
    free(c);
}

// Main function
int main() {
    // Create a new circuit
    circuit *c = create_circuit(5);

    // Add nodes to the circuit
    add_node(c, 0);
    add_node(c, 1);
    add_node(c, 2);
    add_node(c, 3);
    add_node(c, 4);

    // Connect the nodes in the circuit
    connect_nodes(c, 0, 1);
    connect_nodes(c, 1, 2);
    connect_nodes(c, 2, 3);
    connect_nodes(c, 3, 4);

    // Print the circuit
    print_circuit(c);

    // Free the circuit
    free_circuit(c);

    return 0;
}