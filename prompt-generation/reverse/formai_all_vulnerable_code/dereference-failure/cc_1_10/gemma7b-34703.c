//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void draw_road(int **arr)
{
  for(int r = 0; r < ROWS; r++)
  {
    for(int c = 0; c < COLS; c++)
    {
      if(arr[r][c] == 0)
      {
        printf(" ");
      }
      else if(arr[r][c] == 1)
      {
        printf("-");
      }
      else if(arr[r][c] == 2)
      {
        printf("|");
      }
    }
    printf("\n");
  }
}

int main()
{
  int **arr = (int**)malloc(ROWS * sizeof(int*));
  for(int r = 0; r < ROWS; r++)
  {
    arr[r] = (int*)malloc(COLS * sizeof(int));
  }

  srand(time(NULL));

  for(int r = 0; r < ROWS; r++)
  {
    for(int c = 0; c < COLS; c++)
    {
      arr[r][c] = rand() % 3;
    }
  }

  draw_road(arr);

  free(arr);

  return 0;
}