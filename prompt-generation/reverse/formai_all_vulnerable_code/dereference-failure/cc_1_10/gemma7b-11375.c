//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int **arr, int n) {
  int i, j, k, bucketSize, min, max;
  bucketSize = n;
  min = arr[0][0];
  max = arr[0][1];
  for (i = 0; i < n; i++) {
    min = arr[i][0] < min ? arr[i][0] : min;
    max = arr[i][1] > max ? arr[i][1] : max;
  }
  int **buckets = (int **)malloc(bucketSize * sizeof(int *));
  for (i = 0; i < bucketSize; i++) {
    buckets[i] = (int *)malloc(2 * sizeof(int));
  }
  for (i = 0; i < n; i++) {
    buckets[arr[i][0]] = &arr[i][0];
    buckets[arr[i][0]] = &arr[i][1];
  }
  for (i = 0; i < bucketSize; i++) {
    for (j = buckets[i]; j; j = *buckets[j]) {
      k = buckets[j] - buckets[i];
      arr[k][0] = buckets[i][0];
      arr[k][1] = buckets[i][1];
    }
  }
  free(buckets);
}

int main() {
  int n = 5;
  int **arr = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    arr[i] = (int *)malloc(2 * sizeof(int));
  }
  arr[0][0] = 3;
  arr[0][1] = 8;
  arr[1][0] = 1;
  arr[1][1] = 6;
  arr[2][0] = 4;
  arr[2][1] = 7;
  arr[3][0] = 2;
  arr[3][1] = 9;
  arr[4][0] = 6;
  arr[4][1] = 5;

  bucketSort(arr, n);

  for (int i = 0; i < n; i++) {
    printf("(%d, %d) ", arr[i][0], arr[i][1]);
  }

  free(arr);

  return 0;
}