//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: automated
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX_NODES 100

typedef struct node {
    int id;
    int value;
    struct node *next;
} node_t;

typedef struct circuit {
    node_t *nodes[MAX_NODES];
    int num_nodes;
} circuit_t;

circuit_t *create_circuit() {
    circuit_t *circuit = malloc(sizeof(circuit_t));
    circuit->num_nodes = 0;
    return circuit;
}

void destroy_circuit(circuit_t *circuit) {
    for (int i = 0; i < circuit->num_nodes; i++) {
        node_t *node = circuit->nodes[i];
        while (node != NULL) {
            node_t *next = node->next;
            free(node);
            node = next;
        }
    }
    free(circuit);
}

node_t *create_node(int id, int value) {
    node_t *node = malloc(sizeof(node_t));
    node->id = id;
    node->value = value;
    node->next = NULL;
    return node;
}

void add_node(circuit_t *circuit, node_t *node) {
    circuit->nodes[circuit->num_nodes++] = node;
}

void connect_nodes(circuit_t *circuit, node_t *node1, node_t *node2) {
    node_t *new_node = create_node(node1->id + node2->id, node1->value & node2->value);
    add_node(circuit, new_node);
    node1->next = new_node;
    node2->next = new_node;
}

void simulate_circuit(circuit_t *circuit) {
    for (int i = 0; i < circuit->num_nodes; i++) {
        node_t *node = circuit->nodes[i];
        while (node != NULL) {
            node->value = node->value & node->next->value;
            node = node->next;
        }
    }
}

void print_circuit(circuit_t *circuit) {
    for (int i = 0; i < circuit->num_nodes; i++) {
        node_t *node = circuit->nodes[i];
        printf("Node %d: %d\n", node->id, node->value);
    }
}

int main() {
    circuit_t *circuit = create_circuit();
    node_t *node1 = create_node(1, 1);
    node_t *node2 = create_node(2, 0);
    node_t *node3 = create_node(3, 1);
    node_t *node4 = create_node(4, 0);
    add_node(circuit, node1);
    add_node(circuit, node2);
    add_node(circuit, node3);
    add_node(circuit, node4);
    connect_nodes(circuit, node1, node2);
    connect_nodes(circuit, node3, node4);
    simulate_circuit(circuit);
    print_circuit(circuit);
    destroy_circuit(circuit);
    return 0;
}