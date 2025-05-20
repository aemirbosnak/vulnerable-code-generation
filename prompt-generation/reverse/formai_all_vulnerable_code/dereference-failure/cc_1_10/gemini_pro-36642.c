//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum value in an array
int findMax(int arr[], int n) {
  int mx = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > mx) {
      mx = arr[i];
    }
  }
  return mx;
}

// Function to perform bucket sort on an array
void bucketSort(int arr[], int n) {
  // Create n empty buckets
  int buckets[n];
  for (int i = 0; i < n; i++) {
    buckets[i] = 0;
  }

  // Insert elements into the buckets
  int max = findMax(arr, n);
  for (int i = 0; i < n; i++) {
    int bucketIndex = arr[i] * n / (max + 1);
    buckets[bucketIndex]++;
  }

  // Sort the elements in each bucket
  for (int i = 0; i < n; i++) {
    while (buckets[i] > 0) {
      int bucketIndex = i;
      int j = bucketIndex * n / (max + 1);
      while (j >= 0 && arr[j] > arr[bucketIndex]) {
        int temp = arr[j];
        arr[j] = arr[bucketIndex];
        arr[bucketIndex] = temp;
        j--;
      }
      buckets[i]--;
      bucketIndex++;
    }
  }
}

// Function to print an array
void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
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

  // Sort the array using bucket sort
  bucketSort(arr, n);

  // Print the sorted array
  printf("Sorted array: ");
  printArray(arr, n);

  return 0;
}