//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAGIC_NUMBER 0xDEADBEEF

void* mem_alloc(size_t size) {
    void* ptr = NULL;
    if (size > 0) {
        ptr = malloc(size);
        if (ptr == NULL) {
            printf("Memory allocation failed\n");
            abort();
        }
        *(int*)ptr = MAGIC_NUMBER;
    }
    return ptr;
}

void mem_free(void* ptr) {
    if (ptr != NULL) {
        int magic = *(int*)ptr;
        if (magic == MAGIC_NUMBER) {
            free(ptr);
        } else {
            printf("Attempt to free invalid memory\n");
            abort();
        }
    }
}

int main() {
    void* p1 = mem_alloc(10);
    void* p2 = mem_alloc(20);
    void* p3 = mem_alloc(30);

    // Use the memory allocated by mem_alloc
    char* s1 = (char*)p1;
    char* s2 = (char*)p2;
    char* s3 = (char*)p3;

    strcpy(s1, "Hello, world!");
    strcpy(s2, "This is a longer string!");
    strcpy(s3, "And this is the longest string!");

    // Free the memory allocated by mem_alloc
    mem_free(p1);
    mem_free(p2);
    mem_free(p3);

    return 0;
}