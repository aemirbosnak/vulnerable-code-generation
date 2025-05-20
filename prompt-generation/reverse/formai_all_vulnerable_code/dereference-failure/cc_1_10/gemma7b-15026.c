//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 10
#define WALL_CHAR '#'
#define EMPTY_CHAR '.'

void createMaze(int **maze, int size) {
  for (int r = 0; r < size; r++) {
    for (int c = 0; c < size; c++) {
      maze[r][c] = EMPTY_CHAR;
    }
  }

  // Create random walls
  for (int i = 0; i < 50; i++) {
    int r = rand() % size;
    int c = rand() % size;
    maze[r][c] = WALL_CHAR;
  }
}

void traverseMaze(int **maze, int size) {
  int x = 0, y = 0, direction = 0;
  maze[x][y] = '@';

  while (x != size - 1 || y != size - 1) {
    switch (direction) {
      case 0:
        x++;
        break;
      case 1:
        y++;
        break;
      case 2:
        x--;
        break;
      case 3:
        y--;
        break;
    }

    if (maze[x][y] == WALL_CHAR) {
      direction = (direction + 1) % 4;
    } else if (maze[x][y] == EMPTY_CHAR) {
      maze[x][y] = '@';
    }
  }
}

int main() {
  int **maze = NULL;
  int size = MAZE_SIZE;

  maze = (int **)malloc(size * sizeof(int *));
  for (int i = 0; i < size; i++) {
    maze[i] = (int *)malloc(size * sizeof(int));
  }

  createMaze(maze, size);
  traverseMaze(maze, size);

  for (int r = 0; r < size; r++) {
    for (int c = 0; c < size; c++) {
      printf("%c ", maze[r][c]);
    }
    printf("\n");
  }

  return 0;
}