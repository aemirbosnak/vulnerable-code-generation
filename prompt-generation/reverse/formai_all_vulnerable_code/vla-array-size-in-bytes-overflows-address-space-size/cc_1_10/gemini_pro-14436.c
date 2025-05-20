//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum element in an array
int max(int arr[], int n) {
  int max = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
  // Create an array of buckets
  int bucketSize = max(arr, n);
  int buckets[bucketSize];

  // Initialize all buckets to empty
  for (int i = 0; i < bucketSize; i++) {
    buckets[i] = 0;
  }

  // Distribute the elements into the buckets
  for (int i = 0; i < n; i++) {
    buckets[arr[i]]++;
  }

  // Sort the elements in each bucket
  for (int i = 0; i < bucketSize; i++) {
    while (buckets[i] > 0) {
      printf("%d ", i);
      buckets[i]--;
    }
  }
}

// Main function
int main() {
  // Get the size of the array
  int n;
  printf("Enter the size of the array: ");
  scanf("%d", &n);

  // Get the elements of the array
  int arr[n];
  printf("Enter the elements of the array: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // Perform bucket sort on the array
  bucketSort(arr, n);

  return 0;
}