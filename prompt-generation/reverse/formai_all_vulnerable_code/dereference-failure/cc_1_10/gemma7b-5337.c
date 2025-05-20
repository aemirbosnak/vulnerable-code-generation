//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

void generateMaze(int **maze, int w, int h)
{
  int x, y;

  for (x = 0; x < w; x++)
  {
    for (y = 0; y < h; y++)
    {
      maze[x][y] = rand() % 2;
    }
  }
}

void printMaze(int **maze, int w, int h)
{
  int x, y;

  for (x = 0; x < w; x++)
  {
    for (y = 0; y < h; y++)
    {
      printf("%d ", maze[x][y]);
    }
    printf("\n");
  }
}

int main()
{
  int **maze;
  int w, h;

  w = MAZE_WIDTH;
  h = MAZE_HEIGHT;

  maze = (int *)malloc(w * h * sizeof(int));

  generateMaze(maze, w, h);
  printMaze(maze, w, h);

  free(maze);

  return 0;
}