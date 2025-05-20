//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 100
#define MAX_ARR_SIZE 10

// Function to allocate memory for a string
void* alloc_str(size_t len) {
  void* mem = malloc(len + 1);
  if (mem == NULL) {
    perror("malloc failed");
    exit(EXIT_FAILURE);
  }
  memset(mem, 0, len + 1);
  return mem;
}

// Function to allocate memory for an array
void* alloc_arr(size_t size) {
  void* mem = calloc(size, sizeof(int));
  if (mem == NULL) {
    perror("calloc failed");
    exit(EXIT_FAILURE);
  }
  return mem;
}

// Function to deallocate memory for a string
void free_str(void* mem) {
  if (mem == NULL) {
    return;
  }
  free(mem);
}

// Function to deallocate memory for an array
void free_arr(void* mem) {
  if (mem == NULL) {
    return;
  }
  free(mem);
}

int main() {
  // Allocate memory for a string
  char* str = alloc_str(MAX_STR_LEN);
  if (str == NULL) {
    perror("alloc_str failed");
    exit(EXIT_FAILURE);
  }

  // Print the allocated string
  printf("Allocated string: %s\n", str);

  // Allocate memory for an array
  int arr[MAX_ARR_SIZE];
  void* mem = alloc_arr(MAX_ARR_SIZE);
  if (mem == NULL) {
    perror("alloc_arr failed");
    exit(EXIT_FAILURE);
  }

  // Print the allocated array
  for (int i = 0; i < MAX_ARR_SIZE; i++) {
    arr[i] = i * 2;
  }
  printf("Allocated array: {%d, %d, %d, %d, %d, %d}\n", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5]);

  // Deallocate memory for the string
  free_str(str);

  // Deallocate memory for the array
  free_arr(mem);

  return 0;
}