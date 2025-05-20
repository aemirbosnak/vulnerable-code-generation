//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the gravitational constant
#define G 6.67408e-11

// Define the mass of the Earth
#define M_EARTH 5.972e24

// Define the radius of the Earth
#define R_EARTH 6.371e6

// Define the time step
#define DT 10

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
void initialize_particles(particle *p) {
  for (int i = 0; i < N; i++) {
    // Set the mass of the particle
    p[i].m = 1e3;

    // Set the initial position of the particle
    p[i].x = R_EARTH + 1e6 * (rand() / (double)RAND_MAX - 0.5);
    p[i].y = R_EARTH + 1e6 * (rand() / (double)RAND_MAX - 0.5);
    p[i].z = R_EARTH + 1e6 * (rand() / (double)RAND_MAX - 0.5);

    // Set the initial velocity of the particle
    p[i].vx = 1e3 * (rand() / (double)RAND_MAX - 0.5);
    p[i].vy = 1e3 * (rand() / (double)RAND_MAX - 0.5);
    p[i].vz = 1e3 * (rand() / (double)RAND_MAX - 0.5);
  }
}

// Calculate the gravitational force between two particles
void calculate_force(particle *p1, particle *p2) {
  // Calculate the distance between the particles
  double dx = p2->x - p1->x;
  double dy = p2->y - p1->y;
  double dz = p2->z - p1->z;
  double r = sqrt(dx * dx + dy * dy + dz * dz);

  // Calculate the gravitational force
  double f = G * p1->m * p2->m / (r * r);

  // Calculate the unit vector pointing from p1 to p2
  double ux = dx / r;
  double uy = dy / r;
  double uz = dz / r;

  // Apply the force to p1
  p1->vx += f * ux * DT;
  p1->vy += f * uy * DT;
  p1->vz += f * uz * DT;

  // Apply the force to p2
  p2->vx -= f * ux * DT;
  p2->vy -= f * uy * DT;
  p2->vz -= f * uz * DT;
}

// Update the positions and velocities of the particles
void update_particles(particle *p) {
  for (int i = 0; i < N; i++) {
    // Update the position of the particle
    p[i].x += p[i].vx * DT;
    p[i].y += p[i].vy * DT;
    p[i].z += p[i].vz * DT;

    // Update the velocity of the particle
    p[i].vx += -G * M_EARTH / (p[i].x * p[i].x + p[i].y * p[i].y + p[i].z * p[i].z) * p[i].x * DT;
    p[i].vy += -G * M_EARTH / (p[i].x * p[i].x + p[i].y * p[i].y + p[i].z * p[i].z) * p[i].y * DT;
    p[i].vz += -G * M_EARTH / (p[i].x * p[i].x + p[i].y * p[i].y + p[i].z * p[i].z) * p[i].z * DT;
  }
}

// Main function
int main() {
  // Allocate memory for the particles
  particle *p = malloc(N * sizeof(particle));

  // Initialize the particles
  initialize_particles(p);

  // Run the simulation
  for (int i = 0; i < 10000; i++) {
    // Calculate the gravitational force between all pairs of particles
    for (int j = 0; j < N; j++) {
      for (int k = j + 1; k < N; k++) {
        calculate_force(&p[j], &p[k]);
      }
    }

    // Update the positions and velocities of the particles
    update_particles(p);
  }

  // Free the memory allocated for the particles
  free(p);

  return 0;
}