//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Shape-shifting Circuit Simulator
// Simulates complex circuitry that can change shape over time

// Define circuit parameters
#define R1 1000.0
#define R2 2000.0
#define C1 1.0e-6
#define C2 2.0e-6
#define V1 5.0

// Define time and simulation parameters
#define T_START 0.0
#define T_END 0.01
#define T_STEP 1.0e-6

// Define function prototypes
double voltage(double t);
void simulate(double* output);

int main() {
    // Allocate memory for output data
    int num_samples = (int) ((T_END - T_START) / T_STEP) + 1;
    double* output = (double*) malloc(num_samples * sizeof(double));

    // Run simulation and print output
    simulate(output);
    printf("Time (s)\tVoltage (V)\n");
    for (int i = 0; i < num_samples; i++) {
        double t = T_START + i * T_STEP;
        printf("%0.10f\t%0.10f\n", t, output[i]);
    }

    // Free memory and exit
    free(output);
    return 0;
}

double voltage(double t) {
    // TODO: Implement voltage function that changes shape over time
    return V1 * sin(2 * M_PI * 1000.0 * t);
}

void simulate(double* output) {
    // Initialize circuit variables
    double v1 = V1;
    double v2 = 0.0;
    double vout = 0.0;
    double dt = T_STEP;

    // Iterate over time steps and simulate circuit
    for (int i = 0; i < (T_END - T_START) / T_STEP; i++) {
        double t = i * dt;
        double vin = voltage(t);

        // Calculate resistor currents
        double i1 = (v1 - vin) / R1;
        double i2 = (v2 - vin) / R2;

        // Calculate capacitor voltages and update circuit variables
        double dv1 = i1 * dt / C1;
        double dv2 = i2 * dt / C2;
        v1 -= dv1;
        v2 -= dv2;
        vout = v2;
        
        // Store output for current time step
        output[i] = vout;
    }
}