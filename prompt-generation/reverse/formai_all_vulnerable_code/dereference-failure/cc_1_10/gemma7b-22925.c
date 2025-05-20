//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int **arr, int n) {
  int i, j, k, bucket_size, **buckets, min, max;

  min = arr[0][0];
  max = arr[0][0];

  for (i = 0; i < n; i++) {
    for (j = 0; j < arr[i][1]; j++) {
      if (min > arr[i][0]) {
        min = arr[i][0];
      }
      if (max < arr[i][0]) {
        max = arr[i][0];
      }
    }
  }

  bucket_size = (max - min) / n + 1;
  buckets = (int *)malloc(n * bucket_size * sizeof(int));

  for (i = 0; i < n; i++) {
    for (j = 0; j < arr[i][1]; j++) {
      buckets[arr[i][0]]++;
    }
  }

  for (i = 0; i < bucket_size; i++) {
    for (j = 0; j < buckets[i]; j++) {
      printf("%d ", min + i);
    }
  }

  free(buckets);
}

int main() {
  int **arr = (int **)malloc(5 * sizeof(int *));
  arr[0] = (int *)malloc(2 * sizeof(int));
  arr[1] = (int *)malloc(2 * sizeof(int));
  arr[2] = (int *)malloc(2 * sizeof(int));
  arr[3] = (int *)malloc(2 * sizeof(int));
  arr[4] = (int *)malloc(2 * sizeof(int));

  arr[0][0] = 10;
  arr[0][1] = 2;
  arr[1][0] = 8;
  arr[1][1] = 2;
  arr[2][0] = 12;
  arr[2][1] = 2;
  arr[3][0] = 14;
  arr[3][1] = 2;
  arr[4][0] = 16;
  arr[4][1] = 2;

  bucket_sort(arr, 5);

  return 0;
}