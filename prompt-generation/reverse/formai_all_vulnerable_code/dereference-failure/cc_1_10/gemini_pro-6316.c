//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main() {
  int i, j, key;
  int *arr;
  clock_t start, end;
  double time_taken;

  // Generate a random array of integers
  arr = (int *)malloc(ARRAY_SIZE * sizeof(int));
  for (i = 0; i < ARRAY_SIZE; i++) {
    arr[i] = rand() % ARRAY_SIZE;
  }

  // Get the key to search for
  printf("Enter the key to search for: ");
  scanf("%d", &key);

  // Start the clock
  start = clock();

  // Search for the key using linear search
  for (i = 0; i < ARRAY_SIZE; i++) {
    if (arr[i] == key) {
      // Key found at index i
      break;
    }
  }

  // Stop the clock
  end = clock();

  // Calculate the time taken
  time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

  // Print the result
  if (i < ARRAY_SIZE) {
    printf("Key found at index %d\n", i);
  } else {
    printf("Key not found\n");
  }

  printf("Time taken: %f seconds\n", time_taken);

  // Free the allocated memory
  free(arr);

  return 0;
}