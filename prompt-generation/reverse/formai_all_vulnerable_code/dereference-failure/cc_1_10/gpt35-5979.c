//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11 //The gravitational constant
#define NUM_PLANETS 3 //Number of planets in the simulation

void simulatePlanetGravity(double **coords, double **velocities, double *masses, int numPlanets, double timeStep, int numIterations) {
    double accel[numPlanets][3];
    int i, j, k;

    for(i = 0; i < numIterations; i++) {
        for(j = 0; j < numPlanets; j++) {
            accel[j][0] = 0.0;
            accel[j][1] = 0.0;
            accel[j][2] = 0.0;
            for(k = 0; k < numPlanets; k++) {
                if(j == k)
                continue;

                double distance = sqrt(pow(coords[k][0] - coords[j][0], 2) +
                pow(coords[k][1] - coords[j][1], 2) +
                pow(coords[k][2] - coords[j][2], 2));
                double force = G * masses[j] * masses[k] / pow(distance, 2);
                double vector[3] = {coords[k][0] - coords[j][0],
                coords[k][1] - coords[j][1],
                coords[k][2] - coords[j][2]};
                accel[j][0] += force * vector[0] / (masses[j] * distance);
                accel[j][1] += force * vector[1] / (masses[j] * distance);
                accel[j][2] += force * vector[2] / (masses[j] * distance);
            }
        }
        for(j = 0; j < numPlanets; j++) {
            coords[j][0] += velocities[j][0] * timeStep;
            coords[j][1] += velocities[j][1] * timeStep;
            coords[j][2] += velocities[j][2] * timeStep;
            velocities[j][0] += accel[j][0] * timeStep;
            velocities[j][1] += accel[j][1] * timeStep;
            velocities[j][2] += accel[j][2] * timeStep;
        }
    }
}

int main() {
    double **coords;
    double **velocities;
    double *masses;

    coords = malloc(NUM_PLANETS * sizeof(double *));
    for(int i = 0; i < NUM_PLANETS; i++)
        coords[i] = malloc(3 * sizeof(double));

    coords[0][0] = 0.0;
    coords[0][1] = 0.0;
    coords[0][2] = 0.0;
    coords[1][0] = 1.5e11;
    coords[1][1] = 0.0;
    coords[1][2] = 0.0;
    coords[2][0] = 0.0;
    coords[2][1] = 2.5e11;
    coords[2][2] = 0.0;

    velocities = malloc(NUM_PLANETS * sizeof(double *));
    for(int i = 0; i < NUM_PLANETS; i++)
        velocities[i] = malloc(3 * sizeof(double));

    velocities[0][0] = 0.0;
    velocities[0][1] = 0.0;
    velocities[0][2] = 0.0;
    velocities[1][0] = 0.0;
    velocities[1][1] = sqrt(G * 1.98e30 / 1.5e11);
    velocities[1][2] = 0.0;
    velocities[2][0] = sqrt(G * 1.98e30 / 2.5e11);
    velocities[2][1] = 0.0;
    velocities[2][2] = 0.0;

    masses = malloc(NUM_PLANETS * sizeof(double));
    masses[0] = 5.9742e24;
    masses[1] = 1.98e30;
    masses[2] = 3.285e23;

    simulatePlanetGravity(coords, velocities, masses, NUM_PLANETS, 3600.0, 8760);

    printf("Final coordinates and velocities for each planet:\n");
    for(int i = 0; i < NUM_PLANETS; i++)
        printf("Planet %d: (%e, %e, %e) (%e, %e, %e)\n", i, coords[i][0], coords[i][1], coords[i][2], velocities[i][0], velocities[i][1], velocities[i][2]);

    return 0;
}