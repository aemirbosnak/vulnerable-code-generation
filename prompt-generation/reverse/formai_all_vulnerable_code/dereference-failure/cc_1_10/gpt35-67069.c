//FormAI DATASET v1.0 Category: Benchmarking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main(void)
{
  clock_t start, end;
  double cpu_time_used;

  // Allocate memory for array
  int *arr = (int *)malloc(ARRAY_SIZE * sizeof(int));

  // Initialize array with random values
  srand(time(NULL));
  for (int i = 0; i < ARRAY_SIZE; i++)
  {
    arr[i] = rand() % 100;
  }

  // Bubble sort algorithm to sort the array
  start = clock();
  for (int i = 0; i < ARRAY_SIZE - 1; ++i)
  {
    for (int j = 0; j < ARRAY_SIZE - i - 1; ++j)
    {
      if (arr[j] > arr[j + 1])
      {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  end = clock();
  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

  // Print the sorted array
  for (int i = 0; i < ARRAY_SIZE; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");

  // Print the time taken to sort the array
  printf("CPU Time Used: %f seconds\n", cpu_time_used);

  // Free allocated memory
  free(arr);

  return 0;
}