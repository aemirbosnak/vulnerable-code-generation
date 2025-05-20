//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void findRoute(int **maze, int x, int y) {
  if (maze[x][y] == 2) {
    return;
  }
  if (maze[x][y] == 1) {
    return;
  }

  maze[x][y] = 1;

  findRoute(maze, x - 1, y);
  findRoute(maze, x + 1, y);
  findRoute(maze, x, y - 1);
  findRoute(maze, x, y + 1);

  return;
}

int main() {
  int maze[MAX_SIZE][MAX_SIZE] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

  findRoute(maze, 1, 1);

  for (int x = 0; x < MAX_SIZE; x++) {
    for (int y = 0; y < MAX_SIZE; y++) {
      if (maze[x][y] == 1) {
        printf("%c", '*');
      } else if (maze[x][y] == 0) {
        printf(" ");
      }
    }
    printf("\n");
  }

  return 0;
}