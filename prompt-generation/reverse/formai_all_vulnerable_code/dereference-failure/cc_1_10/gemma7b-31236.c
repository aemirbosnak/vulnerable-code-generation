//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 20

typedef struct Room {
  int x, y;
  struct Room* north, *south, *east, *west;
  char name[20];
} Room;

Room** create_map(int size) {
  Room** map = malloc(size * sizeof(Room*));
  for (int i = 0; i < size; i++) {
    map[i] = malloc(sizeof(Room));
    map[i]->x = -1;
    map[i]->y = -1;
    map[i]->north = NULL;
    map[i]->south = NULL;
    map[i]->east = NULL;
    map[i]->west = NULL;
  }
  return map;
}

void place_rooms(Room** map, int num_rooms) {
  for (int i = 0; i < num_rooms; i++) {
    map[rand() % MAP_SIZE]->x = rand() % MAP_SIZE;
    map[rand() % MAP_SIZE]->y = rand() % MAP_SIZE;
  }
}

void connect_rooms(Room** map, int num_rooms) {
  for (int i = 0; i < num_rooms; i++) {
    int direction = rand() % 4;
    switch (direction) {
      case 0:
        map[i]->north = map[rand() % num_rooms];
        break;
      case 1:
        map[i]->south = map[rand() % num_rooms];
        break;
      case 2:
        map[i]->east = map[rand() % num_rooms];
        break;
      case 3:
        map[i]->west = map[rand() % num_rooms];
        break;
    }
  }
}

int main() {
  srand(time(NULL));

  int num_rooms = 10;
  Room** map = create_map(MAP_SIZE);
  place_rooms(map, num_rooms);
  connect_rooms(map, num_rooms);

  // Traverse the map and print the rooms
  for (int i = 0; i < num_rooms; i++) {
    printf("Room %d: (%d, %d), name: %s\n", i, map[i]->x, map[i]->y, map[i]->name);
  }

  return 0;
}