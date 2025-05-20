//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: unmistakable
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

#define EMPTY 0
#define WALL 1
#define PATH 2

void generate_maze(int **maze, int w, int h) {
  int x, y, n_walls = 0;
  srand(time(NULL));

  for (x = 0; x < w; x++) {
    for (y = 0; y < h; y++) {
      maze[x][y] = EMPTY;
    }
  }

  // Generate walls randomly
  for (x = 0; x < w; x++) {
    for (y = 0; y < h; y++) {
      if (rand() % 5 == 0) {
        maze[x][y] = WALL;
        n_walls++;
      }
    }
  }

  // Create a path
  maze[rand() % w][rand() % h] = PATH;

  // Print the maze
  for (x = 0; x < w; x++) {
    for (y = 0; y < h; y++) {
      printf("%d ", maze[x][y]);
    }
    printf("\n");
  }

  printf("Number of walls: %d\n", n_walls);
}

int main() {
  int **maze;
  maze = (int **)malloc(WIDTH * sizeof(int *));
  for (int i = 0; i < WIDTH; i++) {
    maze[i] = (int *)malloc(HEIGHT * sizeof(int));
  }

  generate_maze(maze, WIDTH, HEIGHT);

  return 0;
}