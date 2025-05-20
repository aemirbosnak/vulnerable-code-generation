//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>

typedef struct Resistor {
    float resistance;  // resistance in ohms
    struct Resistor* next; // pointer to the next resistor
} Resistor;

typedef struct VoltageSource {
    float voltage;  // voltage in volts
} VoltageSource;

typedef struct Circuit {
    Resistor* resistors;
    VoltageSource* source;
} Circuit;

// Function to create a resistor
Resistor* create_resistor(float resistance) {
    Resistor* new_resistor = (Resistor*)malloc(sizeof(Resistor));
    new_resistor->resistance = resistance;
    new_resistor->next = NULL;
    return new_resistor;
}

// Function to add a resistor to the circuit
void add_resistor(Circuit* circuit, float resistance) {
    Resistor* new_resistor = create_resistor(resistance);
    new_resistor->next = circuit->resistors;
    circuit->resistors = new_resistor;
}

// Function to set the voltage source
void set_voltage_source(Circuit* circuit, float voltage) {
    if (circuit->source == NULL) {
        circuit->source = (VoltageSource*)malloc(sizeof(VoltageSource));
    }
    circuit->source->voltage = voltage;
}

// Function to calculate total resistance in series
float calculate_total_resistance(Resistor* resistors) {
    float total_resistance = 0;
    while (resistors != NULL) {
        total_resistance += resistors->resistance;
        resistors = resistors->next;
    }
    return total_resistance;
}

// Function to calculate current based on Ohm's Law
float calculate_current(Circuit* circuit) {
    if (circuit->source == NULL) {
        printf("No voltage source set.\n");
        return 0;
    }
    float total_resistance = calculate_total_resistance(circuit->resistors);
    if (total_resistance == 0) {
        printf("Total resistance is zero. Infinite current!\n");
        return 0; // Infinite current case not handled
    }
    return circuit->source->voltage / total_resistance; 
}

// Function to display circuit information
void display_circuit(Circuit* circuit) {
    printf("Voltage Source: %.2f V\n", circuit->source->voltage);
    printf("Resistors:\n");
    Resistor* current = circuit->resistors;
    while (current != NULL) {
        printf(" - Resistance: %.2f Ohms\n", current->resistance);
        current = current->next;
    }
}

void free_circuit(Circuit* circuit) {
    Resistor* current = circuit->resistors;
    while (current != NULL) {
        Resistor* temp = current;
        current = current->next;
        free(temp);
    }
    free(circuit->source);
    free(circuit);
}

int main() {
    Circuit* circuit = (Circuit*)malloc(sizeof(Circuit));
    circuit->resistors = NULL;
    circuit->source = NULL;

    set_voltage_source(circuit, 9.0); // Set a voltage source of 9 volts
    add_resistor(circuit, 100.0); // Add a 100 Ohm resistor
    add_resistor(circuit, 200.0); // Add a 200 Ohm resistor
    add_resistor(circuit, 300.0); // Add a 300 Ohm resistor

    display_circuit(circuit);
    
    float current = calculate_current(circuit);
    printf("Total Current in Circuit: %.2f A\n", current);
    
    free_circuit(circuit);
    return 0;
}