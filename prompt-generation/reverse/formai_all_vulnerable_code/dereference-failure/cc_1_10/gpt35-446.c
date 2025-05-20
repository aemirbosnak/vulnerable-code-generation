//FormAI DATASET v1.0 Category: Physics simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11

struct body {
  double mass;
  double x, y;
  double vx, vy;
  double fx, fy;
};

void update(struct body *b, double time_step) {
  double ax = b->fx / b->mass;
  double ay = b->fy / b->mass;
  b->vx += ax * time_step;
  b->vy += ay * time_step;
  b->x += b->vx * time_step;
  b->y += b->vy * time_step;
  b->fx = 0;
  b->fy = 0;
}

void add_force(struct body *a, struct body *b) {
  double dx = b->x - a->x;
  double dy = b->y - a->y;
  double dist_sq = dx*dx + dy*dy;
  if (dist_sq == 0) return;
  double dist = sqrt(dist_sq);
  double force = (G * a->mass * b->mass) / dist_sq;
  double fx = force * dx / dist;
  double fy = force * dy / dist;
  a->fx += fx;
  a->fy += fy;
  b->fx -= fx;
  b->fy -= fy;
}

int main() {
  int num_bodies = 3;
  struct body *bodies = malloc(num_bodies * sizeof(struct body));

  bodies[0].mass = 5.972e24;
  bodies[0].x = 0;
  bodies[0].y = 0;
  bodies[0].vx = 0;
  bodies[0].vy = 0;

  bodies[1].mass = 7.342e22;
  bodies[1].x = 3.84e8;
  bodies[1].y = 0;
  bodies[1].vx = 0;
  bodies[1].vy = 1022;

  bodies[2].mass = 1000;
  bodies[2].x = 3.84e8 + 10000;
  bodies[2].y = 0;
  bodies[2].vx = 0;
  bodies[2].vy = 1072;

  double time_step = 600;
  double duration = 6 * 30 * 24 * 60 * 60;  // 6 months in seconds

  for (double t = 0; t < duration; t += time_step) {
    for (int i = 0; i < num_bodies; i++) {
      for (int j = i+1; j < num_bodies; j++) {
        add_force(&bodies[i], &bodies[j]);
      }
    }
    for (int i = 0; i < num_bodies; i++) {
      update(&bodies[i], time_step);
    }
  }

  for (int i = 0; i < num_bodies; i++) {
    printf("Body %d: (%.6g, %.6g)\n", i, bodies[i].x, bodies[i].y);
  }

  free(bodies);
  return 0;
}