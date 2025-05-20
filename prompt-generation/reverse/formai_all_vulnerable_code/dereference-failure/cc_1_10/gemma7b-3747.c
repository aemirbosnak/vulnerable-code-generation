//Gemma-7B DATASET v1.0 Category: Data mining ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 100

void reshape(int **arr, int n, int m)
{
  int i, j, k = 0;
  int *temp = (int *)malloc(n * m * sizeof(int));
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      arr[i][j] = temp[k++];
    }
  }
  free(temp);
}

int main()
{
  int **arr = (int **)malloc(MAX * sizeof(int *));
  for (int i = 0; i < MAX; i++)
  {
    arr[i] = (int *)malloc(MAX * sizeof(int));
  }

  // Fill the array with some data
  for (int i = 0; i < MAX; i++)
  {
    for (int j = 0; j < MAX; j++)
    {
      arr[i][j] = rand() % 10;
    }
  }

  // Reshape the array
  reshape(arr, MAX, MAX);

  // Print the rearranged array
  for (int i = 0; i < MAX; i++)
  {
    for (int j = 0; j < MAX; j++)
    {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }

  // Free the memory
  for (int i = 0; i < MAX; i++)
  {
    free(arr[i]);
  }
  free(arr);

  return 0;
}