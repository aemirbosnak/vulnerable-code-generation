//FormAI DATASET v1.0 Category: Memory management ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

int main() {
  int *ptr1, *ptr2, *ptr3;

  // Allocate memory for ptr1
  ptr1 = (int *) malloc(sizeof(int));

  if (ptr1 == NULL) {
    printf("Error: Cannot allocate memory.");
    exit(1);
  } else {
    *ptr1 = 10;
    printf("Value stored in ptr1: %d\n\n", *ptr1);
  }

  // Allocate memory for ptr2
  ptr2 = (int *) calloc(3, sizeof(int));

  if (ptr2 == NULL) {
    printf("Error: Cannot allocate memory.");
    exit(1);
  } else {
    printf("Values stored in ptr2: ");

    // Assign values to ptr2 array
    for (int i = 0; i < 3; i++) {
      *(ptr2 + i) = i * 2;
      printf("%d ", *(ptr2 + i));
    }

    printf("\n\n");
  }

  // Allocate memory for ptr3
  ptr3 = (int *) realloc(ptr2, 5 * sizeof(int));

  if (ptr3 == NULL) {
    printf("Error: Cannot reallocate memory.");
    exit(1);
  } else {
    printf("Values stored in ptr3: ");

    // Print values of ptr3 array
    for (int i = 0; i < 5; i++) {
      printf("%d ", *(ptr3 + i));
    }

    printf("\n\n");
  }

  // Free memory
  free(ptr1);
  free(ptr3);

  return 0;
}