//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void createMaze(int **maze, int size) {
  for (int i = 0; i < size; i++) {
    maze[i] = (int *)malloc(size * sizeof(int));
    for (int j = 0; j < size; j++) {
      maze[i][j] = 0;
    }
  }
}

void printMaze(int **maze, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%d ", maze[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int size = 5;
  int **maze = NULL;

  createMaze(&maze, size);

  // Draw the maze
  printMaze(maze, size);

  // Find the route
  int x = 0, y = 0, target_x = 2, target_y = 2;
  int direction = 0; // 0: up, 1: right, 2: down, 3: left

  while (x != target_x || y != target_y) {
    switch (direction) {
      case 0:
        maze[x][y] = 1;
        y--;
        break;
      case 1:
        maze[x][y] = 1;
        x++;
        break;
      case 2:
        maze[x][y] = 1;
        y++;
        break;
      case 3:
        maze[x][y] = 1;
        x--;
        break;
    }

    printMaze(maze, size);

    direction = (direction + 1) % 4;
  }

  return 0;
}