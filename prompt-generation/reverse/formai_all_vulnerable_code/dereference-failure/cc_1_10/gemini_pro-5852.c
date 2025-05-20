//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_SIZE 100

typedef struct bucket {
  int *data;
  int size;
  int capacity;
} bucket;

bucket *create_bucket(int capacity) {
  bucket *b = (bucket *)malloc(sizeof(bucket));
  b->data = (int *)malloc(sizeof(int) * capacity);
  b->size = 0;
  b->capacity = capacity;
  return b;
}

void free_bucket(bucket *b) {
  free(b->data);
  free(b);
}

void insert_bucket(bucket *b, int value) {
  assert(b->size < b->capacity);
  b->data[b->size++] = value;
}

void bucket_sort(int *array, int size) {
  int min = array[0], max = array[0];
  for (int i = 1; i < size; i++) {
    if (array[i] < min) {
      min = array[i];
    } else if (array[i] > max) {
      max = array[i];
    }
  }

  int bucket_count = max - min + 1;
  bucket **buckets = (bucket **)malloc(sizeof(bucket *) * bucket_count);

  for (int i = 0; i < bucket_count; i++) {
    buckets[i] = create_bucket(size / bucket_count);
  }

  for (int i = 0; i < size; i++) {
    int index = array[i] - min;
    insert_bucket(buckets[index], array[i]);
  }

  int index = 0;
  for (int i = 0; i < bucket_count; i++) {
    for (int j = 0; j < buckets[i]->size; j++) {
      array[index++] = buckets[i]->data[j];
    }
    free_bucket(buckets[i]);
  }
  free(buckets);
}

int main() {
  int array[] = {10, 5, 8, 2, 9, 3, 1, 7, 6, 4};
  int size = sizeof(array) / sizeof(array[0]);

  bucket_sort(array, size);

  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  return 0;
}