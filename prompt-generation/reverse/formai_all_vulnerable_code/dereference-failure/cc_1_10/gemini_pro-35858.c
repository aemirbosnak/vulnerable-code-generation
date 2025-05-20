//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

// Function to create buckets
void createBuckets(int *buckets, int size) {
  for (int i = 0; i < size; i++) {
    buckets[i] = 0;
  }
}

// Function to insert elements into buckets
void insertIntoBuckets(int *arr, int size, int *buckets) {
  int maxValue = arr[0];
  for (int i = 1; i < size; i++) {
    if (arr[i] > maxValue) {
      maxValue = arr[i];
    }
  }

  int bucketSize = maxValue / SIZE;
  for (int i = 0; i < size; i++) {
    int bucketIndex = arr[i] / bucketSize;
    buckets[bucketIndex]++;
  }
}

// Function to sort elements in buckets
void sortBuckets(int *buckets, int size) {
  int count = 0;
  for (int i = 0; i < size; i++) {
    while (buckets[i] > 0) {
      buckets[i]--;
      printf("%d ", i * SIZE + count);
      count++;
    }
  }
}

// Function to perform bucket sort
void bucketSort(int *arr, int size) {
  int *buckets = malloc(sizeof(int) * SIZE);
  createBuckets(buckets, SIZE);
  insertIntoBuckets(arr, size, buckets);
  sortBuckets(buckets, SIZE);
  free(buckets);
}

// Function to print an array
void printArray(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  // Initialize an array of integers
  int arr[] = {38, 27, 43, 3, 9, 82, 10};
  int size = sizeof(arr) / sizeof(arr[0]);

  // Display the original array
  printf("Original array: ");
  printArray(arr, size);

  // Perform bucket sort on the array
  bucketSort(arr, size);

  // Display the sorted array
  printf("Sorted array: ");
  printArray(arr, size);

  return 0;
}