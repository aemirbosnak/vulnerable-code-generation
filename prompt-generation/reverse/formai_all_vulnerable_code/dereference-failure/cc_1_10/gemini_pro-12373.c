//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the gravity constant
#define G 6.674e-11

// Define the mass of the Earth in kilograms
#define EARTH_MASS 5.972e24

// Define the radius of the Earth in meters
#define EARTH_RADIUS 6.371e6

// Define the timestep in seconds
#define DT 1

// Define the number of particles
#define N 1000

// Define the particle data structure
typedef struct {
  double x;
  double y;
  double z;
  double vx;
  double vy;
  double vz;
  double mass;
} particle;

// Initialize the particles
void init_particles(particle *p) {
  for (int i = 0; i < N; i++) {
    // Generate random positions and velocities
    p[i].x = (2 * ((double)rand() / (double)RAND_MAX) - 1) * EARTH_RADIUS;
    p[i].y = (2 * ((double)rand() / (double)RAND_MAX) - 1) * EARTH_RADIUS;
    p[i].z = (2 * ((double)rand() / (double)RAND_MAX) - 1) * EARTH_RADIUS;
    p[i].vx = (2 * ((double)rand() / (double)RAND_MAX) - 1) * 100;
    p[i].vy = (2 * ((double)rand() / (double)RAND_MAX) - 1) * 100;
    p[i].vz = (2 * ((double)rand() / (double)RAND_MAX) - 1) * 100;

    // Set the mass of the particle
    p[i].mass = 1000;
  }
}

// Update the particle positions and velocities
void update_particles(particle *p) {
  for (int i = 0; i < N; i++) {
    // Calculate the gravitational force on the particle
    double fx = 0;
    double fy = 0;
    double fz = 0;
    for (int j = 0; j < N; j++) {
      if (i == j) continue;

      // Calculate the distance between the particles
      double dx = p[i].x - p[j].x;
      double dy = p[i].y - p[j].y;
      double dz = p[i].z - p[j].z;
      double r = sqrt(dx * dx + dy * dy + dz * dz);

      // Calculate the gravitational force
      double f = G * p[i].mass * p[j].mass / (r * r * r);

      // Add the force to the particle's acceleration
      fx += f * dx / r;
      fy += f * dy / r;
      fz += f * dz / r;
    }

    // Update the particle's velocity
    p[i].vx += fx * DT;
    p[i].vy += fy * DT;
    p[i].vz += fz * DT;

    // Update the particle's position
    p[i].x += p[i].vx * DT;
    p[i].y += p[i].vy * DT;
    p[i].z += p[i].vz * DT;
  }
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Allocate memory for the particles
  particle *p = malloc(N * sizeof(particle));

  // Initialize the particles
  init_particles(p);

  // Update the particles
  for (int i = 0; i < 1000; i++) {
    update_particles(p);
  }

  // Free the memory allocated for the particles
  free(p);

  return 0;
}