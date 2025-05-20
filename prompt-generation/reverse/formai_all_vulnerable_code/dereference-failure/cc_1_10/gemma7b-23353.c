//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: modular
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 20
#define MAX_PATHS 10

typedef struct Room {
  int num;
  struct Room* north;
  struct Room* south;
  struct Room* east;
  struct Room* west;
} Room;

Room* generate_room(int num) {
  Room* room = malloc(sizeof(Room));
  room->num = num;
  room->north = NULL;
  room->south = NULL;
  room->east = NULL;
  room->west = NULL;
  return room;
}

void generate_maze(int numRooms) {
  srand(time(NULL));

  Room** rooms = malloc(numRooms * sizeof(Room*));
  for (int i = 0; i < numRooms; i++) {
    rooms[i] = generate_room(i + 1);
  }

  for (int i = 0; i < numRooms - 1; i++) {
    int direction = rand() % 4;
    switch (direction) {
      case 0:
        rooms[i]->north = rooms[i + 1];
        break;
      case 1:
        rooms[i]->south = rooms[i + 1];
        break;
      case 2:
        rooms[i]->east = rooms[i + 1];
        break;
      case 3:
        rooms[i]->west = rooms[i + 1];
        break;
    }
  }

  free(rooms);
}

int main() {
  generate_maze(MAX_ROOMS);
  return 0;
}