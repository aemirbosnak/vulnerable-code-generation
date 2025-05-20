//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAGIC_NUMBER 0xDEADBEEF

void *mem_alloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Memory allocation failed! Size: %zu\n", size);
        exit(1);
    }
    // Add some magic to the memory block
    *((int *)ptr) = MAGIC_NUMBER;
    return ptr;
}

void mem_free(void *ptr) {
    free(ptr);
    // Remove the magic from the memory block
    *((int *)ptr) = 0;
}

int main() {
    void *ptr1 = mem_alloc(10);
    void *ptr2 = mem_alloc(20);
    void *ptr3 = mem_alloc(30);

    // Do some stuff with the memory blocks
    strcpy(ptr1, "Hello");
    strcpy(ptr2, "World");
    strcpy(ptr3, "!");

    // Free the memory blocks
    mem_free(ptr1);
    mem_free(ptr2);
    mem_free(ptr3);

    // Check if the memory blocks are still valid
    if (ptr1 != NULL) {
        printf("ptr1 is still valid\n");
    } else {
        printf("ptr1 is invalid\n");
    }
    if (ptr2 != NULL) {
        printf("ptr2 is still valid\n");
    } else {
        printf("ptr2 is invalid\n");
    }
    if (ptr3 != NULL) {
        printf("ptr3 is still valid\n");
    } else {
        printf("ptr3 is invalid\n");
    }

    return 0;
}