//Gemma-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_CIRcuits 10

typedef struct Circuit
{
    char name[20];
    double resistance;
    double capacitance;
    double inductance;
    double voltage;
    double current;
    double power;
    struct Circuit* next;
} Circuit;

Circuit* createCircuit(char* name, double resistance, double capacitance, double inductance, double voltage)
{
    Circuit* newCircuit = malloc(sizeof(Circuit));
    strcpy(newCircuit->name, name);
    newCircuit->resistance = resistance;
    newCircuit->capacitance = capacitance;
    newCircuit->inductance = inductance;
    newCircuit->voltage = voltage;
    newCircuit->current = 0;
    newCircuit->power = 0;
    newCircuit->next = NULL;
    return newCircuit;
}

void simulateCircuit(Circuit* circuit)
{
    double time = 0;
    double timeStep = 0.01;
    double voltageSource = circuit->voltage;
    double currentSource = circuit->current;

    while (time < 10)
    {
        double voltageAcrossCapacitor = voltageSource * (1 - exp(-time / circuit->capacitance));
        double voltageAcrossInductance = voltageSource * exp(-time / circuit->inductance);
        double voltageAcrossResistor = voltageSource - voltageAcrossCapacitor - voltageAcrossInductance;

        circuit->current = voltageAcrossResistor / circuit->resistance;
        circuit->power = voltageAcrossResistor * circuit->current;

        time += timeStep;
    }
}

int main()
{
    Circuit* circuitList = NULL;

    // Create a few circuits
    Circuit* circuit1 = createCircuit("Circuit 1", 10, 2, 0, 12);
    Circuit* circuit2 = createCircuit("Circuit 2", 20, 4, 0, 16);
    Circuit* circuit3 = createCircuit("Circuit 3", 30, 6, 0, 20);

    // Simulate the circuits
    simulateCircuit(circuit1);
    simulateCircuit(circuit2);
    simulateCircuit(circuit3);

    // Print the results
    printf("Circuit 1:\n");
    printf("Current: %.2f A\n", circuit1->current);
    printf("Power: %.2f W\n", circuit1->power);

    printf("Circuit 2:\n");
    printf("Current: %.2f A\n", circuit2->current);
    printf("Power: %.2f W\n", circuit2->power);

    printf("Circuit 3:\n");
    printf("Current: %.2f A\n", circuit3->current);
    printf("Power: %.2f W\n", circuit3->power);

    return 0;
}