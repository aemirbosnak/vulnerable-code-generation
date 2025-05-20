//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 10
#define WALL_CHAR '#'
#define EMPTY_CHAR ' '

void generate_maze(int **maze, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      maze[i][j] = EMPTY_CHAR;
    }
  }

  // Create a random number of walls
  int num_walls = rand() % 5 + 1;

  // Place the walls
  for (int k = 0; k < num_walls; k++) {
    int x = rand() % size;
    int y = rand() % size;

    maze[x][y] = WALL_CHAR;
  }

  // Connect the walls
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (maze[i][j] == WALL_CHAR) {
        // Connect the wall to the north, south, east, west
        if (i > 0 && maze[i - 1][j] == EMPTY_CHAR) {
          maze[i - 1][j] = WALL_CHAR;
        }
        if (i < size - 1 && maze[i + 1][j] == EMPTY_CHAR) {
          maze[i + 1][j] = WALL_CHAR;
        }
        if (j > 0 && maze[i][j - 1] == EMPTY_CHAR) {
          maze[i][j - 1] = WALL_CHAR;
        }
        if (j < size - 1 && maze[i][j + 1] == EMPTY_CHAR) {
          maze[i][j + 1] = WALL_CHAR;
        }
      }
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

  generate_maze(maze, size);

  // Print the maze
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%c ", maze[i][j]);
    }
    printf("\n");
  }

  return 0;
}