//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Define the number of particles and the time step
#define N 10000
#define dt 0.001

// Define the gravitational constant
#define G 6.674e-11

// Define the particle structure
typedef struct {
  double m; // Mass
  double x; // X-coordinate
  double y; // Y-coordinate
  double vx; // X-velocity
  double vy; // Y-velocity
} particle;

// Initialize the particles
void init_particles(particle *p) {
  // Set the mass of each particle to 1
  for (int i = 0; i < N; i++) {
    p[i].m = 1;
  }

  // Set the initial positions and velocities of the particles
  for (int i = 0; i < N; i++) {
    p[i].x = (double)rand() / RAND_MAX;
    p[i].y = (double)rand() / RAND_MAX;
    p[i].vx = 0;
    p[i].vy = 0;
  }
}

// Compute the gravitational force between two particles
void compute_force(particle *p1, particle *p2, double *fx, double *fy) {
  // Compute the distance between the particles
  double dx = p2->x - p1->x;
  double dy = p2->y - p1->y;
  double r = sqrt(dx * dx + dy * dy);

  // Compute the gravitational force
  double f = G * p1->m * p2->m / (r * r);

  // Compute the X and Y components of the force
  *fx = f * dx / r;
  *fy = f * dy / r;
}

// Update the positions and velocities of the particles
void update_particles(particle *p) {
  // Update the positions of the particles
  for (int i = 0; i < N; i++) {
    p[i].x += p[i].vx * dt;
    p[i].y += p[i].vy * dt;
  }

  // Update the velocities of the particles
  for (int i = 0; i < N; i++) {
    // Compute the total force on the particle
    double fx = 0;
    double fy = 0;
    for (int j = 0; j < N; j++) {
      if (i != j) {
        compute_force(&p[i], &p[j], &fx, &fy);
      }
    }

    // Update the velocity of the particle
    p[i].vx += fx * dt / p[i].m;
    p[i].vy += fy * dt / p[i].m;
  }
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(0));

  // Allocate memory for the particles
  particle *p = (particle *)malloc(N * sizeof(particle));

  // Initialize the particles
  init_particles(p);

  // Update the particles for a number of time steps
  for (int i = 0; i < 1000; i++) {
    update_particles(p);
  }

  // Print the positions of the particles
  for (int i = 0; i < N; i++) {
    printf("%f %f\n", p[i].x, p[i].y);
  }

  // Free the memory allocated for the particles
  free(p);

  return 0;
}