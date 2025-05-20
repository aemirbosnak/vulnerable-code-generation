//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

void compress(char **arr, int *size) {
  int i, j, k = 0, count = 1, flag = 0;
  char temp, prev = '\0';

  for (i = 0; i < *size; i++) {
    if (arr[i] == prev) {
      count++;
    } else {
      if (count > 1) {
        arr[k++] = prev;
        arr[k++] = count - 1;
      } else {
        arr[k++] = arr[i];
      }
      prev = arr[i];
      count = 1;
    }
  }

  *size = k;

  return;
}

int main() {
  char **arr = NULL;
  int size = 0, i;

  arr = (char **)malloc(MAX * sizeof(char *));

  for (i = 0; i < MAX; i++) {
    arr[i] = (char *)malloc(MAX * sizeof(char));
  }

  // Sample data
  arr[0] = "abccaaab";
  arr[1] = "abbccd";
  arr[2] = "abcabc";

  size = 3;

  compress(arr, &size);

  printf("Compressed data:\n");
  for (i = 0; i < size; i++) {
    printf("%c", arr[i]);
  }

  printf("\n");

  printf("Original data size: %d\n", size);
  printf("Compressed data size: %d\n", size);

  return 0;
}