//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

typedef struct circuit {
    int *nodes;
    int num_nodes;
    int *components;
    int num_components;
} Circuit;

Circuit *create_circuit(int num_nodes, int num_components) {
    Circuit *circuit = malloc(sizeof(Circuit));
    circuit->nodes = malloc(num_nodes * sizeof(int));
    circuit->components = malloc(num_components * sizeof(int));
    circuit->num_nodes = num_nodes;
    circuit->num_components = num_components;
    return circuit;
}

void add_component(Circuit *circuit, int component) {
    circuit->components[circuit->num_components++] = component;
}

void connect_nodes(Circuit *circuit, int node1, int node2) {
    circuit->nodes[node1] |= (1 << node2);
    circuit->nodes[node2] |= (1 << node1);
}

int main() {
    Circuit *circuit = create_circuit(5, 3);
    add_component(circuit, 1);
    add_component(circuit, 2);
    add_component(circuit, 3);

    connect_nodes(circuit, 0, 1);
    connect_nodes(circuit, 1, 2);
    connect_nodes(circuit, 2, 3);
    connect_nodes(circuit, 3, 4);

    for (int i = 0; i < circuit->num_nodes; i++) {
        printf("Node %d: ", i);
        for (int j = 0; j < circuit->num_nodes; j++) {
            if (circuit->nodes[i] & (1 << j)) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }

    return 0;
}