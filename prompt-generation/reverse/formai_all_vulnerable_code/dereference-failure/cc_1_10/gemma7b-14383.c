//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int **arr, int n) {
  int i, j, k, bucket_size, min, max;

  min = arr[0][0];
  max = arr[0][0];

  for (i = 0; i < n; i++) {
    for (j = 0; j < arr[i][1]; j++) {
      if (arr[i][j] < min) {
        min = arr[i][j];
      }
      if (arr[i][j] > max) {
        max = arr[i][j];
      }
    }
  }

  bucket_size = (max - min) / n + 1;
  int *buckets = (int *)malloc(bucket_size * n * sizeof(int));

  for (i = 0; i < n; i++) {
    for (j = 0; j < arr[i][1]; j++) {
      buckets[arr[i][j] - min] ++ ;
    }
  }

  int sorted_arr[n][2];
  sorted_arr[0][0] = min;
  sorted_arr[0][1] = bucket_size;

  for (i = 1; i < n; i++) {
    sorted_arr[i][0] = sorted_arr[i - 1][0] + buckets[i - 1];
    sorted_arr[i][1] = buckets[i - 1] + buckets[i];
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < arr[i][1]; j++) {
      arr[i][j] = sorted_arr[i][0] + j;
    }
  }
}

int main() {
  int n = 5;
  int **arr = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    arr[i] = (int *)malloc(2 * sizeof(int));
  }

  arr[0][0] = 1;
  arr[0][1] = 2;
  arr[1][0] = 3;
  arr[1][1] = 2;
  arr[2][0] = 4;
  arr[2][1] = 2;
  arr[3][0] = 2;
  arr[3][1] = 2;
  arr[4][0] = 5;
  arr[4][1] = 2;

  bucket_sort(arr, n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < arr[i][1]; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }

  return 0;
}