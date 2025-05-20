//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct node {
    int id;
    int in_degree;
    int out_degree;
    struct node *in_edges[MAX_EDGES];
    struct node *out_edges[MAX_EDGES];
} node;

typedef struct edge {
    int id;
    int weight;
    struct node *source;
    struct node *destination;
} edge;

typedef struct circuit {
    int num_nodes;
    int num_edges;
    struct node nodes[MAX_NODES];
    struct edge edges[MAX_EDGES];
} circuit;

// Create a new circuit
circuit *new_circuit() {
    circuit *c = malloc(sizeof(circuit));
    c->num_nodes = 0;
    c->num_edges = 0;
    return c;
}

// Add a new node to the circuit
node *add_node(circuit *c) {
    node *n = malloc(sizeof(node));
    n->id = c->num_nodes++;
    n->in_degree = 0;
    n->out_degree = 0;
    return n;
}

// Add a new edge to the circuit
edge *add_edge(circuit *c, node *source, node *destination, int weight) {
    edge *e = malloc(sizeof(edge));
    e->id = c->num_edges++;
    e->weight = weight;
    e->source = source;
    e->destination = destination;
    source->out_edges[source->out_degree++] = e;
    destination->in_edges[destination->in_degree++] = e;
    return e;
}

// Print the circuit
void print_circuit(circuit *c) {
    for (int i = 0; i < c->num_nodes; i++) {
        node *n = &c->nodes[i];
        printf("Node %d: in_degree=%d, out_degree=%d\n", n->id, n->in_degree, n->out_degree);
        for (int j = 0; j < n->in_degree; j++) {
            printf("  In edge: %d\n", n->in_edges[j]->id);
        }
        for (int j = 0; j < n->out_degree; j++) {
            printf("  Out edge: %d\n", n->out_edges[j]->id);
        }
    }
}

// Free the circuit
void free_circuit(circuit *c) {
    for (int i = 0; i < c->num_nodes; i++) {
        free(&c->nodes[i]);
    }
    for (int i = 0; i < c->num_edges; i++) {
        free(&c->edges[i]);
    }
    free(c);
}

int main() {
    // Create a new circuit
    circuit *c = new_circuit();

    // Add some nodes to the circuit
    node *n1 = add_node(c);
    node *n2 = add_node(c);
    node *n3 = add_node(c);

    // Add some edges to the circuit
    add_edge(c, n1, n2, 1);
    add_edge(c, n2, n3, 1);
    add_edge(c, n3, n1, 1);

    // Print the circuit
    print_circuit(c);

    // Free the circuit
    free_circuit(c);

    return 0;
}