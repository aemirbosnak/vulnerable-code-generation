//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUCKETS 10

typedef struct Bucket {
  int key;
  struct Bucket* next;
} Bucket;

Bucket* createBucket(int key) {
  Bucket* bucket = (Bucket*)malloc(sizeof(Bucket));
  bucket->key = key;
  bucket->next = NULL;
  return bucket;
}

void insertIntoBucket(Bucket* bucket, int key) {
  Bucket* newBucket = createBucket(key);
  if (bucket == NULL) {
    bucket = newBucket;
  } else {
    bucket->next = newBucket;
  }
  bucket = newBucket;
}

void bucketSort(int arr[], int n) {
  Bucket* buckets[MAX_BUCKETS] = {NULL};
  for (int i = 0; i < n; i++) {
    insertIntoBucket(buckets[arr[i]], arr[i]);
  }

  int i = 0;
  for (Bucket* bucket = buckets[0]; bucket; bucket = bucket->next) {
    while (bucket) {
      arr[i++] = bucket->key;
      bucket = bucket->next;
    }
  }
}

int main() {
  int arr[] = {4, 3, 8, 6, 2, 5, 1, 9, 7, 0};
  int n = sizeof(arr) / sizeof(int);

  bucketSort(arr, n);

  printf("Sorted array:");
  for (int i = 0; i < n; i++) {
    printf(" %d", arr[i]);
  }

  printf("\n");

  return 0;
}