//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

void createMaze(int **maze, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      maze[i][j] = rand() % 2;
    }
  }
}

int main() {
  int size = MAX_SIZE;
  int **maze = NULL;
  maze = (int **)malloc(size * sizeof(int *));
  for (int i = 0; i < size; i++) {
    maze[i] = (int *)malloc(size * sizeof(int));
  }

  createMaze(maze, size);

  int x = 0, y = 0, target_x = size - 1, target_y = size - 1;

  // Traverse the maze
  while (x != target_x || y != target_y) {
    // Print the maze
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        printf("%d ", maze[i][j]);
      }
      printf("\n");
    }

    // Move in a random direction
    int direction = rand() % 4;

    switch (direction) {
      case 0:
        x--;
        break;
      case 1:
        y++;
        break;
      case 2:
        x++;
        break;
      case 3:
        y--;
        break;
    }

    // Check if the cell is valid
    if (maze[x][y] == 0) {
      x = target_x;
      y = target_y;
    }
  }

  // Print the final maze
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%d ", maze[i][j]);
    }
    printf("\n");
  }

  return 0;
}