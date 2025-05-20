//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the gravitational constant
#define G 6.67408e-11 // m^3 kg^-1 s^-2

// Define the mass of the Earth
#define EARTH_MASS 5.972e24 // kg

// Define the radius of the Earth
#define EARTH_RADIUS 6.371e6 // m

// Define the time step
#define DT 1.0 // s

// Define the number of particles
#define N 100

// Define the particle structure
typedef struct particle {
  double m; // kg
  double x; // m
  double y; // m
  double z; // m
  double vx; // m/s
  double vy; // m/s
  double vz; // m/s
} particle;

// Initialize the particles
void initialize_particles(particle *p, int n) {
  for (int i = 0; i < n; i++) {
    // Set the mass of the particle
    p[i].m = 1.0; // kg

    // Set the initial position of the particle
    p[i].x = (double)rand() / (double)RAND_MAX * EARTH_RADIUS; // m
    p[i].y = (double)rand() / (double)RAND_MAX * EARTH_RADIUS; // m
    p[i].z = (double)rand() / (double)RAND_MAX * EARTH_RADIUS; // m

    // Set the initial velocity of the particle
    p[i].vx = 0.0; // m/s
    p[i].vy = 0.0; // m/s
    p[i].vz = 0.0; // m/s
  }
}

// Update the positions of the particles
void update_positions(particle *p, int n) {
  for (int i = 0; i < n; i++) {
    // Update the position of the particle
    p[i].x += p[i].vx * DT; // m
    p[i].y += p[i].vy * DT; // m
    p[i].z += p[i].vz * DT; // m
  }
}

// Update the velocities of the particles
void update_velocities(particle *p, int n) {
  for (int i = 0; i < n; i++) {
    // Update the velocity of the particle
    for (int j = 0; j < n; j++) {
      if (i != j) {
        // Calculate the distance between the two particles
        double dx = p[i].x - p[j].x; // m
        double dy = p[i].y - p[j].y; // m
        double dz = p[i].z - p[j].z; // m
        double r = sqrt(dx * dx + dy * dy + dz * dz); // m

        // Calculate the force between the two particles
        double f = G * p[i].m * p[j].m / (r * r); // N

        // Calculate the acceleration of the particle
        double ax = f * dx / r; // m/s^2
        double ay = f * dy / r; // m/s^2
        double az = f * dz / r; // m/s^2

        // Update the velocity of the particle
        p[i].vx += ax * DT; // m/s
        p[i].vy += ay * DT; // m/s
        p[i].vz += az * DT; // m/s
      }
    }
  }
}

// Main function
int main() {
  // Allocate memory for the particles
  particle *p = (particle *)malloc(N * sizeof(particle));

  // Initialize the particles
  initialize_particles(p, N);

  // Update the positions and velocities of the particles
  for (int i = 0; i < 1000; i++) {
    update_positions(p, N);
    update_velocities(p, N);
  }

  // Free the memory for the particles
  free(p);

  return 0;
}