//Gemma-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

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

Circuit* circuit_create(char* name, double resistance, double capacitance, double inductance, double voltage, double current)
{
    Circuit* new_circuit = malloc(sizeof(Circuit));

    strcpy(new_circuit->name, name);
    new_circuit->resistance = resistance;
    new_circuit->capacitance = capacitance;
    new_circuit->inductance = inductance;
    new_circuit->voltage = voltage;
    new_circuit->current = current;
    new_circuit->next = NULL;

    return new_circuit;
}

void circuit_simulate(Circuit* circuit)
{
    double time = 0.0;
    double time_step = 0.01;

    while (time < 10.0)
    {
        // Calculate voltage across circuit
        double voltage = circuit->voltage * (1 - exp(-time/circuit->capacitance));

        // Calculate current flowing through circuit
        double current = voltage / circuit->resistance;

        // Update circuit values
        circuit->voltage = voltage;
        circuit->current = current;

        // Increment time
        time += time_step;
    }
}

int main()
{
    Circuit* circuits[MAX_CIRcuits] = { NULL };

    // Create a few circuits
    circuits[0] = circuit_create("Series Circuit", 10.0, 100.0, 0.1, 12.0, 0.0);
    circuits[1] = circuit_create("Parallel Circuit", 2.0, 200.0, 0.2, 12.0, 0.0);

    // Simulate each circuit
    for (int i = 0; i < MAX_CIRcuits; i++)
    {
        if (circuits[i] != NULL)
        {
            circuit_simulate(circuits[i]);
        }
    }

    // Print circuit values
    for (int i = 0; i < MAX_CIRcuits; i++)
    {
        if (circuits[i] != NULL)
        {
            printf("Circuit: %s\n", circuits[i]->name);
            printf("Voltage: %.2f V\n", circuits[i]->voltage);
            printf("Current: %.2f A\n", circuits[i]->current);
            printf("\n");
        }
    }

    return 0;
}