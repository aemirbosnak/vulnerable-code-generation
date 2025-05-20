//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRLEN 1024
#define MAX_ARRAY_SIZE 1024

void* mem_alloc(size_t size) {
    void* mem = malloc(size);
    if (mem == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    return mem;
}

void mem_free(void* mem) {
    free(mem);
}

int main() {
    // Allocate memory for a large array
    int* arr = (int*)mem_alloc(MAX_ARRAY_SIZE * sizeof(int));
    if (arr == NULL) {
        return 1;
    }

    // Allocate memory for a string
    char* str = (char*)mem_alloc(strlen("Hello, world!") + 1);
    if (str == NULL) {
        mem_free(arr);
        return 1;
    }

    // Copy the string into the allocated memory
    strcpy(str, "Hello, world!");

    // Print the array and the string
    for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("%s\n", str);

    // Free the memory for the array and the string
    mem_free(arr);
    mem_free(str);

    return 0;
}