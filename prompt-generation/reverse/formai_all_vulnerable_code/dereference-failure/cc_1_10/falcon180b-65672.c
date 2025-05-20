//Falcon-180B DATASET v1.0 Category: Memory management ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Macros for memory allocation
#define MALLOC(size) (void*)malloc(size)
#define CALLOC(count, size) (void*)calloc(count, size)
#define REALLOC(ptr, size) (void*)realloc(ptr, size)
#define FREE(ptr) free(ptr)

// Function prototypes
void* my_malloc(size_t size);
void* my_realloc(void* ptr, size_t size);
void my_free(void* ptr);

// Global variables for tracking memory usage
size_t total_allocated = 0;
size_t current_allocated = 0;

int main() {
    // Allocate some memory
    void* ptr1 = MALLOC(1024);
    void* ptr2 = CALLOC(10, 128);

    // Use the allocated memory
    char* str1 = (char*)ptr1;
    sprintf(str1, "Hello, world!");

    int* arr2 = (int*)ptr2;
    for (int i = 0; i < 10; i++) {
        arr2[i] = i * 2;
    }

    // Reallocate some memory
    void* ptr3 = REALLOC(ptr1, 2048);
    char* str2 = (char*)ptr3;
    sprintf(str2, "This is a longer string.");

    // Free some memory
    FREE(ptr2);
    FREE(ptr3);

    printf("Total memory allocated: %zu bytes\n", total_allocated);
    printf("Current memory allocated: %zu bytes\n", current_allocated);

    return 0;
}

// Custom memory allocation functions
void* my_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr!= NULL) {
        total_allocated += size;
        current_allocated += size;
    }
    return ptr;
}

void* my_realloc(void* ptr, size_t size) {
    void* new_ptr = realloc(ptr, size);
    if (new_ptr!= NULL) {
        if (ptr!= new_ptr) {
            FREE(ptr);
        }
        total_allocated += size - (new_ptr - ptr);
        current_allocated += size;
    }
    return new_ptr;
}

void my_free(void* ptr) {
    if (ptr!= NULL) {
        FREE(ptr);
        current_allocated -= malloc_usable_size(ptr);
    }
}