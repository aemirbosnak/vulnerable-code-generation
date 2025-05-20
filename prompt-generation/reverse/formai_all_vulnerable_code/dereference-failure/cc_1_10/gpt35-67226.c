//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define BUCKET_SIZE 10

void bucket_sort(int arr[], int n) {
  int i, j;
  int count[BUCKET_SIZE] = {0};
  int *bucket[BUCKET_SIZE];

  // Initialize empty buckets
  for (i = 0; i < BUCKET_SIZE; ++i) {
    bucket[i] = NULL;
  }

  // Count the number of elements in each bucket
  for (i = 0; i < n; ++i) {
    ++count[arr[i]];
  }

  // Allocate memory for each bucket according to the number of elements
  for (i = 0; i < BUCKET_SIZE; ++i) {
    if (count[i] > 0) {
      bucket[i] = (int*)malloc(sizeof(int) * count[i]);
    } else {
      bucket[i] = NULL;
    }
  }

  // Fill the buckets with the elements
  for (i = 0, j = 0; i < BUCKET_SIZE; ++i) {
    if (count[i] > 0) {
      int k;
      for (k = 0; k < count[i]; ++k, ++j) {
        bucket[i][k] = arr[j];
      }
    }
  }

  // Sort each bucket and merge the result
  for (i = 0; i < BUCKET_SIZE; ++i) {
    if (count[i] > 0) {
      int *ptr = bucket[i];
      int k, temp;
      for (j = 1; j < count[i]; ++j) {
        temp = ptr[j];
        for (k = j-1; k >= 0 && ptr[k] > temp; --k) {
          ptr[k+1] = ptr[k];
        }
        ptr[k+1] = temp;
      }
    }
  }

  // Merge the buckets
  for (i = 0, j = 0; i < BUCKET_SIZE; ++i) {
    if (count[i] > 0) {
      int k;
      for (k = 0; k < count[i]; ++k, ++j) {
        arr[j] = bucket[i][k];
      }
      free(bucket[i]);
    }
  }
}

// Driver program
int main() {
  int i;
  int arr[MAX] = {7, 2, 1, 6, 8, 5, 3, 4, 9, 0};

  printf("Original array: ");
  for (i = 0; i < MAX; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  bucket_sort(arr, MAX);

  printf("Bucket sorted array: ");
  for (i = 0; i < MAX; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}