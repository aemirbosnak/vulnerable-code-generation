//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: active
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct {
  int x, y, z;
} vec3i;

typedef struct {
  vec3i pos;
  int type;
} entity;

#define ENT_TYPE_PLAYER 0
#define ENT_TYPE_ENEMY 1
#define ENT_TYPE_ASTEROID 2

entity *entities;
int num_entities;

void init_entities() {
  num_entities = 100;
  entities = malloc(sizeof(entity) * num_entities);

  for (int i = 0; i < num_entities; i++) {
    entities[i].pos.x = rand() % 1000 - 500;
    entities[i].pos.y = rand() % 1000 - 500;
    entities[i].pos.z = rand() % 1000 - 500;
    entities[i].type = rand() % 3;
  }
}

void update_entities() {
  for (int i = 0; i < num_entities; i++) {
    entity *e = &entities[i];

    switch (e->type) {
      case ENT_TYPE_PLAYER:
        // TODO: get input and move player
        break;
      case ENT_TYPE_ENEMY:
        // TODO: move enemy towards player
        break;
      case ENT_TYPE_ASTEROID:
        // TODO: move asteroid
        break;
    }
  }
}

void render_entities() {
  for (int i = 0; i < num_entities; i++) {
    entity *e = &entities[i];

    switch (e->type) {
      case ENT_TYPE_PLAYER:
        printf("Player: (%d, %d, %d)\n", e->pos.x, e->pos.y, e->pos.z);
        break;
      case ENT_TYPE_ENEMY:
        printf("Enemy: (%d, %d, %d)\n", e->pos.x, e->pos.y, e->pos.z);
        break;
      case ENT_TYPE_ASTEROID:
        printf("Asteroid: (%d, %d, %d)\n", e->pos.x, e->pos.y, e->pos.z);
        break;
    }
  }
}

int main() {
  srand(time(NULL));

  init_entities();

  while (1) {
    update_entities();
    render_entities();
  }

  return 0;
}