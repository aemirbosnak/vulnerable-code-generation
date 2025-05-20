//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 100

struct bucket {
  int value;
  struct bucket *next;
};

struct bucket_list {
  struct bucket *head;
  struct bucket *tail;
};

void insert_into_bucket(struct bucket_list *bucket_list, int value) {
  struct bucket *new_bucket = malloc(sizeof(struct bucket));
  new_bucket->value = value;
  new_bucket->next = NULL;

  if (bucket_list->head == NULL) {
    bucket_list->head = new_bucket;
    bucket_list->tail = new_bucket;
  } else {
    bucket_list->tail->next = new_bucket;
    bucket_list->tail = new_bucket;
  }
}

void sort_buckets(struct bucket_list *bucket_list) {
  struct bucket *current = bucket_list->head;
  struct bucket *previous = NULL;

  while (current != NULL) {
    if (previous != NULL && current->value < previous->value) {
      if (previous == bucket_list->head) {
        bucket_list->head = current;
      } else {
        previous->next = current->next;
      }

      current->next = previous;

      if (current == bucket_list->tail) {
        bucket_list->tail = previous;
      }

      previous = current;
      current = current->next;
    } else {
      previous = current;
      current = current->next;
    }
  }
}

void print_bucket_list(struct bucket_list *bucket_list) {
  struct bucket *current = bucket_list->head;

  while (current != NULL) {
    printf("%d ", current->value);
    current = current->next;
  }

  printf("\n");
}

void bucket_sort(int *array, int size) {
  struct bucket_list *bucket_lists[MAX_VALUE + 1];

  for (int i = 0; i <= MAX_VALUE; i++) {
    bucket_lists[i] = malloc(sizeof(struct bucket_list));
    bucket_lists[i]->head = NULL;
    bucket_lists[i]->tail = NULL;
  }

  for (int i = 0; i < size; i++) {
    insert_into_bucket(bucket_lists[array[i]], array[i]);
  }

  for (int i = 0; i <= MAX_VALUE; i++) {
    sort_buckets(bucket_lists[i]);
  }

  int index = 0;

  for (int i = 0; i <= MAX_VALUE; i++) {
    struct bucket *current = bucket_lists[i]->head;

    while (current != NULL) {
      array[index++] = current->value;
      current = current->next;
    }
  }

  for (int i = 0; i <= MAX_VALUE; i++) {
    free(bucket_lists[i]);
  }
}

int main() {
  int array[] = {5, 3, 1, 2, 4};

  bucket_sort(array, 5);

  for (int i = 0; i < 5; i++) {
    printf("%d ", array[i]);
  }

  printf("\n");

  return 0;
}