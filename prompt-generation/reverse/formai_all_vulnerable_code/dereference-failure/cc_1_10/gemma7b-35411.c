//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void percolate(int **arr, int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = i; j < size && arr[j] > arr[i]; j++)
    {
      int temp = arr[j];
      arr[j] = arr[i];
      arr[i] = temp;
    }
  }
}

int main()
{
  int size = MAX_SIZE;
  int **arr = (int **)malloc(size * sizeof(int *));
  for (int i = 0; i < size; i++)
  {
    arr[i] = (int *)malloc(size * sizeof(int));
  }

  // Fill the array with random numbers
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      arr[i][j] = rand() % 10;
    }
  }

  percolate(arr, size);

  // Print the sorted array
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }

  // Free the memory
  for (int i = 0; i < size; i++)
  {
    free(arr[i]);
  }
  free(arr);

  return 0;
}