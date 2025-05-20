//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int **arr, int n) {
  int i, j, k, bucket_size, min, max, **buckets = NULL;

  min = arr[0][0];
  max = arr[0][0];
  for (i = 0; i < n; i++) {
    min = fmin(min, arr[i][0]);
    max = fmax(max, arr[i][0]);
  }

  bucket_size = (max - min) / n + 1;
  buckets = malloc(n * sizeof(int *));
  for (i = 0; i < n; i++) {
    buckets[i] = malloc(bucket_size * sizeof(int));
  }

  for (i = 0; i < n; i++) {
    buckets[arr[i][0]]++;
  }

  for (i = 0; i < bucket_size; i++) {
    for (j = 0; j < buckets[i]; j++) {
      arr[k][0] = i;
      k++;
    }
  }

  free(buckets);
}

int main() {
  int n, i, j, **arr = NULL;

  printf("Enter the number of elements:");
  scanf("%d", &n);

  arr = malloc(n * sizeof(int *));
  for (i = 0; i < n; i++) {
    arr[i] = malloc(2 * sizeof(int));
  }

  printf("Enter the elements:");
  for (i = 0; i < n; i++) {
    scanf("%d %d", &arr[i][0], &arr[i][1]);
  }

  bucket_sort(arr, n);

  printf("The sorted elements:");
  for (i = 0; i < n; i++) {
    printf("%d %d ", arr[i][0], arr[i][1]);
  }

  free(arr);

  return 0;
}