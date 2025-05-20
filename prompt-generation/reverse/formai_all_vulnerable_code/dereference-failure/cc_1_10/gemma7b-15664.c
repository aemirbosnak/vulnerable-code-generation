//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

void draw_maze(int **maze, int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (maze[i][j] == 1)
      {
        printf(" ");
      }
      else
      {
        printf("+");
      }
    }
    printf("\n");
  }
}

int main()
{
  int n = MAX;
  int **maze = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++)
  {
    maze[i] = (int *)malloc(n * sizeof(int));
  }

  srand(time(NULL));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      maze[i][j] = rand() % 2;
    }
  }

  draw_maze(maze, n);

  free(maze);

  return 0;
}