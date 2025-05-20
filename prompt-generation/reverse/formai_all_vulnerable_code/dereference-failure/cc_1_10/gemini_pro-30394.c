//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the gravitational constant.
#define G 6.67408e-11

// Define the mass of the Earth.
#define M_EARTH 5.972e24

// Define the radius of the Earth.
#define R_EARTH 6.371e6

// Define the time step.
#define DT 1.0

// Define the number of particles.
#define N 100

// Define the structure of a particle.
typedef struct {
  double x;
  double y;
  double z;
  double vx;
  double vy;
  double vz;
  double m;
} particle;

// Initialize the particles.
void initialize_particles(particle *p) {
  for (int i = 0; i < N; i++) {
    // Generate a random position within a sphere of radius R_EARTH.
    p[i].x = (2.0 * R_EARTH * ((double)rand() / (RAND_MAX + 1.0))) - R_EARTH;
    p[i].y = (2.0 * R_EARTH * ((double)rand() / (RAND_MAX + 1.0))) - R_EARTH;
    p[i].z = (2.0 * R_EARTH * ((double)rand() / (RAND_MAX + 1.0))) - R_EARTH;

    // Generate a random velocity.
    p[i].vx = 2.0 * ((double)rand() / (RAND_MAX + 1.0)) - 1.0;
    p[i].vy = 2.0 * ((double)rand() / (RAND_MAX + 1.0)) - 1.0;
    p[i].vz = 2.0 * ((double)rand() / (RAND_MAX + 1.0)) - 1.0;

    // Generate a random mass.
    p[i].m = (double)rand() / (RAND_MAX + 1.0);
  }
}

// Calculate the gravitational force between two particles.
void calculate_force(particle *p1, particle *p2, double *fx, double *fy, double *fz) {
  // Calculate the distance between the particles.
  double dx = p2->x - p1->x;
  double dy = p2->y - p1->y;
  double dz = p2->z - p1->z;
  double r = sqrt(dx * dx + dy * dy + dz * dz);

  // Calculate the gravitational force.
  *fx = G * p1->m * p2->m * dx / (r * r * r);
  *fy = G * p1->m * p2->m * dy / (r * r * r);
  *fz = G * p1->m * p2->m * dz / (r * r * r);
}

// Update the velocity and position of a particle.
void update_particle(particle *p, double fx, double fy, double fz) {
  // Update the velocity.
  p->vx += fx * DT / p->m;
  p->vy += fy * DT / p->m;
  p->vz += fz * DT / p->m;

  // Update the position.
  p->x += p->vx * DT;
  p->y += p->vy * DT;
  p->z += p->vz * DT;
}

// Main function.
int main() {
  // Allocate memory for the particles.
  particle *p = malloc(N * sizeof(particle));

  // Initialize the particles.
  initialize_particles(p);

  // Main loop.
  for (int t = 0; t < 1000; t++) {
    // Calculate the gravitational force between each pair of particles.
    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        double fx, fy, fz;
        calculate_force(&p[i], &p[j], &fx, &fy, &fz);

        // Update the velocity and position of each particle.
        update_particle(&p[i], fx, fy, fz);
        update_particle(&p[j], -fx, -fy, -fz);
      }
    }
  }

  // Free the memory.
  free(p);

  return 0;
}