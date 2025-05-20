//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

#define WALL 1
#define EMPTY 0

void generateMaze(int **maze, int w, int h) {
  int i, j, r, c, n, p;
  srand(time(NULL));

  for (i = 0; i < h; i++) {
    for (j = 0; j < w; j++) {
      maze[i][j] = EMPTY;
    }
  }

  n = (w * h) / 2;
  p = rand() % n;

  for (r = 0; r < p; r++) {
    i = rand() % h;
    j = rand() % w;
    if (maze[i][j] == EMPTY) {
      maze[i][j] = WALL;
    }
  }
}

int main() {
  int **maze;
  maze = (int **)malloc(HEIGHT * sizeof(int *));
  for (int i = 0; i < HEIGHT; i++) {
    maze[i] = (int *)malloc(WIDTH * sizeof(int));
  }

  generateMaze(maze, WIDTH, HEIGHT);

  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      printf("%d ", maze[i][j]);
    }
    printf("\n");
  }

  return 0;
}