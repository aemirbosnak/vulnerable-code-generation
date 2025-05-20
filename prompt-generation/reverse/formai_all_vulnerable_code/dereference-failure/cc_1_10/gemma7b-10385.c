//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: visionary
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

#define WALL 1
#define EMPTY 0

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
      if (x == 0 || y == 0 || x == w - 1 || y == h - 1) {
        maze[x][y] = WALL;
      } else {
        if (rand() % 2 == 0) {
          maze[x][y] = WALL;
        }
      }
    }
  }
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