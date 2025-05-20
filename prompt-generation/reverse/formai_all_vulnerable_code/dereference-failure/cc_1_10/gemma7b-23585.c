//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

void compress(char **arr, int **size) {
  int i = 0, j = 0, count = 1, unique = 0;
  char temp = '\0';

  for (; arr[i] && arr[i] == arr[i - 1]; i++) {
    count++;
  }

  if (count > 1) {
    *size = *size - 1;
    arr = realloc(arr, *size);
    arr[j++] = temp;
    arr[j++] = count - 1;
  }

  temp = arr[i];
  unique = 1;

  for (; arr[i] && arr[i] != temp; i++) {
    arr[j++] = arr[i];
    unique++;
  }

  if (unique) {
    *size = *size - 1;
    arr = realloc(arr, *size);
    arr[j++] = temp;
    arr[j++] = unique - 1;
  }

  *size = 0;

  for (; arr[j] && arr[j] != '\0'; j++) {
    *size = *size + 1;
  }

  return;
}

int main() {
  char *arr = "aabbbb";
  int size = 10;

  compress(&arr, &size);

  printf("%s", arr);

  return 0;
}