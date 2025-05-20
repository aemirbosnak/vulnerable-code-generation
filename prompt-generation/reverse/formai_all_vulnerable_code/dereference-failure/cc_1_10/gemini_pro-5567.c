//GEMINI-pro DATASET v1.0 Category: Simulation of the Solar System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
  double x, y, z; // position
  double vx, vy, vz; // velocity
  double m; // mass
} Body;

typedef struct {
  int n; // number of bodies
  Body *bodies; // array of bodies
} System;

// Create a new system with the given number of bodies.
System *new_system(int n) {
  System *system = malloc(sizeof(System));
  system->n = n;
  system->bodies = malloc(n * sizeof(Body));
  return system;
}

// Free the memory used by the system.
void free_system(System *system) {
  free(system->bodies);
  free(system);
}

// Initialize the system with the given parameters.
void init_system(System *system, double masses[], double positions[][3], double velocities[][3]) {
  for (int i = 0; i < system->n; i++) {
    system->bodies[i].m = masses[i];
    for (int j = 0; j < 3; j++) {
      system->bodies[i].x = positions[i][j];
      system->bodies[i].y = positions[i][j];
      system->bodies[i].z = positions[i][j];
      system->bodies[i].vx = velocities[i][j];
      system->bodies[i].vy = velocities[i][j];
      system->bodies[i].vz = velocities[i][j];
    }
  }
}

// Calculate the gravitational force between two bodies.
void calc_force(Body *body1, Body *body2, double force[][3]) {
  double dx = body2->x - body1->x;
  double dy = body2->y - body1->y;
  double dz = body2->z - body1->z;
  double r = sqrt(dx * dx + dy * dy + dz * dz);
  double f = body1->m * body2->m / (r * r);
  for (int i = 0; i < 3; i++) {
    force[0][i] = f * dx / r;
    force[1][i] = f * dy / r;
    force[2][i] = f * dz / r;
  }
}

// Update the velocities and positions of the bodies in the system.
void update_system(System *system, double dt) {
  for (int i = 0; i < system->n; i++) {
    double force[system->n][3];
    for (int j = 0; j < system->n; j++) {
      if (i == j) continue;
      calc_force(&system->bodies[i], &system->bodies[j], force);
      for (int k = 0; k < 3; k++) {
        system->bodies[i].vx += force[j][k] * dt / system->bodies[i].m;
        system->bodies[i].vy += force[j][k] * dt / system->bodies[i].m;
        system->bodies[i].vz += force[j][k] * dt / system->bodies[i].m;
      }
    }
    for (int k = 0; k < 3; k++) {
      system->bodies[i].x += system->bodies[i].vx * dt;
      system->bodies[i].y += system->bodies[i].vy * dt;
      system->bodies[i].z += system->bodies[i].vz * dt;
    }
  }
}

// Print the positions of the bodies in the system.
void print_system(System *system) {
  for (int i = 0; i < system->n; i++) {
    printf("%d: (%.3f, %.3f, %.3f)\n", i, system->bodies[i].x, system->bodies[i].y, system->bodies[i].z);
  }
}

int main() {
  // Create a new system with 3 bodies.
  System *system = new_system(3);

  // Initialize the system with the masses, positions, and velocities of the Sun, Earth, and Moon.
  double masses[] = {1.989e30, 5.972e24, 7.348e22};
  double positions[][3] = {
    {0, 0, 0},
    {1.5e11, 0, 0},
    {3.844e8, 0, 0}
  };
  double velocities[][3] = {
    {0, 0, 0},
    {30000, 0, 0},
    {1200, 0, 0}
  };
  init_system(system, masses, positions, velocities);

  // Update the system for 1000 time steps.
  for (int i = 0; i < 1000; i++) {
    update_system(system, 3600);
  }

  // Print the positions of the bodies in the system.
  print_system(system);

  // Free the memory used by the system.
  free_system(system);

  return 0;
}