//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Function to create buckets
int** createBuckets(int n) {
  int** buckets = (int**)malloc(sizeof(int*) * n);
  for (int i = 0; i < n; i++) {
    buckets[i] = (int*)malloc(sizeof(int) * n);
  }
  return buckets;
}

// Function to sort the elements in each bucket
void sortBuckets(int** buckets, int n) {
  for (int i = 0; i < n; i++) {
    // Sort the elements in the bucket using any sorting algorithm
    // In this example, we use bubble sort
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n - j - 1; k++) {
        if (buckets[i][k] > buckets[i][k + 1]) {
          int temp = buckets[i][k];
          buckets[i][k] = buckets[i][k + 1];
          buckets[i][k + 1] = temp;
        }
      }
    }
  }
}

// Function to merge the elements from all buckets
int* mergeBuckets(int** buckets, int n) {
  int* sortedArray = (int*)malloc(sizeof(int) * n * n);
  int index = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      sortedArray[index++] = buckets[i][j];
    }
  }
  return sortedArray;
}

// Function to perform bucket sort
int* bucketSort(int* arr, int n) {
  // Create buckets
  int** buckets = createBuckets(n);

  // Distribute the elements into buckets
  for (int i = 0; i < n; i++) {
    int bucketIndex = arr[i] % n;
    buckets[bucketIndex][i] = arr[i];
  }

  // Sort the elements in each bucket
  sortBuckets(buckets, n);

  // Merge the elements from all buckets
  int* sortedArray = mergeBuckets(buckets, n);

  // Free the memory allocated for buckets
  for (int i = 0; i < n; i++) {
    free(buckets[i]);
  }
  free(buckets);

  return sortedArray;
}

// Function to print an array
void printArray(int* arr, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  // Input array
  int arr[] = {13, 7, 22, 4, 19, 11, 15, 17, 21, 10, 16, 8};
  int n = sizeof(arr) / sizeof(arr[0]);

  // Sort the array using bucket sort
  int* sortedArray = bucketSort(arr, n);

  // Print the sorted array
  printArray(sortedArray, n);

  return 0;
}