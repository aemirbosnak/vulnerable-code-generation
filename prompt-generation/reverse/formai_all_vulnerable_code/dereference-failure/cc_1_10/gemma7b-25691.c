//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_PATHS 5

typedef struct Room {
  int x, y;
  struct Room* north, *south, *east, *west;
} Room;

Room** generateMaze(int size) {
  srand(time(NULL));
  Room** maze = malloc(size * sizeof(Room*));
  for (int i = 0; i < size; i++) {
    maze[i] = malloc(sizeof(Room));
    maze[i]->x = i;
    maze[i]->y = 0;
    maze[i]->north = NULL;
    maze[i]->south = NULL;
    maze[i]->east = NULL;
    maze[i]->west = NULL;
  }

  for (int i = 0; i < size; i++) {
    int num_paths = rand() % MAX_PATHS;
    for (int j = 0; j < num_paths; j++) {
      switch (rand() % 4) {
        case 0:
          maze[i]->north = maze[rand() % size];
          break;
        case 1:
          maze[i]->south = maze[rand() % size];
          break;
        case 2:
          maze[i]->east = maze[rand() % size];
          break;
        case 3:
          maze[i]->west = maze[rand() % size];
          break;
      }
    }
  }

  return maze;
}

int main() {
  Room** maze = generateMaze(10);

  for (int i = 0; i < 10; i++) {
    printf("Room %d: (%d, %d)\n", maze[i]->x, maze[i]->y);
    if (maze[i]->north) printf("North: Room %d\n", maze[i]->north->x);
    if (maze[i]->south) printf("South: Room %d\n", maze[i]->south->x);
    if (maze[i]->east) printf("East: Room %d\n", maze[i]->east->x);
    if (maze[i]->west) printf("West: Room %d\n", maze[i]->west->x);
  }

  return 0;
}