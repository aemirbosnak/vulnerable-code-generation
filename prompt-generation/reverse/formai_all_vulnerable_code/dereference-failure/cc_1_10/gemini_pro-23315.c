//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define G 6.67408e-11
#define DT 0.001
#define N 100

// Particle structure
typedef struct particle {
  double m; // mass
  double x[3]; // position
  double v[3]; // velocity
  double a[3]; // acceleration
} particle;

// Create a particle
particle *particle_create(double m, double x[3], double v[3]) {
  particle *p = malloc(sizeof(particle));
  p->m = m;
  for (int i = 0; i < 3; i++) {
    p->x[i] = x[i];
    p->v[i] = v[i];
    p->a[i] = 0.0;
  }
  return p;
}

// Destroy a particle
void particle_destroy(particle *p) {
  free(p);
}

// Update the acceleration of a particle
void particle_update_acceleration(particle *p, particle *q) {
  double dx[3];
  double r2;
  for (int i = 0; i < 3; i++) {
    dx[i] = q->x[i] - p->x[i];
  }
  r2 = dx[0] * dx[0] + dx[1] * dx[1] + dx[2] * dx[2];
  for (int i = 0; i < 3; i++) {
    p->a[i] += G * q->m * dx[i] / pow(r2, 1.5);
  }
}

// Update the velocity and position of a particle
void particle_update_velocity_and_position(particle *p) {
  for (int i = 0; i < 3; i++) {
    p->v[i] += p->a[i] * DT;
    p->x[i] += p->v[i] * DT;
  }
}

// Main function
int main() {
  // Set up the simulation
  srand(time(NULL));
  particle *particles[N];
  for (int i = 0; i < N; i++) {
    double m = 1.0 + (double)rand() / (double)RAND_MAX; // Mass between 1 and 2
    double x[3] = {
        (double)rand() / (double)RAND_MAX,
        (double)rand() / (double)RAND_MAX,
        (double)rand() / (double)RAND_MAX,
    }; // Random position
    double v[3] = {
        (double)rand() / (double)RAND_MAX,
        (double)rand() / (double)RAND_MAX,
        (double)rand() / (double)RAND_MAX,
    }; // Random velocity
    particles[i] = particle_create(m, x, v);
  }

  // Run the simulation
  for (int t = 0; t < 10000; t++) {
    // Update the accelerations of all particles
    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        particle_update_acceleration(particles[i], particles[j]);
      }
    }

    // Update the velocities and positions of all particles
    for (int i = 0; i < N; i++) {
      particle_update_velocity_and_position(particles[i]);
    }
  }

  // Print the final positions of all particles
  for (int i = 0; i < N; i++) {
    printf("Particle %d: (%f, %f, %f)\n", i, particles[i]->x[0], particles[i]->x[1],
           particles[i]->x[2]);
  }

  // Clean up
  for (int i = 0; i < N; i++) {
    particle_destroy(particles[i]);
  }

  return 0;
}