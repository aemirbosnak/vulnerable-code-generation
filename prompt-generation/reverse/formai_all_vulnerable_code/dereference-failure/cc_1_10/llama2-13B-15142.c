//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAGIC_NUMBER 42

void* alloc_magic(size_t size) {
    void* mem = malloc(size);
    if (!mem) {
        printf("Failed to allocate memory: %zu\n", size);
        return NULL;
    }
    // Add some magic to the memory
    *(int*)mem = MAGIC_NUMBER;
    return mem;
}

void free_magic(void* mem) {
    if (mem == NULL) {
        printf("Attempt to free null pointer\n");
        return;
    }
    // Remove the magic from the memory
    int magic = *(int*)mem;
    if (magic != MAGIC_NUMBER) {
        printf("Invalid magic number: %d\n", magic);
        return;
    }
    free(mem);
}

int main() {
    // Allocate some memory with magic
    void* mem1 = alloc_magic(100);
    if (!mem1) {
        printf("Failed to allocate memory\n");
        return 1;
    }
    // Use the memory
    char* str = (char*)mem1;
    strcpy(str, "Hello, world!");
    // Free the memory
    free_magic(mem1);

    // Allocate some more memory with magic
    void* mem2 = alloc_magic(500);
    if (!mem2) {
        printf("Failed to allocate memory\n");
        return 1;
    }
    // Use the memory
    double* doubles = (double*)mem2;
    doubles[0] = 3.14;
    doubles[1] = 2.71;
    // Free the memory
    free_magic(mem2);

    // Attempt to free a null pointer
    free_magic(NULL);

    return 0;
}