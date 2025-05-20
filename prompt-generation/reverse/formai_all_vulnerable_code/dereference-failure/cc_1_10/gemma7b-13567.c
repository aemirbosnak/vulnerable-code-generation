//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 10

void bucket_sort(int **arr, int n) {
  int i, j, k, bucket_size, min, max;

  min = arr[0][0];
  max = arr[0][0];

  for (i = 0; i < n; i++) {
    for (j = 0; j < MAX_SIZE; j++) {
      if (arr[i][j] != INT_MIN) {
        if (min > arr[i][j]) min = arr[i][j];
        if (max < arr[i][j]) max = arr[i][j];
      }
    }
  }

  bucket_size = (max - min) / MAX_SIZE + 1;

  int **buckets = (int **)malloc(bucket_size * sizeof(int *));
  for (i = 0; i < bucket_size; i++) {
    buckets[i] = (int *)malloc(MAX_SIZE * sizeof(int));
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < MAX_SIZE; j++) {
      if (arr[i][j] != INT_MIN) {
        buckets[arr[i][j]] = &arr[i][j];
      }
    }
  }

  for (i = 0; i < bucket_size; i++) {
    for (j = 0; j < MAX_SIZE; j++) {
      if (buckets[i][j] != NULL) {
        buckets[i][j] = NULL;
      }
    }
  }

  free(buckets);
}

int main() {
  int **arr = (int **)malloc(10 * sizeof(int *));
  for (int i = 0; i < 10; i++) {
    arr[i] = (int *)malloc(MAX_SIZE * sizeof(int));
  }

  arr[0][0] = 5;
  arr[0][1] = 3;
  arr[0][2] = 8;
  arr[0][3] = 2;
  arr[0][4] = 4;

  arr[1][0] = 2;
  arr[1][1] = 4;
  arr[1][2] = 6;
  arr[1][3] = 8;
  arr[1][4] = 10;

  bucket_sort(arr, 2);

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < MAX_SIZE; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }

  free(arr);

  return 0;
}