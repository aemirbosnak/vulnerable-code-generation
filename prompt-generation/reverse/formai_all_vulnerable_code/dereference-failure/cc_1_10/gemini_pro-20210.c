//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define a protected pointer type
typedef struct {
  int *ptr;  // The actual pointer
  int size;  // The size of the allocated memory
} ProtectedPtr;

// Create a new protected pointer
ProtectedPtr new_protected_ptr(int size) {
  ProtectedPtr ptr;
  ptr.ptr = malloc(size);
  ptr.size = size;
  return ptr;
}

// Free the memory associated with a protected pointer
void free_protected_ptr(ProtectedPtr *ptr) {
  free(ptr->ptr);
  ptr->ptr = NULL;
  ptr->size = 0;
}

// Check if a protected pointer is valid
int is_valid_protected_ptr(ProtectedPtr *ptr) {
  return ptr->ptr != NULL && ptr->size > 0;
}

// Get the actual pointer from a protected pointer
int *get_ptr(ProtectedPtr *ptr) {
  if (!is_valid_protected_ptr(ptr)) {
    fprintf(stderr, "Error: Invalid protected pointer.\n");
    exit(1);
  }
  return ptr->ptr;
}

// Set the actual pointer of a protected pointer
void set_ptr(ProtectedPtr *ptr, int *new_ptr) {
  if (!is_valid_protected_ptr(ptr)) {
    fprintf(stderr, "Error: Invalid protected pointer.\n");
    exit(1);
  }
  ptr->ptr = new_ptr;
}

// Get the size of the allocated memory associated with a protected pointer
int get_size(ProtectedPtr *ptr) {
  if (!is_valid_protected_ptr(ptr)) {
    fprintf(stderr, "Error: Invalid protected pointer.\n");
    exit(1);
  }
  return ptr->size;
}

// Print the contents of a protected pointer
void print_protected_ptr(ProtectedPtr *ptr) {
  if (!is_valid_protected_ptr(ptr)) {
    fprintf(stderr, "Error: Invalid protected pointer.\n");
    exit(1);
  }
  for (int i = 0; i < ptr->size; i++) {
    printf("%d ", ptr->ptr[i]);
  }
  printf("\n");
}

// Example usage
int main() {
  // Create a protected pointer to an array of 10 integers
  ProtectedPtr arr = new_protected_ptr(10 * sizeof(int));

  // Get the actual pointer from the protected pointer
  int *ptr = get_ptr(&arr);

  // Initialize the array with some values
  for (int i = 0; i < 10; i++) {
    ptr[i] = i * i;
  }

  // Print the contents of the array
  print_protected_ptr(&arr);

  // Free the memory associated with the protected pointer
  free_protected_ptr(&arr);

  return 0;
}