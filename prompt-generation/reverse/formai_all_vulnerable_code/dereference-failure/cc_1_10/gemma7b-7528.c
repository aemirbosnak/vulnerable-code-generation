//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

void compress(char **arr, int **size) {
  int i, j, count = 0, unique = 0, prev = -1, current = -1;
  char *temp = malloc(MAX_SIZE);

  for (i = 0; i < **size; i++) {
    int current_char = arr[i];
    if (prev == current_char) {
      count++;
    } else {
      unique++;
      prev = current_char;
      count = 1;
    }
  }

  *size = unique;
  arr = realloc(arr, unique);

  for (i = 0, j = 0; i < **size; i++) {
    arr[j] = arr[i];
    j++;
  }

  free(temp);
}

int main() {
  char *arr = malloc(MAX_SIZE);
  int size = 10;

  // Sample data
  arr[0] = 'a';
  arr[1] = 'a';
  arr[2] = 'b';
  arr[3] = 'c';
  arr[4] = 'c';
  arr[5] = 'c';
  arr[6] = 'd';
  arr[7] = 'e';
  arr[8] = 'e';
  arr[9] = 'f';

  compress(&arr, &size);

  printf("Original size: %d\n", size);
  printf("Compressed size: %d\n", size);

  free(arr);

  return 0;
}