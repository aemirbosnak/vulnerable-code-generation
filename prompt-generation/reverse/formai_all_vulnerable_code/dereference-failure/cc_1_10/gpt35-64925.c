//FormAI DATASET v1.0 Category: Educational ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000

int *generate_random_array(int array_size) {
  int *arr = (int *) malloc(sizeof(int) * array_size);

  srand(time(NULL));
  for(int i = 0; i < array_size; i++) {
    arr[i] = rand() % 1000;
  }

  return arr;
}

void bubble_sort(int *arr, int array_size) {
  int temp;
  int i, j;
  for(i = 0; i < array_size - 1; ++i) {
    for(j = 0; j < array_size - i - 1; ++j) {
      if(arr[j] > arr[j+1]) {
        temp = arr[j+1];
        arr[j+1] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

void print_array(int *arr, int array_size) {
  for(int i = 0; i < array_size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int *arr = generate_random_array(ARRAY_SIZE);
  printf("Unsorted array:\n");
  print_array(arr, ARRAY_SIZE);
  
  printf("Sorting the array using bubble sort...\n");
  bubble_sort(arr, ARRAY_SIZE);

  printf("Sorted array:\n");
  print_array(arr, ARRAY_SIZE);
  
  free(arr);
  return 0;
}