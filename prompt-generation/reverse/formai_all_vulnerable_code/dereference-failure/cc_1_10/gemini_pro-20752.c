//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to create buckets
int** createBuckets(int n) {
  int** buckets = (int**)malloc(sizeof(int*) * n);
  for (int i = 0; i < n; i++) {
    buckets[i] = (int*)malloc(sizeof(int) * MAX_SIZE);
  }
  return buckets;
}

// Function to insert elements into buckets
void insertIntoBuckets(int** buckets, int n, int* arr) {
  for (int i = 0; i < n; i++) {
    int bucketIndex = arr[i] / n;
    buckets[bucketIndex][arr[i] % n] = arr[i];
  }
}

// Function to sort elements in each bucket
void sortBuckets(int** buckets, int n) {
  for (int i = 0; i < n; i++) {
    int* bucket = buckets[i];
    int size = MAX_SIZE;
    for (int j = 0; j < size - 1; j++) {
      for (int k = j + 1; k < size; k++) {
        if (bucket[j] > bucket[k]) {
          int temp = bucket[j];
          bucket[j] = bucket[k];
          bucket[k] = temp;
        }
      }
    }
  }
}

// Function to concatenate buckets
int* concatenateBuckets(int** buckets, int n) {
  int* sortedArr = (int*)malloc(sizeof(int) * n);
  int index = 0;
  for (int i = 0; i < n; i++) {
    int* bucket = buckets[i];
    int size = MAX_SIZE;
    for (int j = 0; j < size; j++) {
      if (bucket[j] != 0) {
        sortedArr[index++] = bucket[j];
      }
    }
  }
  return sortedArr;
}

// Function to bucket sort the array
int* bucketSort(int* arr, int n) {
  // Create buckets
  int** buckets = createBuckets(n);

  // Insert elements into buckets
  insertIntoBuckets(buckets, n, arr);

  // Sort elements in each bucket
  sortBuckets(buckets, n);

  // Concatenate buckets
  int* sortedArr = concatenateBuckets(buckets, n);

  // Free memory allocated for buckets
  for (int i = 0; i < n; i++) {
    free(buckets[i]);
  }
  free(buckets);

  return sortedArr;
}

// Function to print the array
void printArray(int* arr, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  // Input array
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int n = sizeof(arr) / sizeof(arr[0]);

  // Bucket sort the array
  int* sortedArr = bucketSort(arr, n);

  // Print the sorted array
  printArray(sortedArr, n);

  return 0;
}