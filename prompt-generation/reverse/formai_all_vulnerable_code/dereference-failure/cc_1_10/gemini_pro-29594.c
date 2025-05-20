//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: random
// A whimsical C benchmarking journey

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A dancing array of integers
int *twirlingArray(int length) {
  int *array = malloc(length * sizeof(int));
  for (int i = 0; i < length; i++) {
    array[i] = rand() % 100;
  }
  return array;
}

// A spinning loop
int twirlingLoop(int length) {
  int sum = 0;
  for (int i = 0; i < length; i++) {
    sum += (i % 2 == 0) ? i : -i;
  }
  return sum;
}

// A timeless timer
double timekeeping(void (*func)(), int iterations) {
  clock_t start = clock();
  for (int i = 0; i < iterations; i++) {
    func();
  }
  clock_t end = clock();
  return (double)(end - start) / CLOCKS_PER_SEC;
}

// The main act - a benchmarking symphony
int main() {
  int lengths[] = {1000, 5000, 10000, 50000, 100000};
  int iterations = 1000;

  // Array acrobatics
  printf("Time taken for array creation and traversal:\n");
  for (int i = 0; i < 5; i++) {
    printf("Length: %d\tTime (seconds): %.3f\n", lengths[i], timekeeping(twirlingArray, iterations));
  }

  // Loop ballet
  printf("\nTime taken for looping performance:\n");
  for (int i = 0; i < 5; i++) {
    printf("Length: %d\tTime (seconds): %.3f\n", lengths[i], timekeeping(twirlingLoop, iterations));
  }

  return 0;
}