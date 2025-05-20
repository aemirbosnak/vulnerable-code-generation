//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_COMPONENTS 1000
#define MAX_NODES 1000
#define MAX_EDGES 10000

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

Circuit* create_circuit() {
    Circuit* circuit = (Circuit*)malloc(sizeof(Circuit));
    circuit->num_nodes = 0;
    circuit->num_edges = 0;
    return circuit;
}

void add_node(Circuit* circuit) {
    circuit->num_nodes++;
}

void add_edge(Circuit* circuit, int node1, int node2, double resistance) {
    Edge edge = {node1, node2, resistance};
    circuit->edges[circuit->num_edges++] = edge;
}

double get_voltage(int node, Circuit* circuit) {
    double voltage = 0.0;
    int i;
    for (i = 0; i < circuit->num_edges; i++) {
        Edge edge = circuit->edges[i];
        if (edge.node1 == node || edge.node2 == node) {
            voltage += edge.resistance * (get_voltage(edge.node1 == node? edge.node2 : edge.node1, circuit) - get_voltage(edge.node2 == node? edge.node1 : edge.node2, circuit));
        }
    }
    return voltage;
}

int main() {
    Circuit* circuit = create_circuit();
    add_node(circuit);
    add_node(circuit);
    add_edge(circuit, 0, 1, 100.0);
    add_edge(circuit, 1, 0, 100.0);
    printf("Voltage at node 0: %lf\n", get_voltage(0, circuit));
    printf("Voltage at node 1: %lf\n", get_voltage(1, circuit));
    return 0;
}