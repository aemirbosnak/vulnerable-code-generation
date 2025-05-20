//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to swap two elements in an array
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Function to sort an array using the bubble sort algorithm
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

// Function to print an array
void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// Function to generate a random array of integers
int *generateRandomArray(int n) {
  int *arr = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 100;
  }
  return arr;
}

// Main function
int main() {
  // Generate a random array of integers
  int n = MAX_SIZE;
  int *arr = generateRandomArray(n);

  // Print the unsorted array
  printf("Unsorted array: ");
  printArray(arr, n);

  // Sort the array using the bubble sort algorithm
  bubbleSort(arr, n);

  // Print the sorted array
  printf("Sorted array: ");
  printArray(arr, n);

  // Free the allocated memory
  free(arr);

  return 0;
}