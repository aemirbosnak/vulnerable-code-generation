//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#define MAX_COMPONENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_RESISTORS 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    double resistance; // in Ohms
} Resistor;

typedef struct {
    char name[MAX_NAME_LENGTH];
    double capacitance; // in Farads
} Capacitor;

typedef struct {
    char name[MAX_NAME_LENGTH];
    double inductance; // in Henrys
} Inductor;

typedef struct {
    Resistor resistors[MAX_RESISTORS];
    int resistor_count;
    Capacitor capacitors[MAX_RESISTORS];
    int capacitor_count;
    Inductor inductors[MAX_RESISTORS];
    int inductor_count;
} Circuit;

Circuit* create_circuit() {
    Circuit *circuit = (Circuit *)malloc(sizeof(Circuit));
    circuit->resistor_count = 0;
    circuit->capacitor_count = 0;
    circuit->inductor_count = 0;
    return circuit;
}

void add_resistor(Circuit *circuit, const char* name, double resistance) {
    if (circuit->resistor_count < MAX_RESISTORS) {
        strncpy(circuit->resistors[circuit->resistor_count].name, name, MAX_NAME_LENGTH);
        circuit->resistors[circuit->resistor_count].resistance = resistance;
        circuit->resistor_count++;
    } else {
        printf("Too many resistors! You must ensure the count stays healthy.\n");
    }
}

void add_capacitor(Circuit *circuit, const char* name, double capacitance) {
    if (circuit->capacitor_count < MAX_RESISTORS) {
        strncpy(circuit->capacitors[circuit->capacitor_count].name, name, MAX_NAME_LENGTH);
        circuit->capacitors[circuit->capacitor_count].capacitance = capacitance;
        circuit->capacitor_count++;
    } else {
        printf("Too many capacitors! Guard your elements carefully.\n");
    }
}

void add_inductor(Circuit *circuit, const char* name, double inductance) {
    if (circuit->inductor_count < MAX_RESISTORS) {
        strncpy(circuit->inductors[circuit->inductor_count].name, name, MAX_NAME_LENGTH);
        circuit->inductors[circuit->inductor_count].inductance = inductance;
        circuit->inductor_count++;
    } else {
        printf("Too many inductors! Keep your circuit in check.\n");
    }
}

double calculate_total_resistance(Circuit *circuit) {
    double total_resistance = 0.0;
    for (int i = 0; i < circuit->resistor_count; i++) {
        total_resistance += circuit->resistors[i].resistance;
    }
    return total_resistance;
}

void display_circuit(Circuit *circuit) {
    printf("Current Circuit Status:\n");
    for (int i = 0; i < circuit->resistor_count; i++) {
        printf("Resistor: %s, Resistance: %.2f Ohms\n", circuit->resistors[i].name, circuit->resistors[i].resistance);
    }
    for (int i = 0; i < circuit->capacitor_count; i++) {
        printf("Capacitor: %s, Capacitance: %.2f F\n", circuit->capacitors[i].name, circuit->capacitors[i].capacitance);
    }
    for (int i = 0; i < circuit->inductor_count; i++) {
        printf("Inductor: %s, Inductance: %.2f H\n", circuit->inductors[i].name, circuit->inductors[i].inductance);
    }
}

int main() {
    Circuit *my_circuit = create_circuit();
    
    add_resistor(my_circuit, "R1", 10.0);
    add_resistor(my_circuit, "R2", 20.0);
    add_capacitor(my_circuit, "C1", 0.001);
    add_inductor(my_circuit, "L1", 0.005);
    
    display_circuit(my_circuit);
    
    double total_resistance = calculate_total_resistance(my_circuit);
    printf("Total Resistance in Series: %.2f Ohms\n", total_resistance);
    
    // Handle paranoia with checks
    if (my_circuit->resistor_count < 1) {
        printf("Warning: Circuit is lonely; it needs more resistors!\n");
    }
    
    // Free the circuit memory to avoid memory leaks!
    free(my_circuit);
    
    return 0;
}