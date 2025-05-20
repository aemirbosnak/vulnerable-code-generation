//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11 // Gravitational constant

typedef struct {
    double x, y, z; // Position
    double vx, vy, vz; // Velocity
    double mass; // Mass
} Planet;

void calculate_acceleration(Planet *p1, Planet *p2, double *ax, double *ay, double *az) {
    double dx = p1->x - p2->x; // Distance between planets in the x direction
    double dy = p1->y - p2->y; // Distance between planets in the y direction
    double dz = p1->z - p2->z; // Distance between planets in the z direction
    double r = sqrt(dx * dx + dy * dy + dz * dz); // Distance between planets
    double f = G * p1->mass * p2->mass / (r * r); // Force due to gravitational attraction
    *ax = -f * dx / r / p1->mass; // Acceleration in the x direction
    *ay = -f * dy / r / p1->mass; // Acceleration in the y direction
    *az = -f * dz / r / p1->mass; // Acceleration in the z direction
}

int main() {
    int num_planets = 3; // Number of planets
    Planet *planets = malloc(num_planets * sizeof(Planet)); // Allocate memory for planets
    planets[0] = (Planet){0, 0, 0, 0, 0, 0, 5.97e24}; // Earth
    planets[1] = (Planet){1.496e11, 0, 0, 0, 2.98e4, 0, 1.99e30}; // Sun
    planets[2] = (Planet){1.496e11 + 384400e3, 0, 0, 0, 1.02e3 + 2.98e4, 0, 7.35e22}; // Moon
    double ax, ay, az; // Acceleration
    double dt = 3600; // Time step
    int steps = 365 * 24; // Number of time steps per year
    for (int i = 0; i < steps; i++) {
        for (int j = 0; j < num_planets; j++) {
            ax = ay = az = 0; // Reset acceleration
            for (int k = 0; k < num_planets; k++) {
                if (j == k) {
                    continue;
                }
                double ax_k, ay_k, az_k; // Acceleration due to planet k
                calculate_acceleration(&planets[j], &planets[k], &ax_k, &ay_k, &az_k);
                ax += ax_k;
                ay += ay_k;
                az += az_k;
            }
            planets[j].vx += ax * dt; // Update velocity in the x direction
            planets[j].vy += ay * dt; // Update velocity in the y direction
            planets[j].vz += az * dt; // Update velocity in the z direction
            planets[j].x += planets[j].vx * dt; // Update position in the x direction
            planets[j].y += planets[j].vy * dt; // Update position in the y direction
            planets[j].z += planets[j].vz * dt; // Update position in the z direction
        }
    }
    printf("Earth: %f %f %f\n", planets[0].x, planets[0].y, planets[0].z);
    printf("Sun: %f %f %f\n", planets[1].x, planets[1].y, planets[1].z);
    printf("Moon: %f %f %f\n", planets[2].x, planets[2].y, planets[2].z);
    free(planets); // Free memory
    return 0;
}