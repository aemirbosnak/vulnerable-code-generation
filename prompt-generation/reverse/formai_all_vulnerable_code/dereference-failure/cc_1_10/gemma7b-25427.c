//Gemma-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_CIRcuits 10
#define MAX_COMPONENTS 20

typedef struct Circuit
{
    char name[20];
    double resistance;
    double capacitance;
    double inductance;
    double voltage;
    double current;
    struct Circuit* next;
} Circuit;

Circuit* createCircuit(char* name, double resistance, double capacitance, double inductance, double voltage, double current)
{
    Circuit* circuit = (Circuit*)malloc(sizeof(Circuit));
    strcpy(circuit->name, name);
    circuit->resistance = resistance;
    circuit->capacitance = capacitance;
    circuit->inductance = inductance;
    circuit->voltage = voltage;
    circuit->current = current;
    circuit->next = NULL;

    return circuit;
}

void simulateCircuit(Circuit* circuit)
{
    double time = 0;
    double dt = 0.01;

    while (time < 1)
    {
        double voltage_across_capacitor = circuit->voltage * exp(-time / circuit->capacitance);
        double current_through_inductor = circuit->current * exp(-time / circuit->inductance);

        printf("Time: %.2lf, Voltage across capacitor: %.2lf, Current through inductor: %.2lf\n", time, voltage_across_capacitor, current_through_inductor);

        time += dt;
    }
}

int main()
{
    Circuit* circuit_list = NULL;

    // Create a few circuits
    Circuit* circuit1 = createCircuit("Circuit 1", 10, 2, 0, 10, 2);
    Circuit* circuit2 = createCircuit("Circuit 2", 20, 4, 0, 5, 1);
    Circuit* circuit3 = createCircuit("Circuit 3", 30, 6, 0, 7, 0);

    // Add circuits to the list
    circuit_list = circuit1;
    circuit_list->next = circuit2;
    circuit_list->next->next = circuit3;

    // Simulate each circuit
    for (Circuit* circuit = circuit_list; circuit; circuit = circuit->next)
    {
        simulateCircuit(circuit);
    }

    return 0;
}