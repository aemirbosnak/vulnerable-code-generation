//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  double x, y, z;
} Vector;

typedef struct {
  double mass;
  Vector position;
  Vector velocity;
  Vector acceleration;
} Particle;

void update_particle(Particle *p, double dt) {
  p->position.x += p->velocity.x * dt + 0.5 * p->acceleration.x * dt * dt;
  p->position.y += p->velocity.y * dt + 0.5 * p->acceleration.y * dt * dt;
  p->position.z += p->velocity.z * dt + 0.5 * p->acceleration.z * dt * dt;
  p->velocity.x += p->acceleration.x * dt;
  p->velocity.y += p->acceleration.y * dt;
  p->velocity.z += p->acceleration.z * dt;
}

void calculate_acceleration(Particle *p, double G, int n, Particle *particles) {
  double r2, r, a;
  Vector f;
  for (int i = 0; i < n; i++) {
    if (i == p - particles) continue;
    r2 = (p->position.x - particles[i].position.x) * (p->position.x - particles[i].position.x) +
         (p->position.y - particles[i].position.y) * (p->position.y - particles[i].position.y) +
         (p->position.z - particles[i].position.z) * (p->position.z - particles[i].position.z);
    r = sqrt(r2);
    a = G * particles[i].mass / r2;
    f.x = a * (p->position.x - particles[i].position.x) / r;
    f.y = a * (p->position.y - particles[i].position.y) / r;
    f.z = a * (p->position.z - particles[i].position.z) / r;
    p->acceleration.x += f.x / p->mass;
    p->acceleration.y += f.y / p->mass;
    p->acceleration.z += f.z / p->mass;
  }
}

int main() {
  double G = 6.674e-11;  // gravitational constant
  int n = 10;           // number of particles
  double dt = 1e-3;      // time step

  Particle *particles = malloc(n * sizeof(Particle));

  // initialize particles
  for (int i = 0; i < n; i++) {
    particles[i].mass = 1.0;
    particles[i].position.x = i * 10.0;
    particles[i].position.y = i * 10.0;
    particles[i].position.z = i * 10.0;
    particles[i].velocity.x = 0.0;
    particles[i].velocity.y = 0.0;
    particles[i].velocity.z = 0.0;
    particles[i].acceleration.x = 0.0;
    particles[i].acceleration.y = 0.0;
    particles[i].acceleration.z = 0.0;
  }

  // simulation loop
  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < n; j++) {
      calculate_acceleration(&particles[j], G, n, particles);
    }
    for (int j = 0; j < n; j++) {
      update_particle(&particles[j], dt);
    }
  }

  // print particle positions
  for (int i = 0; i < n; i++) {
    printf("%f %f %f\n", particles[i].position.x, particles[i].position.y, particles[i].position.z);
  }

  free(particles);
  return 0;
}