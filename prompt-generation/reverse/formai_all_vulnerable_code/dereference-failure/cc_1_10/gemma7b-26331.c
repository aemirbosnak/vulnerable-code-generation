//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: surrealist
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

int main()
{
  int **arr = NULL;
  int i, j, k, l, m;

  arr = (int **)malloc(WIDTH * sizeof(int *) + HEIGHT * sizeof(int));
  for (i = 0; i < WIDTH; i++)
  {
    arr[i] = (int *)malloc(HEIGHT * sizeof(int));
  }

  for (i = 0; i < WIDTH; i++)
  {
    for (j = 0; j < HEIGHT; j++)
    {
      arr[i][j] = rand() % 2;
    }
  }

  printf("Percolation Simulation:\n");

  for (k = 0; k < 10; k++)
  {
    for (l = 0; l < WIDTH; l++)
    {
      for (m = 0; m < HEIGHT; m++)
      {
        if (arr[l][m] == 1)
        {
          printf("X ");
        }
        else
        {
          printf(". ");
        }
      }
      printf("\n");
    }
    printf("------------------------\n");
  }

  free(arr);
  return 0;
}