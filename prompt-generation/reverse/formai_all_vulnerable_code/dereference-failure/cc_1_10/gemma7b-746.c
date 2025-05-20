//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Ada Lovelace
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

typedef struct Room {
  int x, y;
  struct Room* north, *south, *east, *west;
} Room;

Room** generateRooms(int numRooms) {
  srand(time(NULL));
  Room** rooms = malloc(numRooms * sizeof(Room*));
  for (int i = 0; i < numRooms; i++) {
    rooms[i] = malloc(sizeof(Room));
    rooms[i]->x = rand() % WIDTH;
    rooms[i]->y = rand() % HEIGHT;
    rooms[i]->north = NULL;
    rooms[i]->south = NULL;
    rooms[i]->east = NULL;
    rooms[i]->west = NULL;
  }
  return rooms;
}

void connectRooms(Room** rooms, int numRooms) {
  for (int i = 0; i < numRooms; i++) {
    int direction = rand() % 4;
    switch (direction) {
      case 0:
        rooms[i]->north = rooms[rand() % numRooms];
        break;
      case 1:
        rooms[i]->south = rooms[rand() % numRooms];
        break;
      case 2:
        rooms[i]->east = rooms[rand() % numRooms];
        break;
      case 3:
        rooms[i]->west = rooms[rand() % numRooms];
        break;
    }
  }
}

void printRooms(Room** rooms, int numRooms) {
  for (int i = 0; i < numRooms; i++) {
    printf("Room %d: (%d, %d)\n", i, rooms[i]->x, rooms[i]->y);
  }
}

int main() {
  int numRooms = 10;
  Room** rooms = generateRooms(numRooms);
  connectRooms(rooms, numRooms);
  printRooms(rooms, numRooms);
  return 0;
}