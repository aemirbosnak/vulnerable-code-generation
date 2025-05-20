//GEMINI-pro DATASET v1.0 Category: Simulation of the Solar System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the masses of the planets in Earth masses
#define SUN_MASS 332946
#define MERCURY_MASS 0.0553
#define VENUS_MASS 0.815
#define EARTH_MASS 1.0
#define MARS_MASS 0.107
#define JUPITER_MASS 317.8
#define SATURN_MASS 95.2
#define URANUS_MASS 14.5
#define NEPTUNE_MASS 17.1

// Define the gravitational constant
#define G 6.674e-11

// Define the time step
#define DT 3600

// Define the number of planets
#define NUM_PLANETS 9

// Define the initial positions and velocities of the planets
double positions[NUM_PLANETS][3] = {
    {0, 0, 0}, // Sun
    {57.9e6, 0, 0}, // Mercury
    {108.2e6, 0, 0}, // Venus
    {149.6e6, 0, 0}, // Earth
    {227.9e6, 0, 0}, // Mars
    {778.5e6, 0, 0}, // Jupiter
    {1433.5e6, 0, 0}, // Saturn
    {2872.5e6, 0, 0}, // Uranus
    {4495.1e6, 0, 0}  // Neptune
};

double velocities[NUM_PLANETS][3] = {
    {0, 0, 0}, // Sun
    {47.4e3, 0, 0}, // Mercury
    {35.0e3, 0, 0}, // Venus
    {30.0e3, 0, 0}, // Earth
    {24.1e3, 0, 0}, // Mars
    {13.1e3, 0, 0}, // Jupiter
    {9.6e3, 0, 0}, // Saturn
    {6.8e3, 0, 0}, // Uranus
    {5.4e3, 0, 0}  // Neptune
};

// Calculate the force on a planet due to all other planets
void calculate_force(double positions[][3], double forces[][3], int num_planets) {
    for (int i = 0; i < num_planets; i++) {
        for (int j = 0; j < num_planets; j++) {
            if (i == j) {
                continue;
            }

            // Calculate the distance between the two planets
            double dx = positions[i][0] - positions[j][0];
            double dy = positions[i][1] - positions[j][1];
            double dz = positions[i][2] - positions[j][2];
            double distance = sqrt(dx*dx + dy*dy + dz*dz);

            // Calculate the force between the two planets
            double force = G * positions[i][3] * positions[j][3] / (distance * distance);

            // Add the force to the forces array
            forces[i][0] += force * dx / distance;
            forces[i][1] += force * dy / distance;
            forces[i][2] += force * dz / distance;
        }
    }
}

// Update the positions and velocities of the planets
void update_positions_and_velocities(double positions[][3], double velocities[][3], double forces[][3], int num_planets, double dt) {
    for (int i = 0; i < num_planets; i++) {
        // Update the positions
        positions[i][0] += velocities[i][0] * dt;
        positions[i][1] += velocities[i][1] * dt;
        positions[i][2] += velocities[i][2] * dt;

        // Update the velocities
        velocities[i][0] += forces[i][0] * dt / positions[i][3];
        velocities[i][1] += forces[i][1] * dt / positions[i][3];
        velocities[i][2] += forces[i][2] * dt / positions[i][3];
    }
}

// Print the positions of the planets
void print_positions(double positions[][3], int num_planets) {
    for (int i = 0; i < num_planets; i++) {
        printf("Planet %d: (%f, %f, %f)\n", i, positions[i][0], positions[i][1], positions[i][2]);
    }
}

int main() {
    // Calculate the forces on each planet
    double forces[NUM_PLANETS][3];
    calculate_force(positions, forces, NUM_PLANETS);

    // Update the positions and velocities of the planets
    update_positions_and_velocities(positions, velocities, forces, NUM_PLANETS, DT);

    // Print the positions of the planets
    print_positions(positions, NUM_PLANETS);

    return 0;
}