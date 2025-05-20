//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

#define EMPTY 0
#define WALL 1
#define VISITED 2

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Create the maze
  int **maze = (int **)malloc(HEIGHT * sizeof(int *));
  for (int i = 0; i < HEIGHT; i++) {
    maze[i] = (int *)malloc(WIDTH * sizeof(int));
    for (int j = 0; j < WIDTH; j++) {
      maze[i][j] = EMPTY;
    }
  }

  // Randomly create walls
  for (int i = 0; i < 10; i++) {
    int x = rand() % WIDTH;
    int y = rand() % HEIGHT;
    maze[y][x] = WALL;
  }

  // Mark a path
  maze[10][10] = VISITED;

  // Print the maze
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      printf("%d ", maze[i][j]);
    }
    printf("\n");
  }

  // Free the memory
  for (int i = 0; i < HEIGHT; i++) {
    free(maze[i]);
  }
  free(maze);

  return 0;
}