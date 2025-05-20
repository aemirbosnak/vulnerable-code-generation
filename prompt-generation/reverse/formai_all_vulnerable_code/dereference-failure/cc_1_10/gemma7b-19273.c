//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUCKETS 10

void bucket_sort(int *arr, int n) {
  int i, j, bucket, key;

  // Create buckets
  int **buckets = (int **)malloc(MAX_BUCKETS * sizeof(int *));
  for (i = 0; i < MAX_BUCKETS; i++) {
    buckets[i] = (int *)malloc(n * sizeof(int));
  }

  // Distribute keys to buckets
  for (i = 0; i < n; i++) {
    key = arr[i];
    bucket = key / MAX_BUCKETS;
    buckets[bucket][key % MAX_BUCKETS] = arr[i];
  }

  // Merge buckets into one array
  int k = 0;
  for (i = 0; i < MAX_BUCKETS; i++) {
    for (j = 0; j < n; j++) {
      if (buckets[i][j] != NULL) {
        arr[k++] = buckets[i][j];
      }
    }
  }

  // Free buckets
  for (i = 0; i < MAX_BUCKETS; i++) {
    free(buckets[i]);
  }
  free(buckets);
}

int main() {
  int arr[] = {4, 3, 5, 2, 8, 9, 1, 7, 6, 0};
  int n = sizeof(arr) / sizeof(int);

  bucket_sort(arr, n);

  printf("Sorted array:");
  for (int i = 0; i < n; i++) {
    printf(" %d", arr[i]);
  }

  printf("\n");

  return 0;
}