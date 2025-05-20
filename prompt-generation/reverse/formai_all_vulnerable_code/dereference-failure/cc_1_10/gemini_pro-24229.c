//GEMINI-pro DATASET v1.0 Category: Educational ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Define the maximum number of elements to be generated
#define MAX_ELEMENTS 20

// Function to generate random numbers
int generateRandomNumber(int min, int max) {
  return (rand() % (max - min + 1)) + min;
}

// Function to create an array of random numbers
int* createRandomArray(int size) {
  int* array = (int*)malloc(sizeof(int) * size);
  for (int i = 0; i < size; i++) {
    array[i] = generateRandomNumber(1, 100);
  }
  return array;
}

// Function to print an array
void printArray(int* array, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

// Function to find the maximum element in an array
int findMaxElement(int* array, int size) {
  int maxElement = array[0];
  for (int i = 1; i < size; i++) {
    if (array[i] > maxElement) {
      maxElement = array[i];
    }
  }
  return maxElement;
}

// Function to find the minimum element in an array
int findMinElement(int* array, int size) {
  int minElement = array[0];
  for (int i = 1; i < size; i++) {
    if (array[i] < minElement) {
      minElement = array[i];
    }
  }
  return minElement;
}

// Function to find the average of all elements in an array
float findAverage(int* array, int size) {
  float sum = 0;
  for (int i = 0; i < size; i++) {
    sum += array[i];
  }
  return sum / size;
}

// Function to main
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Create an array of random numbers
  int* array = createRandomArray(MAX_SIZE);

  // Print the original array
  printf("Original array: ");
  printArray(array, MAX_SIZE);

  // Find the maximum element in the array
  int maxElement = findMaxElement(array, MAX_SIZE);

  // Find the minimum element in the array
  int minElement = findMinElement(array, MAX_SIZE);

  // Find the average of all elements in the array
  float average = findAverage(array, MAX_SIZE);

  // Print the maximum element, minimum element, and average
  printf("Maximum element: %d\n", maxElement);
  printf("Minimum element: %d\n", minElement);
  printf("Average: %.2f\n", average);

  // Free the allocated memory
  free(array);

  return 0;
}