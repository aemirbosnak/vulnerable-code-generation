//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAGIC_NUMBER 42

void* mem_alloc(size_t size) {
    void* p = malloc(size);
    if (p == NULL) {
        printf("Error: Out of memory!\n");
        exit(1);
    }
    return p;
}

void mem_free(void* p) {
    free(p);
    printf("Memory freed successfully!\n");
}

int main() {
    // Initialize memory pool
    void* p = mem_alloc(100);
    if (p == NULL) {
        printf("Error: Out of memory!\n");
        return 1;
    }

    // Allocate and free memory puzzle
    void* q = mem_alloc(50);
    if (q == NULL) {
        printf("Error: Out of memory!\n");
        return 1;
    }

    // Puzzle clue 1:
    // The memory address of q is equal to the memory address of p + MAGIC_NUMBER.
    printf("Puzzle clue 1: The memory address of q is equal to the memory address of p + %d.\n", MAGIC_NUMBER);

    // Free q
    mem_free(q);

    // Puzzle clue 2:
    // The memory address of p is equal to the memory address of q + MAGIC_NUMBER.
    printf("Puzzle clue 2: The memory address of p is equal to the memory address of q + %d.\n", MAGIC_NUMBER);

    // Free p
    mem_free(p);

    return 0;
}