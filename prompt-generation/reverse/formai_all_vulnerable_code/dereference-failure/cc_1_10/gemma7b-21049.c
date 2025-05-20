//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void maze_finder(int **maze, int x, int y) {
  if (maze[x][y] == 2) {
    return;
  }

  maze[x][y] = 2;

  if (x - 1 >= 0 && maze[x - 1][y] == 0) {
    maze_finder(maze, x - 1, y);
  }

  if (x + 1 < MAX && maze[x + 1][y] == 0) {
    maze_finder(maze, x + 1, y);
  }

  if (y - 1 >= 0 && maze[x][y - 1] == 0) {
    maze_finder(maze, x, y - 1);
  }

  if (y + 1 < MAX && maze[x][y + 1] == 0) {
    maze_finder(maze, x, y + 1);
  }
}

int main() {
  int maze[MAX][MAX] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

  maze[2][2] = 2;
  maze[4][4] = 2;

  maze_finder(maze, 0, 0);

  for (int x = 0; x < MAX; x++) {
    for (int y = 0; y < MAX; y++) {
      printf("%d ", maze[x][y]);
    }
    printf("\n");
  }

  return 0;
}