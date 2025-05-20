//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <omp.h>

// Define the number of particles
#define N 1000

// Define the mass of each particle
#define m 1.0

// Define the gravitational constant
#define G 6.674e-11

// Define the time step
#define dt 0.001

// Define the size of the simulation box
#define L 100.0

// Initialize the positions and velocities of the particles
void initialize(double *x, double *y, double *z, double *vx, double *vy, double *vz) {
  for (int i = 0; i < N; i++) {
    // Generate random positions within the simulation box
    x[i] = L * (drand48() - 0.5);
    y[i] = L * (drand48() - 0.5);
    z[i] = L * (drand48() - 0.5);

    // Generate random velocities
    vx[i] = 0.0;
    vy[i] = 0.0;
    vz[i] = 0.0;
  }
}

// Calculate the gravitational force between two particles
void calculate_force(double *x, double *y, double *z, double *fx, double *fy, double *fz) {
  // Reset the forces to zero
  for (int i = 0; i < N; i++) {
    fx[i] = 0.0;
    fy[i] = 0.0;
    fz[i] = 0.0;
  }

  // Calculate the gravitational force between each pair of particles
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j) {
        continue;
      }

      // Calculate the distance between the two particles
      double dx = x[i] - x[j];
      double dy = y[i] - y[j];
      double dz = z[i] - z[j];
      double r = sqrt(dx * dx + dy * dy + dz * dz);

      // Calculate the gravitational force
      double f = G * m * m / (r * r);

      // Add the force to the respective components
      fx[i] += f * dx / r;
      fy[i] += f * dy / r;
      fz[i] += f * dz / r;
    }
  }
}

// Update the positions and velocities of the particles
void update(double *x, double *y, double *z, double *vx, double *vy, double *vz, double *fx, double *fy, double *fz) {
  // Update the positions
  for (int i = 0; i < N; i++) {
    x[i] += vx[i] * dt;
    y[i] += vy[i] * dt;
    z[i] += vz[i] * dt;
  }

  // Update the velocities
  for (int i = 0; i < N; i++) {
    vx[i] += fx[i] / m * dt;
    vy[i] += fy[i] / m * dt;
    vz[i] += fz[i] / m * dt;
  }
}

// Main function
int main() {
  // Allocate memory for the particle data
  double *x = (double *)malloc(N * sizeof(double));
  double *y = (double *)malloc(N * sizeof(double));
  double *z = (double *)malloc(N * sizeof(double));
  double *vx = (double *)malloc(N * sizeof(double));
  double *vy = (double *)malloc(N * sizeof(double));
  double *vz = (double *)malloc(N * sizeof(double));
  double *fx = (double *)malloc(N * sizeof(double));
  double *fy = (double *)malloc(N * sizeof(double));
  double *fz = (double *)malloc(N * sizeof(double));

  // Initialize the particle data
  initialize(x, y, z, vx, vy, vz);

  // Repeat the simulation for a number of steps
  for (int i = 0; i < 10000; i++) {
    // Calculate the gravitational force between the particles
    calculate_force(x, y, z, fx, fy, fz);

    // Update the positions and velocities of the particles
    update(x, y, z, vx, vy, vz, fx, fy, fz);
  }

  // Free the memory allocated for the particle data
  free(x);
  free(y);
  free(z);
  free(vx);
  free(vy);
  free(vz);
  free(fx);
  free(fy);
  free(fz);

  return 0;
}