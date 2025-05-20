//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define MAX_COMPONENTS 100
#define MAX_NODES 1000

typedef struct {
    char name[20];
    double value;
    int type;
    int node1;
    int node2;
} Component;

typedef struct {
    int num_nodes;
    int num_components;
    Component components[MAX_COMPONENTS];
    double nodes[MAX_NODES];
} Circuit;

void add_component(Circuit *circuit, Component component) {
    if (circuit->num_components >= MAX_COMPONENTS) {
        printf("Error: Maximum number of components reached.\n");
        return;
    }
    circuit->components[circuit->num_components] = component;
    circuit->num_components++;
}

void add_node(Circuit *circuit, double node) {
    if (circuit->num_nodes >= MAX_NODES) {
        printf("Error: Maximum number of nodes reached.\n");
        return;
    }
    circuit->nodes[circuit->num_nodes] = node;
    circuit->num_nodes++;
}

void connect_nodes(Circuit *circuit, int node1, int node2) {
    Component component;
    component.type = 1;
    component.node1 = node1;
    component.node2 = node2;
    add_component(circuit, component);
}

void connect_component(Circuit *circuit, int component_index, int node1, int node2) {
    Component component;
    component.type = 2;
    component.node1 = node1;
    component.node2 = node2;
    component.value = circuit->components[component_index].value;
    add_component(circuit, component);
}

void simulate_circuit(Circuit *circuit) {
    int i, j;
    double voltage[MAX_NODES];
    for (i = 0; i < circuit->num_nodes; i++) {
        voltage[i] = circuit->nodes[i];
    }
    for (i = 0; i < circuit->num_components; i++) {
        if (circuit->components[i].type == 1) {
            voltage[circuit->components[i].node1] = voltage[circuit->components[i].node2];
        } else if (circuit->components[i].type == 2) {
            voltage[circuit->components[i].node1] = voltage[circuit->components[i].node2] * circuit->components[i].value;
        }
    }
    for (i = 0; i < circuit->num_nodes; i++) {
        printf("%s: %lf\n", circuit->nodes[i] > 0? "V+" : "V-", voltage[i]);
    }
}

int main() {
    Circuit circuit;
    int i, j;
    for (i = 0; i < 3; i++) {
        add_node(&circuit, i * 5);
    }
    for (i = 0; i < 3; i++) {
        for (j = i + 1; j < 3; j++) {
            connect_nodes(&circuit, i * 5, j * 5);
        }
    }
    simulate_circuit(&circuit);
    return 0;
}