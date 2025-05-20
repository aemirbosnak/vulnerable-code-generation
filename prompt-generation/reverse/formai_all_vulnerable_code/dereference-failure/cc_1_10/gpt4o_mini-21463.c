//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_COMPONENTS 100

typedef enum { RESISTOR, CAPACITOR, INDUCTOR, VOLTAGE_SOURCE, CURRENT_SOURCE } ComponentType;

typedef struct {
    ComponentType type;
    char name[10];
    double value; // Resistance, Capacitance, Inductance, Voltage or Current values
    double voltage; // Voltage across the component
    double current; // Current through the component
} Component;

typedef struct {
    Component *components[MAX_COMPONENTS];
    int count;
} Circuit;

void add_component(Circuit *circuit, ComponentType type, const char *name, double value) {
    if (circuit->count >= MAX_COMPONENTS) {
        printf("Error: Maximum number of components reached.\n");
        return;
    }
    Component *comp = (Component *)malloc(sizeof(Component));
    comp->type = type;
    strncpy(comp->name, name, sizeof(comp->name) - 1);
    comp->value = value;
    comp->voltage = 0.0;
    comp->current = 0.0;
    circuit->components[circuit->count++] = comp;
}

void calculate_currents(Circuit *circuit) {
    double total_voltage = 0.0;
    double resistance = 0.0;

    for (int i = 0; i < circuit->count; i++) {
        Component *comp = circuit->components[i];
        if (comp->type == VOLTAGE_SOURCE) {
            total_voltage += comp->value;
        } else if (comp->type == RESISTOR) {
            resistance += comp->value;
        }
    }

    if (resistance > 0) {
        double current = total_voltage / resistance;
        for (int i = 0; i < circuit->count; i++) {
            Component *comp = circuit->components[i];
            if (comp->type == RESISTOR) {
                comp->current = current;
                comp->voltage = current * comp->value;
            }
        }
    }
}

void display_circuit(Circuit *circuit) {
    printf("Circuit Components:\n");
    for (int i = 0; i < circuit->count; i++) {
        Component *comp = circuit->components[i];
        const char *type_str;

        switch (comp->type) {
            case RESISTOR:      type_str = "Resistor"; break;
            case CAPACITOR:     type_str = "Capacitor"; break;
            case INDUCTOR:      type_str = "Inductor"; break;
            case VOLTAGE_SOURCE: type_str = "Voltage Source"; break;
            case CURRENT_SOURCE: type_str = "Current Source"; break;
            default:           type_str = "Unknown"; break; 
        }

        printf("%s (%s): Value = %.2f, Voltage = %.2f, Current = %.2f\n",
               type_str, comp->name, comp->value, comp->voltage, comp->current);
    }
}

void free_circuit(Circuit *circuit) {
    for (int i = 0; i < circuit->count; i++) {
        free(circuit->components[i]);
    }
}

int main() {
    Circuit myCircuit;
    myCircuit.count = 0;

    add_component(&myCircuit, RESISTOR, "R1", 100.0);
    add_component(&myCircuit, RESISTOR, "R2", 200.0);
    add_component(&myCircuit, VOLTAGE_SOURCE, "V1", 10.0);
    
    calculate_currents(&myCircuit);
    
    display_circuit(&myCircuit);
    
    free_circuit(&myCircuit);
    return 0;
}