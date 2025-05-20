//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

void compress(char **arr, int n) {
  int i, j, count = 1, flag = 0;
  char **ptr = (char **)malloc(n * sizeof(char *));
  for (i = 0; i < n; i++) {
    ptr[i] = (char *)malloc(MAX * sizeof(char));
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < MAX; j++) {
      ptr[i][j] = arr[i][j];
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < MAX; j++) {
      if (ptr[i][j] == arr[i][j] && flag) {
        count++;
      } else {
        flag = 1;
        printf("%c ", ptr[i][j]);
        printf("%d ", count);
      }
    }
  }
  free(ptr);
}

int main() {
  char **arr = (char **)malloc(10 * sizeof(char *));
  for (int i = 0; i < 10; i++) {
    arr[i] = (char *)malloc(10 * sizeof(char));
  }
  arr[0][0] = 'a';
  arr[0][1] = 'b';
  arr[0][2] = 'c';
  arr[0][3] = 'a';
  arr[0][4] = 'a';
  arr[0][5] = 'b';
  arr[0][6] = 'c';
  arr[0][7] = 'c';
  arr[0][8] = 'a';
  arr[0][9] = 'b';

  compress(arr, 10);

  return 0;
}