//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_MONSTERS 5

typedef struct {
  int x;
  int y;
} position;

typedef struct {
  char *name;
  int health;
  int attack;
  position pos;
} monster;

typedef struct {
  char *name;
  int health;
  int attack;
  position pos;
  int is_open;
} room;

room rooms[MAX_ROOMS];
monster monsters[MAX_MONSTERS];

void create_rooms() {
  for (int i = 0; i < MAX_ROOMS; i++) {
    rooms[i].name = malloc(10 * sizeof(char));
    sprintf(rooms[i].name, "Room %d", i + 1);
    rooms[i].health = 100;
    rooms[i].attack = 10;
    rooms[i].pos.x = rand() % 10;
    rooms[i].pos.y = rand() % 10;
    rooms[i].is_open = 0;
  }
}

void create_monsters() {
  for (int i = 0; i < MAX_MONSTERS; i++) {
    monsters[i].name = malloc(10 * sizeof(char));
    sprintf(monsters[i].name, "Monster %d", i + 1);
    monsters[i].health = 100;
    monsters[i].attack = 10;
    monsters[i].pos.x = rand() % 10;
    monsters[i].pos.y = rand() % 10;
  }
}

void print_rooms() {
  for (int i = 0; i < MAX_ROOMS; i++) {
    printf("Room %d: (%d, %d)\n", i + 1, rooms[i].pos.x, rooms[i].pos.y);
  }
}

void print_monsters() {
  for (int i = 0; i < MAX_MONSTERS; i++) {
    printf("Monster %d: (%d, %d)\n", i + 1, monsters[i].pos.x, monsters[i].pos.y);
  }
}

int main() {
  srand(time(NULL));

  create_rooms();
  create_monsters();

  print_rooms();
  print_monsters();

  return 0;
}