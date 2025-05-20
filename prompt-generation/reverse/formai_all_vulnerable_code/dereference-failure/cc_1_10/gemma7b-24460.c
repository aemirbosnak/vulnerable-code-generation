//Gemma-7B DATASET v1.0 Category: Sorting ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void sortByAge(int **arr, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if ((*arr)[i] > (*arr)[j]) {
        int temp = (*arr)[i];
        (*arr)[i] = (*arr)[j];
        (*arr)[j] = temp;
      }
    }
  }
}

int main() {
  int n = MAX;
  int **arr = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    arr[i] = (int *)malloc(MAX * sizeof(int));
  }

  // Populate the array
  arr[0][0] = 25;
  arr[0][1] = 30;
  arr[0][2] = 20;
  arr[1][0] = 40;
  arr[1][1] = 20;
  arr[1][2] = 35;

  sortByAge(arr, n);

  // Print the sorted array
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < MAX; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }

  // Free the memory
  for (int i = 0; i < n; i++) {
    free(arr[i]);
  }
  free(arr);

  return 0;
}