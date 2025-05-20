//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

#define EMPTY 0
#define WALL 1
#define PATH 2

void generate_maze(int **maze, int width, int height) {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      maze[y][x] = EMPTY;
    }
  }

  // Create walls
  maze[5][10] = WALL;
  maze[10][15] = WALL;
  maze[15][10] = WALL;
  maze[12][12] = WALL;

  // Create path
  maze[1][1] = PATH;
  maze[1][2] = PATH;
  maze[2][2] = PATH;
  maze[2][3] = PATH;
  maze[3][3] = PATH;
  maze[4][3] = PATH;
  maze[4][4] = PATH;
  maze[5][4] = PATH;
  maze[5][5] = PATH;
  maze[6][5] = PATH;
  maze[6][6] = PATH;
  maze[7][6] = PATH;
  maze[8][6] = PATH;
  maze[8][7] = PATH;
  maze[9][7] = PATH;
  maze[9][8] = PATH;
  maze[10][8] = PATH;
  maze[10][9] = PATH;
  maze[11][9] = PATH;
  maze[11][10] = PATH;
  maze[12][10] = PATH;
  maze[12][11] = PATH;
  maze[13][11] = PATH;
  maze[13][12] = PATH;
  maze[14][12] = PATH;
  maze[14][13] = PATH;
  maze[15][13] = PATH;
  maze[15][14] = PATH;
  maze[16][14] = PATH;
  maze[16][15] = PATH;
  maze[17][15] = PATH;
  maze[17][16] = PATH;
  maze[18][16] = PATH;
  maze[18][17] = PATH;
  maze[19][17] = PATH;
  maze[19][18] = PATH;
  maze[19][19] = PATH;
}

int main() {
  int **maze = NULL;
  int width = MAZE_WIDTH;
  int height = MAZE_HEIGHT;

  maze = (int **)malloc(height * sizeof(int *) + height);
  for (int y = 0; y < height; y++) {
    maze[y] = (int *)malloc(width * sizeof(int) + width);
  }

  generate_maze(maze, width, height);

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      switch (maze[y][x]) {
        case EMPTY:
          printf(" ");
          break;
        case WALL:
          printf("#");
          break;
        case PATH:
          printf("=");
          break;
      }
    }
    printf("\n");
  }

  free(maze);

  return 0;
}