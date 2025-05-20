//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
  double mass;
  double x;
  double y;
  double vx;
  double vy;
} Planet;

void update_velocities(Planet *planets, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      double dx = planets[j].x - planets[i].x;
      double dy = planets[j].y - planets[i].y;
      double d = sqrt(dx * dx + dy * dy);
      double F = (planets[i].mass * planets[j].mass) / (d * d);
      planets[i].vx += F * dx / d;
      planets[i].vy += F * dy / d;
      planets[j].vx -= F * dx / d;
      planets[j].vy -= F * dy / d;
    }
  }
}

void update_positions(Planet *planets, int n, double dt) {
  for (int i = 0; i < n; i++) {
    planets[i].x += planets[i].vx * dt;
    planets[i].y += planets[i].vy * dt;
  }
}

void print_planets(Planet *planets, int n) {
  for (int i = 0; i < n; i++) {
    printf("%f %f %f %f %f\n", planets[i].mass, planets[i].x, planets[i].y, planets[i].vx, planets[i].vy);
  }
}

int main(int argc, char **argv) {
  if (argc != 5) {
    printf("Usage: %s <n> <dt> <T> <seed>\n", argv[0]);
    return 1;
  }

  int n = atoi(argv[1]);
  double dt = atof(argv[2]);
  double T = atof(argv[3]);
  int seed = atoi(argv[4]);

  srand(seed);

  Planet *planets = malloc(n * sizeof(Planet));
  for (int i = 0; i < n; i++) {
    planets[i].mass = rand() % 1000 + 1;
    planets[i].x = rand() % 1000000;
    planets[i].y = rand() % 1000000;
    planets[i].vx = rand() % 1000 - 500;
    planets[i].vy = rand() % 1000 - 500;
  }

  for (double t = 0; t < T; t += dt) {
    update_velocities(planets, n);
    update_positions(planets, n, dt);
    print_planets(planets, n);
  }

  free(planets);

  return 0;
}