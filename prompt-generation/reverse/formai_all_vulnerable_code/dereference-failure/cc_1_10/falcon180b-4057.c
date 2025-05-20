//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_COMPONENTS 100
#define MAX_NODES 1000

typedef struct {
    int type; // 1 for resistor, 2 for capacitor, 3 for inductor
    int node1;
    int node2;
    double value;
} Component;

typedef struct {
    int num_components;
    Component components[MAX_COMPONENTS];
} Circuit;

Circuit* create_circuit() {
    Circuit* circuit = (Circuit*)malloc(sizeof(Circuit));
    circuit->num_components = 0;
    return circuit;
}

void add_component(Circuit* circuit, int type, int node1, int node2, double value) {
    Component* component = &circuit->components[circuit->num_components];
    component->type = type;
    component->node1 = node1;
    component->node2 = node2;
    component->value = value;
    circuit->num_components++;
}

void simulate_circuit(Circuit* circuit, double dt) {
    int i, j;
    double* voltages = (double*)malloc(sizeof(double) * circuit->num_components);
    for (i = 0; i < circuit->num_components; i++) {
        Component* component = &circuit->components[i];
        if (component->type == 1) { // resistor
            voltages[i] = (component->value * (voltages[component->node1] - voltages[component->node2])) / component->value;
        } else if (component->type == 2) { // capacitor
            voltages[i] = (voltages[component->node1] + voltages[component->node2]) / 2;
        } else if (component->type == 3) { // inductor
            voltages[i] = (component->value * voltages[component->node1]) - (component->value * voltages[component->node2]);
        }
    }
    for (i = 0; i < circuit->num_components; i++) {
        Component* component = &circuit->components[i];
        if (component->type == 1) { // resistor
            voltages[component->node1] += voltages[i];
            voltages[component->node2] -= voltages[i];
        } else if (component->type == 2) { // capacitor
            voltages[component->node1] += voltages[i];
            voltages[component->node2] -= voltages[i];
        } else if (component->type == 3) { // inductor
            voltages[component->node1] -= voltages[i];
            voltages[component->node2] += voltages[i];
        }
    }
    free(voltages);
}

void print_circuit(Circuit* circuit) {
    int i;
    for (i = 0; i < circuit->num_components; i++) {
        Component* component = &circuit->components[i];
        printf("Component %d: Type %d, Node1 %d, Node2 %d, Value %lf\n", i, component->type, component->node1, component->node2, component->value);
    }
}

int main() {
    Circuit* circuit = create_circuit();
    add_component(circuit, 1, 0, 1, 1000);
    add_component(circuit, 2, 1, 0, 1);
    add_component(circuit, 3, 1, 2, 1);
    print_circuit(circuit);
    simulate_circuit(circuit, 0.01);
    print_circuit(circuit);
    return 0;
}