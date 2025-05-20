//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

void compress(char **src, int **dest, int size) {
  int i, j, k, count = 0, run_length = 1;
  char prev = '\0';

  for (i = 0; i < size; i++) {
    if (*src[i] == prev) {
      run_length++;
    } else {
      if (run_length > 1) {
        *dest++ = count;
        *dest++ = run_length;
      }
      prev = *src[i];
      count = 1;
      run_length = 1;
    }
  }

  if (run_length > 1) {
    *dest++ = count;
    *dest++ = run_length;
  }
}

int main() {
  char **src = malloc(MAX);
  int **dest = malloc(MAX);
  int size = 0;

  // Get the source text
  printf("Enter text: ");
  getline(src, MAX, stdin);

  // Calculate the size of the source text
  size = strlen(src) + 1;

  // Compress the text
  compress(src, dest, size);

  // Print the compressed text
  printf("Compressed text: ");
  for (int i = 0; dest[i] != NULL; i++) {
    printf("%d ", dest[i]);
  }

  return 0;
}