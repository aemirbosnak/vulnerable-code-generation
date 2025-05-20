//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAGIC_NUMBER 42

void* mem_alloc(size_t size) {
    void* p = malloc(size);
    if (p == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    return p;
}

void mem_free(void* p) {
    free(p);
    printf("Memory freed: %p\n", p);
}

void* mem_realloc(void* p, size_t size) {
    void* new_p = realloc(p, size);
    if (new_p == NULL) {
        perror("realloc failed");
        exit(EXIT_FAILURE);
    }
    return new_p;
}

int main() {
    size_t size = 100;
    void* p = mem_alloc(size);
    if (p == NULL) {
        return 1;
    }

    // Do some magic with the memory
    memset(p, MAGIC_NUMBER, size);
    printf("Memory allocated at %p, size %zu\n", p, size);

    // Reallocate the memory
    size = 200;
    p = mem_realloc(p, size);
    if (p == NULL) {
        return 2;
    }

    // Do some more magic with the memory
    memset(p, MAGIC_NUMBER, size);
    printf("Memory reallocated at %p, size %zu\n", p, size);

    // Free the memory
    mem_free(p);
    printf("Memory freed at %p\n", p);

    return 0;
}