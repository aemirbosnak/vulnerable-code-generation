//Gemma-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1024

int main()
{
    // Define circuit parameters
    double R1 = 1000;
    double R2 = 2000;
    double C1 = 100e-6;
    double Vcc = 12.0;

    // Allocate memory for circuit elements
    double *v = (double *)malloc(MAX);
    double *i = (double *)malloc(MAX);
    double *w = (double *)malloc(MAX);

    // Initialize circuit elements
    v[0] = 0.0;
    i[0] = 0.0;
    w[0] = 0.0;

    // Calculate time step
    double dt = 0.001;

    // Simulate circuit for 1000 steps
    for (int n = 0; n < 1000; n++)
    {
        // Calculate voltage across capacitor
        double Vc = Vcc * (1 - exp(-w[n] * dt / C1));

        // Calculate current through resistor R1
        double I1 = Vc / R1;

        // Calculate current through resistor R2
        double I2 = Vc / R2;

        // Update circuit elements
        v[n+1] = Vc;
        i[n+1] = I1 + I2;
        w[n+1] = w[n] + I1 * dt;
    }

    // Free memory
    free(v);
    free(i);
    free(w);

    return 0;
}