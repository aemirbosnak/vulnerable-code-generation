//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: future-proof
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_ROOMS 10

typedef struct Room {
  int x, y;
  struct Room* north, *south, *east, *west;
} Room;

Room** generateMaze(int size) {
  srand(time(NULL));
  Room** maze = malloc(size * sizeof(Room*));
  for (int i = 0; i < size; i++) {
    maze[i] = malloc(sizeof(Room));
    maze[i]->x = rand() % size;
    maze[i]->y = rand() % size;
    maze[i]->north = NULL;
    maze[i]->south = NULL;
    maze[i]->east = NULL;
    maze[i]->west = NULL;
  }

  for (int i = 0; i < size; i++) {
    Room* r1 = maze[i];
    if (r1->x - 1 >= 0)
      r1->north = maze[rand() % MAX_ROOMS];
    if (r1->x + 1 < size)
      r1->east = maze[rand() % MAX_ROOMS];
    if (r1->y - 1 >= 0)
      r1->south = maze[rand() % MAX_ROOMS];
    if (r1->y + 1 < size)
      r1->west = maze[rand() % MAX_ROOMS];
  }

  return maze;
}

int main() {
  int size = 10;
  Room** maze = generateMaze(size);

  for (int i = 0; i < size; i++) {
    Room* r = maze[i];
    printf("(%d, %d)\n", r->x, r->y);
  }

  return 0;
}