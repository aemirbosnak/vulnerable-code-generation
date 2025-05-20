//Gemma-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define circuit parameters
#define R1 5
#define R2 2
#define R3 3
#define C1 100
#define V1 10

// Define time constants
#define T 0.01
#define T_MAX 1

// Define circuit elements
int main()
{
    // Allocate memory for circuit variables
    double *v = (double *)malloc(T_MAX * sizeof(double));
    double *i = (double *)malloc(T_MAX * sizeof(double));

    // Initialize circuit variables
    for (int n = 0; n < T_MAX; n++)
    {
        v[n] = 0.0;
        i[n] = 0.0;
    }

    // Apply voltage source
    v[0] = V1;

    // Calculate circuit currents and voltages
    for (int n = 0; n < T_MAX; n++)
    {
        i[n] = v[n] / (R1 + R2 + R3);
        v[n+1] = v[n] - i[n] * R2;
    }

    // Print results
    for (int n = 0; n < T_MAX; n++)
    {
        printf("Time: %.3lf, Voltage: %.2lf, Current: %.2lf\n", T * n, v[n], i[n]);
    }

    // Free memory
    free(v);
    free(i);

    return 0;
}