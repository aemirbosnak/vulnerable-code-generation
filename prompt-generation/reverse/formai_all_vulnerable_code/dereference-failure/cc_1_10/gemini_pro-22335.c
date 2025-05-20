//GEMINI-pro DATASET v1.0 Category: Simulation of the Solar System ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_PLANETS 8
#define NUM_THREADS 4

typedef struct {
  double mass;
  double x;
  double y;
  double z;
  double vx;
  double vy;
  double vz;
} Planet;

Planet planets[NUM_PLANETS];

pthread_mutex_t mutex;

void *updatePlanet(void *arg) {
  int i = *(int *)arg;

  while (1) {
    pthread_mutex_lock(&mutex);

    // Calculate the forces on the planet
    double fx = 0;
    double fy = 0;
    double fz = 0;
    for (int j = 0; j < NUM_PLANETS; j++) {
      if (i == j) continue;
      double dx = planets[j].x - planets[i].x;
      double dy = planets[j].y - planets[i].y;
      double dz = planets[j].z - planets[i].z;
      double distance = sqrt(dx * dx + dy * dy + dz * dz);
      double force = planets[j].mass * planets[i].mass / (distance * distance);
      fx += force * dx / distance;
      fy += force * dy / distance;
      fz += force * dz / distance;
    }

    // Update the planet's velocity
    planets[i].vx += fx / planets[i].mass * 0.01;
    planets[i].vy += fy / planets[i].mass * 0.01;
    planets[i].vz += fz / planets[i].mass * 0.01;

    // Update the planet's position
    planets[i].x += planets[i].vx * 0.01;
    planets[i].y += planets[i].vy * 0.01;
    planets[i].z += planets[i].vz * 0.01;

    pthread_mutex_unlock(&mutex);
  }

  return NULL;
}

int main() {
  // Initialize the planets
  planets[0].mass = 1.989e30; // Sun
  planets[0].x = 0;
  planets[0].y = 0;
  planets[0].z = 0;
  planets[0].vx = 0;
  planets[0].vy = 0;
  planets[0].vz = 0;
  planets[1].mass = 3.302e23; // Mercury
  planets[1].x = 57.9e9;
  planets[1].y = 0;
  planets[1].z = 0;
  planets[1].vx = 0;
  planets[1].vy = 47.4e3;
  planets[1].vz = 0;
  planets[2].mass = 4.869e24; // Venus
  planets[2].x = 108.2e9;
  planets[2].y = 0;
  planets[2].z = 0;
  planets[2].vx = 0;
  planets[2].vy = 35.0e3;
  planets[2].vz = 0;
  planets[3].mass = 5.972e24; // Earth
  planets[3].x = 149.6e9;
  planets[3].y = 0;
  planets[3].z = 0;
  planets[3].vx = 0;
  planets[3].vy = 30.0e3;
  planets[3].vz = 0;
  planets[4].mass = 6.419e23; // Mars
  planets[4].x = 227.9e9;
  planets[4].y = 0;
  planets[4].z = 0;
  planets[4].vx = 0;
  planets[4].vy = 24.1e3;
  planets[4].vz = 0;
  planets[5].mass = 1.899e27; // Jupiter
  planets[5].x = 778.5e9;
  planets[5].y = 0;
  planets[5].z = 0;
  planets[5].vx = 0;
  planets[5].vy = 13.1e3;
  planets[5].vz = 0;
  planets[6].mass = 5.685e26; // Saturn
  planets[6].x = 1433.5e9;
  planets[6].y = 0;
  planets[6].z = 0;
  planets[6].vx = 0;
  planets[6].vy = 9.7e3;
  planets[6].vz = 0;
  planets[7].mass = 8.683e25; // Uranus
  planets[7].x = 2872.5e9;
  planets[7].y = 0;
  planets[7].z = 0;
  planets[7].vx = 0;
  planets[7].vy = 6.8e3;
  planets[7].vz = 0;

  // Initialize the mutex
  pthread_mutex_init(&mutex, NULL);

  // Create the threads
  pthread_t threads[NUM_THREADS];
  for (int i = 0; i < NUM_THREADS; i++) {
    int *arg = malloc(sizeof(int));
    *arg = i;
    pthread_create(&threads[i], NULL, updatePlanet, arg);
  }

  // Join the threads
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  // Destroy the mutex
  pthread_mutex_destroy(&mutex);

  return 0;
}