//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

#define WALL 1
#define EMPTY 0

void drawMaze(int **maze) {
  for (int y = 0; y < MAZE_HEIGHT; y++) {
    for (int x = 0; x < MAZE_WIDTH; x++) {
      if (maze[y][x] == WALL) {
        printf("#");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

int main() {
  srand(time(NULL));

  int **maze = (int **)malloc(MAZE_HEIGHT * sizeof(int *));
  for (int y = 0; y < MAZE_HEIGHT; y++) {
    maze[y] = (int *)malloc(MAZE_WIDTH * sizeof(int));
  }

  for (int y = 0; y < MAZE_HEIGHT; y++) {
    for (int x = 0; x < MAZE_WIDTH; x++) {
      maze[y][x] = EMPTY;
    }
  }

  // Dig random passages
  for (int i = 0; i < 50; i++) {
    int x1 = rand() % MAZE_WIDTH;
    int y1 = rand() % MAZE_HEIGHT;
    int x2 = rand() % MAZE_WIDTH;
    int y2 = rand() % MAZE_HEIGHT;

    if (x1 != x2 || y1 != y2) {
      maze[y1][x1] = WALL;
      maze[y2][x2] = WALL;
    }
  }

  drawMaze(maze);

  free(maze);

  return 0;
}