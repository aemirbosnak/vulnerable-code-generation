//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void generateMaze(int **maze, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      maze[i][j] = rand() % 2;
    }
  }
}

int main() {
  int n = 10;
  int **maze = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    maze[i] = (int *)malloc(n * sizeof(int));
  }

  generateMaze(maze, n);

  int x = 0, y = 0, goalx = 9, goaly = 9;
  maze[x][y] = 1;

  while (x != goalx || y != goaly) {
    int direction = rand() % 4;
    switch (direction) {
      case 0:
        y++;
        break;
      case 1:
        x++;
        break;
      case 2:
        y--;
        break;
      case 3:
        x--;
        break;
    }

    if (maze[x][y] == 0) {
      maze[x][y] = 1;
    }
  }

  printf("The path is: (%d, %d) - ", x, y);
  printf("(%d, %d)\n", goalx, goaly);

  free(maze);

  return 0;
}