//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 10000000

int main() {
  clock_t start, end;
  double time_taken;

  // Allocate memory for arrays
  int *a = (int *)malloc(N * sizeof(int));
  int *b = (int *)malloc(N * sizeof(int));
  int *c = (int *)malloc(N * sizeof(int));

  // Initialize arrays
  for (int i = 0; i < N; i++) {
    a[i] = rand() % 100;
    b[i] = rand() % 100;
  }

  // Time the addition operation
  start = clock();
  for (int i = 0; i < N; i++) {
    c[i] = a[i] + b[i];
  }
  end = clock();
  time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

  // Print the time taken
  printf("Time taken for addition: %f seconds\n", time_taken);

  // Time the multiplication operation
  start = clock();
  for (int i = 0; i < N; i++) {
    c[i] = a[i] * b[i];
  }
  end = clock();
  time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

  // Print the time taken
  printf("Time taken for multiplication: %f seconds\n", time_taken);

  // Time the comparison operation
  start = clock();
  for (int i = 0; i < N; i++) {
    if (a[i] > b[i]) {
      c[i] = a[i];
    } else {
      c[i] = b[i];
    }
  }
  end = clock();
  time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

  // Print the time taken
  printf("Time taken for comparison: %f seconds\n", time_taken);

  // Time the string concatenation operation
  char *s1 = "Hello";
  char *s2 = "World!";
  char *s3 = (char *)malloc(strlen(s1) + strlen(s2) + 1);

  start = clock();
  for (int i = 0; i < N; i++) {
    strcpy(s3, s1);
    strcat(s3, s2);
  }
  end = clock();
  time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

  // Print the time taken
  printf("Time taken for string concatenation: %f seconds\n", time_taken);

  // Free memory
  free(a);
  free(b);
  free(c);
  free(s3);

  return 0;
}