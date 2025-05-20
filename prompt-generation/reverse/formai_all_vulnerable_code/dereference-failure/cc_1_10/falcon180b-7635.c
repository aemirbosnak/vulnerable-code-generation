//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_COMPONENTS 100
#define MAX_NODES 200
#define MAX_EDGES 200

typedef struct {
    int node1;
    int node2;
    double resistance;
} Edge;

typedef struct {
    int num_nodes;
    int num_edges;
    Edge edges[MAX_EDGES];
} Circuit;

Circuit create_circuit() {
    Circuit c;
    c.num_nodes = 0;
    c.num_edges = 0;
    return c;
}

void add_node(Circuit *c) {
    c->num_nodes++;
}

void add_edge(Circuit *c, int node1, int node2, double resistance) {
    Edge e;
    e.node1 = node1;
    e.node2 = node2;
    e.resistance = resistance;
    c->edges[c->num_edges++] = e;
}

void print_circuit(Circuit c) {
    printf("Circuit:\n");
    printf("Number of nodes: %d\n", c.num_nodes);
    printf("Number of edges: %d\n", c.num_edges);
    for (int i = 0; i < c.num_edges; i++) {
        Edge e = c.edges[i];
        printf("Edge %d: Node1 = %d, Node2 = %d, Resistance = %lf\n", i, e.node1, e.node2, e.resistance);
    }
}

void simulate_circuit(Circuit c, double voltage) {
    int *currents = malloc(c.num_nodes * sizeof(int));
    for (int i = 0; i < c.num_nodes; i++) {
        currents[i] = 0;
    }

    for (int i = 0; i < c.num_edges; i++) {
        Edge e = c.edges[i];
        int node1 = e.node1;
        int node2 = e.node2;
        double resistance = e.resistance;

        double current = (voltage - currents[node1]) / resistance;
        currents[node1] += current;
        currents[node2] -= current;
    }

    printf("Simulation:\n");
    for (int i = 0; i < c.num_nodes; i++) {
        printf("Node %d: Current = %lf\n", i, currents[i]);
    }
}

int main() {
    Circuit c = create_circuit();
    add_node(&c);
    add_node(&c);
    add_edge(&c, 0, 1, 10.0);

    print_circuit(c);
    simulate_circuit(c, 5.0);

    return 0;
}