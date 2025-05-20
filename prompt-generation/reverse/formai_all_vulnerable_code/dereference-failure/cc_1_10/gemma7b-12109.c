//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void bucketSort(int **arr, int n) {
  int i, j, k, bucketSize, min, max, **buckets;

  min = arr[0][0];
  max = arr[0][0];

  for (i = 0; i < n; i++) {
    min = arr[i][0] < min ? arr[i][0] : min;
    max = arr[i][0] > max ? arr[i][0] : max;
  }

  bucketSize = (max - min) / MAX + 1;
  buckets = (int **)malloc(bucketSize * sizeof(int *));
  for (i = 0; i < bucketSize; i++) {
    buckets[i] = (int *)malloc(n * sizeof(int));
  }

  for (i = 0; i < n; i++) {
    buckets[arr[i][0] - min] = &arr[i];
  }

  for (i = 0; i < bucketSize; i++) {
    for (j = 0; buckets[i] != NULL; j++) {
      buckets[i][j] = buckets[i][j] + min;
    }
  }

  free(buckets);
}

int main() {
  int n, i, **arr;

  scanf("Enter the number of elements:", &n);

  arr = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++) {
    arr[i] = (int *)malloc(2 * sizeof(int));
  }

  for (i = 0; i < n; i++) {
    scanf("Enter the element:", &arr[i][0]);
    scanf("Enter the element:", &arr[i][1]);
  }

  bucketSort(arr, n);

  printf("The sorted array is:\n");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i][0]);
  }

  printf("\n");

  free(arr);

  return 0;
}