//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: configurable
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

#define WALL_CHAR '#'
#define EMPTY_CHAR '.'

void generateMaze(int **maze, int w, int h) {
  int x, y;
  srand(time(NULL));

  for (x = 0; x < w; x++) {
    for (y = 0; y < h; y++) {
      maze[x][y] = EMPTY_CHAR;
    }
  }

  // Create walls randomly
  for (x = 0; x < w; x++) {
    for (y = 0; y < h; y++) {
      if (rand() % 2 == 0) {
        maze[x][y] = WALL_CHAR;
      }
    }
  }

  // Connect rooms
  for (x = 0; x < w; x++) {
    for (y = 0; y < h; y++) {
      if (maze[x][y] == WALL_CHAR) {
        // Connect randomly to adjacent walls
        if (rand() % 2 == 0) {
          maze[x][y - 1] = EMPTY_CHAR;
        }
        if (rand() % 2 == 0) {
          maze[x + 1][y] = EMPTY_CHAR;
        }
        if (rand() % 2 == 0) {
          maze[x][y + 1] = EMPTY_CHAR;
        }
        if (rand() % 2 == 0) {
          maze[x - 1][y] = EMPTY_CHAR;
        }
      }
    }
  }
}

int main() {
  int **maze;
  int w, h;

  w = MAZE_WIDTH;
  h = MAZE_HEIGHT;

  maze = (int *)malloc(w * h * sizeof(int));
  generateMaze(maze, w, h);

  // Print the maze
  for (int x = 0; x < w; x++) {
    for (int y = 0; y < h; y++) {
      printf("%c ", maze[x][y]);
    }
    printf("\n");
  }

  free(maze);

  return 0;
}