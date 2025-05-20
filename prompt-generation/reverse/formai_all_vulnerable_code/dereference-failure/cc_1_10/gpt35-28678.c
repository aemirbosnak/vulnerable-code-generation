//FormAI DATASET v1.0 Category: Error handling ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void checkDivideByZero(int);
void checkPointerNull(void *);
void checkArrayOutOfBounds(int *, int);

int main() {
  int num1 = 10;
  int num2 = 0;
  int *arr = (int *)malloc(5 * sizeof(int));
  int index = 6;

  // Check for divide by zero error
  checkDivideByZero(num2);

  // Check for null pointer error
  checkPointerNull(arr);

  // Check for array out of bounds error
  checkArrayOutOfBounds(arr, index);

  // Free the allocated memory
  free(arr);

  return 0;
}

/*
 * Check if the integer is zero before performing division
 * Throw an error message if it is zero
 */
void checkDivideByZero(int num) {
  if (num == 0) {
    fprintf(stderr, "Error: Divide by zero\n");
    exit(EXIT_FAILURE);
  } else {
    printf("Result: %d\n", 10 / num);
  }
}

/*
 * Check if the pointer is null before accessing its value
 * Throw an error message if it is null
 */
void checkPointerNull(void *ptr) {
  if (ptr == NULL) {
    fprintf(stderr, "Error: Null pointer\n");
    exit(EXIT_FAILURE);
  } else {
    printf("Pointer value: %p\n", ptr);
  }
}

/*
 * Check if the array index is within bounds
 * Throw an error message if it is out of bounds
 */
void checkArrayOutOfBounds(int *arr, int index) {
  if (index < 0 || index > 4) {
    fprintf(stderr, "Error: Array index out of bounds\n");
    exit(EXIT_FAILURE);
  } else {
    printf("Array element: %d\n", arr[index]);
  }
}