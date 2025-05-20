//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int **arr, int n) {
  int i, j, k, bucket_size, max_size = arr[0][0] + 1;
  bucket_size = max_size / n;
  int **buckets = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++) {
    buckets[i] = (int *)malloc(bucket_size * sizeof(int));
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < bucket_size; j++) {
      buckets[i][j] = 0;
    }
  }

  for (i = 0; i < n; i++) {
    buckets[arr[i][0]][arr[i][1]] = arr[i];
  }

  int **sorted_arr = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++) {
    sorted_arr[i] = (int *)malloc(2 * sizeof(int));
  }

  for (i = 0; i < n; i++) {
    sorted_arr[i][0] = buckets[i][0];
    sorted_arr[i][1] = buckets[i][1];
  }

  free(buckets);
  free(sorted_arr);
}

int main() {
  int **arr = (int **)malloc(5 * sizeof(int *));
  for (int i = 0; i < 5; i++) {
    arr[i] = (int *)malloc(2 * sizeof(int));
  }

  arr[0][0] = 1;
  arr[0][1] = 3;
  arr[1][0] = 2;
  arr[1][1] = 4;
  arr[2][0] = 3;
  arr[2][1] = 5;
  arr[3][0] = 2;
  arr[3][1] = 4;
  arr[4][0] = 1;
  arr[4][1] = 5;

  bucket_sort(arr, 5);

  for (int i = 0; i < 5; i++) {
    printf("(%d, %d) ", arr[i][0], arr[i][1]);
  }

  free(arr);

  return 0;
}