//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int **arr, int n) {
  int i, j, k, bucket_size, min, max, *bucket, **sorted_arr;

  min = arr[0][0];
  max = arr[0][0];

  for (i = 0; i < n; i++) {
    min = arr[i][0] < min ? arr[i][0] : min;
    max = arr[i][0] > max ? arr[i][0] : max;
  }

  bucket_size = (max - min) / 10 + 1;
  bucket = (int *)malloc(bucket_size * sizeof(int));
  sorted_arr = (int **)malloc(n * sizeof(int *));

  for (i = 0; i < bucket_size; i++) {
    bucket[i] = 0;
  }

  for (i = 0; i < n; i++) {
    bucket[arr[i][0]]++;
  }

  for (i = 1; i < bucket_size; i++) {
    bucket[i] += bucket[i - 1];
  }

  for (i = 0; i < n; i++) {
    sorted_arr[i] = (int *)malloc(2 * sizeof(int));
    sorted_arr[i][0] = arr[i][0];
    sorted_arr[i][1] = bucket[arr[i][0]] - 1;
  }

  free(bucket);
  free(sorted_arr);
}

int main() {
  int **arr = (int **)malloc(5 * sizeof(int *));
  arr[0] = (int *)malloc(2 * sizeof(int));
  arr[1] = (int *)malloc(2 * sizeof(int));
  arr[2] = (int *)malloc(2 * sizeof(int));
  arr[3] = (int *)malloc(2 * sizeof(int));
  arr[4] = (int *)malloc(2 * sizeof(int));

  arr[0][0] = 10;
  arr[0][1] = 20;
  arr[1][0] = 30;
  arr[1][1] = 40;
  arr[2][0] = 50;
  arr[2][1] = 60;
  arr[3][0] = 70;
  arr[3][1] = 80;
  arr[4][0] = 90;
  arr[4][1] = 100;

  bucket_sort(arr, 5);

  for (int i = 0; i < 5; i++) {
    printf("arr[%d][0] = %d, arr[%d][1] = %d\n", i, arr[i][0], arr[i][1]);
  }

  free(arr);

  return 0;
}