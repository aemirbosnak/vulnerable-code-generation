//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_COMPONENTS 100
#define MAX_NODES 1000

typedef struct component {
    int type;
    int num_nodes;
    double value;
    int *node_indices;
} Component;

typedef struct circuit {
    int num_components;
    Component *components;
} Circuit;

void create_circuit(Circuit *circuit) {
    circuit->num_components = 0;
    circuit->components = malloc(MAX_COMPONENTS * sizeof(Component));
}

void add_component(Circuit *circuit, int type, double value, int num_nodes, int *node_indices) {
    if (circuit->num_components >= MAX_COMPONENTS) {
        printf("Error: Maximum number of components reached.\n");
        exit(1);
    }

    Component *new_component = &circuit->components[circuit->num_components];
    new_component->type = type;
    new_component->value = value;
    new_component->num_nodes = num_nodes;
    new_component->node_indices = malloc(num_nodes * sizeof(int));
    for (int i = 0; i < num_nodes; i++) {
        new_component->node_indices[i] = node_indices[i];
    }

    circuit->num_components++;
}

void simulate_circuit(Circuit *circuit) {
    for (int i = 0; i < circuit->num_components; i++) {
        Component *component = &circuit->components[i];
        int num_nodes = component->num_nodes;
        double value = component->value;

        for (int j = 0; j < num_nodes; j++) {
            int node_index = component->node_indices[j];
            double node_voltage = 0;

            for (int k = 0; k < circuit->num_components; k++) {
                if (k == i) continue;

                Component *other_component = &circuit->components[k];
                int other_num_nodes = other_component->num_nodes;

                if (other_num_nodes == 2) {
                    int other_node1_index = other_component->node_indices[0];
                    int other_node2_index = other_component->node_indices[1];

                    if (other_node1_index == node_index || other_node2_index == node_index) {
                        node_voltage += other_component->value;
                    }
                }
            }

            node_voltage /= value;
            printf("Node %d voltage: %.2f\n", node_index, node_voltage);
        }
    }
}

int main() {
    Circuit circuit;
    create_circuit(&circuit);

    add_component(&circuit, 1, 1.0, 2, (int[]) {0, 1});
    add_component(&circuit, 2, 1.0, 2, (int[]) {1, 2});
    add_component(&circuit, 3, 1.0, 2, (int[]) {2, 0});

    simulate_circuit(&circuit);

    return 0;
}