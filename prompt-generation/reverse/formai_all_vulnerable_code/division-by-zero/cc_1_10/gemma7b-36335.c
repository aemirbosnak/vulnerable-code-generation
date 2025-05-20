//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: curious
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
  int **buckets = malloc(n * sizeof(int *));
  for (i = 0; i < n; i++) {
    buckets[i] = malloc(bucket_size * sizeof(int));
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < arr[i][1]; j++) {
      buckets[i][arr[i][j] - min] = 1;
    }
  }
  int **sorted_arr = malloc(n * sizeof(int *));
  for (i = 0; i < n; i++) {
    sorted_arr[i] = malloc(arr[i][1] * sizeof(int));
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < arr[i][1]; j++) {
      sorted_arr[i][j] = buckets[i][j] * min;
    }
  }
  free(buckets);
  free(sorted_arr);
}

int main() {
  int n, i, j, **arr, **sorted_arr;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  arr = malloc(n * sizeof(int *));
  for (i = 0; i < n; i++) {
    arr[i] = malloc(2 * sizeof(int));
  }
  printf("Enter the elements: ");
  for (i = 0; i < n; i++) {
    for (j = 0; j < 2; j++) {
      scanf("%d", &arr[i][j]);
    }
  }
  bucket_sort(arr, n);
  printf("Sorted elements: ");
  for (i = 0; i < n; i++) {
    for (j = 0; j < 2; j++) {
      printf("%d ", sorted_arr[i][j]);
    }
    printf("\n");
  }
  free(arr);
  free(sorted_arr);
  return 0;
}