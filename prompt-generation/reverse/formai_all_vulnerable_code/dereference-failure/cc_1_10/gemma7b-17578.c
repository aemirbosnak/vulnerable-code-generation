//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

#define EMPTY 0
#define WALL 1
#define PATH 2

void generate_maze(int **maze, int w, int h) {
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      maze[y][x] = EMPTY;
    }
  }

  // Create walls
  maze[5][10] = WALL;
  maze[10][10] = WALL;
  maze[15][10] = WALL;
  maze[10][15] = WALL;

  // Create the path
  maze[12][12] = PATH;
  maze[13][12] = PATH;
  maze[13][13] = PATH;
  maze[12][13] = PATH;
}

int main() {
  int **maze = NULL;
  int w = MAZE_WIDTH;
  int h = MAZE_HEIGHT;

  maze = (int **)malloc(h * sizeof(int *));
  for (int i = 0; i < h; i++) {
    maze[i] = (int *)malloc(w * sizeof(int));
  }

  generate_maze(maze, w, h);

  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      switch (maze[y][x]) {
        case EMPTY:
          printf(" ");
          break;
        case WALL:
          printf("#");
          break;
        case PATH:
          printf("o");
          break;
      }
    }
    printf("\n");
  }

  return 0;
}