//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: inquisitive
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_PATHS 5

typedef struct Room {
  int x, y;
  struct Room* north, *south, *east, *west;
} Room;

Room** generate_maze(int numRooms) {
  srand(time(NULL));
  Room** rooms = malloc(numRooms * sizeof(Room*));
  for (int i = 0; i < numRooms; i++) {
    rooms[i] = malloc(sizeof(Room));
    rooms[i]->x = rand() % MAX_ROOMS;
    rooms[i]->y = rand() % MAX_ROOMS;
    rooms[i]->north = NULL;
    rooms[i]->south = NULL;
    rooms[i]->east = NULL;
    rooms[i]->west = NULL;
  }

  for (int i = 0; i < numRooms; i++) {
    int numPaths = rand() % MAX_PATHS;
    for (int j = 0; j < numPaths; j++) {
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

  return rooms;
}

int main() {
  Room** maze = generate_maze(10);
  for (int i = 0; i < 10; i++) {
    printf("Room %d: (%d, %d)\n", i, maze[i]->x, maze[i]->y);
  }

  return 0;
}