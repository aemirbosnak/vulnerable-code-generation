//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX 256

void compress(char **arr, int *sz) {
  int i, j, count = 0, prev = 0, current = 0, min = MAX;
  char *ptr = NULL;

  for (i = 0; i < *sz; i++) {
    current = arr[i];
    if (prev != current) {
      count++;
      prev = current;
    }
    if (count < min) {
      min = count;
    }
  }

  *sz = min + 1;
  ptr = malloc((*sz) * sizeof(char));

  i = 0;
  prev = 0;
  count = 0;
  for (j = 0; j < *sz; j++) {
    current = arr[i];
    if (prev != current) {
      ptr[j] = count;
      count = 1;
      prev = current;
    } else {
      count++;
    }
  }

  ptr[j] = count;
  free(arr);
  arr = ptr;

  printf("Compressed size: %d\n", *sz);
  for (i = 0; i < *sz; i++) {
    printf("%c ", arr[i]);
  }
  printf("\n");
}

int main() {
  char *arr = "HELLO WORLD!";
  int sz = 13;

  compress(&arr, &sz);

  return 0;
}