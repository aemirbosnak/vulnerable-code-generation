//FormAI DATASET v1.0 Category: Physics simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constants
#define TIME_STEP 0.1
#define NUM_PARTICLES 1000
#define MASS 1
#define RADIUS 0.1
#define GRAVITY 9.8

typedef struct Particle {
  double x, y, z;   // Position of the particle
  double vx, vy, vz; // Velocity of the particle
} Particle;

// Define function for updating particle positions
void update_particles(Particle *p, double dt) {
  int i, j, k;
  double dx, dy, dz, dsq, f;
  for (i = 0; i < NUM_PARTICLES; i++) {
    // Update position of particle i
    p[i].x += p[i].vx * dt;
    p[i].y += p[i].vy * dt;
    p[i].z += p[i].vz * dt; 

    // Apply gravity to particle i
    p[i].vy -= GRAVITY * dt; 

    // Detect collision between particles
    for (j = i+1; j < NUM_PARTICLES; j++) { 
      dx = p[j].x - p[i].x;
      dy = p[j].y - p[i].y;
      dz = p[j].z - p[i].z;
      dsq = dx*dx + dy*dy + dz*dz;
      if (dsq <= (2*RADIUS)*(2*RADIUS)) {
        f = sqrt(GRAVITY*MASS*MASS/dsq);
        p[i].vx += f * dx * dt;
        p[i].vy += f * dy * dt;
        p[i].vz += f * dz * dt;
        p[j].vx -= f * dx * dt;
        p[j].vy -= f * dy * dt;
        p[j].vz -= f * dz * dt;
      }
    }
  }
}

int main() {
  int i;
  double t;
  
  // Create an array of particles
  Particle *particles = (Particle*) malloc(NUM_PARTICLES*sizeof(Particle));
  for (i = 0; i < NUM_PARTICLES; i++) {
    particles[i].x = 2*RADIUS * (rand()/(double)RAND_MAX - 0.5);
    particles[i].y = 2*RADIUS * (rand()/(double)RAND_MAX - 0.5);
    particles[i].z = 2*RADIUS * (rand()/(double)RAND_MAX - 0.5) + 10;
    particles[i].vx = 10 * (rand()/(double)RAND_MAX - 0.5);
    particles[i].vy = 10 * (rand()/(double)RAND_MAX - 0.5);
    particles[i].vz = 10 * (rand()/(double)RAND_MAX - 0.5);
  }

  // Simulate particle motion for 10 seconds
  for (t = 0; t < 10; t += TIME_STEP) {
    update_particles(particles, TIME_STEP);
  
    // Print progress to console
    printf("%.2f%% complete.\r", t/10*100);
    fflush(stdout);
  }

  // Free memory
  free(particles);
  return 0;
}