//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_COMPONENTS 1000
#define MAX_NODES 10000
#define MAX_BRANCHES 10000

typedef struct {
    int type;
    double value;
    int nodes[2];
} Component;

typedef struct {
    int num_nodes;
    int num_components;
    Component *components;
    double *node_values;
} Circuit;

void add_component(Circuit *circuit, Component *component) {
    circuit->components[circuit->num_components++] = *component;
}

void add_branch(Circuit *circuit, int node1, int node2, Component *component) {
    circuit->components[circuit->num_components++] = *component;
    circuit->node_values[node1] += component->value;
    circuit->node_values[node2] -= component->value;
}

void solve_circuit(Circuit *circuit) {
    for (int i = 0; i < circuit->num_components; i++) {
        Component *component = &circuit->components[i];
        int node1 = component->nodes[0];
        int node2 = component->nodes[1];
        circuit->node_values[node1] -= component->value;
        circuit->node_values[node2] += component->value;
    }
}

int main() {
    Circuit circuit;
    circuit.num_nodes = 0;
    circuit.num_components = 0;
    circuit.components = malloc(MAX_COMPONENTS * sizeof(Component));
    circuit.node_values = malloc(MAX_NODES * sizeof(double));

    // Example circuit with a voltage source and a resistor
    Component voltage_source = {.type = 1,.value = 5.0,.nodes = {0, 1}};
    Component resistor = {.type = 2,.value = 100.0,.nodes = {1, 2}};

    add_component(&circuit, &voltage_source);
    add_component(&circuit, &resistor);
    add_branch(&circuit, 0, 1, &voltage_source);

    solve_circuit(&circuit);

    printf("Node 1 voltage: %.2f\n", circuit.node_values[1]);
    printf("Node 2 voltage: %.2f\n", circuit.node_values[2]);

    return 0;
}