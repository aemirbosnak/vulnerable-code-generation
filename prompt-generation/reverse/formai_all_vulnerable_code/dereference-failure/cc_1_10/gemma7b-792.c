//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void bucket_sort(int **arr, int n) {
  int i, j, k, bucket_size, key, min, max;
  int *bucket;

  min = arr[0][0];
  max = arr[0][0];

  for (i = 0; i < n; i++) {
    min = arr[i][0] < min ? arr[i][0] : min;
    max = arr[i][0] > max ? arr[i][0] : max;
  }

  bucket_size = (max - min) / MAX_SIZE + 1;
  bucket = (int *)malloc(bucket_size * sizeof(int));

  for (i = 0; i < n; i++) {
    key = arr[i][0] - min;
    bucket[key] = bucket[key] + 1;
  }

  for (i = 0; i < bucket_size; i++) {
    for (j = 0; j < bucket[i]; j++) {
      arr[j][0] = min + i * MAX_SIZE;
    }
  }

  free(bucket);
}

int main() {
  int n, i, j;
  int **arr;

  printf("Enter the number of elements:");
  scanf("%d", &n);

  arr = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++) {
    arr[i] = (int *)malloc(2 * sizeof(int));
  }

  printf("Enter the elements:");
  for (i = 0; i < n; i++) {
    scanf("%d %d", &arr[i][0], &arr[i][1]);
  }

  bucket_sort(arr, n);

  printf("Sorted elements:");
  for (i = 0; i < n; i++) {
    printf(" %d %d", arr[i][0], arr[i][1]);
  }

  return 0;
}