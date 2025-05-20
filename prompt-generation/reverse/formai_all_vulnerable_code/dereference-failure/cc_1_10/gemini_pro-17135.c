//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random array of integers
int *generateRandomArray(int size) {
  int *array = (int *)malloc(size * sizeof(int));
  for (int i = 0; i < size; i++) {
    array[i] = rand() % 100;
  }
  return array;
}

// Function to find the maximum element in an array
int findMaxElement(int *array, int size) {
  int max = array[0];
  for (int i = 1; i < size; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }
  return max;
}

// Function to find the minimum element in an array
int findMinElement(int *array, int size) {
  int min = array[0];
  for (int i = 1; i < size; i++) {
    if (array[i] < min) {
      min = array[i];
    }
  }
  return min;
}

// Function to calculate the average of an array
double calculateAverage(int *array, int size) {
  double sum = 0;
  for (int i = 0; i < size; i++) {
    sum += array[i];
  }
  return sum / size;
}

// Function to print an array
void printArray(int *array, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Create an array of 1000 random integers
  int *array = generateRandomArray(1000);

  // Find the maximum element in the array
  int maxElement = findMaxElement(array, 1000);

  // Find the minimum element in the array
  int minElement = findMinElement(array, 1000);

  // Calculate the average of the array
  double average = calculateAverage(array, 1000);

  // Print the array, the maximum element, the minimum element, and the average
  printArray(array, 1000);
  printf("Maximum element: %d\n", maxElement);
  printf("Minimum element: %d\n", minElement);
  printf("Average: %f\n", average);

  // Free the memory allocated for the array
  free(array);

  return 0;
}