//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

void compress(int **arr, int n) {
  int i, j, count = 0, size = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < MAX; j++) {
      if (arr[i][j] != 0) {
        count++;
      }
    }
  }

  size = count * 2 + n;

  arr = realloc(arr, size);

  count = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < MAX; j++) {
      if (arr[i][j] != 0) {
        arr[count][0] = arr[i][j];
        arr[count][1] = count;
        count++;
      }
    }
  }
}

int main() {
  int n, i, j, **arr;

  printf("Enter the number of players: ");
  scanf("%d", &n);

  arr = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++) {
    arr[i] = (int *)malloc(MAX * sizeof(int));
  }

  // Each player fills their array with random numbers
  for (i = 0; i < n; i++) {
    for (j = 0; j < MAX; j++) {
      arr[i][j] = rand() % 10;
    }
  }

  // Compress the array
  compress(arr, n);

  // Print the compressed array
  for (i = 0; i < n; i++) {
    for (j = 0; j < MAX; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }

  return 0;
}