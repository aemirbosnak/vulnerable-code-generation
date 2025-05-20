//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 50
#define MAZE_HEIGHT 50

#define WALL_CHAR '#'
#define EMPTY_CHAR '.'

void generate_maze(int **maze, int width, int height) {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      maze[y][x] = EMPTY_CHAR;
    }
  }

  int num_walls = 50;
  for (int i = 0; i < num_walls; i++) {
    int x = rand() % width;
    int y = rand() % height;

    if (maze[y][x] == EMPTY_CHAR) {
      maze[y][x] = WALL_CHAR;
    }
  }

  maze[0][0] = maze[0][width - 1] = WALL_CHAR;
  maze[height - 1][0] = maze[height - 1][width - 1] = WALL_CHAR;
}

int main() {
  int **maze = NULL;
  int width = MAZE_WIDTH;
  int height = MAZE_HEIGHT;

  maze = (int**)malloc(height * sizeof(int*));
  for (int i = 0; i < height; i++) {
    maze[i] = (int*)malloc(width * sizeof(int));
  }

  generate_maze(maze, width, height);

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      printf("%c ", maze[y][x]);
    }
    printf("\n");
  }

  free(maze);

  return 0;
}