//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Define structures for components
typedef struct {
    char name[20];
    double resistance; // in ohms
} Resistor;

typedef struct {
    char name[20];
    double capacitance; // in farads
} Capacitor;

typedef struct {
    char name[20];
    double inductance; // in henrys
} Inductor;

typedef struct {
    Resistor *resistors;
    int num_resistors;
    Capacitor *capacitors;
    int num_capacitors;
    Inductor *inductors;
    int num_inductors;
} Circuit;

// Function prototypes
void add_resistor(Circuit *circuit, char *name, double resistance);
void add_capacitor(Circuit *circuit, char *name, double capacitance);
void add_inductor(Circuit *circuit, char *name, double inductance);
void display_circuit(Circuit *circuit);
void calculate_total_resistance(Circuit *circuit);
void free_circuit(Circuit *circuit);

int main() {
    Circuit circuit;
    circuit.num_resistors = 0;
    circuit.num_capacitors = 0;
    circuit.num_inductors = 0;

    // Memory allocation
    circuit.resistors = (Resistor *)malloc(10 * sizeof(Resistor));
    circuit.capacitors = (Capacitor *)malloc(10 * sizeof(Capacitor));
    circuit.inductors = (Inductor *)malloc(10 * sizeof(Inductor));

    // Adding components to the circuit
    add_resistor(&circuit, "R1", 100);
    add_resistor(&circuit, "R2", 150);
    add_capacitor(&circuit, "C1", 0.000001);
    add_inductor(&circuit, "L1", 0.01);

    // Displaying circuit information
    display_circuit(&circuit);
    
    // Calculating and displaying total resistance
    calculate_total_resistance(&circuit);

    // Free allocated memory
    free_circuit(&circuit);

    return 0;
}

// Function to add a resistor
void add_resistor(Circuit *circuit, char *name, double resistance) {
    Resistor *r = &circuit->resistors[circuit->num_resistors++];
    strncpy(r->name, name, sizeof(r->name));
    r->resistance = resistance;
}

// Function to add a capacitor
void add_capacitor(Circuit *circuit, char *name, double capacitance) {
    Capacitor *c = &circuit->capacitors[circuit->num_capacitors++];
    strncpy(c->name, name, sizeof(c->name));
    c->capacitance = capacitance;
}

// Function to add an inductor
void add_inductor(Circuit *circuit, char *name, double inductance) {
    Inductor *l = &circuit->inductors[circuit->num_inductors++];
    strncpy(l->name, name, sizeof(l->name));
    l->inductance = inductance;
}

// Function to display the current circuit
void display_circuit(Circuit *circuit) {
    printf("Circuit Components:\n");

    printf("Resistors:\n");
    for (int i = 0; i < circuit->num_resistors; i++) {
        printf("%s: %.2f ohms\n", circuit->resistors[i].name, circuit->resistors[i].resistance);
    }

    printf("Capacitors:\n");
    for (int i = 0; i < circuit->num_capacitors; i++) {
        printf("%s: %.2f farads\n", circuit->capacitors[i].name, circuit->capacitors[i].capacitance);
    }

    printf("Inductors:\n");
    for (int i = 0; i < circuit->num_inductors; i++) {
        printf("%s: %.2f henries\n", circuit->inductors[i].name, circuit->inductors[i].inductance);
    }
}

// Function to calculate total resistance (series)
void calculate_total_resistance(Circuit *circuit) {
    double total_resistance = 0;
    for (int i = 0; i < circuit->num_resistors; i++) {
        total_resistance += circuit->resistors[i].resistance;
    }
    printf("Total Resistance in Series: %.2f ohms\n", total_resistance);
}

// Function to free allocated memory
void free_circuit(Circuit *circuit) {
    free(circuit->resistors);
    free(circuit->capacitors);
    free(circuit->inductors);
}