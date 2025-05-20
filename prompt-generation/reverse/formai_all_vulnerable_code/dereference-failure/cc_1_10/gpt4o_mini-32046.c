//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_COMPONENTS 100

typedef enum {
    RESISTOR,
    CAPACITOR,
    INDUCTOR,
    VOLTAGE_SOURCE,
    CURRENT_SOURCE
} ComponentType;

typedef struct {
    ComponentType type;
    char name[20];
    double value; // Ohms for resistor, Farads for capacitor, etc.
} Component;

typedef struct {
    Component *components[MAX_COMPONENTS];
    int component_count;
} Circuit;

void add_component(Circuit *circuit, ComponentType type, const char *name, double value) {
    if (circuit->component_count >= MAX_COMPONENTS) {
        printf("Max component limit reached.\n");
        return;
    }
    Component *component = (Component *)malloc(sizeof(Component));
    component->type = type;
    strcpy(component->name, name);
    component->value = value;
    circuit->components[circuit->component_count++] = component;
}

void print_circuit(const Circuit *circuit) {
    printf("Circuit Components:\n");
    for (int i = 0; i < circuit->component_count; i++) {
        Component *c = circuit->components[i];
        char *type_string;
        switch (c->type) {
            case RESISTOR: type_string = "Resistor"; break;
            case CAPACITOR: type_string = "Capacitor"; break;
            case INDUCTOR: type_string = "Inductor"; break;
            case VOLTAGE_SOURCE: type_string = "Voltage Source"; break;
            case CURRENT_SOURCE: type_string = "Current Source"; break;
            default: type_string = "Unknown"; break;
        }
        printf("Component: %s, Type: %s, Value: %.2f\n", c->name, type_string, c->value);
    }
}

double calculate_total_resistance(const Circuit *circuit) {
    double total_resistance = 0.0;
    for (int i = 0; i < circuit->component_count; i++) {
        if (circuit->components[i]->type == RESISTOR) {
            total_resistance += circuit->components[i]->value;
        }
    }
    return total_resistance;
}

double calculate_total_capacitance(const Circuit *circuit) {
    double total_capacitance = 0.0;
    for (int i = 0; i < circuit->component_count; i++) {
        if (circuit->components[i]->type == CAPACITOR) {
            total_capacitance += circuit->components[i]->value;
        }
    }
    return total_capacitance;
}

void free_circuit(Circuit *circuit) {
    for (int i = 0; i < circuit->component_count; i++) {
        free(circuit->components[i]);
    }
    circuit->component_count = 0;
}

int main() {
    Circuit circuit = { .component_count = 0 };

    add_component(&circuit, RESISTOR, "R1", 100.0);
    add_component(&circuit, CAPACITOR, "C1", 1e-6);
    add_component(&circuit, INDUCTOR, "L1", 0.01);
    add_component(&circuit, VOLTAGE_SOURCE, "V1", 5.0);
    add_component(&circuit, CURRENT_SOURCE, "I1", 0.1);

    print_circuit(&circuit);

    double total_resistance = calculate_total_resistance(&circuit);
    printf("Total Resistance: %.2f Ohms\n", total_resistance);

    double total_capacitance = calculate_total_capacitance(&circuit);
    printf("Total Capacitance: %.2e Farads\n", total_capacitance);

    free_circuit(&circuit);
    return 0;
}