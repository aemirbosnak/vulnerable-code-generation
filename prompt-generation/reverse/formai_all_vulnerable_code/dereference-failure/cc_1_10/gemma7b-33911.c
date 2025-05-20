//Gemma-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359

typedef struct Circuit
{
    double R;
    double L;
    double C;
    double V;
    double I;
    struct Circuit* next;
} Circuit;

Circuit* circuit_create(double R, double L, double C, double V)
{
    Circuit* new_circuit = malloc(sizeof(Circuit));
    new_circuit->R = R;
    new_circuit->L = L;
    new_circuit->C = C;
    new_circuit->V = V;
    new_circuit->I = 0;
    new_circuit->next = NULL;
    return new_circuit;
}

void circuit_simulate(Circuit* circuit)
{
    double time = 0;
    double dt = 0.01;
    double V_source = circuit->V;
    double I_source = V_source / circuit->R;
    circuit->I = I_source;

    while (time < 1)
    {
        double voltage = V_source * sin(2 * PI * 50 * time);
        double current = circuit->I * voltage / circuit->R;

        printf("Time: %.2f, Voltage: %.2f, Current: %.2f\n", time, voltage, current);

        time += dt;
    }
}

int main()
{
    Circuit* circuit = circuit_create(10, 1, 0.1, 220);
    circuit_simulate(circuit);

    return 0;
}