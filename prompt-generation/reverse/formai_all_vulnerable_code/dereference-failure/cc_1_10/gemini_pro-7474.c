//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct node {
    int id;
    int value;
    int num_edges;
    int edges[MAX_EDGES];
} node;

typedef struct circuit {
    int num_nodes;
    node nodes[MAX_NODES];
} circuit;

circuit* create_circuit(int num_nodes) {
    circuit* c = malloc(sizeof(circuit));
    c->num_nodes = num_nodes;
    for (int i = 0; i < num_nodes; i++) {
        c->nodes[i].id = i;
        c->nodes[i].value = 0;
        c->nodes[i].num_edges = 0;
    }
    return c;
}

void add_edge(circuit* c, int node1, int node2) {
    c->nodes[node1].edges[c->nodes[node1].num_edges++] = node2;
    c->nodes[node2].edges[c->nodes[node2].num_edges++] = node1;
}

void print_circuit(circuit* c) {
    for (int i = 0; i < c->num_nodes; i++) {
        printf("Node %d: value = %d, edges = [", c->nodes[i].id, c->nodes[i].value);
        for (int j = 0; j < c->nodes[i].num_edges; j++) {
            printf(" %d", c->nodes[i].edges[j]);
        }
        printf(" ]\n");
    }
}

void simulate_circuit(circuit* c) {
    int changed = 1;
    while (changed) {
        changed = 0;
        for (int i = 0; i < c->num_nodes; i++) {
            int new_value = 0;
            for (int j = 0; j < c->nodes[i].num_edges; j++) {
                new_value |= c->nodes[c->nodes[i].edges[j]].value;
            }
            if (new_value != c->nodes[i].value) {
                c->nodes[i].value = new_value;
                changed = 1;
            }
        }
    }
}

int main() {
    circuit* c = create_circuit(5);
    add_edge(c, 0, 1);
    add_edge(c, 1, 2);
    add_edge(c, 2, 3);
    add_edge(c, 3, 4);
    print_circuit(c);
    simulate_circuit(c);
    print_circuit(c);
    return 0;
}