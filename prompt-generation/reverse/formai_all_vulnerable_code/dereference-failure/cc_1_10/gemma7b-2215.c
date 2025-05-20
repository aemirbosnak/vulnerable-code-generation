//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: asynchronous
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

#define EMPTY 0
#define WALL 1
#define PATH 2

void generate_maze(int **maze, int w, int h) {
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      maze[y][x] = EMPTY;
    }
  }

  int num_walls = 50;
  for (int i = 0; i < num_walls; i++) {
    int x = rand() % w;
    int y = rand() % h;

    if (maze[y][x] == EMPTY) {
      maze[y][x] = WALL;
    }
  }

  int num_paths = 10;
  for (int i = 0; i < num_paths; i++) {
    int x = rand() % w;
    int y = rand() % h;

    if (maze[y][x] == EMPTY) {
      maze[y][x] = PATH;
    }
  }
}

int main() {
  int **maze = (int **)malloc(HEIGHT * sizeof(int *));
  for (int i = 0; i < HEIGHT; i++) {
    maze[i] = (int *)malloc(WIDTH * sizeof(int));
  }

  generate_maze(maze, WIDTH, HEIGHT);

  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      printf("%d ", maze[y][x]);
    }
    printf("\n");
  }

  free(maze);

  return 0;
}