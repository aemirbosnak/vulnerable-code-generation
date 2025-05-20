//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the gravitational constant
#define G 6.674e-11

// Define the mass of the Earth
#define M 5.972e24

// Define the radius of the Earth
#define R 6.371e6

// Define the time step
#define dt 1.0

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
void init_particles(particle *p) {
  for (int i = 0; i < N; i++) {
    // Generate random positions and velocities
    p[i].x = (2.0 * R) * ((double)rand() / RAND_MAX) - R;
    p[i].y = (2.0 * R) * ((double)rand() / RAND_MAX) - R;
    p[i].z = (2.0 * R) * ((double)rand() / RAND_MAX) - R;
    p[i].vx = 0.0;
    p[i].vy = 0.0;
    p[i].vz = 0.0;
    
    // Generate random masses
    p[i].m = 1000.0 * ((double)rand() / RAND_MAX);
  }
}

// Calculate the gravitational force between two particles
void calc_force(particle *p1, particle *p2) {
  // Calculate the distance between the particles
  double dx = p2->x - p1->x;
  double dy = p2->y - p1->y;
  double dz = p2->z - p1->z;
  double r = sqrt(dx * dx + dy * dy + dz * dz);
  
  // Calculate the force
  double f = G * p1->m * p2->m / (r * r);
  
  // Calculate the direction of the force
  double fx = f * dx / r;
  double fy = f * dy / r;
  double fz = f * dz / r;
  
  // Apply the force to the particles
  p1->vx += fx * dt / p1->m;
  p1->vy += fy * dt / p1->m;
  p1->vz += fz * dt / p1->m;
  p2->vx -= fx * dt / p2->m;
  p2->vy -= fy * dt / p2->m;
  p2->vz -= fz * dt / p2->m;
}

// Update the positions of the particles
void update_positions(particle *p) {
  for (int i = 0; i < N; i++) {
    // Update the positions
    p[i].x += p[i].vx * dt;
    p[i].y += p[i].vy * dt; 
    p[i].z += p[i].vz * dt;
    
    // Check if the particle has escaped from the simulation
    if (sqrt(p[i].x * p[i].x + p[i].y * p[i].y + p[i].z * p[i].z) > R) {
      // Reset the particle's position
      p[i].x = (2.0 * R) * ((double)rand() / RAND_MAX) - R;
      p[i].y = (2.0 * R) * ((double)rand() / RAND_MAX) - R;
      p[i].z = (2.0 * R) * ((double)rand() / RAND_MAX) - R;
      
      // Reset the particle's velocity
      p[i].vx = 0.0;
      p[i].vy = 0.0;
      p[i].vz = 0.0;
    }
  }
}

// Main function
int main() {
  // Allocate memory for the particles
  particle *p = malloc(N * sizeof(particle));
  
  // Initialize the particles
  init_particles(p);
  
  // Main simulation loop
  for (int i = 0; i < 100000; i++) {
    // Calculate the forces between the particles
    for (int j = 0; j < N; j++) {
      for (int k = j + 1; k < N; k++) {
        calc_force(&p[j], &p[k]);
      }
    }
  
    // Update the positions of the particles
    update_positions(p);
  }
  
  // Free the memory allocated for the particles
  free(p);
  
  return 0;
}