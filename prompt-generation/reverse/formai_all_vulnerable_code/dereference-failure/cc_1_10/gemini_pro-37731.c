//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: Claude Shannon
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define MAX_X 100
#define MAX_Y 100

// Generate a random number between 0 and 1.
double rand01() {
  return (double)rand() / RAND_MAX;
}

// Generate a random number between a and b.
double randab(double a, double b) {
  return a + rand01() * (b - a);
}

// Generate a random integer between a and b.
int randiab(int a, int b) {
  return (int)randab(a, b + 1);
}

// Generate a random point in a square.
struct point {
  double x;
  double y;
};

struct point randpoint() {
  struct point p;
  p.x = randab(0, MAX_X);
  p.y = randab(0, MAX_Y);
  return p;
}

// Generate a random planet.
struct planet {
  struct point p;
  double r;
  double m;
};

struct planet randplanet() {
  struct planet p;
  p.p = randpoint();
  p.r = randab(0, 10);
  p.m = randab(0, 1000);
  return p;
}

// Generate a random solar system.
struct solarsystem {
  int n;
  struct planet *planets;
};

struct solarsystem randsolarsystem(int n) {
  struct solarsystem s;
  s.n = n;
  s.planets = malloc(n * sizeof(struct planet));
  for (int i = 0; i < n; i++) {
    s.planets[i] = randplanet();
  }
  return s;
}

// Generate a random galaxy.
struct galaxy {
  int s;
  struct solarsystem *solarsystems;
};

struct galaxy randgalaxy(int s) {
  struct galaxy g;
  g.s = s;
  g.solarsystems = malloc(s * sizeof(struct solarsystem));
  for (int i = 0; i < s; i++) {
    g.solarsystems[i] = randsolarsystem(randiab(1, 10));
  }
  return g;
}

// Print a solar system.
void printsolarsystem(struct solarsystem s) {
  printf("Solar system:\n");
  for (int i = 0; i < s.n; i++) {
    printf("  Planet %d:\n", i + 1);
    printf("    Position: (%f, %f)\n", s.planets[i].p.x, s.planets[i].p.y);
    printf("    Radius: %f\n", s.planets[i].r);
    printf("    Mass: %f\n", s.planets[i].m);
  }
}

// Print a galaxy.
void printgalaxy(struct galaxy g) {
  printf("Galaxy:\n");
  for (int i = 0; i < g.s; i++) {
    printf("  Solar system %d:\n", i + 1);
    printsolarsystem(g.solarsystems[i]);
  }
}

// Free a solar system.
void freesolarsystem(struct solarsystem s) {
  free(s.planets);
}

// Free a galaxy.
void freegalaxy(struct galaxy g) {
  for (int i = 0; i < g.s; i++) {
    freesolarsystem(g.solarsystems[i]);
  }
  free(g.solarsystems);
}

// Main function.
int main() {
  srand(time(NULL));

  // Generate a random galaxy.
  struct galaxy g = randgalaxy(10);

  // Print the galaxy.
  printgalaxy(g);

  // Free the galaxy.
  freegalaxy(g);

  return 0;
}