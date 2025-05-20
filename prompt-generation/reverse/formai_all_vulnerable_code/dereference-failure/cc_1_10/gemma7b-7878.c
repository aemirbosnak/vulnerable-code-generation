//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void bucketSort(int **arr, int n) {
  int i, j, k, bucketSize, min, max;
  min = arr[0][0];
  max = arr[0][0];
  for (i = 0; i < n; i++) {
    min = arr[i][0] < min ? arr[i][0] : min;
    max = arr[i][0] > max ? arr[i][0] : max;
  }
  bucketSize = (max - min) / MAX + 1;
  int **buckets = (int **)malloc(bucketSize * sizeof(int *));
  for (i = 0; i < bucketSize; i++) {
    buckets[i] = (int *)malloc(n * sizeof(int));
  }
  for (i = 0; i < n; i++) {
    buckets[arr[i][0] - min] [arr[i][1]] = arr[i];
  }
  int **mergedArr = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++) {
    mergedArr[i] = (int *)malloc(2 * sizeof(int));
  }
  for (i = 0; i < n; i++) {
    mergedArr[i][0] = buckets[arr[i][0] - min][0];
    mergedArr[i][1] = buckets[arr[i][0] - min][1];
  }
  free(buckets);
  free(mergedArr);
}

int main() {
  int **arr = (int **)malloc(10 * sizeof(int *));
  for (int i = 0; i < 10; i++) {
    arr[i] = (int *)malloc(2 * sizeof(int));
  }
  arr[0][0] = 10;
  arr[0][1] = 20;
  arr[1][0] = 15;
  arr[1][1] = 30;
  arr[2][0] = 25;
  arr[2][1] = 40;
  bucketSort(arr, 10);
  for (int i = 0; i < 10; i++) {
    printf("(%d, %d)\n", arr[i][0], arr[i][1]);
  }
  free(arr);
  return 0;
}