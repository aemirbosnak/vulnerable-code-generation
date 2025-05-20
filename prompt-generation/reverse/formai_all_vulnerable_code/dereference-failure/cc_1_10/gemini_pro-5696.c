//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the gravitational constant
const double G = 6.674e-11; // m^3 kg^-1 s^-2

// Define the mass of the Earth
const double EarthMass = 5.972e24; // kg

// Define the radius of the Earth
const double EarthRadius = 6.371e6; // m

// Define the time step
const double dt = 1.0; // s

// Define the number of particles you are interested to have
int n;

// Define the structure of a particle
typedef struct {
    double x; // m
    double y; // m
    double z; // m
    double vx; // m/s
    double vy; // m/s
    double vz; // m/s
    double m; // kg
} Particle;

// Define an array of particles
Particle *particles;

void calculateForces() {
    // Reset the forces on all particles
    for (int i = 0; i < n; i++) {
        particles[i].vx = 0.0;
        particles[i].vy = 0.0;
        particles[i].vz = 0.0;
    }

    // Calculate the forces between all particles
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Calculate the distance between the particles
            double dx = particles[i].x - particles[j].x;
            double dy = particles[i].y - particles[j].y;
            double dz = particles[i].z - particles[j].z;
            double r = sqrt(dx * dx + dy * dy + dz * dz);

            // Calculate the force between the particles
            double f = G * particles[i].m * particles[j].m / (r * r);

            // Calculate the unit vector between the particles
            double ux = dx / r;
            double uy = dy / r;
            double uz = dz / r;

            // Apply the force to the particles
            particles[i].vx += f * ux / particles[i].m;
            particles[i].vy += f * uy / particles[i].m;
            particles[i].vz += f * uz / particles[i].m;
            particles[j].vx -= f * ux / particles[j].m;
            particles[j].vy -= f * uy / particles[j].m;
            particles[j].vz -= f * uz / particles[j].m;
        }
    }
}

void updatePositions() {
    // Update the positions of all particles
    for (int i = 0; i < n; i++) {
        particles[i].x += particles[i].vx * dt;
        particles[i].y += particles[i].vy * dt;
        particles[i].z += particles[i].vz * dt;
    }
}

void printPositions() {
    // Print the positions of all particles
    for (int i = 0; i < n; i++) {
        printf("%f %f %f\n", particles[i].x, particles[i].y, particles[i].z);
    }
}

int main() {
    // Get the number of particles from the user
    printf("Enter the number of particles: ");
    scanf("%d", &n);

    // Allocate memory for the particles
    particles = malloc(n * sizeof(Particle));

    // Initialize the particles
    for (int i = 0; i < n; i++) {
        particles[i].x = 0.0; // m
        particles[i].y = 0.0; // m
        particles[i].z = 0.0; // m
        particles[i].vx = 0.0; // m/s
        particles[i].vy = 0.0; // m/s
        particles[i].vz = 0.0; // m/s
        particles[i].m = 1.0; // kg
    }

    // Calculate the forces on the particles
    calculateForces();

    // Update the positions of the particles
    updatePositions();

    // Print the positions of the particles
    printPositions();

    return 0;
}