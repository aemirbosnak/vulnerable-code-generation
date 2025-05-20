//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

typedef struct Resistor {
    double resistance;
    struct Resistor *next;
} Resistor;

typedef struct Capacitor {
    double capacitance;
    struct Capacitor *next;
} Capacitor;

typedef struct Circuit {
    Resistor *resistors;
    Capacitor *capacitors;
    double voltage;
} Circuit;

Circuit* create_circuit(double voltage) {
    Circuit *circuit = (Circuit *)malloc(sizeof(Circuit));
    circuit->resistors = NULL;
    circuit->capacitors = NULL;
    circuit->voltage = voltage;
    return circuit;
}

void add_resistor(Circuit *circuit, double resistance) {
    Resistor *new_resistor = (Resistor *)malloc(sizeof(Resistor));
    new_resistor->resistance = resistance;
    new_resistor->next = circuit->resistors;
    circuit->resistors = new_resistor;
}

void add_capacitor(Circuit *circuit, double capacitance) {
    Capacitor *new_capacitor = (Capacitor *)malloc(sizeof(Capacitor));
    new_capacitor->capacitance = capacitance;
    new_capacitor->next = circuit->capacitors;
    circuit->capacitors = new_capacitor;
}

double calculate_total_resistance(Circuit *circuit) {
    double total_resistance = 0;
    Resistor *current = circuit->resistors;
    while(current != NULL) {
        total_resistance += current->resistance;
        current = current->next;
    }
    return total_resistance;
}

double calculate_total_capacitance(Circuit *circuit) {
    double total_capacitance = 0;
    Capacitor *current = circuit->capacitors;
    while(current != NULL) {
        total_capacitance += current->capacitance;
        current = current->next;
    }
    return total_capacitance;
}

void simulate(Circuit *circuit) {
    double total_resistance = calculate_total_resistance(circuit);
    double current = circuit->voltage / total_resistance;

    printf("Circuit Simulation:\n");
    printf("Total Resistance: %.2f Ohms\n", total_resistance);
    printf("Simulated Current: %.2f Amps\n", current);
    
    double total_capacitance = calculate_total_capacitance(circuit);
    printf("Total Capacitance: %.2f Farads\n", total_capacitance);
    
    if(total_capacitance > 0) {
        double time_constant = total_resistance * total_capacitance;
        printf("Time Constant (τ): %.2f seconds\n", time_constant);
    }
}

void free_circuit(Circuit *circuit) {
    Resistor *current_resistor = circuit->resistors;
    while(current_resistor != NULL) {
        Resistor *to_free = current_resistor;
        current_resistor = current_resistor->next;
        free(to_free);
    }
    
    Capacitor *current_capacitor = circuit->capacitors;
    while(current_capacitor != NULL) {
        Capacitor *to_free = current_capacitor;
        current_capacitor = current_capacitor->next;
        free(to_free);
    }
    
    free(circuit);
}

int main() {
    Circuit *myCircuit = create_circuit(10.0); // Creating a circuit with 10V supply
    add_resistor(myCircuit, 5.0); // Adding a 5 Ohm resistor
    add_resistor(myCircuit, 10.0); // Adding a 10 Ohm resistor
    add_capacitor(myCircuit, 0.001); // Adding 1 mF capacitor

    simulate(myCircuit); // Simulating the circuit

    free_circuit(myCircuit); // Free the allocated memory
    return 0;
}