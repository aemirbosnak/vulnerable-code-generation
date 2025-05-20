//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int **arr, int n) {
  int i, j, k, bucket_size, min_max = arr[0][0] - arr[0][0] + 1;
  int *bucket = (int *)malloc(bucket_size * sizeof(int));

  for (i = 0; i < n; i++) {
    for (j = 0; j < min_max; j++) {
      bucket[j] = 0;
    }
    bucket[arr[i][0]]++;
  }

  for (k = 0; k < min_max; k++) {
    if (bucket[k] > 0) {
      for (i = 0; i < bucket[k]; i++) {
        arr[i][0] = k + 1;
      }
    }
  }

  free(bucket);
}

int main() {
  int **arr = (int **)malloc(5 * sizeof(int *));
  for (int i = 0; i < 5; i++) {
    arr[i] = (int *)malloc(2 * sizeof(int));
  }

  arr[0][0] = 3;
  arr[0][1] = 4;
  arr[1][0] = 2;
  arr[1][1] = 5;
  arr[2][0] = 2;
  arr[2][1] = 4;
  arr[3][0] = 5;
  arr[3][1] = 6;
  arr[4][0] = 4;
  arr[4][1] = 7;

  bucket_sort(arr, 5);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 2; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < 5; i++) {
    free(arr[i]);
  }
  free(arr);

  return 0;
}