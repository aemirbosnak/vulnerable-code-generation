//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_COMPONENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    double value; // resistance or capacitance
} Resistor;

typedef struct {
    char name[MAX_NAME_LENGTH];
    double value; // voltage or current
} VoltageSource;

typedef struct {
    char name[MAX_NAME_LENGTH];
    Resistor* resistors[MAX_COMPONENTS];
    int resistor_count;
    VoltageSource* voltage_sources[MAX_COMPONENTS];
    int voltage_source_count;
} Circuit;

void add_resistor(Circuit* circuit, const char* name, double value) {
    Resistor* r = malloc(sizeof(Resistor));
    strcpy(r->name, name);
    r->value = value;
    circuit->resistors[circuit->resistor_count++] = r;
}

void add_voltage_source(Circuit* circuit, const char* name, double value) {
    VoltageSource* v = malloc(sizeof(VoltageSource));
    strcpy(v->name, name);
    v->value = value;
    circuit->voltage_sources[circuit->voltage_source_count++] = v;
}

void display_circuit(Circuit* circuit) {
    printf("Circuit Components:\n");
    for (int i = 0; i < circuit->resistor_count; i++) {
        printf("Resistor %s: %.2f Ohm\n", circuit->resistors[i]->name, circuit->resistors[i]->value);
    }

    for (int j = 0; j < circuit->voltage_source_count; j++) {
        printf("Voltage Source %s: %.2f V\n", circuit->voltage_sources[j]->name, circuit->voltage_sources[j]->value);
    }
}

double calculate_total_resistance(Circuit* circuit) {
    double total_resistance = 0.0;
    for (int i = 0; i < circuit->resistor_count; i++) {
        total_resistance += circuit->resistors[i]->value; // Series resistance
    }
    return total_resistance;
}

double calculate_total_voltage(Circuit* circuit) {
    double total_voltage = 0.0;
    for (int j = 0; j < circuit->voltage_source_count; j++) {
        total_voltage += circuit->voltage_sources[j]->value; // Aggregate voltage
    }
    return total_voltage;
}

double calculate_current(Circuit* circuit) {
    double total_resistance = calculate_total_resistance(circuit);
    double total_voltage = calculate_total_voltage(circuit);

    return (total_resistance > 0) ? (total_voltage / total_resistance) : 0;
}

void free_circuit(Circuit* circuit) {
    for (int i = 0; i < circuit->resistor_count; i++) {
        free(circuit->resistors[i]);
    }
    for (int j = 0; j < circuit->voltage_source_count; j++) {
        free(circuit->voltage_sources[j]);
    }
}

int main() {
    Circuit my_circuit;
    my_circuit.resistor_count = 0;
    my_circuit.voltage_source_count = 0;

    add_resistor(&my_circuit, "R1", 100);
    add_resistor(&my_circuit, "R2", 200);
    add_voltage_source(&my_circuit, "V1", 12);
    add_voltage_source(&my_circuit, "V2", 5);

    display_circuit(&my_circuit);

    double total_resistance = calculate_total_resistance(&my_circuit);
    double total_voltage = calculate_total_voltage(&my_circuit);
    double current = calculate_current(&my_circuit);

    printf("\nTotal Resistance: %.2f Ohm\n", total_resistance);
    printf("Total Voltage: %.2f V\n", total_voltage);
    printf("Current flowing through the circuit: %.2f A\n", current);

    free_circuit(&my_circuit);

    return 0;
}