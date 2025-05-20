//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the gravity constant
const double G = 6.67408e-11; // m^3 / (kg s^2)

// Define the mass of the Earth
const double M_EARTH = 5.972e24; // kg

// Define the radius of the Earth
const double R_EARTH = 6.371e6; // m

// Define the time step
const double DT = 1.0; // s

// Define the number of particles
const int N = 100;

// Define the particle structure
typedef struct {
  double x; // m
  double y; // m
  double z; // m
  double vx; // m/s
  double vy; // m/s
  double vz; // m/s
  double m; // kg
} particle_t;

// Initialize the particles
void initialize_particles(particle_t *particles) {
  for (int i = 0; i < N; i++) {
    // Generate a random position within a sphere of radius R_EARTH
    particles[i].x = 2 * R_EARTH * (drand48() - 0.5);
    particles[i].y = 2 * R_EARTH * (drand48() - 0.5);
    particles[i].z = 2 * R_EARTH * (drand48() - 0.5);

    // Generate a random velocity
    particles[i].vx = 100 * (drand48() - 0.5);
    particles[i].vy = 100 * (drand48() - 0.5);
    particles[i].vz = 100 * (drand48() - 0.5);

    // Generate a random mass
    particles[i].m = 1000 * (drand48() + 0.5);
  }
}

// Calculate the gravitational force between two particles
void calculate_force(particle_t *particle1, particle_t *particle2, double *fx, double *fy, double *fz) {
  // Calculate the distance between the two particles
  double dx = particle2->x - particle1->x;
  double dy = particle2->y - particle1->y;
  double dz = particle2->z - particle1->z;
  double r = sqrt(dx * dx + dy * dy + dz * dz);

  // Calculate the gravitational force
  double f = G * particle1->m * particle2->m / (r * r);

  // Calculate the force components
  *fx = f * dx / r;
  *fy = f * dy / r;
  *fz = f * dz / r;
}

// Update the velocities and positions of the particles
void update_particles(particle_t *particles) {
  // Calculate the forces on each particle
  for (int i = 0; i < N; i++) {
    double fx = 0;
    double fy = 0;
    double fz = 0;
    for (int j = 0; j < N; j++) {
      if (i != j) {
        calculate_force(&particles[i], &particles[j], &fx, &fy, &fz);
      }
    }

    // Update the velocities
    particles[i].vx += fx * DT / particles[i].m;
    particles[i].vy += fy * DT / particles[i].m;
    particles[i].vz += fz * DT / particles[i].m;

    // Update the positions
    particles[i].x += particles[i].vx * DT;
    particles[i].y += particles[i].vy * DT;
    particles[i].z += particles[i].vz * DT;
  }
}

// Main function
int main() {
  // Allocate memory for the particles
  particle_t *particles = malloc(N * sizeof(particle_t));

  // Initialize the particles
  initialize_particles(particles);

  // Run the simulation
  for (int i = 0; i < 10000; i++) {
    // Update the velocities and positions of the particles
    update_particles(particles);
  }

  // Free the memory allocated for the particles
  free(particles);

  return 0;
}