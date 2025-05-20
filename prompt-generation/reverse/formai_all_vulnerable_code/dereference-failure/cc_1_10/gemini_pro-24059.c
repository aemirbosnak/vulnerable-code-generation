//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct circuit {
    int num_nodes;
    int num_edges;
    node **nodes;
    int **edges;
} circuit;

circuit *create_circuit(int num_nodes, int num_edges) {
    circuit *c = malloc(sizeof(circuit));
    c->num_nodes = num_nodes;
    c->num_edges = num_edges;
    c->nodes = malloc(sizeof(node *) * num_nodes);
    c->edges = malloc(sizeof(int *) * num_edges);
    for (int i = 0; i < num_nodes; i++) {
        c->nodes[i] = malloc(sizeof(node));
        c->nodes[i]->data = i;
        c->nodes[i]->next = NULL;
    }
    for (int i = 0; i < num_edges; i++) {
        c->edges[i] = malloc(sizeof(int) * 2);
    }
    return c;
}

void destroy_circuit(circuit *c) {
    for (int i = 0; i < c->num_nodes; i++) {
        free(c->nodes[i]);
    }
    for (int i = 0; i < c->num_edges; i++) {
        free(c->edges[i]);
    }
    free(c->nodes);
    free(c->edges);
    free(c);
}

void print_circuit(circuit *c) {
    printf("Circuit has %d nodes and %d edges:\n", c->num_nodes, c->num_edges);
    for (int i = 0; i < c->num_nodes; i++) {
        printf("Node %d: ", i);
        node *n = c->nodes[i];
        while (n != NULL) {
            printf("%d ", n->data);
            n = n->next;
        }
        printf("\n");
    }
    for (int i = 0; i < c->num_edges; i++) {
        printf("Edge %d: %d -> %d\n", i, c->edges[i][0], c->edges[i][1]);
    }
}

int main() {
    circuit *c = create_circuit(5, 5);
    c->edges[0][0] = 0; c->edges[0][1] = 1;
    c->edges[1][0] = 1; c->edges[1][1] = 2;
    c->edges[2][0] = 2; c->edges[2][1] = 3;
    c->edges[3][0] = 3; c->edges[3][1] = 4;
    c->edges[4][0] = 4; c->edges[4][1] = 0;
    print_circuit(c);
    destroy_circuit(c);
    return 0;
}