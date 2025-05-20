//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAZE_SIZE 10

#define EMPTY 0
#define WALL 1
#define PATH 2

void generateMaze(int **maze, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      maze[i][j] = EMPTY;
    }
  }

  int numWalls = size * size / 4;
  for (int i = 0; i < numWalls; i++) {
    int x = rand() % size;
    int y = rand() % size;
    if (maze[x][y] == EMPTY) {
      maze[x][y] = WALL;
    }
  }

  int startx = rand() % size;
  int starty = rand() % size;
  maze[startx][starty] = PATH;
}

int main() {
  int **maze = NULL;
  generateMaze(maze, MAZE_SIZE);

  for (int i = 0; i < MAZE_SIZE; i++) {
    for (int j = 0; j < MAZE_SIZE; j++) {
      switch (maze[i][j]) {
        case EMPTY:
          printf(" ");
          break;
        case WALL:
          printf("#");
          break;
        case PATH:
          printf("o");
          break;
      }
    }
    printf("\n");
  }

  return 0;
}