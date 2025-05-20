//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 50
#define MAX_HEIGHT 50

void generate_maze(int **maze, int width, int height) {
  int x, y, r, c;
  srand(time(NULL));

  for (x = 0; x < width; x++) {
    for (y = 0; y < height; y++) {
      maze[x][y] = rand() % 2;
    }
  }

  for (x = 0; x < width; x++) {
    for (y = 0; y < height; y++) {
      if (maze[x][y] == 0) {
        r = rand() % 4;
        switch (r) {
          case 0:
            maze[x][y - 1] = 1;
            break;
          case 1:
            maze[x + 1][y] = 1;
            break;
          case 2:
            maze[x][y + 1] = 1;
            break;
          case 3:
            maze[x][y - 1] = 1;
            maze[x + 1][y] = 1;
            break;
        }
      }
    }
  }
}

int main() {
  int **maze;
  int width, height;

  printf("Enter the width of the maze: ");
  scanf("%d", &width);

  printf("Enter the height of the maze: ");
  scanf("%d", &height);

  maze = (int **)malloc(width * sizeof(int *) + height * sizeof(int));
  for (int i = 0; i < width; i++) {
    maze[i] = (int *)malloc(height * sizeof(int));
  }

  generate_maze(maze, width, height);

  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      printf("%d ", maze[x][y]);
    }
    printf("\n");
  }

  free(maze);

  return 0;
}