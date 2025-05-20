//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

void findRoute(int **maze, int x, int y, int targetX, int targetY) {
  if (maze[x][y] == targetX && maze[x][y] == targetY) {
    return;
  }
  if (maze[x][y] == -1) {
    return;
  }
  maze[x][y] = -1;
  findRoute(maze, x - 1, y, targetX, targetY);
  findRoute(maze, x + 1, y, targetX, targetY);
  findRoute(maze, x, y - 1, targetX, targetY);
  findRoute(maze, x, y + 1, targetX, targetY);
}

int main() {
  int **maze = NULL;
  int x, y, targetX, targetY;

  printf("Enter the number of rows: ");
  scanf("%d", &x);

  printf("Enter the number of columns: ");
  scanf("%d", &y);

  printf("Enter the target X: ");
  scanf("%d", &targetX);

  printf("Enter the target Y: ");
  scanf("%d", &targetY);

  maze = (int **)malloc(x * sizeof(int *));
  for (int i = 0; i < x; i++) {
    maze[i] = (int *)malloc(y * sizeof(int));
  }

  // Populate the maze
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      scanf("%d", &maze[i][j]);
    }
  }

  findRoute(maze, 0, 0, targetX, targetY);

  // Print the route
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      printf("%d ", maze[i][j]);
    }
    printf("\n");
  }

  return 0;
}