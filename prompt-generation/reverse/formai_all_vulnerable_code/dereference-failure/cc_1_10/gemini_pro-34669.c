//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: scalable
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM_ROOMS 10
#define NUM_MONSTERS 5

typedef struct Room {
  int id;
  char *description;
  struct Room *north;
  struct Room *east;
  struct Room *south;
  struct Room *west;
  struct Monster *monster;
} Room;

typedef struct Monster {
  int id;
  char *name;
  int health;
  int attack;
  int defense;
} Monster;

Room *rooms[NUM_ROOMS];

Monster *monsters[NUM_MONSTERS];

void create_rooms() {
  for (int i = 0; i < NUM_ROOMS; i++) {
    rooms[i] = malloc(sizeof(Room));
    rooms[i]->id = i;
    rooms[i]->description = malloc(50);
    sprintf(rooms[i]->description, "Room %d", i);
    rooms[i]->north = NULL;
    rooms[i]->east = NULL;
    rooms[i]->south = NULL;
    rooms[i]->west = NULL;
    rooms[i]->monster = NULL;
  }

  // Connect the rooms randomly
  for (int i = 0; i < NUM_ROOMS; i++) {
    int num_connections = rand() % 4;
    for (int j = 0; j < num_connections; j++) {
      int direction = rand() % 4;
      switch (direction) {
        case 0:
          if (rooms[i]->north == NULL) {
            rooms[i]->north = rooms[rand() % NUM_ROOMS];
          }
          break;
        case 1:
          if (rooms[i]->east == NULL) {
            rooms[i]->east = rooms[rand() % NUM_ROOMS];
          }
          break;
        case 2:
          if (rooms[i]->south == NULL) {
            rooms[i]->south = rooms[rand() % NUM_ROOMS];
          }
          break;
        case 3:
          if (rooms[i]->west == NULL) {
            rooms[i]->west = rooms[rand() % NUM_ROOMS];
          }
          break;
      }
    }
  }

  // Place monsters in some of the rooms
  for (int i = 0; i < NUM_MONSTERS; i++) {
    monsters[i] = malloc(sizeof(Monster));
    monsters[i]->id = i;
    monsters[i]->name = malloc(20);
    sprintf(monsters[i]->name, "Monster %d", i);
    monsters[i]->health = rand() % 100;
    monsters[i]->attack = rand() % 20;
    monsters[i]->defense = rand() % 20;
    rooms[rand() % NUM_ROOMS]->monster = monsters[i];
  }
}

void print_rooms() {
  for (int i = 0; i < NUM_ROOMS; i++) {
    printf("Room %d:\n", rooms[i]->id);
    printf("  Description: %s\n", rooms[i]->description);
    printf("  North: %s\n", rooms[i]->north != NULL ? rooms[i]->north->description : "None");
    printf("  East: %s\n", rooms[i]->east != NULL ? rooms[i]->east->description : "None");
    printf("  South: %s\n", rooms[i]->south != NULL ? rooms[i]->south->description : "None");
    printf("  West: %s\n", rooms[i]->west != NULL ? rooms[i]->west->description : "None");
    printf("  Monster: %s\n", rooms[i]->monster != NULL ? rooms[i]->monster->name : "None");
    printf("\n");
  }
}

int main() {
  srand(time(NULL));

  create_rooms();
  print_rooms();

  return 0;
}