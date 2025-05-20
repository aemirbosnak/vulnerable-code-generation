//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

#define WALL_CHAR '#'
#define EMPTY_CHAR '.'
#define PATH_CHAR '*'

void generateMaze(int **maze, int width, int height) {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      maze[y][x] = EMPTY_CHAR;
    }
  }

  // Create walls
  maze[0][0] = maze[0][width - 1] = WALL_CHAR;
  maze[height - 1][0] = maze[height - 1][width - 1] = WALL_CHAR;

  // Create passages
  maze[5][5] = PATH_CHAR;
  maze[10][10] = PATH_CHAR;

  // Add more complexity
  maze[3][3] = maze[12][12] = WALL_CHAR;
}

int main() {
  int **maze = NULL;
  int width = MAZE_WIDTH;
  int height = MAZE_HEIGHT;

  maze = (int **)malloc(height * sizeof(int *));
  for (int i = 0; i < height; i++) {
    maze[i] = (int *)malloc(width * sizeof(int));
  }

  generateMaze(maze, width, height);

  // Print the maze
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      printf("%c ", maze[y][x]);
    }
    printf("\n");
  }

  free(maze);

  return 0;
}