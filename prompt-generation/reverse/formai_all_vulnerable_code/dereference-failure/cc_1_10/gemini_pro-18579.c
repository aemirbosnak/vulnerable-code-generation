//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    RESISTOR,
    CAPACITOR,
    INDUCTOR,
    VOLTAGE_SOURCE,
    CURRENT_SOURCE
} ComponentType;

typedef struct {
    ComponentType type;
    double value;
    char *name;
} Component;

typedef struct {
    int num_components;
    Component *components;
} Circuit;

Circuit *create_circuit(int num_components) {
    Circuit *circuit = malloc(sizeof(Circuit));
    circuit->num_components = num_components;
    circuit->components = malloc(sizeof(Component) * num_components);
    return circuit;
}

void add_component(Circuit *circuit, ComponentType type, double value, char *name) {
    Component component = {type, value, name};
    circuit->components[circuit->num_components++] = component;
}

void print_circuit(Circuit *circuit) {
    for (int i = 0; i < circuit->num_components; i++) {
        Component component = circuit->components[i];
        printf("Component %d: %s, %f\n", i, component.name, component.value);
    }
}

int main() {
    Circuit *circuit = create_circuit(3);

    add_component(circuit, RESISTOR, 100, "R1");
    add_component(circuit, CAPACITOR, 10e-6, "C1");
    add_component(circuit, VOLTAGE_SOURCE, 10, "V1");
    
    // A simple DC simulation
    for (int i = 0; i < circuit->num_components; i++) {
        Component component = circuit->components[i];
        if (component.type == VOLTAGE_SOURCE) {
            printf("Voltage across %s: %fV\n", component.name, component.value);
        } else if (component.type == CURRENT_SOURCE) {
            printf("Current through %s: %f\n", component.name, component.value);
        }
    }

    print_circuit(circuit);

    return 0;
}