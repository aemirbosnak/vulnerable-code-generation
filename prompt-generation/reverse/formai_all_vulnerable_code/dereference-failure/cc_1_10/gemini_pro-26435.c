//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000

typedef struct {
  int *data;
  int size;
  int capacity;
} array;

array *new_array(int capacity) {
  array *a = malloc(sizeof(array));
  if (a == NULL) {
    fprintf(stderr, "Error: malloc failed\n");
    exit(1);
  }
  a->data = malloc(capacity * sizeof(int));
  if (a->data == NULL) {
    fprintf(stderr, "Error: malloc failed\n");
    exit(1);
  }
  a->size = 0;
  a->capacity = capacity;
  return a;
}

void free_array(array *a) {
  free(a->data);
  free(a);
}

void push_back(array *a, int value) {
  if (a->size == a->capacity) {
    a->data = realloc(a->data, 2 * a->capacity * sizeof(int));
    if (a->data == NULL) {
      fprintf(stderr, "Error: realloc failed\n");
      exit(1);
    }
    a->capacity *= 2;
  }
  a->data[a->size++] = value;
}

int pop_back(array *a) {
  if (a->size == 0) {
    fprintf(stderr, "Error: array is empty\n");
    exit(1);
  }
  return a->data[--a->size];
}

void print_array(array *a) {
  printf("[");
  for (int i = 0; i < a->size; i++) {
    printf("%d, ", a->data[i]);
  }
  printf("]\n");
}

int main() {
  int n;
  scanf("%d", &n);

  array *a = new_array(n);

  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    push_back(a, x);
  }

  print_array(a);

  int x = pop_back(a);
  printf("Popped: %d\n", x);

  print_array(a);

  free_array(a);

  return 0;
}