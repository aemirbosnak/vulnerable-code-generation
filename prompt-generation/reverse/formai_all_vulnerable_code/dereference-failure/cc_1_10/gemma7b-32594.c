//Gemma-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_CIRcuits 10

typedef struct Circuit {
    char name[20];
    double resistance, capacitance, inductance;
    double voltage, current;
    struct Circuit* next;
} Circuit;

Circuit* createCircuit(char* name, double resistance, double capacitance, double inductance) {
    Circuit* newCircuit = malloc(sizeof(Circuit));
    strcpy(newCircuit->name, name);
    newCircuit->resistance = resistance;
    newCircuit->capacitance = capacitance;
    newCircuit->inductance = inductance;
    newCircuit->voltage = 0.0;
    newCircuit->current = 0.0;
    newCircuit->next = NULL;
    return newCircuit;
}

void simulateCircuit(Circuit* circuit) {
    double time = 0.0;
    double timeStep = 0.01;
    double voltageSource = 12.0;

    while (time < 10.0) {
        double voltage = voltageSource * sin(2 * M_PI * 50 * time);
        circuit->voltage = voltage;

        double current = voltage / circuit->resistance;
        circuit->current = current;

        time += timeStep;
    }

    printf("Circuit name: %s\n", circuit->name);
    printf("Voltage: %.2f V\n", circuit->voltage);
    printf("Current: %.2f A\n", circuit->current);
}

int main() {
    Circuit* head = NULL;
    Circuit* currentCircuit = NULL;

    // Create a few circuits
    Circuit* circuit1 = createCircuit("Circuit 1", 10.0, 2.0, 0.5);
    Circuit* circuit2 = createCircuit("Circuit 2", 20.0, 4.0, 1.0);

    // Link the circuits together
    currentCircuit = circuit1;
    currentCircuit->next = circuit2;

    // Simulate the circuits
    simulateCircuit(currentCircuit);

    return 0;
}