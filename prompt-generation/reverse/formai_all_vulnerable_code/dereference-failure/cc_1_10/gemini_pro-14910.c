//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
  double mass;
  double x, y, z;
  double vx, vy, vz;
} Particle;

typedef struct {
  double G;
  int nParticles;
  Particle *particles;
} System;

void initSystem(System *system, int nParticles, double mass) {
  system->G = 6.674e-11;
  system->nParticles = nParticles;
  system->particles = malloc(nParticles * sizeof(Particle));

  for (int i = 0; i < nParticles; i++) {
    system->particles[i].mass = mass;
    system->particles[i].x = 0;
    system->particles[i].y = 0;
    system->particles[i].z = 0;
    system->particles[i].vx = 0;
    system->particles[i].vy = 0;
    system->particles[i].vz = 0;
  }
}

void updateSystem(System *system, double dt) {
  for (int i = 0; i < system->nParticles; i++) {
    double ax = 0, ay = 0, az = 0;
    for (int j = 0; j < system->nParticles; j++) {
      if (i == j) continue;
      double dx = system->particles[j].x - system->particles[i].x;
      double dy = system->particles[j].y - system->particles[i].y;
      double dz = system->particles[j].z - system->particles[i].z;
      double r = sqrt(dx * dx + dy * dy + dz * dz);
      ax += system->G * system->particles[j].mass * dx / (r * r * r);
      ay += system->G * system->particles[j].mass * dy / (r * r * r);
      az += system->G * system->particles[j].mass * dz / (r * r * r);
    }
    system->particles[i].vx += ax * dt;
    system->particles[i].vy += ay * dt;
    system->particles[i].vz += az * dt;
    system->particles[i].x += system->particles[i].vx * dt;
    system->particles[i].y += system->particles[i].vy * dt;
    system->particles[i].z += system->particles[i].vz * dt;
  }
}

void printSystem(System *system) {
  for (int i = 0; i < system->nParticles; i++) {
    printf("%d %f %f %f\n", i, system->particles[i].x, system->particles[i].y, system->particles[i].z);
  }
}

int main() {
  System system;
  initSystem(&system, 10, 1);

  double dt = 0.01;
  for (int i = 0; i < 1000; i++) {
    updateSystem(&system, dt);
  }

  printSystem(&system);

  return 0;
}