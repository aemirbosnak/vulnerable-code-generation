//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPONENTS 100
#define MAX_NODES 1000

typedef struct {
    int type;
    int value;
    int nodes[2];
} Component;

typedef struct {
    int num_components;
    Component components[MAX_COMPONENTS];
} Circuit;

void add_component(Circuit* circuit, int type, int value, int node1, int node2) {
    if (circuit->num_components >= MAX_COMPONENTS) {
        printf("Error: Too many components!\n");
        exit(1);
    }

    Component component;
    component.type = type;
    component.value = value;
    component.nodes[0] = node1;
    component.nodes[1] = node2;

    circuit->components[circuit->num_components++] = component;
}

void simulate_circuit(Circuit* circuit) {
    int num_nodes = 0;
    for (int i = 0; i < circuit->num_components; i++) {
        Component component = circuit->components[i];
        int node1 = component.nodes[0];
        int node2 = component.nodes[1];

        if (node1 >= MAX_NODES || node2 >= MAX_NODES) {
            printf("Error: Invalid node number!\n");
            exit(1);
        }

        if (node1 >= num_nodes) {
            num_nodes = node1 + 1;
        }

        if (node2 >= num_nodes) {
            num_nodes = node2 + 1;
        }
    }

    int* node_voltages = malloc(num_nodes * sizeof(int));
    for (int i = 0; i < num_nodes; i++) {
        node_voltages[i] = 0;
    }

    for (int i = 0; i < circuit->num_components; i++) {
        Component component = circuit->components[i];
        int node1 = component.nodes[0];
        int node2 = component.nodes[1];
        int voltage = component.value;

        node_voltages[node1] += voltage;
        node_voltages[node2] -= voltage;
    }

    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d voltage: %d\n", i, node_voltages[i]);
    }

    free(node_voltages);
}

int main() {
    Circuit circuit;

    add_component(&circuit, 1, 5, 0, 1);
    add_component(&circuit, 2, 10, 1, 2);
    add_component(&circuit, 3, 15, 2, 0);

    simulate_circuit(&circuit);

    return 0;
}