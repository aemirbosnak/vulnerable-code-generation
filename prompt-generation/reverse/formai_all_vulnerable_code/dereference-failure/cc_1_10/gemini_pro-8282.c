//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// a function to measure the elapsed time
double elapsed_time(clock_t start, clock_t end) {
  return (double)(end - start) / CLOCKS_PER_SEC;
}

// a function to generate a random array
int* generate_array(int size) {
  int* array = (int*)malloc(sizeof(int) * size);
  for (int i = 0; i < size; i++) {
    array[i] = rand() % size;
  }
  return array;
}

// a function to sort an array using the bubble sort algorithm
void bubble_sort(int* array, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}

// a function to sort an array using the selection sort algorithm
void selection_sort(int* array, int size) {
  for (int i = 0; i < size; i++) {
    int min_index = i;
    for (int j = i + 1; j < size; j++) {
      if (array[j] < array[min_index]) {
        min_index = j;
      }
    }
    int temp = array[i];
    array[i] = array[min_index];
    array[min_index] = temp;
  }
}

// a function to sort an array using the insertion sort algorithm
void insertion_sort(int* array, int size) {
  for (int i = 1; i < size; i++) {
    int key = array[i];
    int j = i - 1;
    while (j >= 0 && array[j] > key) {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = key;
  }
}

// a function to sort an array using the merge sort algorithm
void merge_sort(int* array, int size) {
  if (size <= 1) {
    return;
  }
  int mid = size / 2;
  int* left_array = (int*)malloc(sizeof(int) * mid);
  int* right_array = (int*)malloc(sizeof(int) * (size - mid));
  for (int i = 0; i < mid; i++) {
    left_array[i] = array[i];
  }
  for (int i = mid; i < size; i++) {
    right_array[i - mid] = array[i];
  }
  merge_sort(left_array, mid);
  merge_sort(right_array, size - mid);
  int left_index = 0;
  int right_index = 0;
  int merged_index = 0;
  while (left_index < mid && right_index < size - mid) {
    if (left_array[left_index] <= right_array[right_index]) {
      array[merged_index] = left_array[left_index];
      left_index++;
    } else {
      array[merged_index] = right_array[right_index];
      right_index++;
    }
    merged_index++;
  }
  while (left_index < mid) {
    array[merged_index] = left_array[left_index];
    left_index++;
    merged_index++;
  }
  while (right_index < size - mid) {
    array[merged_index] = right_array[right_index];
    right_index++;
    merged_index++;
  }
  free(left_array);
  free(right_array);
}

// a function to sort an array using the quick sort algorithm
void quick_sort(int* array, int size) {
  if (size <= 1) {
    return;
  }
  int pivot = array[size / 2];
  int left_index = 0;
  int right_index = size - 1;
  while (left_index <= right_index) {
    while (array[left_index] < pivot) {
      left_index++;
    }
    while (array[right_index] > pivot) {
      right_index--;
    }
    if (left_index <= right_index) {
      int temp = array[left_index];
      array[left_index] = array[right_index];
      array[right_index] = temp;
      left_index++;
      right_index--;
    }
  }
  quick_sort(array, left_index);
  quick_sort(array + left_index, size - left_index);
}

int main() {
  // generate an array of random numbers
  int size = 100000;
  int* array = generate_array(size);

  // print the unsorted array
  printf("Unsorted array:\n");
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  // sort the array using the bubble sort algorithm
  clock_t start = clock();
  bubble_sort(array, size);
  clock_t end = clock();
  printf("Bubble sort elapsed time: %f seconds\n", elapsed_time(start, end));

  // sort the array using the selection sort algorithm
  start = clock();
  selection_sort(array, size);
  end = clock();
  printf("Selection sort elapsed time: %f seconds\n", elapsed_time(start, end));

  // sort the array using the insertion sort algorithm
  start = clock();
  insertion_sort(array, size);
  end = clock();
  printf("Insertion sort elapsed time: %f seconds\n", elapsed_time(start, end));

  // sort the array using the merge sort algorithm
  start = clock();
  merge_sort(array, size);
  end = clock();
  printf("Merge sort elapsed time: %f seconds\n", elapsed_time(start, end));

  // sort the array using the quick sort algorithm
  start = clock();
  quick_sort(array, size);
  end = clock();
  printf("Quick sort elapsed time: %f seconds\n", elapsed_time(start, end));

  // print the sorted array
  printf("Sorted array:\n");
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  // free the array
  free(array);

  return 0;
}