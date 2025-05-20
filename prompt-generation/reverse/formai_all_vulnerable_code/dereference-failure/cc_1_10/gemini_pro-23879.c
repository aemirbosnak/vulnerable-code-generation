//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: immersive
// Welcome to the Memory Odyssey, where we embark on a journey through the labyrinthine realm of memory management!

#include <stdio.h>
#include <stdlib.h>

int main() {
  // **Chapter 1: The Allocation Maze**

  int *intPointer = (int *)malloc(sizeof(int)); // Allocate an integer
  if (intPointer == NULL) {
    printf("Oh no! We've stumbled into a null pointer abyss! Memory allocation failed!");
    return EXIT_FAILURE;
  }

  // **Chapter 2: The Pointer Playground**

  *intPointer = 42; // Assign the integer value 42
  printf("Behold the secret of life hidden within our allocated memory: %d\n", *intPointer);

  // **Chapter 3: The Dereference Dilemma**

  int anotherInteger = *intPointer; // Dereference the pointer to retrieve the value
  printf("The mystery unfolds! We've dereferenced our way to: %d\n", anotherInteger);

  // **Chapter 4: The Memory Minefield**

  free(intPointer); // Release the allocated memory to avoid the dreaded memory leak
  if (intPointer != NULL) {
    printf("Whoops! We've stepped on a dangling pointer! Resetting to avoid chaos.\n");
    intPointer = NULL;
  }

  // **Chapter 5: The Reallocation Realm**

  intPointer = (int *)realloc(intPointer, 2 * sizeof(int)); // Resize the allocated memory
  if (intPointer == NULL) {
    printf("Expansion failed! We're stuck in a memory bottleneck.");
    return EXIT_FAILURE;
  }

  // **Chapter 6: The Memory Map**

  int *secondInteger = (int *)calloc(1, sizeof(int)); // Allocate and initialize to zero
  printf("Exploring a new memory region! Starting with a pristine zero: %d\n", *secondInteger);

  // **Chapter 7: The Memory Maze**

  int **doublePointer = (int **)malloc(sizeof(int *)); // Pointer to a pointer
  *doublePointer = intPointer; // Assign the pointer to the allocated memory
  printf("Entering the memory maze! Navigating through the layers: %d\n", **doublePointer);

  // **Chapter 8: The Memory Cleanup**

  free(intPointer); // Clean up the primary allocation
  free(doublePointer); // Clean up the pointer to the allocation

  // **The Grand Finale: The Memory Odyssey**

  printf("Congratulations! You've traversed the Memory Odyssey, mastering the art of memory management.\n");
  return EXIT_SUCCESS;
}