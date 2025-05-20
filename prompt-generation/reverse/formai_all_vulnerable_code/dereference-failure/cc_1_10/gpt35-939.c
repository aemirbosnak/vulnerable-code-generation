//FormAI DATASET v1.0 Category: Memory management ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define KB 1024
#define MB (KB * 1024)

int main() {
    char *ptr1, *ptr2, *ptr3;

    // Allocate 1 MB of memory
    ptr1 = (char*) malloc(MB);
    if (ptr1 != NULL) {
        printf("1 MB of memory has been allocated at address: %p\n", ptr1);
    } else {
        printf("Error: Failed to allocate memory\n");
        exit(1);
    }

    // Allocate 512 KB of memory
    ptr2 = (char*) malloc(512 * KB);
    if (ptr2 != NULL) {
        printf("512 KB of memory has been allocated at address: %p\n", ptr2);
    } else {
        printf("Error: Failed to allocate memory\n");
        exit(1);
    }

    // Allocate 256 KB of memory
    ptr3 = (char*) malloc(256 * KB);
    if (ptr3 != NULL) {
        printf("256 KB of memory has been allocated at address: %p\n", ptr3);
    } else {
        printf("Error: Failed to allocate memory\n");
        exit(1);
    }

    // Free allocated memory
    free(ptr1);
    free(ptr2);
    free(ptr3);

    // Allocate 2 MB of memory using calloc
    ptr1 = (char*) calloc(2, MB);
    if (ptr1 != NULL) {
        printf("2 MB of memory has been allocated using calloc at address: %p\n", ptr1);
    } else {
        printf("Error: Failed to allocate memory\n");
        exit(1);
    }

    // Reallocate memory
    ptr1 = (char*) realloc(ptr1, 3 * MB);
    if (ptr1 != NULL) {
        printf("Memory reallocated to 3 MB at address: %p\n", ptr1);
    } else {
        printf("Error: Failed to reallocate memory\n");
        exit(1);
    }

    // Free allocated memory
    free(ptr1);

    return 0;
}