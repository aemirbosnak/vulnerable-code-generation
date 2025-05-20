//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// Define the maximum number of planets in the simulation
#define MAX_PLANETS 100

// Define the gravitational constant
#define G 6.674e-11

// Define the time step for the simulation
#define DT 0.01

// Define the mass of the Earth for comparison
#define EARTH_MASS 5.972e24

// Define the radius of the Earth for comparison
#define EARTH_RADIUS 6.371e6

// Define the planet struct
typedef struct {
    double mass;             // Mass of the planet (kg)
    double radius;           // Radius of the planet (m)
    double x;                // X-coordinate of the planet's center (m)
    double y;                // Y-coordinate of the planet's center (m)
    double z;                // Z-coordinate of the planet's center (m)
    double vx;               // X-component of the planet's velocity (m/s)
    double vy;               // Y-component of the planet's velocity (m/s)
    double vz;               // Z-component of the planet's velocity (m/s)
} planet;

// Define the simulation struct
typedef struct {
    int num_planets;        // Number of planets in the simulation
    planet planets[MAX_PLANETS];  // Array of planets
} simulation;

// Create a new simulation
simulation* create_simulation(int num_planets) {
    simulation* sim = malloc(sizeof(simulation));
    sim->num_planets = num_planets;
    for (int i = 0; i < num_planets; i++) {
        sim->planets[i].mass = EARTH_MASS * (0.5 + (double)rand() / (double)RAND_MAX);
        sim->planets[i].radius = EARTH_RADIUS * (0.5 + (double)rand() / (double)RAND_MAX);
        sim->planets[i].x = (double)rand() / (double)RAND_MAX * 1e12;
        sim->planets[i].y = (double)rand() / (double)RAND_MAX * 1e12;
        sim->planets[i].z = (double)rand() / (double)RAND_MAX * 1e12;
        sim->planets[i].vx = 0.0;
        sim->planets[i].vy = 0.0;
        sim->planets[i].vz = 0.0;
    }
    return sim;
}

// Free the memory allocated for a simulation
void free_simulation(simulation* sim) {
    free(sim);
}

// Update the positions and velocities of the planets in the simulation
void update_simulation(simulation* sim) {
    for (int i = 0; i < sim->num_planets; i++) {
        // Calculate the acceleration of the planet due to gravity
        double ax = 0.0;
        double ay = 0.0;
        double az = 0.0;
        for (int j = 0; j < sim->num_planets; j++) {
            if (i != j) {
                double dx = sim->planets[j].x - sim->planets[i].x;
                double dy = sim->planets[j].y - sim->planets[i].y;
                double dz = sim->planets[j].z - sim->planets[i].z;
                double r = sqrt(dx * dx + dy * dy + dz * dz);
                double f = G * sim->planets[j].mass / (r * r);
                ax += f * dx / r;
                ay += f * dy / r;
                az += f * dz / r;
            }
        }

        // Update the velocity of the planet
        sim->planets[i].vx += ax * DT;
        sim->planets[i].vy += ay * DT;
        sim->planets[i].vz += az * DT;

        // Update the position of the planet
        sim->planets[i].x += sim->planets[i].vx * DT;
        sim->planets[i].y += sim->planets[i].vy * DT;
        sim->planets[i].z += sim->planets[i].vz * DT;
    }
}

// Run the simulation for a given number of time steps
void run_simulation(simulation* sim, int num_steps) {
    for (int i = 0; i < num_steps; i++) {
        update_simulation(sim);
    }
}

// Print the positions and velocities of the planets in the simulation
void print_simulation(simulation* sim) {
    for (int i = 0; i < sim->num_planets; i++) {
        printf("Planet %d:\n", i);
        printf("    Mass: %.2e kg\n", sim->planets[i].mass);
        printf("    Radius: %.2e m\n", sim->planets[i].radius);
        printf("    Position: (%.2e, %.2e, %.2e) m\n", sim->planets[i].x, sim->planets[i].y, sim->planets[i].z);
        printf("    Velocity: (%.2e, %.2e, %.2e) m/s\n", sim->planets[i].vx, sim->planets[i].vy, sim->planets[i].vz);
        printf("\n");
    }
}

// Main function
int main() {
    // Create a new simulation with 10 planets
    simulation* sim = create_simulation(10);

    // Run the simulation for 1000 time steps
    run_simulation(sim, 1000);

    // Print the positions and velocities of the planets in the simulation
    print_simulation(sim);

    // Free the memory allocated for the simulation
    free_simulation(sim);

    return 0;
}