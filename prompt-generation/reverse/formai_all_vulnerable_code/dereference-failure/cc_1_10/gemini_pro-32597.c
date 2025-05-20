//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a bucket
typedef struct Bucket {
  int *array;
  int size;
  int capacity;
} Bucket;

// A function to create a bucket of a given capacity
Bucket *createBucket(int capacity) {
  Bucket *bucket = (Bucket *)malloc(sizeof(Bucket));
  bucket->array = (int *)malloc(sizeof(int) * capacity);
  bucket->size = 0;
  bucket->capacity = capacity;
  return bucket;
}

// A function to insert an element into a bucket
void insertIntoBucket(Bucket *bucket, int element) {
  if (bucket->size == bucket->capacity) {
    // If the bucket is full, double its capacity
    bucket->capacity *= 2;
    bucket->array = (int *)realloc(bucket->array, sizeof(int) * bucket->capacity);
  }
  bucket->array[bucket->size++] = element;
}

// A function to sort the elements in a bucket
void sortBucket(Bucket *bucket) {
  for (int i = 0; i < bucket->size - 1; i++) {
    for (int j = 0; j < bucket->size - i - 1; j++) {
      if (bucket->array[j] > bucket->array[j + 1]) {
        int temp = bucket->array[j];
        bucket->array[j] = bucket->array[j + 1];
        bucket->array[j + 1] = temp;
      }
    }
  }
}

// A function to perform bucket sort on an array
void bucketSort(int *array, int size) {
  // Create an array of buckets
  Bucket **buckets = (Bucket **)malloc(sizeof(Bucket *) * size);

  // Create a bucket for each possible value in the array
  for (int i = 0; i < size; i++) {
    buckets[i] = createBucket(size);
  }

  // Insert each element into its corresponding bucket
  for (int i = 0; i < size; i++) {
    insertIntoBucket(buckets[array[i]], array[i]);
  }

  // Sort the elements in each bucket
  for (int i = 0; i < size; i++) {
    sortBucket(buckets[i]);
  }

  // Concatenate the sorted buckets into a single array
  int index = 0;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < buckets[i]->size; j++) {
      array[index++] = buckets[i]->array[j];
    }
  }

  // Free the memory allocated for the buckets
  for (int i = 0; i < size; i++) {
    free(buckets[i]->array);
    free(buckets[i]);
  }
  free(buckets);
}

// A function to print an array
void printArray(int *array, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

// A function to generate a random array of integers
int *generateRandomArray(int size) {
  int *array = (int *)malloc(sizeof(int) * size);
  for (int i = 0; i < size; i++) {
    array[i] = rand() % size;
  }
  return array;
}

int main() {
  // Generate a random array of integers
  int size = 100;
  int *array = generateRandomArray(size);

  // Print the unsorted array
  printf("Unsorted array: ");
  printArray(array, size);

  // Sort the array using bucket sort
  bucketSort(array, size);

  // Print the sorted array
  printf("Sorted array: ");
  printArray(array, size);

  return 0;
}