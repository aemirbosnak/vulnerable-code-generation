//FormAI DATASET v1.0 Category: Temperature monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Constants
#define N 1000
const double ALPHA = 0.1;
const double BETA = 0.01;

// Function prototypes
double getTemperature();
double calculateDerivative(double u[N], int n);
void eulerMethod(double dt, double u[N], int n);

int main() {
    // Initializing variables
    double u[N];
    u[0] = getTemperature();
    double dt = 0.1;
    int n = 0;

    // Simulation loop
    while (n < N) {
        // Calculate the derivative at the current temperature
        double derivative = calculateDerivative(u, n);
        
        // Use Euler's Method to find the temperature at the next time step
        eulerMethod(dt, u, n);
        u[n+1] = u[n] + derivative * dt;
        
        // Print the current temperature
        printf("Temperature at time %d is %.2f\n", n, u[n]);
        
        // Increase time step
        n++;
    }

    return 0;
}

/**
 * Simulates getting a temperature reading from some temperature monitoring device.
 *
 * @return the temperature read from the device.
 */
double getTemperature() {
    // Simulating a temperature reading between 20 and 30 degrees Celsius
    return 20 + ((double) rand() / RAND_MAX) * 10;
}

/**
 * Calculates the derivative at the current temperature.
 *
 * @param u the readings from previous time steps.
 * @param n the current time step.
 * @return the derivative at the current temperature.
 */
double calculateDerivative(double u[N], int n) {
    return -ALPHA * (u[n] - 25) - BETA * (u[n] - u[n-1]);
}

/**
 * Uses Euler's Method to update the temperature at the next time step.
 *
 * @param dt the time step.
 * @param u the readings from previous time steps.
 * @param n the current time step.
 */
void eulerMethod(double dt, double u[N], int n) {
    u[n+1] = u[n] + calculateDerivative(u, n) * dt;
}