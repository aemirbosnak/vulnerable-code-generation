//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define REPEAT 1000000

int main(int argc, char **argv) {
  int i;
  char *str1 = "Hello, world!";
  char *str2 = malloc(strlen(str1) + 1);

  // Benchmark strcpy()
  clock_t start = clock();
  for (i = 0; i < REPEAT; i++) {
    strcpy(str2, str1);
  }
  clock_t end = clock();
  double strcpy_time = (double)(end - start) / CLOCKS_PER_SEC;

  // Benchmark memcpy()
  start = clock();
  for (i = 0; i < REPEAT; i++) {
    memcpy(str2, str1, strlen(str1) + 1);
  }
  end = clock();
  double memcpy_time = (double)(end - start) / CLOCKS_PER_SEC;

  // Benchmark strncpy()
  start = clock();
  for (i = 0; i < REPEAT; i++) {
    strncpy(str2, str1, strlen(str1) + 1);
  }
  end = clock();
  double strncpy_time = (double)(end - start) / CLOCKS_PER_SEC;

  // Benchmark sprintf()
  char str3[strlen(str1) + 1];
  start = clock();
  for (i = 0; i < REPEAT; i++) {
    sprintf(str3, "%s", str1);
  }
  end = clock();
  double sprintf_time = (double)(end - start) / CLOCKS_PER_SEC;

  // Print the results
  printf("strcpy() time: %.6f seconds\n", strcpy_time);
  printf("memcpy() time: %.6f seconds\n", memcpy_time);
  printf("strncpy() time: %.6f seconds\n", strncpy_time);
  printf("sprintf() time: %.6f seconds\n", sprintf_time);

  free(str2);

  return 0;
}