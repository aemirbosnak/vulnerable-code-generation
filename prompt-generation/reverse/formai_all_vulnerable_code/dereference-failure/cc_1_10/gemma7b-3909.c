//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: happy
#include <stdio.h>
#include <stdlib.h>

void print_table(int **arr, int n, int m)
{
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      printf("%4d ", arr[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  int n = 4;
  int m = 5;
  int **arr = (int **)malloc(n * sizeof(int *));
  for(int i = 0; i < n; i++)
  {
    arr[i] = (int *)malloc(m * sizeof(int));
  }

  arr[0][0] = 10;
  arr[0][1] = 20;
  arr[0][2] = 30;
  arr[0][3] = 40;
  arr[0][4] = 50;

  arr[1][0] = 60;
  arr[1][1] = 70;
  arr[1][2] = 80;
  arr[1][3] = 90;
  arr[1][4] = 100;

  arr[2][0] = 110;
  arr[2][1] = 120;
  arr[2][2] = 130;
  arr[2][3] = 140;
  arr[2][4] = 150;

  arr[3][0] = 160;
  arr[3][1] = 170;
  arr[3][2] = 180;
  arr[3][3] = 190;
  arr[3][4] = 200;

  print_table(arr, n, m);

  free(arr);

  return 0;
}