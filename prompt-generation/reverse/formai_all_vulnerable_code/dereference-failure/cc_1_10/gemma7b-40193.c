//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

#define EMPTY 0
#define WALL 1
#define PLAYER 2
#define GOAL 3

void generateMaze(int **maze, int w, int h) {
  srand(time(NULL));
  for (int r = 0; r < h; r++) {
    for (int c = 0; c < w; c++) {
      maze[r][c] = EMPTY;
    }
  }

  // Create walls
  for (int r = 0; r < h; r++) {
    for (int c = 0; c < w; c++) {
      if (r == 0 || r == h - 1) {
        maze[r][c] = WALL;
      } else if (c == 0 || c == w - 1) {
        maze[r][c] = WALL;
      }
    }
  }

  // Create the player and goal positions
  maze[5][5] = PLAYER;
  maze[2][2] = GOAL;
}

int main() {
  int **maze = NULL;
  maze = (int **)malloc(HEIGHT * sizeof(int *));
  for (int i = 0; i < HEIGHT; i++) {
    maze[i] = (int *)malloc(WIDTH * sizeof(int));
  }

  generateMaze(maze, WIDTH, HEIGHT);

  for (int r = 0; r < HEIGHT; r++) {
    for (int c = 0; c < WIDTH; c++) {
      printf("%d ", maze[r][c]);
    }
    printf("\n");
  }

  free(maze);
  return 0;
}