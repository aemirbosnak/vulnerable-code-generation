//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOMS 10
#define OBJECTS 100

typedef struct {
  int x, y;
  char *name;
} object;

typedef struct {
  object *objects[OBJECTS];
  int num_objects;
} room;

room *rooms[ROOMS];

void create_rooms() {
  for (int i = 0; i < ROOMS; i++) {
    rooms[i] = malloc(sizeof(room));
    rooms[i]->num_objects = 0;
  }
}

void create_objects() {
  for (int i = 0; i < OBJECTS; i++) {
    object *o = malloc(sizeof(object));
    o->x = rand() % ROOMS;
    o->y = rand() % ROOMS;
    o->name = malloc(10);
    sprintf(o->name, "object%d", i);
    rooms[o->x]->objects[rooms[o->x]->num_objects++] = o;
  }
}

void print_rooms() {
  for (int i = 0; i < ROOMS; i++) {
    printf("Room %d:\n", i);
    for (int j = 0; j < rooms[i]->num_objects; j++) {
      printf("  %s\n", rooms[i]->objects[j]->name);
    }
  }
}

int main() {
  srand(time(NULL));
  create_rooms();
  create_objects();
  print_rooms();
  return 0;
}