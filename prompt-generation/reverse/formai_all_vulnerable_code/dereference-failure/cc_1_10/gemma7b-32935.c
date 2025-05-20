//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

typedef struct Room {
  int x, y;
  struct Room* north, *south, *east, *west;
} Room;

Room* createRoom(int x, int y) {
  Room* room = malloc(sizeof(Room));
  room->x = x;
  room->y = y;
  room->north = NULL;
  room->south = NULL;
  room->east = NULL;
  room->west = NULL;
  return room;
}

void generateMap() {
  srand(time(NULL));
  int map[MAP_HEIGHT][MAP_WIDTH] = {{0}};
  for (int y = 0; y < MAP_HEIGHT; y++) {
    for (int x = 0; x < MAP_WIDTH; x++) {
      map[y][x] = rand() % 3;
    }
  }

  // Connect rooms
  Room* rooms = createRoom(0, 0);
  rooms->north = createRoom(0, 1);
  rooms->east = createRoom(1, 0);
  rooms->south = createRoom(0, -1);
  rooms->west = createRoom(-1, 0);

  // Print the map
  for (int y = 0; y < MAP_HEIGHT; y++) {
    for (int x = 0; x < MAP_WIDTH; x++) {
      switch (map[y][x]) {
        case 0:
          printf(" ");
          break;
        case 1:
          printf("O");
          break;
        case 2:
          printf("#");
          break;
      }
    }
    printf("\n");
  }
}

int main() {
  generateMap();
  return 0;
}