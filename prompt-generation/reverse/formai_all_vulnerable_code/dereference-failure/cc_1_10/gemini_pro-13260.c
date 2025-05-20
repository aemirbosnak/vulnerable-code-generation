//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the mass and radius of the Earth
#define EARTH_MASS 5.972e24 // kg
#define EARTH_RADIUS 6.371e6 // m

// Define the gravitational constant
#define G 6.674e-11 // m^3 kg^-1 s^-2

// Define the time step for the simulation
#define DT 1 // s

// Define the number of particles in the simulation
#define N 100

// Define the particle data structure
typedef struct {
    double mass; // kg
    double radius; // m
    double x; // m
    double y; // m
    double z; // m
    double vx; // m/s
    double vy; // m/s
    double vz; // m/s
} Particle;

// Initialize the particle data
void initialize_particles(Particle *particles) {
    for (int i = 0; i < N; i++) {
        // Generate a random mass between 1 and 10 kg
        particles[i].mass = 1.0 + 9.0 * (double)rand() / (double)RAND_MAX;

        // Generate a random radius between 0.1 and 1.0 m
        particles[i].radius = 0.1 + 0.9 * (double)rand() / (double)RAND_MAX;

        // Generate a random position within a sphere of radius 1000 m around the origin
        double r = 1000.0 * (double)rand() / (double)RAND_MAX;
        double theta = 2.0 * M_PI * (double)rand() / (double)RAND_MAX;
        double phi = acos(2.0 * (double)rand() / (double)RAND_MAX - 1.0);
        particles[i].x = r * sin(theta) * cos(phi);
        particles[i].y = r * sin(theta) * sin(phi);
        particles[i].z = r * cos(theta);

        // Generate a random velocity between 0 and 10 m/s
        particles[i].vx = 10.0 * (double)rand() / (double)RAND_MAX;
        particles[i].vy = 10.0 * (double)rand() / (double)RAND_MAX;
        particles[i].vz = 10.0 * (double)rand() / (double)RAND_MAX;
    }
}

// Update the particle positions and velocities
void update_particles(Particle *particles) {
    for (int i = 0; i < N; i++) {
        // Calculate the gravitational force on the particle
        double fx = 0.0;
        double fy = 0.0;
        double fz = 0.0;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;

            double dx = particles[j].x - particles[i].x;
            double dy = particles[j].y - particles[i].y;
            double dz = particles[j].z - particles[i].z;
            double r = sqrt(dx * dx + dy * dy + dz * dz);

            double f = G * particles[i].mass * particles[j].mass / (r * r);

            fx += f * dx / r;
            fy += f * dy / r;
            fz += f * dz / r;
        }

        // Update the particle's velocity
        particles[i].vx += fx / particles[i].mass * DT;
        particles[i].vy += fy / particles[i].mass * DT;
        particles[i].vz += fz / particles[i].mass * DT;

        // Update the particle's position
        particles[i].x += particles[i].vx * DT;
        particles[i].y += particles[i].vy * DT;
        particles[i].z += particles[i].vz * DT;
    }
}

// Calculate the potential energy of the system
double calculate_potential_energy(Particle *particles) {
    double U = 0.0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            double dx = particles[j].x - particles[i].x;
            double dy = particles[j].y - particles[i].y;
            double dz = particles[j].z - particles[i].z;
            double r = sqrt(dx * dx + dy * dy + dz * dz);

            U += G * particles[i].mass * particles[j].mass / r;
        }
    }

    return U;
}

// Calculate the kinetic energy of the system
double calculate_kinetic_energy(Particle *particles) {
    double K = 0.0;
    for (int i = 0; i < N; i++) {
        K += 0.5 * particles[i].mass * (particles[i].vx * particles[i].vx + particles[i].vy * particles[i].vy + particles[i].vz * particles[i].vz);
    }

    return K;
}

// Main function
int main() {
    // Allocate memory for the particles
    Particle *particles = malloc(N * sizeof(Particle));

    // Initialize the particles
    initialize_particles(particles);

    // Open a file to write the data to
    FILE *fp = fopen("data.csv", "w");

    // Run the simulation for 1000 time steps
    for (int t = 0; t < 1000; t++) {
        // Update the particle positions and velocities
        update_particles(particles);

        // Calculate the potential and kinetic energies of the system
        double U = calculate_potential_energy(particles);
        double K = calculate_kinetic_energy(particles);

        // Write the data to the file
        fprintf(fp, "%d, %f, %f\n", t, U, K);
    }

    // Close the file
    fclose(fp);

    // Free the memory allocated for the particles
    free(particles);

    return 0;
}