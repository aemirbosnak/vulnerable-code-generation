//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

#define WALL 1
#define EMPTY 0

void generate_maze(int **maze, int w, int h) {
  int x, y;
  srand(time(NULL));

  for (x = 0; x < w; x++) {
    for (y = 0; y < h; y++) {
      maze[x][y] = EMPTY;
    }
  }

  for (x = 0; x < w; x++) {
    for (y = 0; y < h; y++) {
      if (x == 0 || y == 0 || x == w - 1 || y == h - 1) {
        maze[x][y] = WALL;
      } else {
        maze[x][y] = EMPTY + rand() % 2;
      }
    }
  }
}

void print_maze(int **maze, int w, int h) {
  int x, y;

  for (x = 0; x < w; x++) {
    for (y = 0; y < h; y++) {
      printf("%c ", maze[x][y] == WALL ? '#' : '.');
    }
    printf("\n");
  }
}

int main() {
  int **maze;
  int w, h;

  w = MAZE_WIDTH;
  h = MAZE_HEIGHT;

  maze = (int**)malloc(w * sizeof(int*));
  for (int i = 0; i < w; i++) {
    maze[i] = (int*)malloc(h * sizeof(int));
  }

  generate_maze(maze, w, h);
  print_maze(maze, w, h);

  return 0;
}