//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: Cryptic
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

typedef struct {
  int x, y, z;
} vec3;

typedef struct {
  vec3 pos;
  vec3 vel;
} body;

typedef struct {
  body *bodies;
  int nbodies;
} sim;

sim *sim_new(int nbodies) {
  sim *s = malloc(sizeof(sim));
  s->bodies = malloc(nbodies * sizeof(body));
  s->nbodies = nbodies;
  return s;
}

void sim_free(sim *s) {
  free(s->bodies);
  free(s);
}

void sim_init(sim *s) {
  for (int i = 0; i < s->nbodies; i++) {
    s->bodies[i].pos.x = rand() % 100;
    s->bodies[i].pos.y = rand() % 100;
    s->bodies[i].pos.z = rand() % 100;
    s->bodies[i].vel.x = (rand() % 20) - 10;
    s->bodies[i].vel.y = (rand() % 20) - 10;
    s->bodies[i].vel.z = (rand() % 20) - 10;
  }
}

void sim_update(sim *s, float dt) {
  for (int i = 0; i < s->nbodies; i++) {
    for (int j = 0; j < s->nbodies; j++) {
      if (i == j) continue;

      vec3 v = {s->bodies[i].pos.x - s->bodies[j].pos.x,
                 s->bodies[i].pos.y - s->bodies[j].pos.y,
                 s->bodies[i].pos.z - s->bodies[j].pos.z};

      float dist = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
      float force = 1 / (dist * dist);

      s->bodies[i].vel.x += force * v.x * dt;
      s->bodies[i].vel.y += force * v.y * dt;
      s->bodies[i].vel.z += force * v.z * dt;
    }

    s->bodies[i].pos.x += s->bodies[i].vel.x * dt;
    s->bodies[i].pos.y += s->bodies[i].vel.y * dt;
    s->bodies[i].pos.z += s->bodies[i].vel.z * dt;
  }
}

void sim_render(sim *s) {
  for (int i = 0; i < s->nbodies; i++) {
    printf("Body %d: ", i + 1);
    printf("(%d, %d, %d)\n", s->bodies[i].pos.x, s->bodies[i].pos.y, s->bodies[i].pos.z);
  }
}

int main() {
  srand(time(NULL));

  sim *s = sim_new(100);
  sim_init(s);

  for (int i = 0; i < 1000; i++) {
    sim_update(s, 0.01);
  }

  sim_render(s);

  sim_free(s);
}