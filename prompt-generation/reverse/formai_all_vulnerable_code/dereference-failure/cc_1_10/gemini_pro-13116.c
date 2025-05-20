//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: funny
// Welcome to the wacky world of Planet Gravity Simulation!
// Brace yourself for a cosmic comedy of celestial proportions!

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// What's a simulation without a cast of silly characters?
typedef struct Planet {
  char* name;
  double mass; // Mass in earth masses. Don't let them get too heavy, or the simulation will be a real drag!
  double x, y; // Positions in AU. Let's keep things astronomical!
  double vx, vy; // Velocities in AU/yr. Prepare for a wild interstellar road trip!
} Planet;

// We need a lot of planets, so let's just randomly generate a bunch!
Planet* generatePlanets(int n) {
  Planet* planets = malloc(n * sizeof(Planet));
  char* names[] = {"Luna", "Marsha", "Jupiterius", "Neptunia", "Pluto", "Betty", "Zelda", "Barney", "Kermit", "Fozzie"};
  for (int i = 0; i < n; ++i) {
    planets[i].name = names[rand() % 10];
    planets[i].mass = 0.0001 + ((double) rand()) / (double) RAND_MAX; // Tiny planets to avoid gravitational chaos!
    planets[i].x = (rand() % 100 - 50.0) / 10.0; // Let's spread them out a bit!
    planets[i].y = (rand() % 100 - 50.0) / 10.0;
    planets[i].vx = (rand() % 10 - 5.0) / 100.0; // Give them a little initial shove!
    planets[i].vy = (rand() % 10 - 5.0) / 100.0;
  }
  return planets;
}

// Time to dance! Let's calculate the gravitational forces between our celestial comedians.
void calculateForces(Planet* planets, int n) {
  for (int i = 0; i < n; ++i) {
    planets[i].vx = 0; // Reset forces for this time step.
    planets[i].vy = 0;
    for (int j = 0; j < n; ++j) {
      if (i == j) continue; // No self-gravity, please!
      double dx = planets[j].x - planets[i].x;
      double dy = planets[j].y - planets[i].y;
      double dist = sqrt(dx * dx + dy * dy);
      double force = planets[i].mass * planets[j].mass / (dist * dist);
      double theta = atan2(dy, dx);
      planets[i].vx += force * cos(theta) / planets[i].mass;
      planets[i].vy += force * sin(theta) / planets[i].mass;
    }
  }
}

// Now, let's move the planets based on the gravitational dance they just had.
void updatePositions(Planet* planets, int n, double dt) {
  for (int i = 0; i < n; ++i) {
    planets[i].x += planets[i].vx * dt;
    planets[i].y += planets[i].vy * dt;
    // Don't let them crash into each other!
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      double dx = planets[j].x - planets[i].x;
      double dy = planets[j].y - planets[i].y;
      double dist = sqrt(dx * dx + dy * dy);
      if (dist < 0.01) { // A playful collision!
        printf("Oh no, %s and %s crashed! They're making a space-sized mess!\n", planets[i].name, planets[j].name);
        exit(0); // Let's not get too messy!
      }
    }
  }
}

// Let's put on a show!
int main() {
  // The more planets, the merrier!
  int n = 10;
  Planet* planets = generatePlanets(n);

  // Let's run the simulation for a while, shall we?
  double t = 0; // Time in years.
  double dt = 0.01; // Time step in years. We don't want things to move too fast!

  // Prepare for the cosmic chaos!
  while (t < 100) { // 100 years of wild planetary antics!
    calculateForces(planets, n);
    updatePositions(planets, n, dt);
    t += dt;
  }

  // Let's see how our celestial clowns fared!
  printf("After %0.2f years of gravitational shenanigans:\n", t);
  for (int i = 0; i < n; ++i) {
    printf("%s (%.4f Earth masses): (%.2f, %.2f) AU, (%.3f, %.3f) AU/yr\n", planets[i].name, planets[i].mass, planets[i].x, planets[i].y, planets[i].vx, planets[i].vy);
  }

  // Free the memory of our spacey crew.
  free(planets);
  return 0;
}