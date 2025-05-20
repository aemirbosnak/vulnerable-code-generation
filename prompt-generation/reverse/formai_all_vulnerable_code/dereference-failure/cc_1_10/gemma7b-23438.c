//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: interoperable
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

#define WALL 1
#define EMPTY 0

int main() {
  int **maze = NULL;
  int x, y, seed, generated = 0;

  // Allocate memory for the maze
  maze = (int **)malloc(HEIGHT * sizeof(int *));
  for (y = 0; y < HEIGHT; y++) {
    maze[y] = (int *)malloc(WIDTH * sizeof(int));
  }

  // Seed the random number generator
  srand(time(NULL));

  // Generate the maze
  while (!generated) {
    seed = rand() % 10;
    for (x = 0; x < WIDTH; x++) {
      for (y = 0; y < HEIGHT; y++) {
        maze[y][x] = EMPTY;
      }
    }

    // Create a wall randomly
    maze[rand() % HEIGHT][rand() % WIDTH] = WALL;

    // Check if the generated maze is valid
    if (valid(maze)) {
      generated = 1;
    }
  }

  // Print the maze
  for (y = 0; y < HEIGHT; y++) {
    for (x = 0; x < WIDTH; x++) {
      printf("%d ", maze[y][x]);
    }
    printf("\n");
  }

  // Free the memory allocated for the maze
  for (y = 0; y < HEIGHT; y++) {
    free(maze[y]);
  }
  free(maze);

  return 0;
}

int valid(int **maze) {
  int x, y;

  // Check if the maze is bordered by walls
  for (x = 0; x < WIDTH; x++) {
    maze[0][x] = WALL;
    maze[HEIGHT - 1][x] = WALL;
  }

  // Check if the maze has any closed loops
  for (x = 0; x < WIDTH; x++) {
    for (y = 0; y < HEIGHT; y++) {
      if (maze[y][x] == WALL && (maze[y - 1][x] == WALL || maze[y + 1][x] == WALL || maze[y][x - 1] == WALL || maze[y][x + 1] == WALL)) {
        return 0;
      }
    }
  }

  return 1;
}