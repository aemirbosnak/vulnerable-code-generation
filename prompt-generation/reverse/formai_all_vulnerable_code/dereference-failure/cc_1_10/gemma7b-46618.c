//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

#define WALL 1
#define EMPTY 0

void generateMaze(int **maze, int w, int h) {
  int i, j;
  srand(time(NULL));
  for (i = 0; i < h; i++) {
    for (j = 0; j < w; j++) {
      maze[i][j] = EMPTY;
    }
  }

  for (i = 0; i < 5; i++) {
    int x = rand() % w;
    int y = rand() % h;
    maze[y][x] = WALL;
  }

  maze[0][0] = WALL;
  maze[0][w - 1] = WALL;
  maze[h - 1][0] = WALL;
  maze[h - 1][w - 1] = WALL;
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

  free(maze);
  return 0;
}