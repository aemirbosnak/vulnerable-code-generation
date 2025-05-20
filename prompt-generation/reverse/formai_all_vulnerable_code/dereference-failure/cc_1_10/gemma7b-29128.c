//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void search(int **arr, int n, int target)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < MAX_SIZE; j++)
    {
      if (arr[i][j] == target)
      {
        printf("Target found at index (%d, %d)\n", i, j);
        return;
      }
    }
  }

  printf("Target not found\n");
}

int main()
{
  int n = 5;
  int target = 12;

  int **arr = (int **)malloc(n * MAX_SIZE * sizeof(int));

  // Populate the array
  arr[0][0] = 10;
  arr[0][1] = 20;
  arr[0][2] = 30;
  arr[1][0] = 40;
  arr[1][1] = 50;
  arr[1][2] = 60;
  arr[2][0] = 70;
  arr[2][1] = 80;
  arr[2][2] = 90;
  arr[3][0] = 100;
  arr[3][1] = 110;
  arr[3][2] = 120;
  arr[4][0] = 130;
  arr[4][1] = 140;
  arr[4][2] = 150;

  search(arr, n, target);

  free(arr);

  return 0;
}