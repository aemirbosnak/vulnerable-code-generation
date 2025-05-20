//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables that store the memory addresses of the dynamically allocated arrays
int* g_arr1;
int* g_arr2;
char* g_str1;
char* g_str2;

// Function to dynamically allocate memory for the arrays
void* allocate_mem(size_t size, const char* func) {
  void* mem = malloc(size);
  if (mem == NULL) {
    fprintf(stderr, "%s: failed to allocate memory\n", func);
    exit(EXIT_FAILURE);
  }
  return mem;
}

// Function to deallocate the memory allocated by allocate_mem
void deallocate_mem(void* mem, const char* func) {
  free(mem);
}

int main() {
  // Dynamically allocate memory for the first array
  g_arr1 = allocate_mem(10 * sizeof(int), "g_arr1");
  if (g_arr1 == NULL) {
    fprintf(stderr, "Failed to allocate memory for g_arr1\n");
    return EXIT_FAILURE;
  }

  // Dynamically allocate memory for the second array
  g_arr2 = allocate_mem(20 * sizeof(int), "g_arr2");
  if (g_arr2 == NULL) {
    fprintf(stderr, "Failed to allocate memory for g_arr2\n");
    deallocate_mem(g_arr1, "g_arr1");
    return EXIT_FAILURE;
  }

  // Dynamically allocate memory for the first string
  g_str1 = allocate_mem(10 * sizeof(char), "g_str1");
  if (g_str1 == NULL) {
    fprintf(stderr, "Failed to allocate memory for g_str1\n");
    deallocate_mem(g_arr1, "g_arr1");
    deallocate_mem(g_arr2, "g_arr2");
    return EXIT_FAILURE;
  }

  // Dynamically allocate memory for the second string
  g_str2 = allocate_mem(20 * sizeof(char), "g_str2");
  if (g_str2 == NULL) {
    fprintf(stderr, "Failed to allocate memory for g_str2\n");
    deallocate_mem(g_str1, "g_str1");
    deallocate_mem(g_arr1, "g_arr1");
    deallocate_mem(g_arr2, "g_arr2");
    return EXIT_FAILURE;
  }

  // Print the memory addresses of the dynamically allocated arrays
  printf("g_arr1: %p\n", g_arr1);
  printf("g_arr2: %p\n", g_arr2);
  printf("g_str1: %p\n", g_str1);
  printf("g_str2: %p\n", g_str2);

  // Deallocate the memory allocated by allocate_mem
  deallocate_mem(g_arr1, "g_arr1");
  deallocate_mem(g_arr2, "g_arr2");
  deallocate_mem(g_str1, "g_str1");
  deallocate_mem(g_str2, "g_str2");

  return EXIT_SUCCESS;
}