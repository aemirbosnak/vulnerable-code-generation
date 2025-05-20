//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: scalable
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_PATHS 5

typedef struct Room {
  int x, y;
  struct Room* north, *south, *east, *west;
} Room;

Room** generateMaze(int size) {
  Room** maze = malloc(size * sizeof(Room*));
  for (int i = 0; i < size; i++) {
    maze[i] = malloc(sizeof(Room));
    maze[i]->x = -1;
    maze[i]->y = -1;
    maze[i]->north = NULL;
    maze[i]->south = NULL;
    maze[i]->east = NULL;
    maze[i]->west = NULL;
  }

  return maze;
}

void connectRooms(Room** maze) {
  srand(time(NULL));
  for (int i = 0; i < MAX_ROOMS; i++) {
    int n = rand() % MAX_PATHS;
    switch (n) {
      case 0:
        maze[i]->north = maze[rand() % MAX_ROOMS];
        break;
      case 1:
        maze[i]->south = maze[rand() % MAX_ROOMS];
        break;
      case 2:
        maze[i]->east = maze[rand() % MAX_ROOMS];
        break;
      case 3:
        maze[i]->west = maze[rand() % MAX_ROOMS];
        break;
    }
  }
}

int main() {
  int size = 10;
  Room** maze = generateMaze(size);
  connectRooms(maze);

  return 0;
}