//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_COMPONENTS 100
#define MAX_NODES 1000
#define MAX_LINKS 10000

typedef struct {
    double value;
    int node1, node2;
} link;

typedef struct {
    double value;
    int node;
    int type;
} node;

typedef struct {
    int num_components;
    int num_nodes;
    int num_links;
    node *nodes;
    link *links;
} circuit;

void create_circuit(circuit *c) {
    c->num_components = 0;
    c->num_nodes = 0;
    c->num_links = 0;
    c->nodes = (node *)malloc(MAX_NODES * sizeof(node));
    c->links = (link *)malloc(MAX_LINKS * sizeof(link));
}

void destroy_circuit(circuit *c) {
    free(c->nodes);
    free(c->links);
}

void add_node(circuit *c, double value, int type) {
    node *n = &c->nodes[c->num_nodes++];
    n->value = value;
    n->node = c->num_nodes - 1;
    n->type = type;
}

void add_link(circuit *c, double value, int node1, int node2) {
    link *l = &c->links[c->num_links++];
    l->value = value;
    l->node1 = node1;
    l->node2 = node2;
}

void simulate_circuit(circuit *c) {
    for (int i = 0; i < c->num_components; i++) {
        node *n = &c->nodes[i];
        double voltage = 0;
        for (int j = 0; j < n->node; j++) {
            link *l = &c->links[j];
            voltage += l->value * (n->value - c->nodes[l->node2].value);
        }
        printf("Component %d has voltage %f\n", i, voltage);
    }
}

int main() {
    circuit c;
    create_circuit(&c);
    add_node(&c, 5, 0);
    add_node(&c, 10, 0);
    add_node(&c, 15, 0);
    add_link(&c, 1, 0, 1);
    add_link(&c, 2, 1, 2);
    simulate_circuit(&c);
    destroy_circuit(&c);
    return 0;
}