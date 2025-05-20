//FormAI DATASET v1.0 Category: Benchmarking ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000

int* generate_random_array() {
  int* array = malloc(sizeof(int) * ARRAY_SIZE);
  for (int i = 0; i < ARRAY_SIZE; i++) {
    array[i] = rand();
  }
  return array;
}

void print_array(int* array) {
  for (int i = 0; i < ARRAY_SIZE; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void bubble_sort(int* array) {
  for (int i = 0; i < ARRAY_SIZE - 1; i++) {
    for (int j = 0; j < ARRAY_SIZE - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}

void quick_sort(int* array, int left, int right) {
  if (left >= right) {
    return;
  }
  int pivot = array[(left + right) / 2];
  int i = left;
  int j = right;
  while (i <= j) {
    while (array[i] < pivot) {
      i++;
    }
    while (array[j] > pivot) {
      j--;
    }
    if (i <= j) {
      int temp = array[i];
      array[i] = array[j];
      array[j] = temp;
      i++;
      j--;
    }
  }
  quick_sort(array, left, j);
  quick_sort(array, i, right);
}

int main() {
  int* array = generate_random_array();
  printf("Original Array:\n");
  print_array(array);
  
  clock_t start_bubble = clock();
  bubble_sort(array);
  clock_t end_bubble = clock();
  double time_bubble = (double)(end_bubble - start_bubble) / CLOCKS_PER_SEC;
  printf("Bubble Sort Result:\n");
  print_array(array);
  printf("Bubble Sort Time: %f seconds\n", time_bubble);
  
  clock_t start_quick = clock();
  quick_sort(array, 0, ARRAY_SIZE - 1);
  clock_t end_quick = clock();
  double time_quick = (double)(end_quick - start_quick) / CLOCKS_PER_SEC;
  printf("Quick Sort Result:\n");
  print_array(array);
  printf("Quick Sort Time: %f seconds\n", time_quick);
  
  free(array);
  return 0;
}