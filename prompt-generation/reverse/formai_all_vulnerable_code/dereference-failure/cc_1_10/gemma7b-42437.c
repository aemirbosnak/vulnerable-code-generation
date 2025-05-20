//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

#define WALL_CHAR '#'
#define EMPTY_CHAR '.'

void generateMaze(int **maze, int width, int height) {
  int x, y;
  srand(time(NULL));

  for (x = 0; x < width; x++) {
    for (y = 0; y < height; y++) {
      maze[x][y] = EMPTY_CHAR;
    }
  }

  // Create random walls
  for (x = 0; x < width; x++) {
    for (y = 0; y < height; y++) {
      if (rand() % 5 == 0) {
        maze[x][y] = WALL_CHAR;
      }
    }
  }
}

int main() {
  int **maze;
  int width, height;

  width = MAZE_WIDTH;
  height = MAZE_HEIGHT;

  maze = (int *)malloc(width * height * sizeof(int));
  generateMaze(maze, width, height);

  // Print the maze
  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      printf("%c ", maze[x][y]);
    }
    printf("\n");
  }

  return 0;
}