//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void percolate(int **arr, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[i][j] > 0) {
        int x = i;
        int y = j;
        arr[x][y] = 0;
        if (x > 0) arr[x - 1][y] = 1;
        if (x < MAX - 1) arr[x + 1][y] = 1;
        if (y > 0) arr[x][y - 1] = 1;
        if (y < MAX - 1) arr[x][y + 1] = 1;
      }
    }
  }
}

int main() {
  int n = MAX;
  int **arr = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    arr[i] = (int *)malloc(n * sizeof(int));
  }

  // Initializing the array
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      arr[i][j] = 0;
    }
  }

  // Percolation
  percolate(arr, n);

  // Printing the result
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }

  // Freeing the memory
  for (int i = 0; i < n; i++) {
    free(arr[i]);
  }
  free(arr);

  return 0;
}