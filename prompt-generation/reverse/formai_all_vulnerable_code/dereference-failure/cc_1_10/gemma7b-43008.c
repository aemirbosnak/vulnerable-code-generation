//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

#define EMPTY 0
#define WALL 1
#define VISITED 2

void generateMaze(int **maze, int w, int h) {
  int x, y, r, c;
  srand(time(NULL));

  for (x = 0; x < w; x++) {
    for (y = 0; y < h; y++) {
      maze[x][y] = EMPTY;
    }
  }

  for (r = 0; r < 10; r++) {
    x = rand() % w;
    y = rand() % h;

    if (maze[x][y] == EMPTY) {
      maze[x][y] = WALL;
    }
  }

  maze[0][0] = VISITED;
  maze[0][h - 1] = VISITED;
  maze[w - 1][0] = VISITED;
  maze[w - 1][h - 1] = VISITED;
}

void drawMaze(int **maze, int w, int h) {
  int x, y;

  for (x = 0; x < w; x++) {
    for (y = 0; y < h; y++) {
      switch (maze[x][y]) {
        case EMPTY:
          printf(" ");
          break;
        case WALL:
          printf("#");
          break;
        case VISITED:
          printf("$");
          break;
      }
    }
    printf("\n");
  }
}

int main() {
  int **maze;
  int w, h;

  w = WIDTH;
  h = HEIGHT;

  maze = (int **)malloc(w * sizeof(int *));
  for (int i = 0; i < w; i++) {
    maze[i] = (int *)malloc(h * sizeof(int));
  }

  generateMaze(maze, w, h);
  drawMaze(maze, w, h);

  return 0;
}