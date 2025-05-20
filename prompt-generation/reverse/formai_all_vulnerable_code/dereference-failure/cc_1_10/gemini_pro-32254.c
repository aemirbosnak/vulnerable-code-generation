//GEMINI-pro DATASET v1.0 Category: Educational ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 100

// Function to print the array
void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// Function to swap two elements in the array
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Function to sort the array using bubble sort
void bubbleSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]);
      }
    }
  }
}

// Function to generate a random array of size n
int *generateRandomArray(int n) {
  int *arr = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 100;
  }
  return arr;
}

// Function to check if the array is sorted
int isSorted(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] > arr[i + 1]) {
      return 0;
    }
  }
  return 1;
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a random array of size MAX_SIZE
  int *arr = generateRandomArray(MAX_SIZE);

  // Print the unsorted array
  printf("Unsorted array:\n");
  printArray(arr, MAX_SIZE);

  // Sort the array using bubble sort
  bubbleSort(arr, MAX_SIZE);

  // Print the sorted array
  printf("Sorted array:\n");
  printArray(arr, MAX_SIZE);

  // Check if the array is sorted
  int sorted = isSorted(arr, MAX_SIZE);

  // Print the result
  if (sorted) {
    printf("The array is sorted.\n");
  } else {
    printf("The array is not sorted.\n");
  }

  // Free the memory allocated for the array
  free(arr);

  return 0;
}