//Gemma-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: high level of detail
#include <stdio.h>
#include <math.h>

// Define the circuit parameters
#define R1 10
#define R2 20
#define R3 30
#define C1 100

// Define the time constants
#define T 0.01

// Define the source voltage
#define Vs 12

// Define the output voltage
#define Vo 0

// Main function
int main()
{

    // Allocate memory for the simulation variables
    double *v = malloc(sizeof(double) * T);
    double *i = malloc(sizeof(double) * T);

    // Initialize the simulation variables
    for (int n = 0; n < T; n++)
    {
        v[n] = 0;
        i[n] = 0;
    }

    // Calculate the voltage across R1
    v[0] = Vs * R2 / (R1 + R2);

    // Calculate the current through R2
    i[0] = v[0] / R2;

    // Calculate the voltage across R3
    v[1] = v[0] * R3 / (R2 + R3);

    // Calculate the current through R3
    i[1] = v[1] / R3;

    // Print the results
    for (int n = 0; n < T; n++)
    {
        printf("Time: %.2f, Voltage: %.2f, Current: %.2f\n", T * n * T, v[n], i[n]);
    }

    // Free the memory
    free(v);
    free(i);

    return 0;
}