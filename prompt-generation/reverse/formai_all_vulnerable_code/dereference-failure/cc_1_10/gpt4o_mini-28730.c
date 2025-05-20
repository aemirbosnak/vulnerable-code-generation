//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    char name[10];
    float resistance; // in Ohms
} Resistor;

typedef struct {
    char name[10];
    float capacitance; // in Farads
} Capacitor;

typedef struct {
    char name[10];
    float inductance; // in Henrys
} Inductor;

typedef struct {
    Resistor *resistors;
    Capacitor *capacitors;
    Inductor *inductors;
    int r_count, c_count, l_count;
} Circuit;

void add_resistor(Circuit *circuit, const char *name, float resistance) {
    circuit->resistors = realloc(circuit->resistors, (circuit->r_count + 1) * sizeof(Resistor));
    if (!circuit->resistors) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strncpy(circuit->resistors[circuit->r_count].name, name, 10);
    circuit->resistors[circuit->r_count].resistance = resistance;
    circuit->r_count++;
}

void add_capacitor(Circuit *circuit, const char *name, float capacitance) {
    circuit->capacitors = realloc(circuit->capacitors, (circuit->c_count + 1) * sizeof(Capacitor));
    if (!circuit->capacitors) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strncpy(circuit->capacitors[circuit->c_count].name, name, 10);
    circuit->capacitors[circuit->c_count].capacitance = capacitance;
    circuit->c_count++;
}

void add_inductor(Circuit *circuit, const char *name, float inductance) {
    circuit->inductors = realloc(circuit->inductors, (circuit->l_count + 1) * sizeof(Inductor));
    if (!circuit->inductors) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strncpy(circuit->inductors[circuit->l_count].name, name, 10);
    circuit->inductors[circuit->l_count].inductance = inductance;
    circuit->l_count++;
}

void print_circuit_info(Circuit *circuit) {
    printf("Circuit Overview:\n");
    printf("Resistors:\n");
    for (int i = 0; i < circuit->r_count; i++) {
        printf("  %s: %.2f Ohms\n", circuit->resistors[i].name, circuit->resistors[i].resistance);
    }
    printf("Capacitors:\n");
    for (int i = 0; i < circuit->c_count; i++) {
        printf("  %s: %.2f F\n", circuit->capacitors[i].name, circuit->capacitors[i].capacitance);
    }
    printf("Inductors:\n");
    for (int i = 0; i < circuit->l_count; i++) {
        printf("  %s: %.2f H\n", circuit->inductors[i].name, circuit->inductors[i].inductance);
    }
}

float calculate_total_resistance(Circuit *circuit) {
    float total_resistance = 0.0;
    for (int i = 0; i < circuit->r_count; i++) {
        total_resistance += circuit->resistors[i].resistance;
    }
    return total_resistance;
}

float calculate_total_capacitance(Circuit *circuit) {
    float total_capacitance = 0.0;
    for (int i = 0; i < circuit->c_count; i++) {
        total_capacitance += circuit->capacitors[i].capacitance;
    }
    return total_capacitance;
}

float calculate_total_inductance(Circuit *circuit) {
    float total_inductance = 0.0;
    for (int i = 0; i < circuit->l_count; i++) {
        total_inductance += circuit->inductors[i].inductance;
    }
    return total_inductance;
}

void free_circuit(Circuit *circuit) {
    free(circuit->resistors);
    free(circuit->capacitors);
    free(circuit->inductors);
}

int main() {
    Circuit circuit = {NULL, NULL, NULL, 0, 0, 0};

    add_resistor(&circuit, "R1", 100.0);
    add_resistor(&circuit, "R2", 150.0);
    add_capacitor(&circuit, "C1", 0.001);
    add_capacitor(&circuit, "C2", 0.002);
    add_inductor(&circuit, "L1", 0.01);
    
    print_circuit_info(&circuit);

    printf("\nTotal Resistance: %.2f Ohms\n", calculate_total_resistance(&circuit));
    printf("Total Capacitance: %.3f F\n", calculate_total_capacitance(&circuit));
    printf("Total Inductance: %.3f H\n", calculate_total_inductance(&circuit));
    
    free_circuit(&circuit);
    
    return 0;
}