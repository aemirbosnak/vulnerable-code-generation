//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: mathematical
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define RAND_STAR (32767)
#define NUM_STARS 100
#define MAX_STARS 10000

struct star {
  double x, y, z;
  double vx, vy, vz;
  int mass;
  char *name;
};

struct universe {
  struct star stars[MAX_STARS];
  int num_stars;
};

struct universe *create_universe(int n) {
  struct universe *u = malloc(sizeof(struct universe));
  u->num_stars = n;
  for (int i = 0; i < n; i++) {
    u->stars[i].x = (rand() / (RAND_STAR + 1.0)) * 100.0;
    u->stars[i].y = (rand() / (RAND_STAR + 1.0)) * 100.0;
    u->stars[i].z = (rand() / (RAND_STAR + 1.0)) * 100.0;
    u->stars[i].vx = (rand() / (RAND_STAR + 1.0)) * 10.0;
    u->stars[i].vy = (rand() / (RAND_STAR + 1.0)) * 10.0;
    u->stars[i].vz = (rand() / (RAND_STAR + 1.0)) * 10.0;
    u->stars[i].mass = 1 + (rand() / (RAND_STAR + 1.0)) * 100;
    u->stars[i].name = malloc(10);
    sprintf(u->stars[i].name, "Star %d", i);
  }
  return u;
}

void destroy_universe(struct universe *u) {
  for (int i = 0; i < u->num_stars; i++) {
    free(u->stars[i].name);
  }
  free(u);
}

void print_universe(struct universe *u) {
  for (int i = 0; i < u->num_stars; i++) {
    printf("%s (%f, %f, %f)\n", u->stars[i].name, u->stars[i].x, u->stars[i].y,
           u->stars[i].z);
  }
}

void update_universe(struct universe *u, double dt) {
  for (int i = 0; i < u->num_stars; i++) {
    u->stars[i].x += u->stars[i].vx * dt;
    u->stars[i].y += u->stars[i].vy * dt;
    u->stars[i].z += u->stars[i].vz * dt;
  }
}

int main() {
  struct universe *u = create_universe(NUM_STARS);
  print_universe(u);
  update_universe(u, 1.0);
  print_universe(u);
  destroy_universe(u);
  return 0;
}