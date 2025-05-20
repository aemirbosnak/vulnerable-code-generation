//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// A bucket is an array of integers
struct Bucket {
  int* arr;
  int capacity;
  int size;
};

// Create a new bucket with the given capacity
struct Bucket* createBucket(int capacity) {
  struct Bucket* bucket = malloc(sizeof(struct Bucket));
  bucket->arr = malloc(sizeof(int) * capacity);
  bucket->capacity = capacity;
  bucket->size = 0;
  return bucket;
}

// Insert an integer into the bucket
void insert(struct Bucket* bucket, int num) {
  if (bucket->size == bucket->capacity) {
    printf("Bucket overflow\n");
    return;
  }
  bucket->arr[bucket->size++] = num;
}

// Sort the bucket using insertion sort
void sortBucket(struct Bucket* bucket) {
  for (int i = 1; i < bucket->size; i++) {
    int key = bucket->arr[i];
    int j = i - 1;
    while (j >= 0 && bucket->arr[j] > key) {
      bucket->arr[j + 1] = bucket->arr[j];
      j--;
    }
    bucket->arr[j + 1] = key;
  }
}

// Create an array of buckets
struct Bucket** createBuckets(int numBuckets) {
  struct Bucket** buckets = malloc(sizeof(struct Bucket*) * numBuckets);
  for (int i = 0; i < numBuckets; i++) {
    buckets[i] = createBucket(100);
  }
  return buckets;
}

// Insert integers into the buckets based on their values
void distribute(struct Bucket** buckets, int* arr, int size) {
  for (int i = 0; i < size; i++) {
    int bucketIndex = arr[i] / 10;
    insert(buckets[bucketIndex], arr[i]);
  }
}

// Sort the buckets and concatenate them into a single array
void bucketSort(int* arr, int size) {
  // Create an array of buckets
  struct Bucket** buckets = createBuckets(10);

  // Distribute the integers into the buckets
  distribute(buckets, arr, size);

  // Sort each bucket
  for (int i = 0; i < 10; i++) {
    sortBucket(buckets[i]);
  }

  // Concatenate the sorted buckets into a single array
  int index = 0;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < buckets[i]->size; j++) {
      arr[index++] = buckets[i]->arr[j];
    }
  }
}

// Print the array
void printArray(int* arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[] = {9, 7, 5, 3, 1, 2, 4, 6, 8, 10};
  int size = sizeof(arr) / sizeof(arr[0]);

  bucketSort(arr, size);

  printArray(arr, size);

  return 0;
}