//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define some fun memory management functions
void * malloc_magic(size_t size) {
  void * magic = malloc(size);
  if (magic == NULL) {
    printf("Oops, we ran out of magic! :(");
  }
  return magic;
}

void free_fairy(void * mem) {
  free(mem);
  printf("Fairy free memories fly away... 🧚‍♀️\n");
}

int main() {
  // Create some enchanted objects
  char * name = malloc_magic(20);
  printf("Hello, my name is %s! 👸\n", name);

  int age = 25;
  int * age_ptr = &age;
  printf("I am %d years old... 👶\n", age);

  // Play with some memory
  char * message = malloc_magic(50);
  strcpy(message, "Once upon a time...");
  printf("I have a message for you: %s 📝\n", message);

  // Free the memories
  free_fairy(name);
  free_fairy(message);

  // Use a pointer to free some more memories
  void * magic_ptr = malloc_magic(10);
  free_fairy(magic_ptr);

  // Play with some more memory
  int * array = malloc_magic(5 * sizeof(int));
  for (int i = 0; i < 5; i++) {
    array[i] = i * 2;
  }
  printf("My array contains: ");
  for (int i = 0; i < 5; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  // Free the array
  free_fairy(array);

  return 0;
}