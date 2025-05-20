//FormAI DATASET v1.0 Category: Benchmarking ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MILLION 1000000

int main() {
  int arr_size = 100000;
  long int total_time1 = 0, total_time2 = 0;
  clock_t start, end;

  // dynamically allocate memory for the arrays
  int *arr1 = malloc(sizeof(int) * arr_size);
  int *arr2 = malloc(sizeof(int) * arr_size);

  // fill the arrays with random integers
  srand(time(NULL));
  for (int i = 0; i < arr_size; i++) {
    arr1[i] = rand() % 1000;
    arr2[i] = rand() % 1000;
  }

  // perform benchmarking using C's built-in clock() function
  for (int i = 0; i < MILLION; i++) {
    start = clock();

    // perform some operation on the first array
    for (int j = 0; j < arr_size; j++) {
      arr1[j] = arr1[j] + 1;
    }

    end = clock();
    total_time1 += (end - start);

    start = clock();

    // perform the same operation on the second array
    for (int j = 0; j < arr_size; j++) {
      arr2[j] = arr2[j] + 1;
    }

    end = clock();
    total_time2 += (end - start);
  }

  printf("Benchmarking results for Operation: Increment Array Elements by 1\n");
  printf("Array size: %d\n", arr_size);
  printf("Total time for arr1: %ld microseconds\n", total_time1 / MILLION);
  printf("Total time for arr2: %ld microseconds\n", total_time2 / MILLION);

  if (total_time1 < total_time2) {
    printf("arr1 is faster than arr2!\n");
  } else if (total_time1 > total_time2) {
    printf("arr2 is faster than arr1!\n");
  } else {
    printf("Both arr1 and arr2 have the same speed!\n");
  }

  // free the memory
  free(arr1);
  free(arr2);

  return 0;
}