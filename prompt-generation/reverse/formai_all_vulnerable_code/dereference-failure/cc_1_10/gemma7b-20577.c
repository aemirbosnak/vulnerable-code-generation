//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int **arr, int n) {
  int i, j, k, bucket_size, *bucket, **sorted_arr;

  bucket_size = n / 10 + 1;
  bucket = (int *)malloc(bucket_size * sizeof(int));
  sorted_arr = (int **)malloc(n * sizeof(int *));

  for (i = 0; i < n; i++) {
    arr[i] = bucket_sort_calc(arr[i]);
  }

  for (i = 0; i < bucket_size; i++) {
    for (j = 0; j < bucket_size; j++) {
      k = bucket[i] - 1;
      if (k >= 0) {
        sorted_arr[k] = arr[i];
      }
    }
  }

  for (i = 0; i < n; i++) {
    arr[i] = sorted_arr[i];
  }

  free(bucket);
  free(sorted_arr);
}

int bucket_sort_calc(int num) {
  return num / 10;
}

int main() {
  int n, i, **arr;

  printf("Enter the number of elements: ");
  scanf("%d", &n);

  arr = (int **)malloc(n * sizeof(int *));

  for (i = 0; i < n; i++) {
    arr[i] = (int *)malloc(sizeof(int));
  }

  printf("Enter the elements: ");
  for (i = 0; i < n; i++) {
    scanf("%d", arr[i]);
  }

  bucket_sort(arr, n);

  printf("Sorted array: ");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  for (i = 0; i < n; i++) {
    free(arr[i]);
  }
  free(arr);

  return 0;
}