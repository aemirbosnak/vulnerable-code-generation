//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: mathematical
#include <stdio.h>
#include <math.h>
#define GRAV_CONST  6.674e-11
#define SOLAR_MASS  1.98892e30
#define YEAR        31536000

typedef struct {
  double x,y,z; /* position */
  double vx,vy,vz; /* velocity */
  double mass; /* mass */
} body;

typedef struct {
  body *bodies; /* array of bodies */
  int count; /* number of bodies */
} system;

system initialize_system() {
  system s = {NULL, 0};
  return s;
}

void destroy_system(system *s) {
  free(s->bodies);
  s->bodies = NULL;
  s->count = 0;
}

void add_body(system *s, body b) {
  s->bodies = realloc(s->bodies, (s->count + 1) * sizeof(body));
  s->bodies[s->count++] = b;
}

void update_body(body *b, double dt) {
  /* update position using current velocity */
  b->x += b->vx * dt;
  b->y += b->vy * dt;
  b->z += b->vz * dt;
}

void calculate_force(body *a, body *b, double *fx, double *fy, double *fz) {
  /* calculate distance between a and b */
  double dx = b->x - a->x;
  double dy = b->y - a->y;
  double dz = b->z - a->z;
  double dist_squared = dx*dx + dy*dy + dz*dz;
  double dist = sqrt(dist_squared);
  /* calculate force using Newton's law of gravitation */
  double magnitude = GRAV_CONST * a->mass * b->mass / dist_squared;
  *fx += magnitude * dx / dist;
  *fy += magnitude * dy / dist;
  *fz += magnitude * dz / dist;
}

void update_velocity(body *b, double fx, double fy, double fz, double dt) {
  /* update velocity using current force */
  b->vx += fx / b->mass * dt;
  b->vy += fy / b->mass * dt;
  b->vz += fz / b->mass * dt;
}

void update_system(system *s, double dt) {
  int i,j;
  for (i = 0; i < s->count; i++) {
    double fx = 0, fy = 0, fz = 0;
    for (j = 0; j < s->count; j++) {
      if (i == j) continue;
      calculate_force(&s->bodies[i], &s->bodies[j], &fx, &fy, &fz);
    }
    update_velocity(&s->bodies[i], fx, fy, fz, dt);
  }
  for (i = 0; i < s->count; i++) {
    update_body(&s->bodies[i], dt);
  }
}

void print_system(system *s) {
  int i;
  for (i = 0; i < s->count; i++) {
    printf("body %d: x=%f y=%f z=%f vx=%f vy=%f vz=%f\n",
           i, s->bodies[i].x, s->bodies[i].y, s->bodies[i].z,
           s->bodies[i].vx, s->bodies[i].vy, s->bodies[i].vz);
  }
}

int main() {
  system s = initialize_system();
  add_body(&s, (body) {0, 0, 0, 0, 0, 0, 2e30});
  add_body(&s, (body) {149.6e9, 0, 0, 0, 29800, 0, 5.97e24});
  double dt = 3600*24*365; /* one year */
  int steps = 365*10; /* ten years */
  int i;
  for (i = 0; i < steps; i++) {
    update_system(&s, dt);
  }
  print_system(&s);
  destroy_system(&s);
  return 0;
}