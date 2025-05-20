//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 20
#define HEIGHT 20

#define EMPTY 0
#define WALL 1
#define PATH 2

int main() {
  int x, y, z;
  int **maze = NULL;

  maze = malloc(HEIGHT * sizeof(int *) + HEIGHT);
  for (y = 0; y < HEIGHT; y++) {
    maze[y] = malloc(WIDTH * sizeof(int) + WIDTH);
    for (x = 0; x < WIDTH; x++) {
      maze[y][x] = EMPTY;
    }
  }

  // Seed the random number generator
  srand(time(NULL));

  // Generate the maze
  for (z = 0; z < 10; z++) {
    x = rand() % WIDTH;
    y = rand() % HEIGHT;
    if (maze[y][x] == EMPTY) {
      maze[y][x] = WALL;
    }
  }

  // Draw the maze
  for (y = 0; y < HEIGHT; y++) {
    for (x = 0; x < WIDTH; x++) {
      switch (maze[y][x]) {
        case EMPTY:
          printf(" ");
          break;
        case WALL:
          printf("#");
          break;
        case PATH:
          printf(".");
          break;
      }
    }
    printf("\n");
  }

  return 0;
}