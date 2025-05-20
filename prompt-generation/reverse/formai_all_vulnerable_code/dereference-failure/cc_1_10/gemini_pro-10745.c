//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the gravitational constant
#define G 6.674e-11

// Define the mass of the Earth
#define M_EARTH 5.972e24

// Define the radius of the Earth
#define R_EARTH 6.371e6

// Define the time step
#define DT 1.0

// Define the number of particles
#define N 1000

// Define the particle structure
typedef struct {
  double x;
  double y;
  double z;
  double vx;
  double vy;
  double vz;
  double m;
} particle;

// Initialize the particles
void initialize_particles(particle *p) {
  for (int i = 0; i < N; i++) {
    // Generate a random position within a sphere of radius R_EARTH
    p[i].x = (2.0 * R_EARTH * (rand() / (RAND_MAX + 1.0))) - R_EARTH;
    p[i].y = (2.0 * R_EARTH * (rand() / (RAND_MAX + 1.0))) - R_EARTH;
    p[i].z = (2.0 * R_EARTH * (rand() / (RAND_MAX + 1.0))) - R_EARTH;

    // Generate a random velocity
    p[i].vx = 0.0;
    p[i].vy = 0.0;
    p[i].vz = 0.0;

    // Set the mass of the particle
    p[i].m = 1.0;
  }
}

// Calculate the gravitational force between two particles
void calculate_force(particle *p1, particle *p2, double *fx, double *fy, double *fz) {
  // Calculate the distance between the particles
  double dx = p2->x - p1->x;
  double dy = p2->y - p1->y;
  double dz = p2->z - p1->z;
  double r = sqrt(dx * dx + dy * dy + dz * dz);

  // Calculate the gravitational force
  *fx = G * p1->m * p2->m * dx / (r * r * r);
  *fy = G * p1->m * p2->m * dy / (r * r * r);
  *fz = G * p1->m * p2->m * dz / (r * r * r);
}

// Update the velocities and positions of the particles
void update_particles(particle *p) {
  for (int i = 0; i < N; i++) {
    // Calculate the gravitational force on the particle
    double fx = 0.0;
    double fy = 0.0;
    double fz = 0.0;
    for (int j = 0; j < N; j++) {
      if (i != j) {
        calculate_force(&p[i], &p[j], &fx, &fy, &fz);
      }
    }

    // Update the velocity of the particle
    p[i].vx += fx * DT / p[i].m;
    p[i].vy += fy * DT / p[i].m;
    p[i].vz += fz * DT / p[i].m;

    // Update the position of the particle
    p[i].x += p[i].vx * DT;
    p[i].y += p[i].vy * DT;
    p[i].z += p[i].vz * DT;
  }
}

// Main function
int main() {
  // Initialize the particles
  particle *p = malloc(N * sizeof(particle));
  initialize_particles(p);

  // Simulate the system for a period of time
  for (int t = 0; t < 1000; t++) {
    // Update the velocities and positions of the particles
    update_particles(p);

    // Output the positions of the particles
    for (int i = 0; i < N; i++) {
      printf("%f %f %f\n", p[i].x, p[i].y, p[i].z);
    }
  }

  // Free the memory allocated for the particles
  free(p);

  return 0;
}