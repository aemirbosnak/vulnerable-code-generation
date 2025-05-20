//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int *arr, int n) {
  int i, j, k, bucket_size, min, max;
  bucket_size = n / 10 + 1;
  min = arr[0];
  max = arr[0];
  for (i = 0; i < n; i++) {
    if (arr[i] < min) {
      min = arr[i];
    }
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  int *buckets = (int *)malloc(bucket_size * sizeof(int));
  for (i = 0; i < bucket_size; i++) {
    buckets[i] = 0;
  }
  for (i = 0; i < n; i++) {
    buckets[arr[i] / 10] += 1;
  }
  int *sorted_arr = (int *)malloc(n * sizeof(int));
  k = 0;
  for (i = 0; i < bucket_size; i++) {
    for (j = 0; j < buckets[i]; j++) {
      sorted_arr[k++] = min + i * 10;
    }
  }
  free(buckets);
  free(sorted_arr);
}

int main() {
  int n, i, arr[100];
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  printf("Enter the elements: ");
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  bucket_sort(arr, n);
  printf("The sorted array is: ");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}