//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct particle {
  double x, y, z; // Position
  double vx, vy, vz; // Velocity
  double m; // Mass
} particle_t;

int main() {
  // Initialize random number generator
  srand(time(NULL));

  // Number of particles
  const int N = 1000;

  // Allocate memory for particles
  particle_t *particles = malloc(N * sizeof(particle_t));

  // Initialize particles with random positions and velocities
  for (int i = 0; i < N; i++) {
    // Position
    particles[i].x = (double)rand() / RAND_MAX;
    particles[i].y = (double)rand() / RAND_MAX;
    particles[i].z = (double)rand() / RAND_MAX;

    // Velocity
    particles[i].vx = (double)(rand() % 100) / 100.0;
    particles[i].vy = (double)(rand() % 100) / 100.0;
    particles[i].vz = (double)(rand() % 100) / 100.0;

    // Mass
    particles[i].m = (double)(rand() % 100) / 100.0;
  }

  // Time step
  const double dt = 0.001;

  // Simulation time
  const double t_max = 10.0;

  // Main simulation loop
  for (double t = 0.0; t < t_max; t += dt) {
    // Update positions and velocities
    for (int i = 0; i < N; i++) {
      // Update positions
      particles[i].x += particles[i].vx * dt;
      particles[i].y += particles[i].vy * dt;
      particles[i].z += particles[i].vz * dt;

      // Update velocities
      particles[i].vx += (double)(rand() % 100) / 1000.0;
      particles[i].vy += (double)(rand() % 100) / 1000.0;
      particles[i].vz += (double)(rand() % 100) / 1000.0;
    }

    // Visualization
    // ...

    // Print particle positions
    for (int i = 0; i < N; i++) {
      printf("%f %f %f\n", particles[i].x, particles[i].y, particles[i].z);
    }
  }

  // Free memory
  free(particles);

  return 0;
}