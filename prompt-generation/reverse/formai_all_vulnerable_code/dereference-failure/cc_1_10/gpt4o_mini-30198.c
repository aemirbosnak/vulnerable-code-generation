//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_COMPONENTS 100

typedef enum {
    RESISTOR,
    CAPACITOR,
    INDUCTOR,
    SOURCE
} ComponentType;

typedef struct {
    ComponentType type;
    char name[20];
    double value; // resistance in Ohms, capacitance in Farads, inductance in Henrys, voltage in Volts
} Component;

typedef struct {
    Component* components[MAX_COMPONENTS];
    int component_count;
} Circuit;

Circuit* create_circuit() {
    Circuit* circuit = (Circuit*)malloc(sizeof(Circuit));
    circuit->component_count = 0;
    return circuit;
}

void add_component(Circuit* circuit, ComponentType type, const char* name, double value) {
    if (circuit->component_count >= MAX_COMPONENTS) {
        printf("Maximum component limit reached.\n");
        return;
    }
    Component* component = (Component*)malloc(sizeof(Component));
    component->type = type;
    snprintf(component->name, sizeof(component->name), "%s", name);
    component->value = value;
    circuit->components[circuit->component_count++] = component;
}

void display_circuit(Circuit* circuit) {
    printf("Circuit contains:\n");
    for (int i = 0; i < circuit->component_count; i++) {
        Component* comp = circuit->components[i];
        switch (comp->type) {
            case RESISTOR:
                printf("Resistor: %s, Resistance: %.2f Ohms\n", comp->name, comp->value);
                break;
            case CAPACITOR:
                printf("Capacitor: %s, Capacitance: %.2f Farads\n", comp->name, comp->value);
                break;
            case INDUCTOR:
                printf("Inductor: %s, Inductance: %.2f Henrys\n", comp->name, comp->value);
                break;
            case SOURCE:
                printf("Source: %s, Voltage: %.2f Volts\n", comp->name, comp->value);
                break;
        }
    }
}

double calculate_total_resistance(Circuit* circuit) {
    double total_resistance = 0.0;
    for (int i = 0; i < circuit->component_count; i++) {
        if (circuit->components[i]->type == RESISTOR) {
            total_resistance += circuit->components[i]->value;
        }
    }
    return total_resistance;
}

double calculate_total_capacitance(Circuit* circuit) {
    double total_capacitance = 0.0;
    for (int i = 0; i < circuit->component_count; i++) {
        if (circuit->components[i]->type == CAPACITOR) {
            total_capacitance += circuit->components[i]->value;
        }
    }
    return total_capacitance;
}

double calculate_total_inductance(Circuit* circuit) {
    double total_inductance = 0.0;
    for (int i = 0; i < circuit->component_count; i++) {
        if (circuit->components[i]->type == INDUCTOR) {
            total_inductance += circuit->components[i]->value;
        }
    }
    return total_inductance;
}

void free_circuit(Circuit* circuit) {
    for (int i = 0; i < circuit->component_count; i++) {
        free(circuit->components[i]);
    }
    free(circuit);
}

int main() {
    Circuit* my_circuit = create_circuit();

    add_component(my_circuit, RESISTOR, "R1", 100.0);
    add_component(my_circuit, CAPACITOR, "C1", 0.001);
    add_component(my_circuit, INDUCTOR, "L1", 0.05);
    add_component(my_circuit, SOURCE, "V1", 12.0);
    add_component(my_circuit, RESISTOR, "R2", 150.0);

    display_circuit(my_circuit);

    double total_res = calculate_total_resistance(my_circuit);
    double total_cap = calculate_total_capacitance(my_circuit);
    double total_ind = calculate_total_inductance(my_circuit);

    printf("\nTotal Resistance: %.2f Ohms\n", total_res);
    printf("Total Capacitance: %.6f Farads\n", total_cap);
    printf("Total Inductance: %.2f Henrys\n", total_ind);

    free_circuit(my_circuit);
    return 0;
}