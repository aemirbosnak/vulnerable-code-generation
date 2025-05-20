//FormAI DATASET v1.0 Category: Benchmarking ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int main()
{
  int i, j, temp;
  clock_t start, end;
  double cpu_time_used;

  int* arr = (int*) malloc(SIZE * sizeof(int));
  
  // Generate random array
  srand(time(NULL));
  for(i = 0; i < SIZE; i++)
    arr[i] = rand() % SIZE;

  // Start clock
  start = clock();

  // Bubble Sort
  for(i = 0; i < SIZE - 1; i++)
  {
    for(j = 0; j < SIZE - i - 1; j++)
    {
      if(arr[j] > arr[j+1])
      {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }

  // Stop clock
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

  printf("Sorted array: ");
  for(i = 0; i < SIZE; i++)
    printf("%d ", arr[i]);

  printf("\nTime used for sorting: %f seconds", cpu_time_used);

  // Free memory
  free(arr);

  return 0;
}