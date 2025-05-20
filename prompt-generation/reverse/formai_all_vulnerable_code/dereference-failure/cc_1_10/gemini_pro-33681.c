//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
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
        c->nodes[i].data = 0;
        c->nodes[i].next = NULL;
    }
    return c;
}

void destroy_circuit(circuit *c) {
    for (int i = 0; i < c->num_nodes; i++) {
        node *n = c->nodes[i].next;
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
    node *n = malloc(sizeof(node));
    n->data = node2;
    n->next = c->nodes[node1].next;
    c->nodes[node1].next = n;
}

void print_circuit(circuit *c) {
    for (int i = 0; i < c->num_nodes; i++) {
        printf("Node %d: ", i);
        node *n = c->nodes[i].next;
        while (n != NULL) {
            printf("%d ", n->data);
            n = n->next;
        }
        printf("\n");
    }
}

int main() {
    circuit *c = create_circuit(5);
    connect_nodes(c, 0, 1);
    connect_nodes(c, 0, 2);
    connect_nodes(c, 1, 3);
    connect_nodes(c, 2, 4);
    print_circuit(c);
    destroy_circuit(c);
    return 0;
}