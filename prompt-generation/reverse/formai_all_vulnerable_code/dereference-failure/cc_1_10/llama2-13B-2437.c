//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a function to swap two elements
void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Define a function to sort an array of integers
void sort(int arr[], int low, int high) {
  // Base case: if the length of the array is 1 or less, return
  if (low >= high) return;

  // Partition the array into two halves
  int mid = (low + high) / 2;
  swap(arr[low], arr[mid]);
  swap(arr[high], arr[low]);

  // Recursively sort the two halves
  sort(arr, low, mid - 1);
  sort(arr, mid + 1, high);
}

// Main function to demonstrate the sort function
int main() {
  // Generate a random array of integers
  int arr[10] = {5, 2, 8, 3, 1, 6, 4, 2, 9};
  int i, j, temp;

  // Print the unsorted array
  printf("Unsorted array: ");
  for (i = 0; i < 10; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  // Sort the array using the quicksort algorithm
  sort(arr, 0, 9);

  // Print the sorted array
  printf("Sorted array: ");
  for (i = 0; i < 10; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}