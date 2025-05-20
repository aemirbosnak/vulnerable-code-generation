//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 5
#define MAX_VALUE 100

// Function to insert an element into the bucket
void insert_into_bucket(int *bucket, int value) {
  // Find the index of the bucket to insert the element into
  int index = value / BUCKET_SIZE;

  // Insert the element into the bucket
  bucket[index] = value;
}

// Function to sort the elements in the bucket
void sort_bucket(int *bucket) {
  // Sort the elements in the bucket using any sorting algorithm (e.g., insertion sort)
  for (int i = 0; i < BUCKET_SIZE; i++) {
    for (int j = i + 1; j < BUCKET_SIZE; j++) {
      if (bucket[i] > bucket[j]) {
        int temp = bucket[i];
        bucket[i] = bucket[j];
        bucket[j] = temp;
      }
    }
  }
}

// Function to perform bucket sort on the input array
void bucket_sort(int *array, int size) {
  // Create an array of buckets
  int **buckets = malloc(sizeof(int *) * (MAX_VALUE / BUCKET_SIZE));

  // Initialize the buckets
  for (int i = 0; i < MAX_VALUE / BUCKET_SIZE; i++) {
    buckets[i] = malloc(sizeof(int) * BUCKET_SIZE);
    for (int j = 0; j < BUCKET_SIZE; j++) {
      buckets[i][j] = -1;
    }
  }

  // Insert the elements into the buckets
  for (int i = 0; i < size; i++) {
    insert_into_bucket(buckets[array[i] / BUCKET_SIZE], array[i]);
  }

  // Sort the elements in each bucket
  for (int i = 0; i < MAX_VALUE / BUCKET_SIZE; i++) {
    sort_bucket(buckets[i]);
  }

  // Concatenate the sorted buckets into the output array
  int index = 0;
  for (int i = 0; i < MAX_VALUE / BUCKET_SIZE; i++) {
    for (int j = 0; j < BUCKET_SIZE; j++) {
      if (buckets[i][j] != -1) {
        array[index++] = buckets[i][j];
      }
    }
  }

  // Free the memory allocated for the buckets
  for (int i = 0; i < MAX_VALUE / BUCKET_SIZE; i++) {
    free(buckets[i]);
  }
  free(buckets);
}

// Function to print the array
void print_array(int *array, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main() {
  // Create an input array
  int array[] = {4, 2, 1, 5, 3, 9, 7, 8, 6};
  int size = sizeof(array) / sizeof(array[0]);

  // Sort the array using bucket sort
  bucket_sort(array, size);

  // Print the sorted array
  print_array(array, size);

  return 0;
}