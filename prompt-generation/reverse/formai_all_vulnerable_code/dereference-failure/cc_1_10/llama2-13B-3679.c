//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAGIC_NUMBER 0x42

void* mem_alloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        printf("Oops, out of memory! 😱\n");
        exit(1);
    }
    // Add some magic to the memory
    *((int*)ptr) = MAGIC_NUMBER;
    return ptr;
}

void mem_free(void* ptr) {
    if (ptr == NULL) {
        printf("Error: Trying to free a NULL pointer! 😳\n");
        return;
    }
    // Remove the magic from the memory
    int magic = *((int*)ptr);
    if (magic != MAGIC_NUMBER) {
        printf("Error: Attempt to free a non-magical pointer! 😶\n");
        return;
    }
    free(ptr);
}

int main() {
    void* p1 = mem_alloc(10);
    void* p2 = mem_alloc(20);
    void* p3 = mem_alloc(30);

    // Use the memory
    printf("p1: %p\np2: %p\np3: %p\n", p1, p2, p3);

    // Free the memory
    mem_free(p1);
    mem_free(p2);
    mem_free(p3);

    // Check if the memory is still magic
    if (*((int*)p1) != MAGIC_NUMBER) {
        printf("Error: Memory not properly freed! 😱\n");
        return 1;
    }
    if (*((int*)p2) != MAGIC_NUMBER) {
        printf("Error: Memory not properly freed! 😱\n");
        return 1;
    }
    if (*((int*)p3) != MAGIC_NUMBER) {
        printf("Error: Memory not properly freed! 😱\n");
        return 1;
    }

    return 0;
}