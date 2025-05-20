//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_COMPONENTS 100
#define MAX_NAME_LENGTH 20

typedef enum {
    RESISTOR,
    CAPACITOR,
    INDUCTOR,
    VOLTAGE_SOURCE,
    CURRENT_SOURCE
} ComponentType;

typedef struct {
    char name[MAX_NAME_LENGTH];
    ComponentType type;
    double value;
} Component;

typedef struct {
    Component *components[MAX_COMPONENTS];
    int count;
} Circuit;

void add_component(Circuit *circuit, const char *name, ComponentType type, double value) {
    if (circuit->count >= MAX_COMPONENTS) {
        printf("Error: Cannot add more components to the circuit.\n");
        return;
    }
    Component *component = (Component *)malloc(sizeof(Component));
    strncpy(component->name, name, MAX_NAME_LENGTH);
    component->type = type;
    component->value = value;
    circuit->components[circuit->count++] = component;
}

void display_circuit(const Circuit *circuit) {
    printf("Circuit Components:\n");
    for (int i = 0; i < circuit->count; i++) {
        Component *component = circuit->components[i];
        switch (component->type) {
            case RESISTOR:
                printf("Resistor: %s, Value: %.2f Ohms\n", component->name, component->value);
                break;
            case CAPACITOR:
                printf("Capacitor: %s, Value: %.2f F\n", component->name, component->value);
                break;
            case INDUCTOR:
                printf("Inductor: %s, Value: %.2f H\n", component->name, component->value);
                break;
            case VOLTAGE_SOURCE:
                printf("Voltage Source: %s, Value: %.2f V\n", component->name, component->value);
                break;
            case CURRENT_SOURCE:
                printf("Current Source: %s, Value: %.2f A\n", component->name, component->value);
                break;
        }
    }
}

double calculate_total_resistance(const Circuit *circuit) {
    double total_resistance = 0;
    for (int i = 0; i < circuit->count; i++) {
        if (circuit->components[i]->type == RESISTOR) {
            total_resistance += circuit->components[i]->value;
        }
    }
    return total_resistance;
}

double calculate_total_capacitance(const Circuit *circuit) {
    double total_capacitance = 0;
    for (int i = 0; i < circuit->count; i++) {
        if (circuit->components[i]->type == CAPACITOR) {
            total_capacitance += circuit->components[i]->value;
        }
    }
    return total_capacitance;
}

double calculate_total_inductance(const Circuit *circuit) {
    double total_inductance = 0;
    for (int i = 0; i < circuit->count; i++) {
        if (circuit->components[i]->type == INDUCTOR) {
            total_inductance += circuit->components[i]->value;
        }
    }
    return total_inductance;
}

int main() {
    Circuit circuit;
    circuit.count = 0;

    // Add components
    add_component(&circuit, "R1", RESISTOR, 100.0);
    add_component(&circuit, "C1", CAPACITOR, 0.001);
    add_component(&circuit, "L1", INDUCTOR, 0.25);
    add_component(&circuit, "V1", VOLTAGE_SOURCE, 5.0);
    add_component(&circuit, "I1", CURRENT_SOURCE, 0.01);

    // Display circuit components
    display_circuit(&circuit);

    // Calculate and display total resistance, capacitance, and inductance
    double total_resistance = calculate_total_resistance(&circuit);
    double total_capacitance = calculate_total_capacitance(&circuit);
    double total_inductance = calculate_total_inductance(&circuit);

    printf("Total Resistance: %.2f Ohms\n", total_resistance);
    printf("Total Capacitance: %.6f F\n", total_capacitance);
    printf("Total Inductance: %.2f H\n", total_inductance);

    // Free allocated memory
    for (int i = 0; i < circuit.count; i++) {
        free(circuit.components[i]);
    }

    return 0;
}