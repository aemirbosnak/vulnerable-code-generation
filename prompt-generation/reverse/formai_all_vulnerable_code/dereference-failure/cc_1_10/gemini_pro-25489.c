//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int val;
    struct node *next;
} node;

typedef struct circuit {
    int num_nodes;
    node *nodes;
} circuit;

circuit *create_circuit(int num_nodes) {
    circuit *c = malloc(sizeof(circuit));
    c->num_nodes = num_nodes;
    c->nodes = malloc(sizeof(node) * num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        c->nodes[i].val = 0;
        c->nodes[i].next = NULL;
    }
    return c;
}

void destroy_circuit(circuit *c) {
    for (int i = 0; i < c->num_nodes; i++) {
        node *n = c->nodes[i].next;
        while (n != NULL) {
            node *tmp = n;
            n = n->next;
            free(tmp);
        }
    }
    free(c->nodes);
    free(c);
}

void connect_nodes(circuit *c, int node1, int node2) {
    node *n1 = &c->nodes[node1];
    node *n2 = &c->nodes[node2];
    while (n1->next != NULL) {
        n1 = n1->next;
    }
    n1->next = n2;
}

void set_node_value(circuit *c, int node, int val) {
    c->nodes[node].val = val;
}

int get_node_value(circuit *c, int node) {
    return c->nodes[node].val;
}

void simulate_circuit(circuit *c) {
    for (int i = 0; i < c->num_nodes; i++) {
        node *n = &c->nodes[i];
        int val = n->val;
        while (n->next != NULL) {
            n = n->next;
            val &= n->val;
        }
        c->nodes[i].val = val;
    }
}

int main() {
    circuit *c = create_circuit(5);
    connect_nodes(c, 0, 1);
    connect_nodes(c, 1, 2);
    connect_nodes(c, 2, 3);
    connect_nodes(c, 3, 4);
    set_node_value(c, 0, 1);
    set_node_value(c, 2, 1);
    simulate_circuit(c);
    printf("Node 4 value: %d\n", get_node_value(c, 4));
    destroy_circuit(c);
    return 0;
}