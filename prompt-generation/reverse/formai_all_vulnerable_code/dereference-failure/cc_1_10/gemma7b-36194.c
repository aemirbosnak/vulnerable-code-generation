//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void bucket_sort(int **arr, int n) {
  int i, j, k, bucket_size, min, max, range, **bucket;

  min = arr[0][0];
  max = arr[0][0];

  for (i = 0; i < n; i++) {
    if (arr[i][0] < min) {
      min = arr[i][0];
    }
    if (arr[i][0] > max) {
      max = arr[i][0];
    }
  }

  range = max - min + 1;
  bucket_size = range / MAX_SIZE;

  bucket = (int *)malloc(sizeof(int) * bucket_size);

  for (i = 0; i < bucket_size; i++) {
    bucket[i] = 0;
  }

  for (i = 0; i < n; i++) {
    bucket[arr[i][0] - min]++;
  }

  for (i = 0; i < bucket_size; i++) {
    for (j = 0; j < bucket[i]; j++) {
      arr[j][0] = min + i;
    }
  }

  free(bucket);
}

int main() {
  int **arr = (int **)malloc(sizeof(int *) * MAX_SIZE);
  int n, i;

  n = MAX_SIZE;
  for (i = 0; i < n; i++) {
    arr[i] = (int *)malloc(sizeof(int) * MAX_SIZE);
  }

  // Insert sample data
  arr[0][0] = 10;
  arr[1][0] = 20;
  arr[2][0] = 30;
  arr[3][0] = 40;
  arr[4][0] = 50;

  bucket_sort(arr, n);

  // Print sorted data
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i][0]);
  }

  free(arr);
  return 0;
}