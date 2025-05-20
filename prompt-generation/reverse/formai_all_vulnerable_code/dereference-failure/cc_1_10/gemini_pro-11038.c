//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 1000  // number of particles
#define dt 0.001 // time step

// particle structure
typedef struct {
  double m; // mass
  double x, y, z; // position
  double vx, vy, vz; // velocity
  double fx, fy, fz; // force
} particle;

// function to calculate the force between two particles
void calc_force(particle *p1, particle *p2) {
  double dx = p2->x - p1->x;
  double dy = p2->y - p1->y;
  double dz = p2->z - p1->z;
  double r = sqrt(dx * dx + dy * dy + dz * dz);
  double f = (p1->m * p2->m) / (r * r);
  p1->fx -= f * dx / r;
  p1->fy -= f * dy / r;
  p1->fz -= f * dz / r;
  p2->fx += f * dx / r;
  p2->fy += f * dy / r;
  p2->fz += f * dz / r;
}

// function to update the velocity and position of a particle
void update_particle(particle *p) {
  p->vx += p->fx / p->m * dt;
  p->vy += p->fy / p->m * dt;
  p->vz += p->fz / p->m * dt;
  p->x += p->vx * dt;
  p->y += p->vy * dt;
  p->z += p->vz * dt;
}

// main function
int main() {
  // initialize the random number generator
  srand(time(NULL));

  // create an array of particles
  particle *particles = malloc(N * sizeof(particle));

  // initialize the particles
  for (int i = 0; i < N; i++) {
    particles[i].m = 1.0;  // mass
    particles[i].x = (double)rand() / RAND_MAX; // position
    particles[i].y = (double)rand() / RAND_MAX; // position
    particles[i].z = (double)rand() / RAND_MAX; // position
    particles[i].vx = 0.0; // velocity
    particles[i].vy = 0.0; // velocity
    particles[i].vz = 0.0; // velocity
    particles[i].fx = 0.0; // force
    particles[i].fy = 0.0; // force
    particles[i].fz = 0.0; // force
  }

  // run the simulation
  for (int t = 0; t < 1000; t++) {
    // calculate the force between each pair of particles
    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        calc_force(&particles[i], &particles[j]);
      }
    }

    // update the velocity and position of each particle
    for (int i = 0; i < N; i++) {
      update_particle(&particles[i]);
    }
  }

  // free the array of particles
  free(particles);

  return 0;
}