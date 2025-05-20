//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double value;
    int pin1;
    int pin2;
} component;

typedef struct {
    int num_components;
    component* components;
} circuit;

void add_component(circuit* circuit, double value, int pin1, int pin2) {
    circuit->components = realloc(circuit->components, sizeof(component) * ++circuit->num_components);
    circuit->components[circuit->num_components - 1].value = value;
    circuit->components[circuit->num_components - 1].pin1 = pin1;
    circuit->components[circuit->num_components - 1].pin2 = pin2;
}

void simulate_circuit(circuit* circuit, double* voltages, int num_nodes) {
    for (int i = 0; i < circuit->num_components; i++) {
        int node1 = circuit->components[i].pin1;
        int node2 = circuit->components[i].pin2;
        double resistance = circuit->components[i].value;

        voltages[node1] += resistance * (voltages[node2] - voltages[node1]);
        voltages[node2] -= resistance * (voltages[node2] - voltages[node1]);
    }
}

int main() {
    circuit circuit = {0};
    add_component(&circuit, 1000, 0, 1);
    add_component(&circuit, 1000, 1, 2);
    add_component(&circuit, 1000, 2, 0);

    double voltages[3];
    voltages[0] = 5;
    voltages[1] = 0;
    voltages[2] = 0;

    int num_nodes = 3;

    for (int i = 0; i < 10; i++) {
        simulate_circuit(&circuit, voltages, num_nodes);
        printf("Iteration %d:\n", i);
        for (int j = 0; j < num_nodes; j++) {
            printf("Node %d: %.2f V\n", j, voltages[j]);
        }
    }

    return 0;
}