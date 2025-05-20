//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: futuristic
// Futuristic C Bucket Sort Implementation

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BUCKETS 10

typedef struct Bucket {
  int key;
  struct Bucket* next;
} Bucket;

void insertBucket(Bucket* bucket, int key) {
  Bucket* newBucket = malloc(sizeof(Bucket));
  newBucket->key = key;
  newBucket->next = NULL;

  if (bucket == NULL) {
    bucket = newBucket;
  } else {
    bucket->next = newBucket;
  }

  bucket = newBucket;
}

void bucketSort(int arr[], int n) {
  int i, key, bucketIndex;
  Bucket* buckets[MAX_BUCKETS] = { NULL };

  for (i = 0; i < n; i++) {
    key = arr[i];
    bucketIndex = key % MAX_BUCKETS;
    insertBucket(buckets[bucketIndex], key);
  }

  for (i = 0; i < MAX_BUCKETS; i++) {
    Bucket* currentBucket = buckets[i];
    while (currentBucket) {
      arr[i] = currentBucket->key;
      currentBucket = currentBucket->next;
    }
  }
}

int main() {
  int arr[] = { 4, 3, 8, 6, 2, 5, 1, 9, 7, 3 };
  int n = sizeof(arr) / sizeof(int);

  bucketSort(arr, n);

  printf("Sorted array:");
  for (int i = 0; i < n; i++) {
    printf(" %d", arr[i]);
  }

  return 0;
}