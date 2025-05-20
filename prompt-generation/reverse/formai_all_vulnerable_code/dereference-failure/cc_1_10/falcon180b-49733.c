//Falcon-180B DATASET v1.0 Category: Physics simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Initialize variables
    double x, y, vx, vy, ax, ay, dt;
    int i;

    // Set initial conditions
    x = 0;
    y = 0;
    vx = 1;
    vy = 0;

    // Set time step
    dt = 0.01;

    // Allocate memory for arrays
    double *x_array = (double*) malloc(1000 * sizeof(double));
    double *y_array = (double*) malloc(1000 * sizeof(double));

    // Initialize arrays
    for (i = 0; i < 1000; i++) {
        x_array[i] = x;
        y_array[i] = y;
    }

    // Run simulation
    for (i = 0; i < 1000; i++) {
        // Update position
        x += vx * dt;
        y += vy * dt;

        // Update velocity
        ax = 0;
        ay = -9.81;
        vx += ax * dt;
        vy += ay * dt;

        // Store position in arrays
        x_array[i] = x;
        y_array[i] = y;
    }

    // Free memory
    free(x_array);
    free(y_array);

    return 0;
}