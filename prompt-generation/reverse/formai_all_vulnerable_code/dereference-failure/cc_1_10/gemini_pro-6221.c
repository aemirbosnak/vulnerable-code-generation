//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COUNT 1000000
#define ASCENDING 1
#define DESCENDING -1

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubble_sort(int *arr, int size, int order) {
  int i, j;
  for (i = 0; i < size - 1; i++) {
    for (j = 0; j < size - i - 1; j++) {
      if ((arr[j] > arr[j + 1] && order == ASCENDING) ||
          (arr[j] < arr[j + 1] && order == DESCENDING)) {
        swap(&arr[j], &arr[j + 1]);
      }
    }
  }
}

int main() {
  int *arr = (int *)malloc(COUNT * sizeof(int));
  srand(time(NULL));
  for (int i = 0; i < COUNT; i++) {
    arr[i] = rand() % COUNT;
  }

  printf("Unsorted array:\n");
  for (int i = 0; i < 10; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  struct timespec start, end;
  clock_gettime(CLOCK_MONOTONIC_RAW, &start);
  bubble_sort(arr, COUNT, ASCENDING);
  clock_gettime(CLOCK_MONOTONIC_RAW, &end);
  unsigned long long delta_us =
      (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000;
  printf("Sorted array in ascending order (time: %llu microseconds):\n", delta_us);
  for (int i = 0; i < 10; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  clock_gettime(CLOCK_MONOTONIC_RAW, &start);
  bubble_sort(arr, COUNT, DESCENDING);
  clock_gettime(CLOCK_MONOTONIC_RAW, &end);
  delta_us =
      (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000;
  printf("Sorted array in descending order (time: %llu microseconds):\n", delta_us);
  for (int i = 0; i < 10; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  free(arr);
  return 0;
}