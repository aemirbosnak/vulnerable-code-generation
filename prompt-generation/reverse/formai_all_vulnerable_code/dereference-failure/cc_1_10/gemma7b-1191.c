//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: minimalist
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

#define WALL_CHAR '#'
#define EMPTY_CHAR '.'

void generate_maze(int **maze, int w, int h) {
  int x, y;
  for (x = 0; x < w; x++) {
    for (y = 0; y < h; y++) {
      maze[x][y] = EMPTY_CHAR;
    }
  }

  // Generate walls randomly
  for (x = 0; x < w; x++) {
    for (y = 0; y < h; y++) {
      if (rand() % 2 == 0) {
        maze[x][y] = WALL_CHAR;
      }
    }
  }

  // Create the main path
  maze[5][5] = EMPTY_CHAR;
  maze[5][6] = EMPTY_CHAR;
  maze[5][7] = EMPTY_CHAR;
  maze[6][6] = EMPTY_CHAR;
  maze[7][6] = EMPTY_CHAR;
  maze[8][6] = EMPTY_CHAR;
  maze[8][7] = EMPTY_CHAR;
  maze[8][8] = EMPTY_CHAR;
  maze[9][8] = EMPTY_CHAR;
  maze[10][8] = EMPTY_CHAR;
  maze[10][9] = EMPTY_CHAR;
  maze[10][10] = EMPTY_CHAR;

  return;
}

int main() {
  int **maze;
  int w, h;

  w = MAZE_WIDTH;
  h = MAZE_HEIGHT;

  maze = (int *)malloc(w * h * sizeof(int));
  generate_maze(maze, w, h);

  // Print the maze
  for (int x = 0; x < w; x++) {
    for (int y = 0; y < h; y++) {
      printf("%c ", maze[x][y]);
    }
    printf("\n");
  }

  return 0;
}