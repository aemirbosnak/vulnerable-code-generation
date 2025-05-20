//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Bucket {
  int *arr;
  int size;
  struct Bucket *next;
} Bucket;

void insert(Bucket *bucket, int data) {
  if (bucket->size == bucket->arr) {
    bucket = malloc(sizeof(Bucket) * 2);
    bucket->arr = malloc(MAX_SIZE * sizeof(int));
    bucket->size = MAX_SIZE;
    bucket->next = NULL;
  }
  bucket->arr[bucket->size++] = data;
}

void sort(Bucket *buckets) {
  int i, j, k;
  for (i = 0; buckets; buckets = buckets->next) {
    for (j = 0; j < buckets->size; j++) {
      for (k = 0; k < buckets->size; k++) {
        if (j != k && buckets->arr[j] > buckets->arr[k]) {
          int temp = buckets->arr[j];
          buckets->arr[j] = buckets->arr[k];
          buckets->arr[k] = temp;
        }
      }
    }
  }
}

int main() {
  Bucket *buckets = NULL;
  insert(buckets, 5);
  insert(buckets, 3);
  insert(buckets, 8);
  insert(buckets, 2);
  insert(buckets, 4);
  insert(buckets, 7);
  sort(buckets);
  for (buckets = buckets; buckets; buckets = buckets->next) {
    for (int i = 0; i < buckets->size; i++) {
      printf("%d ", buckets->arr[i]);
    }
    printf("\n");
  }
  return 0;
}