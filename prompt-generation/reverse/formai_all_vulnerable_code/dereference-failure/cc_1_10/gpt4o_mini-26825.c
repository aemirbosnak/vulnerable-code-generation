//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_COMPONENTS 100

typedef enum {
    RESISTOR,
    CAPACITOR,
    INDUCTOR,
    SOURCE
} ComponentType;

typedef struct {
    char name[20];
    ComponentType type;
    double value; // Ohms for resistors, Farads for capacitors, Henrys for inductors, Volts for sources
} Component;

typedef struct {
    Component *components[MAX_COMPONENTS];
    int count;
} Circuit;

void add_component(Circuit *circuit, const char *name, ComponentType type, double value) {
    if (circuit->count >= MAX_COMPONENTS) {
        printf("Circuit is full! Cannot add more components.\n");
        return;
    }
    Component *new_component = (Component *)malloc(sizeof(Component));
    strcpy(new_component->name, name);
    new_component->type = type;
    new_component->value = value;
    circuit->components[circuit->count++] = new_component;
}

void print_circuit(Circuit *circuit) {
    printf("Circuit contains %d components:\n", circuit->count);
    for (int i = 0; i < circuit->count; i++) {
        printf("Component %d: Name: %s, Type: %d, Value: %.2f\n", i + 1,
               circuit->components[i]->name, circuit->components[i]->type,
               circuit->components[i]->value);
    }
}

double calculate_total_resistance(Circuit *circuit) {
    double total_resistance = 0.0;
    for (int i = 0; i < circuit->count; i++) {
        if (circuit->components[i]->type == RESISTOR) {
            total_resistance += circuit->components[i]->value; // Series resistance
        }
    }
    return total_resistance;
}

double calculate_total_capacitance(Circuit *circuit) {
    double total_capacitance = 0.0;
    for (int i = 0; i < circuit->count; i++) {
        if (circuit->components[i]->type == CAPACITOR) {
            total_capacitance += circuit->components[i]->value; // Series capacitance
        }
    }
    return total_capacitance;
}

double calculate_total_inductance(Circuit *circuit) {
    double total_inductance = 0.0;
    for (int i = 0; i < circuit->count; i++) {
        if (circuit->components[i]->type == INDUCTOR) {
            total_inductance += circuit->components[i]->value; // Series inductance
        }
    }
    return total_inductance;
}

void free_circuit(Circuit *circuit) {
    for (int i = 0; i < circuit->count; i++) {
        free(circuit->components[i]);
    }
}

int main() {
    Circuit my_circuit;
    my_circuit.count = 0;

    printf("Welcome to the Circuit Simulator!\n");

    add_component(&my_circuit, "R1", RESISTOR, 100.0);
    add_component(&my_circuit, "C1", CAPACITOR, 0.00001);
    add_component(&my_circuit, "L1", INDUCTOR, 0.5);
    add_component(&my_circuit, "V1", SOURCE, 10.0);

    print_circuit(&my_circuit);

    double total_resistance = calculate_total_resistance(&my_circuit);
    double total_capacitance = calculate_total_capacitance(&my_circuit);
    double total_inductance = calculate_total_inductance(&my_circuit);

    printf("Total Resistance: %.2f Ohms\n", total_resistance);
    printf("Total Capacitance: %.2e Farads\n", total_capacitance);
    printf("Total Inductance: %.2f Henrys\n", total_inductance);

    free_circuit(&my_circuit);
    printf("Exiting the simulator. Thank you!\n");

    return 0;
}