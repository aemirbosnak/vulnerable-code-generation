//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

void compress(char **arr, int *size) {
  int i = 0, j = 0, count = 1, repeat = 1, flag = 0;
  char **compressed = malloc(MAX_SIZE);

  for (i = 0; i < *size; i++) {
    if (flag) {
      compressed[j++] = arr[i] - arr[i - 1];
    } else {
      compressed[j++] = arr[i];
      flag = 1;
    }

    if (arr[i] == arr[i - 1] && count > 1) {
      compressed[j++] = count - 1;
      count = 1;
    }
  }

  *size = j;
  free(arr);
  arr = compressed;
}

int main() {
  char *arr = malloc(MAX_SIZE);
  int size = 10;

  arr[0] = 1;
  arr[1] = 2;
  arr[2] = 2;
  arr[3] = 3;
  arr[4] = 3;
  arr[5] = 4;
  arr[6] = 4;
  arr[7] = 5;
  arr[8] = 5;
  arr[9] = 6;

  compress(&arr, &size);

  printf("Compressed size: %d\n", size);

  for (int i = 0; i < size; i++) {
    printf("%c ", arr[i]);
  }

  free(arr);

  return 0;
}