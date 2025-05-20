//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Declare the global variables
int n;
int *arr;

// Function to take input from the user
void getInput() {
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  arr = (int *)malloc(n * sizeof(int));
  printf("Enter the elements: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
}

// Function to print the array
void printArray() {
  printf("The array is: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// Function to search for an element in the array using linear search
int linearSearch(int key) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == key) {
      return i;
    }
  }
  return -1;
}

// Function to search for an element in the array using binary search
int binarySearch(int key) {
  int low = 0;
  int high = n - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] == key) {
      return mid;
    } else if (arr[mid] < key) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

// Main function
int main() {
  // Get input from the user
  getInput();

  // Print the array
  printArray();

  // Ask the user to enter the element to be searched
  int key;
  printf("Enter the element to be searched: ");
  scanf("%d", &key);

  // Search for the element using linear search
  int result = linearSearch(key);
  if (result == -1) {
    printf("Element not found using linear search\n");
  } else {
    printf("Element found at index %d using linear search\n", result);
  }

  // Search for the element using binary search
  result = binarySearch(key);
  if (result == -1) {
    printf("Element not found using binary search\n");
  } else {
    printf("Element found at index %d using binary search\n", result);
  }

  return 0;
}