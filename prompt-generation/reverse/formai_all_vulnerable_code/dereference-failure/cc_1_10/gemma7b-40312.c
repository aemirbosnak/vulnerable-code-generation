//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 21
#define MAZE_HEIGHT 11

void generateMaze(int **maze, int w, int h) {
  int i, j;
  srand(time(NULL));

  for (i = 0; i < h; i++) {
    for (j = 0; j < w; j++) {
      maze[i][j] = rand() % 2;
    }
  }
}

void printMaze(int **maze, int w, int h) {
  int i, j;

  for (i = 0; i < h; i++) {
    for (j = 0; j < w; j++) {
      printf("%d ", maze[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int **maze = NULL;
  int w, h;

  w = MAZE_WIDTH;
  h = MAZE_HEIGHT;

  maze = (int **)malloc(h * sizeof(int *));
  for (int i = 0; i < h; i++) {
    maze[i] = (int *)malloc(w * sizeof(int));
  }

  generateMaze(maze, w, h);
  printMaze(maze, w, h);

  for (int i = 0; i < h; i++) {
    free(maze[i]);
  }
  free(maze);

  return 0;
}