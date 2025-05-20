//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_COMPONENTS 100
#define MAX_NAME_LENGTH 30

typedef enum {
    RESISTOR,
    CAPACITOR,
    INDUCTOR,
    VOLTAGE_SOURCE,
    CURRENT_SOURCE,
    NONE
} ComponentType;

typedef struct {
    ComponentType type;
    char name[MAX_NAME_LENGTH];
    double value; // In Ohms, Farads, Henries, Volts or Amperes
} Component;

Component *circuit[MAX_COMPONENTS];
int component_count = 0;

void add_component(ComponentType type, const char *name, double value) {
    if (component_count >= MAX_COMPONENTS) {
        printf("Circuit is full! Cannot add more components.\n");
        return;
    }
    
    Component *comp = (Component *)malloc(sizeof(Component));
    comp->type = type;
    strncpy(comp->name, name, MAX_NAME_LENGTH);
    comp->value = value;

    circuit[component_count++] = comp;
    printf("Added component: %s of type %d with value %.2lf\n", name, type, value);
}

void display_circuit() {
    printf("=== Circuit Components ===\n");
    for (int i = 0; i < component_count; i++) {
        Component *comp = circuit[i];
        char *type_name;

        switch (comp->type) {
            case RESISTOR: type_name = "Resistor"; break;
            case CAPACITOR: type_name = "Capacitor"; break;
            case INDUCTOR: type_name = "Inductor"; break;
            case VOLTAGE_SOURCE: type_name = "Voltage Source"; break;
            case CURRENT_SOURCE: type_name = "Current Source"; break;
            default: type_name = "Unknown"; break;
        }

        printf("%d: %s (%s) - %.2lf\n", i + 1, comp->name, type_name, comp->value);
    }
    printf("==========================\n");
}

double calculate_total_resistance() {
    double total_resistance = 0.0;

    // Assuming all resistors are in series for simplicity
    for (int i = 0; i < component_count; i++) {
        if (circuit[i]->type == RESISTOR) {
            total_resistance += circuit[i]->value;
        }
    }
    
    return total_resistance;
}

void clean_up() {
    for (int i = 0; i < component_count; i++) {
        free(circuit[i]);
    }
}

int main() {
    printf("⚡ Welcome to the Shocking Circuit Simulator! ⚡\n");

    add_component(RESISTOR, "R1", 1000); // 1 kOhm
    add_component(CAPACITOR, "C1", 1e-6); // 1 µF
    add_component(INDUCTOR, "L1", 0.1); // 100 mH
    add_component(VOLTAGE_SOURCE, "V1", 5); // 5 V
    add_component(CURRENT_SOURCE, "I1", 0.01); // 10 mA

    display_circuit();

    double total_resistance = calculate_total_resistance();
    printf("Total Resistance in the circuit is: %.2lf Ohms\n", total_resistance);

    clean_up();
    
    printf("⚡ Simulation Complete! ⚡\n");
    
    return 0;
}