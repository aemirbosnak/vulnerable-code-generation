//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the mass and radius of the planet
#define MASS 1000000.0
#define RADIUS 1000.0

// Define the gravitational constant
#define G 6.674e-11

// Define the number of particles
#define N 100

// Define the particle structure
typedef struct {
  double x, y, z;     // Position
  double vx, vy, vz;  // Velocity
  double m;           // Mass
} Particle;

// Initialize the particles
void initialize_particles(Particle *particles) {
  for (int i = 0; i < N; i++) {
    // Generate random positions within a sphere of radius 1000
    particles[i].x = 2000.0 * (rand() / (RAND_MAX + 1.0) - 0.5);
    particles[i].y = 2000.0 * (rand() / (RAND_MAX + 1.0) - 0.5);
    particles[i].z = 2000.0 * (rand() / (RAND_MAX + 1.0) - 0.5);

    // Generate random velocities within a range of -100 to 100
    particles[i].vx = 200.0 * (rand() / (RAND_MAX + 1.0) - 0.5);
    particles[i].vy = 200.0 * (rand() / (RAND_MAX + 1.0) - 0.5);
    particles[i].vz = 200.0 * (rand() / (RAND_MAX + 1.0) - 0.5);

    // Set the mass of each particle to 1
    particles[i].m = 1.0;
  }
}

// Update the positions and velocities of the particles
void update_particles(Particle *particles, double dt) {
  // Calculate the gravitational force on each particle
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j) continue;

      // Calculate the distance between the particles
      double dx = particles[i].x - particles[j].x;
      double dy = particles[i].y - particles[j].y;
      double dz = particles[i].z - particles[j].z;
      double r = sqrt(dx * dx + dy * dy + dz * dz);

      // Calculate the gravitational force
      double f = G * particles[i].m * particles[j].m / (r * r);

      // Calculate the acceleration
      double ax = f * dx / r;
      double ay = f * dy / r;
      double az = f * dz / r;

      // Update the velocities
      particles[i].vx += ax * dt;
      particles[i].vy += ay * dt;
      particles[i].vz += az * dt;
    }
  }

  // Update the positions
  for (int i = 0; i < N; i++) {
    particles[i].x += particles[i].vx * dt;
    particles[i].y += particles[i].vy * dt;
    particles[i].z += particles[i].vz * dt;
  }
}

// Draw the particles
void draw_particles(Particle *particles) {
  // Open a file to write the particle positions to
  FILE *file = fopen("particles.xyz", "w");

  // Write the number of particles to the file
  fprintf(file, "%d\n", N);

  // Write the positions of the particles to the file
  for (int i = 0; i < N; i++) {
    fprintf(file, "%f %f %f\n", particles[i].x, particles[i].y, particles[i].z);
  }

  // Close the file
  fclose(file);
}

// Main function
int main() {
  // Allocate memory for the particles
  Particle *particles = malloc(N * sizeof(Particle));

  // Initialize the particles
  initialize_particles(particles);

  // Update the particles for a specified number of time steps
  for (int i = 0; i < 1000; i++) {
    update_particles(particles, 0.001);
  }

  // Draw the particles
  draw_particles(particles);

  // Free the memory allocated for the particles
  free(particles);

  return 0;
}