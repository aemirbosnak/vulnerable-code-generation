//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void initializeMaze(int **maze, int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      maze[i][j] = 0;
    }
  }
}

int generateMaze(int **maze, int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (rand() % 2 == 0)
      {
        maze[i][j] = 1;
      }
    }
  }
  return 1;
}

void printMaze(int **maze, int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%d ", maze[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  int n = 10;
  int **maze = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++)
  {
    maze[i] = (int *)malloc(n * sizeof(int));
  }

  initializeMaze(maze, n);
  generateMaze(maze, n);
  printMaze(maze, n);

  return 0;
}