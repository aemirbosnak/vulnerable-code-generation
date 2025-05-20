//Gemma-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: automated
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
    struct Circuit* next;
} Circuit;

Circuit* createCircuit(char* name, double resistance, double capacitance, double inductance, double voltage, double current)
{
    Circuit* circuit = malloc(sizeof(Circuit));

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
    double time = 0.0;
    double time_step = 0.01;

    while (time < 1.0)
    {
        double voltage_across_capacitor = circuit->voltage * exp(-time / circuit->capacitance);
        double current_through_inductor = circuit->voltage / circuit->inductance;

        printf("%f, %f, %f, %f, %f\n", time, voltage_across_capacitor, current_through_inductor, circuit->current, circuit->voltage);

        time += time_step;
    }
}

int main()
{
    Circuit* circuits[MAX_CIRcuits];

    // Create and simulate a circuit
    circuits[0] = createCircuit("Circuit 1", 10.0, 2.0, 0.5, 12.0, 0.2);
    simulateCircuit(circuits[0]);

    // Create and simulate another circuit
    circuits[1] = createCircuit("Circuit 2", 20.0, 4.0, 1.0, 16.0, 0.4);
    simulateCircuit(circuits[1]);

    return 0;
}