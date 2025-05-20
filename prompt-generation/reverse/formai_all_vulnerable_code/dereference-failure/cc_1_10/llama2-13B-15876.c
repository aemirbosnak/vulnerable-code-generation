//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAGIC_NUMBER 0xDEADBEEF

void* mem_alloc(size_t size) {
    void* p = malloc(size);
    if (p == NULL) {
        printf("Error: Memory allocation failed\n");
        return NULL;
    }
    // Add some randomness to the memory block
    int rnd = rand() % 100;
    memset(p, rnd, size);
    return p;
}

void mem_free(void* p) {
    free(p);
    printf("Memory freed: %p\n", p);
}

int main() {
    // Allocate some memory
    void* p1 = mem_alloc(100);
    void* p2 = mem_alloc(200);
    void* p3 = mem_alloc(300);

    // Do some stuff with the memory
    char* s1 = (char*)p1;
    strcpy(s1, "Hello, world!");
    char* s2 = (char*)p2;
    strcpy(s2, "Random data");
    char* s3 = (char*)p3;
    strcpy(s3, "More random data");

    // Free the memory
    mem_free(p1);
    mem_free(p2);
    mem_free(p3);

    // Check if the memory is still valid
    if (p1 != NULL) {
        printf("Memory at %p is still valid\n", p1);
    }
    if (p2 != NULL) {
        printf("Memory at %p is still valid\n", p2);
    }
    if (p3 != NULL) {
        printf("Memory at %p is still valid\n", p3);
    }

    return 0;
}