//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUCKET_SIZE 10

typedef struct Bucket {
  int *arr;
  int size;
  struct Bucket *next;
} Bucket;

void insert_bucket(Bucket **buckets, int data) {
  Bucket *new_bucket = malloc(sizeof(Bucket));
  new_bucket->arr = malloc(BUCKET_SIZE * sizeof(int));
  new_bucket->size = 0;
  new_bucket->next = NULL;

  if (*buckets == NULL) {
    *buckets = new_bucket;
  } else {
    (*buckets)->next = new_bucket;
  }

  new_bucket->arr[new_bucket->size++] = data;
}

void bucket_sort(Bucket **buckets) {
  int i, j, k, max_size = 0;

  for (i = 0; buckets[i] != NULL; i++) {
    max_size = fmax(max_size, buckets[i]->size);
  }

  for (j = 0; j < max_size; j++) {
    for (k = 0; buckets[k] != NULL; k++) {
      if (buckets[k]->arr[j] != NULL) {
        printf("%d ", buckets[k]->arr[j]);
      }
    }
    printf("\n");
  }
}

int main() {
  time_t t1, t2;

  t1 = time(NULL);

  int n = 100000;
  Bucket **buckets = NULL;
  for (int i = 0; i < n; i++) {
    insert_bucket(buckets, rand() % 1000);
  }

  bucket_sort(buckets);

  t2 = time(NULL);

  printf("Time taken: %ld seconds\n", t2 - t1);

  return 0;
}