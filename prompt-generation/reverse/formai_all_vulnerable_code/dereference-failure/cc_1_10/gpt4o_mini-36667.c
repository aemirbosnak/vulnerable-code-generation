//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double voltage; // Voltage in volts
    double resistance; // Resistance in ohms
} Resistor;

typedef struct {
    Resistor *resistors;
    int count;
} Circuit;

// Function to calculate the total resistance in series
double calculate_series_resistance(Circuit *circuit) {
    double total_resistance = 0;

    for (int i = 0; i < circuit->count; i++) {
        total_resistance += circuit->resistors[i].resistance;
    }

    return total_resistance;
}

// Function to calculate the total resistance in parallel
double calculate_parallel_resistance(Circuit *circuit) {
    double total_inverse = 0;

    for (int i = 0; i < circuit->count; i++) {
        total_inverse += 1.0 / circuit->resistors[i].resistance;
    }

    return 1.0 / total_inverse;
}

// Function to calculate current for the series circuit using Ohm's law
double calculate_series_current(Circuit *circuit) {
    double total_resistance = calculate_series_resistance(circuit);
    return circuit->resistors[0].voltage / total_resistance; // Assuming voltage is same across first resistor
}

// Function to calculate current for the parallel circuit
double calculate_parallel_current(Circuit *circuit) {
    double total_resistance = calculate_parallel_resistance(circuit);
    double total_current = 0;

    for (int i = 0; i < circuit->count; i++) {
        total_current += circuit->resistors[i].voltage / circuit->resistors[i].resistance;
    }

    return total_current;
}

// Function to create a Circuit
Circuit create_circuit(int count) {
    Circuit circuit;
    circuit.count = count;
    circuit.resistors = (Resistor *)malloc(count * sizeof(Resistor));

    return circuit;
}

// Function to input resistor values
void input_resistor_values(Circuit *circuit) {
    for (int i = 0; i < circuit->count; i++) {
        printf("Enter voltage (V) and resistance (Ohms) for resistor %d: ", i + 1);
        scanf("%lf %lf", &circuit->resistors[i].voltage, &circuit->resistors[i].resistance);
    }
}

// Function to calculate and display circuit analysis results
void analyze_circuit(Circuit *circuit) {
    double series_resistance = calculate_series_resistance(circuit);
    double parallel_resistance = calculate_parallel_resistance(circuit);
    double series_current = calculate_series_current(circuit);
    double parallel_current = calculate_parallel_current(circuit);

    printf("\nCircuit Analysis Results:\n");
    printf("Total Series Resistance: %.2f Ohms\n", series_resistance);
    printf("Total Parallel Resistance: %.2f Ohms\n", parallel_resistance);
    printf("Total Series Current: %.2f A\n", series_current);
    printf("Total Parallel Current: %.2f A\n", parallel_current);
}

// Function to free allocated memory
void free_circuit(Circuit *circuit) {
    free(circuit->resistors);
}

int main() {
    int count;

    printf("Enter the number of resistors in your circuit: ");
    scanf("%d", &count);

    Circuit circuit = create_circuit(count);
    input_resistor_values(&circuit);
    analyze_circuit(&circuit);
    free_circuit(&circuit);

    return 0;
}