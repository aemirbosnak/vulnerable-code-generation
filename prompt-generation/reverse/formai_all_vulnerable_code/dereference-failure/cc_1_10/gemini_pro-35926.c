//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_t {
    int value;
    struct node_t *next;
} node_t;

typedef struct circuit_t {
    node_t *nodes;
    int num_nodes;
} circuit_t;

circuit_t *create_circuit(int num_nodes) {
    circuit_t *circuit = malloc(sizeof(circuit_t));
    circuit->nodes = malloc(sizeof(node_t) * num_nodes);
    circuit->num_nodes = num_nodes;
    return circuit;
}

void destroy_circuit(circuit_t *circuit) {
    free(circuit->nodes);
    free(circuit);
}

void add_node(circuit_t *circuit, int value) {
    node_t *node = malloc(sizeof(node_t));
    node->value = value;
    node->next = circuit->nodes;
    circuit->nodes = node;
}

void print_circuit(circuit_t *circuit) {
    node_t *node = circuit->nodes;
    while (node) {
        printf("%d ", node->value);
        node = node->next;
    }
    printf("\n");
}

int main(void) {
    circuit_t *circuit = create_circuit(5);

    add_node(circuit, 1);
    add_node(circuit, 2);
    add_node(circuit, 3);
    add_node(circuit, 4);
    add_node(circuit, 5);

    print_circuit(circuit);

    destroy_circuit(circuit);

    return 0;
}