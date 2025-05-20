//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structures for components
typedef struct {
    char name[20];
    double resistance;  // In Ohms
} Resistor;

typedef struct {
    char name[20];
    double capacitance; // In Farads
} Capacitor;

typedef struct {
    char name[20];
    double inductance;  // In Henrys
} Inductor;

typedef struct {
    Resistor *resistors;
    Capacitor *capacitors;
    Inductor *inductors;
    int resistor_count;
    int capacitor_count;
    int inductor_count;
} Circuit;

// Function prototypes
void add_resistor(Circuit *circuit, const char *name, double resistance);
void add_capacitor(Circuit *circuit, const char *name, double capacitance);
void add_inductor(Circuit *circuit, const char *name, double inductance);
void display_circuit(const Circuit *circuit);
double calculate_total_resistance(const Circuit *circuit);

// Main function
int main() {
    Circuit circuit;
    circuit.resistor_count = 0;
    circuit.capacitor_count = 0;
    circuit.inductor_count = 0;
    circuit.resistors = (Resistor *)malloc(10 * sizeof(Resistor));
    circuit.capacitors = (Capacitor *)malloc(10 * sizeof(Capacitor));
    circuit.inductors = (Inductor *)malloc(10 * sizeof(Inductor));

    // Adding components to the circuit
    add_resistor(&circuit, "R1", 100.0);
    add_resistor(&circuit, "R2", 150.0);
    add_capacitor(&circuit, "C1", 1.0e-6);
    add_inductor(&circuit, "L1", 0.01);

    // Display circuit details
    display_circuit(&circuit);

    // Calculate and display total resistance
    double total_resistance = calculate_total_resistance(&circuit);
    printf("Total Resistance of the circuit: %.2f Ohms\n", total_resistance);

    // Free allocated memory
    free(circuit.resistors);
    free(circuit.capacitors);
    free(circuit.inductors);

    return 0;
}

// Function to add a resistor to the circuit
void add_resistor(Circuit *circuit, const char *name, double resistance) {
    if (circuit->resistor_count < 10) {
        strcpy(circuit->resistors[circuit->resistor_count].name, name);
        circuit->resistors[circuit->resistor_count].resistance = resistance;
        circuit->resistor_count++;
    } else {
        printf("Error: Maximum resistors reached.\n");
    }
}

// Function to add a capacitor to the circuit
void add_capacitor(Circuit *circuit, const char *name, double capacitance) {
    if (circuit->capacitor_count < 10) {
        strcpy(circuit->capacitors[circuit->capacitor_count].name, name);
        circuit->capacitors[circuit->capacitor_count].capacitance = capacitance;
        circuit->capacitor_count++;
    } else {
        printf("Error: Maximum capacitors reached.\n");
    }
}

// Function to add an inductor to the circuit
void add_inductor(Circuit *circuit, const char *name, double inductance) {
    if (circuit->inductor_count < 10) {
        strcpy(circuit->inductors[circuit->inductor_count].name, name);
        circuit->inductors[circuit->inductor_count].inductance = inductance;
        circuit->inductor_count++;
    } else {
        printf("Error: Maximum inductors reached.\n");
    }
}

// Function to display circuit components
void display_circuit(const Circuit *circuit) {
    printf("Circuit Components:\n");
    for (int i = 0; i < circuit->resistor_count; i++) {
        printf("Resistor: %s, Resistance: %.2f Ohms\n", circuit->resistors[i].name, circuit->resistors[i].resistance);
    }
    for (int i = 0; i < circuit->capacitor_count; i++) {
        printf("Capacitor: %s, Capacitance: %.2e F\n", circuit->capacitors[i].name, circuit->capacitors[i].capacitance);
    }
    for (int i = 0; i < circuit->inductor_count; i++) {
        printf("Inductor: %s, Inductance: %.2f H\n", circuit->inductors[i].name, circuit->inductors[i].inductance);
    }
}

// Function to calculate total resistance in series
double calculate_total_resistance(const Circuit *circuit) {
    double total_resistance = 0.0;
    for (int i = 0; i < circuit->resistor_count; i++) {
        total_resistance += circuit->resistors[i].resistance;
    }
    return total_resistance;
}