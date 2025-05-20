//FormAI DATASET v1.0 Category: Sorting ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// function to swap two integer values
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// function to perform bubble sort
void bubbleSort(int arr[], int n) {
  int i, j;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]);
      }
    }
  }
}

// function to perform insertion sort
void insertionSort(int arr[], int n) {
  int i, j, key;
  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

// function to perform selection sort
void selectionSort(int arr[], int n) {
  int i, j, min_idx;
  for (i = 0; i < n - 1; i++) {
    min_idx = i;
    for (j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }
    swap(&arr[min_idx], &arr[i]);
  }
}

// function to print the sorted array
void printArray(int arr[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int choice, n, i;
  printf("Select the type of sorting algorithm you want to perform:\n");
  printf("1. Bubble Sort\n2. Insertion Sort\n3. Selection Sort\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  printf("Enter the size of the array: ");
  scanf("%d", &n);
  int arr[n];

  printf("Enter the elements of the array:\n");
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  switch (choice) {
    case 1:
      printf("Performing bubble sort\n");
      bubbleSort(arr, n);
      printArray(arr, n);
      break;
    case 2:
      printf("Performing insertion sort\n");
      insertionSort(arr, n);
      printArray(arr, n);
      break;
    case 3:
      printf("Performing selection sort\n");
      selectionSort(arr, n);
      printArray(arr, n);
      break;
    default:
      printf("Invalid choice!\n");
  }

  return 0;
}