//GEMINI-pro DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: authentic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct {
  int x, y;
} Point;

typedef struct {
  char c;
  Point pos;
} Entity;

typedef struct {
  Entity* entities;
  int num_entities;
  int width, height;
} World;

World* create_world(int width, int height) {
  World* world = malloc(sizeof(World));
  world->width = width;
  world->height = height;
  world->num_entities = 0;
  world->entities = malloc(sizeof(Entity) * 100);
  return world;
}

void free_world(World* world) {
  free(world->entities);
  free(world);
}

void add_entity(World* world, Entity entity) {
  world->entities[world->num_entities++] = entity;
}

void generate_world(World* world) {
  srand(time(NULL));
  for (int i = 0; i < 100; i++) {
    Entity entity;
    entity.c = rand() % 26 + 'a';
    entity.pos.x = rand() % world->width;
    entity.pos.y = rand() % world->height;
    add_entity(world, entity);
  }
}

void print_world(World* world) {
  for (int y = 0; y < world->height; y++) {
    for (int x = 0; x < world->width; x++) {
      char c = '.';
      for (int i = 0; i < world->num_entities; i++) {
        Entity entity = world->entities[i];
        if (entity.pos.x == x && entity.pos.y == y) {
          c = entity.c;
          break;
        }
      }
      printf("%c", c);
    }
    printf("\n");
  }
}

int main() {
  World* world = create_world(80, 25);
  generate_world(world);
  print_world(world);
  free_world(world);
  return 0;
}