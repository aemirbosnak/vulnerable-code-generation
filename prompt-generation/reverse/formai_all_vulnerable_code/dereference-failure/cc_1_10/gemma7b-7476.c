//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: intelligent
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 10
#define MAX_HEIGHT 10

#define WALL_CHAR '#'
#define EMPTY_CHAR '.'

void generateMaze(int **maze, int width, int height) {
  int x, y;
  srand(time(NULL));

  // Allocate memory for the maze
  maze = malloc(height * sizeof(int *));
  for (y = 0; y < height; y++) {
    maze[y] = malloc(width * sizeof(int));
  }

  // Initialize the maze with empty cells
  for (y = 0; y < height; y++) {
    for (x = 0; x < width; x++) {
      maze[y][x] = EMPTY_CHAR;
    }
  }

  // Create the walls of the maze
  for (x = 0; x < width; x++) {
    maze[0][x] = WALL_CHAR;
  }
  for (y = 0; y < height; y++) {
    maze[y][0] = WALL_CHAR;
  }
  maze[0][0] = WALL_CHAR;
  maze[0][width - 1] = WALL_CHAR;
  maze[height - 1][0] = WALL_CHAR;
  maze[height - 1][width - 1] = WALL_CHAR;

  // Create the center passage
  x = rand() % width;
  y = rand() % height;
  maze[y][x] = EMPTY_CHAR;
}

int main() {
  int **maze;
  int width = MAX_WIDTH;
  int height = MAX_HEIGHT;

  generateMaze(maze, width, height);

  // Print the maze
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      printf("%c ", maze[y][x]);
    }
    printf("\n");
  }

  return 0;
}