//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A simple swap function to swap two elements
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// A function to generate a random array of integers
int *generate_random_array(int size) {
  int *array = malloc(sizeof(int) * size);
  for (int i = 0; i < size; i++) {
    array[i] = rand() % 100;
  }
  return array;
}

// A function to print an array of integers
void print_array(int *array, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

// A function to sort an array of integers using the bubble sort algorithm
void bubble_sort(int *array, int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        swap(&array[j], &array[j + 1]);
      }
    }
  }
}

// A function to sort an array of integers using the selection sort algorithm
void selection_sort(int *array, int size) {
  for (int i = 0; i < size - 1; i++) {
    int min_index = i;
    for (int j = i + 1; j < size; j++) {
      if (array[j] < array[min_index]) {
        min_index = j;
      }
    }
    swap(&array[min_index], &array[i]);
  }
}

// A function to sort an array of integers using the insertion sort algorithm
void insertion_sort(int *array, int size) {
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

// A function to sort an array of integers using the merge sort algorithm
void merge_sort(int *array, int size) {
  if (size <= 1) {
    return;
  }

  int mid = size / 2;
  int *left = malloc(sizeof(int) * mid);
  int *right = malloc(sizeof(int) * (size - mid));

  for (int i = 0; i < mid; i++) {
    left[i] = array[i];
  }

  for (int i = mid; i < size; i++) {
    right[i - mid] = array[i];
  }

  merge_sort(left, mid);
  merge_sort(right, size - mid);

  int i = 0;
  int j = 0;
  int k = 0;

  while (i < mid && j < size - mid) {
    if (left[i] <= right[j]) {
      array[k] = left[i];
      i++;
    } else {
      array[k] = right[j];
      j++;
    }
    k++;
  }

  while (i < mid) {
    array[k] = left[i];
    i++;
    k++;
  }

  while (j < size - mid) {
    array[k] = right[j];
    j++;
    k++;
  }

  free(left);
  free(right);
}

// A function to sort an array of integers using the quick sort algorithm
void quick_sort(int *array, int size) {
  if (size <= 1) {
    return;
  }

  int pivot = array[size - 1];
  int i = 0;
  int j = size - 2;

  while (i <= j) {
    if (array[i] <= pivot) {
      i++;
    } else if (array[j] > pivot) {
      j--;
    } else {
      swap(&array[i], &array[j]);
      i++;
      j--;
    }
  }

  swap(&array[i], &array[size - 1]);

  quick_sort(array, i);
  quick_sort(&array[i + 1], size - i - 1);
}

// A function to test the sorting algorithms
void test_sorting_algorithms() {
  int size = 10;
  int *array = generate_random_array(size);

  printf("Original array:\n");
  print_array(array, size);

  bubble_sort(array, size);
  printf("Bubble sort:\n");
  print_array(array, size);

  selection_sort(array, size);
  printf("Selection sort:\n");
  print_array(array, size);

  insertion_sort(array, size);
  printf("Insertion sort:\n");
  print_array(array, size);

  merge_sort(array, size);
  printf("Merge sort:\n");
  print_array(array, size);

  quick_sort(array, size);
  printf("Quick sort:\n");
  print_array(array, size);

  free(array);
}

int main() {
  srand(time(NULL));

  test_sorting_algorithms();

  return 0;
}