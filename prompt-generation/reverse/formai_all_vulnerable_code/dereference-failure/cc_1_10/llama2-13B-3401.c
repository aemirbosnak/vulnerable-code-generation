//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define MAGIC_NUMBER 42

void* mem_alloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        printf("Oops, out of memory! (%zu bytes)\n", size);
        return NULL;
    }
    printf("Memory allocated at %p (%zu bytes)\n", ptr, size);
    return ptr;
}

void mem_free(void* ptr) {
    free(ptr);
    printf("Memory freed at %p\n", ptr);
}

int main() {
    srand(time(NULL));

    // Allocate some memory
    void* ptr1 = mem_alloc(100);
    void* ptr2 = mem_alloc(50);
    void* ptr3 = mem_alloc(200);

    // Play some memory games
    printf("Swapping memory locations...\n");
    void* temp = ptr1;
    ptr1 = ptr2;
    ptr2 = ptr3;
    ptr3 = temp;

    // Free some memory
    printf("Freeing memory...\n");
    mem_free(ptr1);
    mem_free(ptr2);

    // Check for leaks
    printf("Checking for leaks...\n");
    if (ptr3 == NULL) {
        printf("No leaks detected.\n");
    } else {
        printf("Leak detected! (%p)\n", ptr3);
    }

    return 0;
}