//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the gravitational constant
#define G 6.674e-11

// Define the mass of the earth
#define EARTH_MASS 5.972e24

// Define the radius of the earth
#define EARTH_RADIUS 6.371e6

// Define the timestep
#define DT 1.0

// Define the number of particles
#define N 100

// Define the particle structure
typedef struct {
  double m; // mass
  double x; // x-coordinate
  double y; // y-coordinate
  double z; // z-coordinate
  double vx; // x-velocity
  double vy; // y-velocity
  double vz; // z-velocity
} particle;

// Initialize the particles
void init_particles(particle *p) {
  for (int i = 0; i < N; i++) {
    p[i].m = 1.0;
    p[i].x = 0.0;
    p[i].y = 0.0;
    p[i].z = 0.0;
    p[i].vx = 0.0;
    p[i].vy = 0.0;
    p[i].vz = 0.0;
  }
}

// Calculate the force on a particle
void calc_force(particle *p) {
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      double dx = p[j].x - p[i].x;
      double dy = p[j].y - p[i].y;
      double dz = p[j].z - p[i].z;
      double r = sqrt(dx * dx + dy * dy + dz * dz);
      double f = G * p[i].m * p[j].m / (r * r);
      double fx = f * dx / r;
      double fy = f * dy / r;
      double fz = f * dz / r;
      p[i].vx += fx * DT / p[i].m;
      p[i].vy += fy * DT / p[i].m;
      p[i].vz += fz * DT / p[i].m;
      p[j].vx -= fx * DT / p[j].m;
      p[j].vy -= fy * DT / p[j].m;
      p[j].vz -= fz * DT / p[j].m;
    }
  }
}

// Update the positions of the particles
void update_positions(particle *p) {
  for (int i = 0; i < N; i++) {
    p[i].x += p[i].vx * DT;
    p[i].y += p[i].vy * DT;
    p[i].z += p[i].vz * DT;
  }
}

// Main function
int main() {
  // Allocate memory for the particles
  particle *p = malloc(N * sizeof(particle));

  // Initialize the particles
  init_particles(p);

  // Calculate the force on each particle
  calc_force(p);

  // Update the positions of the particles
  update_positions(p);

  // Print the positions of the particles
  for (int i = 0; i < N; i++) {
    printf("%f %f %f\n", p[i].x, p[i].y, p[i].z);
  }

  // Free the memory allocated for the particles
  free(p);

  return 0;
}