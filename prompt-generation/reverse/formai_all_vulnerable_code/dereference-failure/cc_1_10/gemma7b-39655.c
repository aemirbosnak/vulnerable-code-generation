//Gemma-7B DATASET v1.0 Category: Weather simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_PARTICLES 1000

typedef struct Particle {
  double x, y, z;
  double vx, vy, vz;
  int color;
} Particle;

void simulateWeather(Particle *particles, int numParticles) {
  for (int i = 0; i < numParticles; i++) {
    particles[i].x += particles[i].vx * 0.01 * (double)rand() / RAND_MAX;
    particles[i].y += particles[i].vy * 0.01 * (double)rand() / RAND_MAX;
    particles[i].z += particles[i].vz * 0.01 * (double)rand() / RAND_MAX;

    particles[i].vx *= 0.99;
    particles[i].vy *= 0.99;
    particles[i].vz *= 0.99;

    particles[i].color = (particles[i].color + 1) % 10;
  }
}

int main() {
  Particle *particles = malloc(MAX_PARTICLES * sizeof(Particle));

  for (int i = 0; i < MAX_PARTICLES; i++) {
    particles[i].x = (double)rand() / RAND_MAX;
    particles[i].y = (double)rand() / RAND_MAX;
    particles[i].z = (double)rand() / RAND_MAX;

    particles[i].vx = (double)rand() / RAND_MAX;
    particles[i].vy = (double)rand() / RAND_MAX;
    particles[i].vz = (double)rand() / RAND_MAX;

    particles[i].color = rand() % 10;
  }

  simulateWeather(particles, MAX_PARTICLES);

  for (int i = 0; i < MAX_PARTICLES; i++) {
    printf("Particle %d: x = %.2lf, y = %.2lf, z = %.2lf, color = %d\n", i, particles[i].x, particles[i].y, particles[i].z, particles[i].color);
  }

  free(particles);

  return 0;
}