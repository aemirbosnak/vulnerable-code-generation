//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void bucket_sort(int **arr, int n) {
  int i, j, k, bucket_size, *bucket, **histogram = NULL;

  histogram = malloc(n * sizeof(int *));
  for (i = 0; i < n; i++) {
    histogram[i] = malloc(MAX_SIZE * sizeof(int));
  }

  for (i = 0; i < n; i++) {
    arr[i] = malloc(MAX_SIZE * sizeof(int));
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < MAX_SIZE; j++) {
      histogram[i][j] = 0;
    }
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < MAX_SIZE; j++) {
      bucket_size = arr[i][j];
      histogram[i][j] = bucket_size;
    }
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < MAX_SIZE; j++) {
      if (histogram[i][j] > 0) {
        for (k = 0; k < histogram[i][j]; k++) {
          arr[i][k] = j + 1;
        }
      }
    }
  }

  free(histogram);
  for (i = 0; i < n; i++) {
    free(arr[i]);
  }
}

int main() {
  int n = 10;
  int **arr = NULL;

  arr = malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    arr[i] = malloc(MAX_SIZE * sizeof(int));
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < MAX_SIZE; j++) {
      arr[i][j] = rand() % MAX_SIZE;
    }
  }

  bucket_sort(arr, n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < MAX_SIZE; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }

  free(arr);
  return 0;
}