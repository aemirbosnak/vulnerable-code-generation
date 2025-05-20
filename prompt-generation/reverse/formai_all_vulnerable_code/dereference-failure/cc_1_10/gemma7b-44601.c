//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

#define EMPTY 0
#define WALL 1
#define PLAYER 2

void generateMaze(int **maze, int w, int h) {
  int x, y;
  srand(time(NULL));

  for (x = 0; x < w; x++) {
    for (y = 0; y < h; y++) {
      maze[x][y] = EMPTY;
    }
  }

  for (x = 0; x < w; x++) {
    for (y = 0; y < h; y++) {
      if (rand() % 2) {
        maze[x][y] = WALL;
      }
    }
  }

  maze[0][0] = PLAYER;
}

int main() {
  int **maze;
  maze = (int **)malloc(MAZE_WIDTH * sizeof(int *));
  for (int i = 0; i < MAZE_WIDTH; i++) {
    maze[i] = (int *)malloc(MAZE_HEIGHT * sizeof(int));
  }

  generateMaze(maze, MAZE_WIDTH, MAZE_HEIGHT);

  for (int x = 0; x < MAZE_WIDTH; x++) {
    for (int y = 0; y < MAZE_HEIGHT; y++) {
      printf("%d ", maze[x][y]);
    }
    printf("\n");
  }

  return 0;
}