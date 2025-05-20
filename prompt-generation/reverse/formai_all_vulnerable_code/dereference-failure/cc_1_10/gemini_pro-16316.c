//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} node;

typedef struct circuit {
    int num_nodes;
    node **nodes;
} circuit;

circuit *create_circuit(int num_nodes) {
    circuit *c = malloc(sizeof(circuit));
    c->num_nodes = num_nodes;
    c->nodes = malloc(sizeof(node *) * num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        c->nodes[i] = malloc(sizeof(node));
        c->nodes[i]->value = 0;
        c->nodes[i]->next = NULL;
    }
    return c;
}

void destroy_circuit(circuit *c) {
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

void connect_nodes(circuit *c, int node1, int node2) {
    node *n1 = c->nodes[node1];
    while (n1->next != NULL) {
        n1 = n1->next;
    }
    n1->next = c->nodes[node2];
}

void set_node_value(circuit *c, int node, int value) {
    c->nodes[node]->value = value;
}

int get_node_value(circuit *c, int node) {
    return c->nodes[node]->value;
}

void simulate_circuit(circuit *c) {
    for (int i = 0; i < c->num_nodes; i++) {
        node *n = c->nodes[i];
        int value = n->value;
        while (n != NULL) {
            value |= n->next->value;
            n = n->next;
        }
        set_node_value(c, i, value);
    }
}

void print_circuit(circuit *c) {
    for (int i = 0; i < c->num_nodes; i++) {
        printf("Node %d: %d\n", i, get_node_value(c, i));
    }
}

int main() {
    circuit *c = create_circuit(5);

    connect_nodes(c, 0, 1);
    connect_nodes(c, 1, 2);
    connect_nodes(c, 2, 3);
    connect_nodes(c, 3, 4);

    set_node_value(c, 0, 1);

    simulate_circuit(c);

    print_circuit(c);

    destroy_circuit(c);

    return 0;
}