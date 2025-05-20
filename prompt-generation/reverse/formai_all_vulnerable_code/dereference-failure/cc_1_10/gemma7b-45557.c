//Gemma-7B DATASET v1.0 Category: Sorting ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void sort(int **arr, int n) {
  int i, j, k;
  for (i = 0; i < n - 1; i++) {
    for (j = i + 1; j < n; j++) {
      if ((*arr)[i] > (*arr)[j]) {
        int temp = (*arr)[i];
        (*arr)[i] = (*arr)[j];
        (*arr)[j] = temp;
      }
    }
  }
}

int main() {
  int **arr = (int **)malloc(MAX * sizeof(int *));
  for (int i = 0; i < MAX; i++) {
    arr[i] = (int *)malloc(MAX * sizeof(int));
  }

  // Fill the array with some data
  arr[0][0] = 4;
  arr[0][1] = 2;
  arr[0][2] = 8;
  arr[0][3] = 6;
  arr[0][4] = 3;

  arr[1][0] = 9;
  arr[1][1] = 12;
  arr[1][2] = 5;
  arr[1][3] = 11;
  arr[1][4] = 10;

  sort(arr, 2);

  // Print the sorted array
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }

  free(arr);

  return 0;
}