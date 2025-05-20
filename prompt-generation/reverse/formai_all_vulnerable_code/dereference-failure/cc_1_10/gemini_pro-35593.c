//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: curious
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int val;
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
        c->nodes[i] = NULL;
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

void add_edge(circuit *c, int from, int to) {
    node *n = malloc(sizeof(node));
    n->val = to;
    n->next = c->nodes[from];
    c->nodes[from] = n;
}

void print_circuit(circuit *c) {
    for (int i = 0; i < c->num_nodes; i++) {
        printf("Node %d: ", i);
        node *n = c->nodes[i];
        while (n != NULL) {
            printf("%d ", n->val);
            n = n->next;
        }
        printf("\n");
    }
}

int main() {
    circuit *c = create_circuit(5);
    add_edge(c, 0, 1);
    add_edge(c, 0, 2);
    add_edge(c, 1, 3);
    add_edge(c, 2, 4);
    print_circuit(c);
    destroy_circuit(c);
    return 0;
}