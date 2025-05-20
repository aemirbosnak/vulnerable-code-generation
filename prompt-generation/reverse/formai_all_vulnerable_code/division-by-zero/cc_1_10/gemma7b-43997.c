//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int **arr, int n) {
  int i, j, k, min, max, bucket_size, **buckets, count = 0;

  min = arr[0][0];
  max = arr[0][0];
  for (i = 0; i < n; i++) {
    min = arr[i][0] < min ? arr[i][0] : min;
    max = arr[i][0] > max ? arr[i][0] : max;
  }

  bucket_size = (max - min) / n + 1;
  buckets = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++)
    buckets[i] = (int *)malloc(bucket_size * sizeof(int));

  for (i = 0; i < n; i++) {
    k = arr[i][0] - min;
    buckets[k][count] = arr[i];
    count++;
  }

  for (i = 0; i < n; i++) {
    for (j = 0; buckets[i][j] != NULL; j++) {
      arr[i] = buckets[i][j];
    }
  }

  free(buckets);
}

int main() {
  int **arr = NULL;
  int n = 0;

  // Get the number of elements
  printf("Enter the number of elements: ");
  scanf("%d", &n);

  // Allocate memory for the array
  arr = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++)
    arr[i] = (int *)malloc(2 * sizeof(int));

  // Get the elements
  printf("Enter the elements: ");
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &arr[i][0], &arr[i][1]);
  }

  bucket_sort(arr, n);

  // Print the sorted array
  printf("The sorted array is:\n");
  for (int i = 0; i < n; i++) {
    printf("%d %d\n", arr[i][0], arr[i][1]);
  }

  free(arr);

  return 0;
}