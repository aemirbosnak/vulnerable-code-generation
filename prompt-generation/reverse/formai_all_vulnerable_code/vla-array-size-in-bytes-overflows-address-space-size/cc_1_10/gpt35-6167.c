//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Define the maximum value that can be sorted
#define MAX_VALUE 10000

// Define the size of each bucket
#define BUCKET_SIZE 10

void bucket_sort(int arr[], int n) {

  // Create an array of buckets
  int* buckets[BUCKET_SIZE];

  // Initialize each bucket as an empty array
  for (int i = 0; i < BUCKET_SIZE; i++) {
    buckets[i] = malloc(sizeof(int) * MAX_VALUE);
  }

  // Initialize count array to hold the number of items in each bucket
  int count[BUCKET_SIZE] = {0};

  // Divide the array into buckets and insert items into them
  for (int i = 0; i < n; i++) {
    int bucket_num = (arr[i] / BUCKET_SIZE);
    buckets[bucket_num][count[bucket_num]] = arr[i];
    count[bucket_num]++;
  }

  // Perform insertion sort on each bucket
  for (int i = 0; i < BUCKET_SIZE; i++) {
    int len = count[i];
    for (int j = 1; j < len; j++) {
      int key = buckets[i][j];
      int k = j - 1;
      while (k >= 0 && buckets[i][k] > key) {
        buckets[i][k+1] = buckets[i][k];
        k--;
      }
      buckets[i][k+1] = key;
    }
  }

  // Merge all sorted buckets back into arr
  int index = 0;
  for (int i = 0; i < BUCKET_SIZE; i++) {
    int len = count[i];
    for (int j = 0; j < len; j++) {
      arr[index] = buckets[i][j];
      index++;
    }
  }

  // Free the memory
  for (int i = 0; i < BUCKET_SIZE; i++) {
    free(buckets[i]);
  }
}

int main() {

  // Prompt user to enter number of elements to be sorted
  printf("Enter number of elements: ");
  int n;
  scanf("%d", &n);

  // Prompt user to enter each element
  printf("Enter %d elements:\n", n);
  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // Sort the array using bucket sort
  bucket_sort(arr, n);

  // Print sorted array
  printf("Sorted array: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}