//FormAI DATASET v1.0 Category: Memory management ; Style: irregular
#include <stdlib.h>
#include <stdio.h>

int main() {
  // Random memory allocation sizes
  int sizes[] = {100, 200, 50, 75, 300, 150, 25, 500};
  
  // Allocate memory
  int* ptr1 = (int*) malloc(sizes[0] * sizeof(int));
  int* ptr2 = (int*) malloc(sizes[1] * sizeof(int));
  char* ptr3 = (char*) malloc(sizes[2] * sizeof(char));
  
  // Set values for first and second pointers
  for (int i=0; i < sizes[0]; i++) {
    ptr1[i] = i;
  }
  for (int i=0; i < sizes[1]; i++) {
    ptr2[i] = i*2;
  }
  
  // Fill third pointer with characters
  for (int i=0; i < sizes[2]; i++) {
    ptr3[i] = 'a' + i;
  }
  
  // Print out values
  printf("Pointer 1 values:\n");
  for (int i=0; i < sizes[0]; i++) {
    printf("%d ", ptr1[i]);
  }
  printf("\n\n");
  
  printf("Pointer 2 values:\n");
  for (int i=0; i < sizes[1]; i++) {
    printf("%d ", ptr2[i]);
  }
  printf("\n\n");
  
  printf("Pointer 3 values:\n");
  for (int i=0; i < sizes[2]; i++) {
    printf("%c ", ptr3[i]);
  }
  printf("\n\n");
  
  // Free memory
  free(ptr1);
  free(ptr2);
  free(ptr3);
  
  return 0;
}