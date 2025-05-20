//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Define a custom memory management function
void* my_malloc(size_t size) {
  // Allocate memory using the standard malloc function
  void* ptr = malloc(size);

  // Check if the allocation was successful
  if (ptr == NULL) {
    // If the allocation failed, print an error message and exit the program
    fprintf(stderr, "Error: Could not allocate memory.\n");
    exit(1);
  }

  // Return the allocated memory pointer
  return ptr;
}

// Define a custom memory free function
void my_free(void* ptr) {
  // Free the memory using the standard free function
  free(ptr);
}

// Define a custom memory reallocation function
void* my_realloc(void* ptr, size_t size) {
  // Reallocate memory using the standard realloc function
  void* new_ptr = realloc(ptr, size);

  // Check if the reallocation was successful
  if (new_ptr == NULL) {
    // If the reallocation failed, print an error message and exit the program
    fprintf(stderr, "Error: Could not reallocate memory.\n");
    exit(1);
  }

  // Return the reallocated memory pointer
  return new_ptr;
}

// Define a data structure to store a list of integers
typedef struct {
  int* data;
  int size;
  int capacity;
} int_list;

// Create a new int_list
int_list* int_list_new() {
  // Allocate memory for the int_list
  int_list* list = my_malloc(sizeof(int_list));

  // Initialize the int_list
  list->data = NULL;
  list->size = 0;
  list->capacity = 0;

  // Return the int_list
  return list;
}

// Free an int_list
void int_list_free(int_list* list) {
  // Free the int_list's data
  my_free(list->data);

  // Free the int_list
  my_free(list);
}

// Add an integer to the int_list
void int_list_add(int_list* list, int value) {
  // If the int_list's capacity is too small, reallocate it
  if (list->size == list->capacity) {
    list->capacity *= 2;
    list->data = my_realloc(list->data, list->capacity * sizeof(int));
  }

  // Add the integer to the int_list
  list->data[list->size++] = value;
}

// Get the integer at the specified index in the int_list
int int_list_get(int_list* list, int index) {
  // Check if the index is valid
  if (index < 0 || index >= list->size) {
    // If the index is invalid, print an error message and exit the program
    fprintf(stderr, "Error: Invalid index.\n");
    exit(1);
  }

  // Return the integer at the specified index
  return list->data[index];
}

// Set the integer at the specified index in the int_list
void int_list_set(int_list* list, int index, int value) {
  // Check if the index is valid
  if (index < 0 || index >= list->size) {
    // If the index is invalid, print an error message and exit the program
    fprintf(stderr, "Error: Invalid index.\n");
    exit(1);
  }

  // Set the integer at the specified index
  list->data[index] = value;
}

// Remove the integer at the specified index from the int_list
void int_list_remove(int_list* list, int index) {
  // Check if the index is valid
  if (index < 0 || index >= list->size) {
    // If the index is invalid, print an error message and exit the program
    fprintf(stderr, "Error: Invalid index.\n");
    exit(1);
  }

  // Move the remaining integers down one index
  for (int i = index + 1; i < list->size; i++) {
    list->data[i - 1] = list->data[i];
  }

  // Decrement the int_list's size
  list->size--;
}

// Print the int_list
void int_list_print(int_list* list) {
  // Print the int_list's data
  for (int i = 0; i < list->size; i++) {
    printf("%d ", list->data[i]);
  }

  // Print a newline
  printf("\n");
}

// Main function
int main() {
  // Create a new int_list
  int_list* list = int_list_new();

  // Add some integers to the int_list
  int_list_add(list, 1);
  int_list_add(list, 2);
  int_list_add(list, 3);

  // Print the int_list
  int_list_print(list);

  // Get the integer at the specified index
  int value = int_list_get(list, 1);

  // Set the integer at the specified index
  int_list_set(list, 1, 4);

  // Remove the integer at the specified index
  int_list_remove(list, 1);

  // Print the int_list
  int_list_print(list);

  // Free the int_list
  int_list_free(list);

  return 0;
}