//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: light-weight
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

#define WALL_CHAR '#'
#define EMPTY_CHAR '.'

void generate_maze(int **maze, int w, int h) {
  int x, y;
  srand(time(NULL));

  for (x = 0; x < w; x++) {
    for (y = 0; y < h; y++) {
      maze[x][y] = EMPTY_CHAR;
    }
  }

  for (x = 0; x < w; x++) {
    for (y = 0; y < h; y++) {
      if (rand() % 2) {
        maze[x][y] = WALL_CHAR;
      }
    }
  }
}

int main() {
  int **maze;
  int w, h;

  w = MAZE_WIDTH;
  h = MAZE_HEIGHT;

  maze = (int **)malloc(w * sizeof(int *) + h * sizeof(int));
  for (int i = 0; i < w; i++) {
    maze[i] = (int *)malloc(h * sizeof(int));
  }

  generate_maze(maze, w, h);

  // Print the maze
  for (int x = 0; x < w; x++) {
    for (int y = 0; y < h; y++) {
      printf("%c ", maze[x][y]);
    }
    printf("\n");
  }

  return 0;
}