//Gemma-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: active
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

Circuit* createCircuit(char* name, double resistance, double capacitance, double inductance, double voltage, double current)
{
    Circuit* newCircuit = (Circuit*)malloc(sizeof(Circuit));
    strcpy(newCircuit->name, name);
    newCircuit->resistance = resistance;
    newCircuit->capacitance = capacitance;
    newCircuit->inductance = inductance;
    newCircuit->voltage = voltage;
    newCircuit->current = current;
    newCircuit->next = NULL;

    return newCircuit;
}

void simulateCircuit(Circuit* circuit)
{
    double time = 0.0;
    double dt = 0.01;

    while (time < 10.0)
    {
        double voltage_across_capacitor = circuit->voltage * (1 - exp(-time / circuit->capacitance));
        double current_through_inductor = circuit->current * exp(-time / circuit->inductance);

        printf("%f, %f, %f\n", time, voltage_across_capacitor, current_through_inductor);

        time += dt;
    }
}

int main()
{
    Circuit* head = NULL;

    head = createCircuit("Series Circuit", 10.0, 100.0, 1.0, 12.0, 2.0);
    simulateCircuit(head);

    head = createCircuit("Parallel Circuit", 2.0, 20.0, 0.5, 12.0, 2.0);
    simulateCircuit(head);

    return 0;
}