//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NODES 1000
#define MAX_COMPONENTS 1000
#define MAX_CONNECTIONS 10000

typedef struct {
    int num_nodes;
    int nodes[MAX_NODES];
    double values[MAX_NODES];
} Circuit;

Circuit *create_circuit(int num_nodes) {
    Circuit *circuit = (Circuit *) malloc(sizeof(Circuit));
    circuit->num_nodes = num_nodes;
    for (int i = 0; i < num_nodes; i++) {
        circuit->nodes[i] = -1;
        circuit->values[i] = 0.0;
    }
    return circuit;
}

void add_node(Circuit *circuit, int node) {
    circuit->nodes[circuit->num_nodes] = node;
    circuit->num_nodes++;
}

void add_connection(Circuit *circuit, int node1, int node2, double value) {
    int index = circuit->nodes[node1] - circuit->nodes[0];
    if (index == -1) {
        add_node(circuit, node1);
        index = circuit->nodes[node1] - circuit->nodes[0];
    }
    index = circuit->nodes[node2] - circuit->nodes[0];
    if (index == -1) {
        add_node(circuit, node2);
        index = circuit->nodes[node2] - circuit->nodes[0];
    }
    circuit->values[index] = value;
}

void simulate_circuit(Circuit *circuit) {
    for (int i = 0; i < circuit->num_nodes; i++) {
        int node = circuit->nodes[i];
        double value = circuit->values[i];
        if (node == 0) {
            printf("Node %d = %f\n", node, value);
        } else {
            printf("Connection between nodes %d and %d with value %f\n", node, node - 1, value);
        }
    }
}

int main() {
    Circuit *circuit = create_circuit(5);
    add_node(circuit, 0);
    add_node(circuit, 1);
    add_node(circuit, 2);
    add_node(circuit, 3);
    add_node(circuit, 4);
    add_connection(circuit, 0, 1, 1.0);
    add_connection(circuit, 1, 2, 2.0);
    add_connection(circuit, 2, 3, 3.0);
    add_connection(circuit, 3, 4, 4.0);
    add_connection(circuit, 4, 0, 5.0);
    simulate_circuit(circuit);
    return 0;
}