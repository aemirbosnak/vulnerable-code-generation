//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

void bucket_sort(int arr[], int n) {
  int i, j, k;

  // Create empty buckets
  int** buckets = (int**)malloc(BUCKET_SIZE * sizeof(int*));
  for (i = 0; i < BUCKET_SIZE; i++) {
    buckets[i] = (int*)malloc(n * sizeof(int));
    for (j = 0; j < n; j++) {
      buckets[i][j] = 0;
    }
  }

  // Fill the buckets
  for (i = 0; i < n; i++) {
    int idx = arr[i] / BUCKET_SIZE;
    for (j = 0; j < n; j++) {
      if (buckets[idx][j] == 0) {
        buckets[idx][j] = arr[i];
        break;
      }
    }
  }

  // Sort each bucket
  for (i = 0; i < BUCKET_SIZE; i++) {
    for (j = 0; j < n; j++) {
      for (k = j + 1; k < n; k++) {
        if (buckets[i][k] < buckets[i][j]) {
          int temp = buckets[i][j];
          buckets[i][j] = buckets[i][k];
          buckets[i][k] = temp;
        }
      }
    }
  }

  // Copy the elements back to the original array
  int idx = 0;
  for (i = 0; i < BUCKET_SIZE; i++) {
    for (j = 0; j < n; j++) {
      if (buckets[i][j] != 0) {
        arr[idx++] = buckets[i][j];
      }
    }
  }

  // Free the memory
  for (i = 0; i < BUCKET_SIZE; i++) {
    free(buckets[i]);
  }
  free(buckets);
}

int main() {
  printf("\nWelcome to Artistic Bucket Sort example code!\n\n");
  printf("Please enter the number of elements to sort: ");
  int n;
  scanf("%d", &n);

  int arr[n];
  printf("\nPlease enter %d numbers separated by space: ", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("\nUnsorted array:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  bucket_sort(arr, n);

  printf("\n\nSorted array:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n\nThank you for using Artistic Bucket Sort!\n");

  return 0;
}