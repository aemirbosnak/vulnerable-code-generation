//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

// Declare a function to manage our memory! 💪
void * alloc_mem(size_t size) {
  // Check if the size is negative, because whoa, that's just not right! 😳
  if (size < 0) {
    printf("Oops, you can't allocate negative memory! 😅\n");
    return NULL;
  }
  
  // Use malloc to allocate the memory, yay! 🎉
  void *ptr = malloc(size);
  
  // Check if malloc failed, boo! 😔
  if (ptr == NULL) {
    printf("Malloc failed! 😢\n");
    return NULL;
  }
  
  // Return the pointer to our happy user! 😊
  return ptr;
}

// Declare a function to deallocate our memory! 💸
void dealloc_mem(void *ptr) {
  // Check if the pointer is NULL, because why bother? 😴
  if (ptr == NULL) {
    printf("Whoa, you tried to deallocate NULL memory! 😱\n");
    return;
  }
  
  // Use free to deallocate the memory, yay! 💥
  free(ptr);
}

int main() {
  // Allocate some memory for a big ol' string! 📝
  char *str = alloc_mem(50);
  
  // Print out the allocated string! 📰
  printf("Allocated string: %s\n", str);
  
  // Deallocate the memory when we're done! 💸
  dealloc_mem(str);
  
  // Allocate some more memory for a smaller string! 📝
  char *str2 = alloc_mem(20);
  
  // Print out the second allocated string! 📰
  printf("Second allocated string: %s\n", str2);
  
  // Deallocate the second memory too! 💸
  dealloc_mem(str2);
  
  // Finally, allocate some memory for a integer! 🤔
  int *num = alloc_mem(4);
  
  // Print out the allocated integer! 📝
  printf("Allocated integer: %d\n", *num);
  
  // Deallocate the integer memory too! 💸
  dealloc_mem(num);
  
  return 0;
}