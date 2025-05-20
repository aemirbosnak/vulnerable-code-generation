//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct node {
    int id;
    char *name;
    int num_edges;
    int *edges;
} node;

typedef struct edge {
    int id;
    int source;
    int destination;
    int weight;
} edge;

typedef struct circuit {
    int num_nodes;
    int num_edges;
    node *nodes;
    edge *edges;
} circuit;

circuit *create_circuit() {
    circuit *c = malloc(sizeof(circuit));
    c->num_nodes = 0;
    c->num_edges = 0;
    c->nodes = malloc(sizeof(node) * MAX_NODES);
    c->edges = malloc(sizeof(edge) * MAX_EDGES);
    return c;
}

void destroy_circuit(circuit *c) {
    for (int i = 0; i < c->num_nodes; i++) {
        free(c->nodes[i].name);
        free(c->nodes[i].edges);
    }
    free(c->nodes);
    free(c->edges);
    free(c);
}

node *create_node(circuit *c, char *name) {
    node *n = &c->nodes[c->num_nodes++];
    n->id = c->num_nodes;
    n->name = strdup(name);
    n->num_edges = 0;
    n->edges = malloc(sizeof(int) * MAX_EDGES);
    return n;
}

edge *create_edge(circuit *c, int source, int destination, int weight) {
    edge *e = &c->edges[c->num_edges++];
    e->id = c->num_edges;
    e->source = source;
    e->destination = destination;
    e->weight = weight;
    return e;
}

void add_edge(circuit *c, node *source, node *destination, int weight) {
    edge *e = create_edge(c, source->id, destination->id, weight);
    source->edges[source->num_edges++] = e->id;
    destination->edges[destination->num_edges++] = e->id;
}

void print_circuit(circuit *c) {
    for (int i = 0; i < c->num_nodes; i++) {
        printf("Node %d: %s\n", c->nodes[i].id, c->nodes[i].name);
        for (int j = 0; j < c->nodes[i].num_edges; j++) {
            printf("  Edge %d: %d -> %d (%d)\n", c->edges[c->nodes[i].edges[j]].id, c->edges[c->nodes[i].edges[j]].source, c->edges[c->nodes[i].edges[j]].destination, c->edges[c->nodes[i].edges[j]].weight);
        }
    }
}

int main() {
    circuit *c = create_circuit();

    node *n1 = create_node(c, "Node 1");
    node *n2 = create_node(c, "Node 2");
    node *n3 = create_node(c, "Node 3");

    add_edge(c, n1, n2, 10);
    add_edge(c, n1, n3, 20);
    add_edge(c, n2, n3, 30);

    print_circuit(c);

    destroy_circuit(c);

    return 0;
}