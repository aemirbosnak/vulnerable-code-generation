//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: Linus Torvalds
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

#define WALL_CHAR '#'
#define EMPTY_CHAR '.'

int main() {
  int x, y;
  time_t t;

  // Generate a seed for randomness
  t = time(NULL);
  srand(t);

  // Create a 2D array for the maze
  char **maze = malloc(HEIGHT * sizeof(char *));
  for (y = 0; y < HEIGHT; y++) {
    maze[y] = malloc(WIDTH * sizeof(char));
  }

  // Dig random holes in the maze
  for (x = 0; x < WIDTH; x++) {
    for (y = 0; y < HEIGHT; y++) {
      if (rand() % 5 == 0) {
        maze[y][x] = EMPTY_CHAR;
      } else {
        maze[y][x] = WALL_CHAR;
      }
    }
  }

  // Draw the maze
  for (y = 0; y < HEIGHT; y++) {
    for (x = 0; x < WIDTH; x++) {
      printf("%c ", maze[y][x]);
    }
    printf("\n");
  }

  // Free the memory
  for (y = 0; y < HEIGHT; y++) {
    free(maze[y]);
  }
  free(maze);

  return 0;
}