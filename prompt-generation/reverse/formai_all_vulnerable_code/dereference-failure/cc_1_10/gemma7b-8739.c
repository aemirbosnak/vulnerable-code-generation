//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: Ada Lovelace
#include <stdio.h>

void generateMaze(int size)
{
  int i, j, x, y;
  int **maze = NULL;

  maze = (int **)malloc(size * sizeof(int *));
  for (i = 0; i < size; i++)
  {
    maze[i] = (int *)malloc(size * sizeof(int));
    for (j = 0; j < size; j++)
    {
      maze[i][j] = 0;
    }
  }

  x = size / 2;
  y = size / 2;

  maze[x][y] = 1;

  for (i = 0; i < size; i++)
  {
    for (j = 0; j < size; j++)
    {
      if (maze[i][j] == 0)
      {
        int r = rand() % 4;
        switch (r)
        {
          case 0:
            maze[i][j] = 1;
            break;
          case 1:
            maze[i][j - 1] = 1;
            break;
          case 2:
            maze[i + 1][j] = 1;
            break;
          case 3:
            maze[i][j + 1] = 1;
            break;
        }
      }
    }
  }

  free(maze);
}

int main()
{
  generateMaze(10);

  return 0;
}