//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

void compress(char **arr, int n) {
  int i, j, count = 0, prev = -1, flag = 0;
  char **ptr = (char**)malloc(n * sizeof(char*));

  for (i = 0; i < n; i++) {
    if (prev != arr[i] && flag == 0) {
      ptr[count++] = arr[i];
      prev = arr[i];
    } else if (prev == arr[i] && flag == 0) {
      ptr[count++] = arr[i] - prev + 'a';
      flag = 1;
    } else if (flag) {
      ptr[count++] = arr[i];
      prev = arr[i];
      flag = 0;
    }
  }

  *arr = ptr;
  n = count;
}

int main() {
  char *arr = (char*)malloc(MAX * sizeof(char));
  arr[0] = 'a';
  arr[1] = 'a';
  arr[2] = 'b';
  arr[3] = 'b';
  arr[4] = 'c';
  arr[5] = 'c';
  arr[6] = 'c';

  compress(&arr, 7);

  printf("Original array:\n");
  for (int i = 0; i < 7; i++) {
    printf("%c ", arr[i]);
  }

  printf("\nCompressed array:\n");
  for (int i = 0; i < 3; i++) {
    printf("%c ", arr[i]);
  }

  printf("\nNumber of elements after compression: %d", arr[0]);

  return 0;
}