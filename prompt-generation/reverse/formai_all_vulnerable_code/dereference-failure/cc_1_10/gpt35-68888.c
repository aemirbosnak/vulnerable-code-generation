//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: retro
#include <stdio.h>
#include <math.h>

// Define constants
#define PI 3.14159265358979323846
#define RESISTOR 0
#define CAPACITOR 1
#define INDUCTOR 2

// Define structures
struct Element {
    int type;
    double value;
};

struct Circuit {
    int numElements;
    struct Element *elements;
};

// Function declarations
void simulateCircuit(struct Circuit circuit, double tStep, double duration);

// Main function
int main() {
    // Create circuit
    struct Circuit circuit;
    circuit.numElements = 4;
    circuit.elements = malloc(circuit.numElements * sizeof(struct Element));
    
    // Set element values
    circuit.elements[0].type = RESISTOR;
    circuit.elements[0].value = 1000;
    circuit.elements[1].type = CAPACITOR;
    circuit.elements[1].value = 1.5e-6;
    circuit.elements[2].type = RESISTOR;
    circuit.elements[2].value = 500;
    circuit.elements[3].type = INDUCTOR;
    circuit.elements[3].value = 25e-3;
    
    // Simulate circuit
    simulateCircuit(circuit, 1e-6, 0.05);
    
    // Free memory
    free(circuit.elements);
    
    return 0;
}

// Simulate circuit function
void simulateCircuit(struct Circuit circuit, double tStep, double duration) {
    // Calculate number of time steps to simulate
    int numSteps = (int) round(duration / tStep);
    
    // Initialize state variables
    double v1 = 5;
    double v2 = 0;
    double iL = 0;
    
    // Simulate circuit
    for (int i = 0; i < numSteps; i++) {
        // Calculate new voltages and currents
        double iR1 = v1 / circuit.elements[0].value;
        double iC2 = (v2 - v1) / circuit.elements[1].value;
        double iR2 = (v2 - 0) / circuit.elements[2].value;
        double vL = iL * circuit.elements[3].value;
        double iLp = (v2 - vL) / circuit.elements[3].value;
        double iLc = (iL + iLp) / 2;
        iL += tStep * iLc;
        v1 += tStep * (iR1 - iC2);
        v2 += tStep * (-iC2 - iR2 + iLp);
        
        // Print output
        printf("%.6f %.6f %.6f %.6f\n", i * tStep, v1, v2, iL);
    }
}