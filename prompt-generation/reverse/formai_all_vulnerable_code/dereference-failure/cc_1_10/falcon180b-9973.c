//Falcon-180B DATASET v1.0 Category: Memory management ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

/* Recursive function to allocate memory */
void *recursive_malloc(size_t size) {
    void *ptr;
    if (size <= 0) {
        printf("Invalid size specified!\n");
        exit(1);
    }

    /* Allocate memory using recursive function */
    if ((ptr = malloc(size)) == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    /* Initialize memory with zeros */
    memset(ptr, 0, size);

    return ptr;
}

/* Recursive function to free memory */
void recursive_free(void *ptr) {
    if (ptr!= NULL) {
        free(ptr);
    }
}

/* Recursive function to print memory allocation details */
void print_memory_allocation_details(void *ptr) {
    printf("Memory allocated at: %p\n", ptr);
    printf("Size of memory allocated: %ld bytes\n", sizeof(ptr));
}

/* Main function */
int main() {
    void *ptr1, *ptr2, *ptr3;

    /* Allocate memory recursively */
    ptr1 = recursive_malloc(MAX_SIZE);
    print_memory_allocation_details(ptr1);

    /* Allocate memory recursively */
    ptr2 = recursive_malloc(MAX_SIZE);
    print_memory_allocation_details(ptr2);

    /* Allocate memory recursively */
    ptr3 = recursive_malloc(MAX_SIZE);
    print_memory_allocation_details(ptr3);

    /* Free memory recursively */
    recursive_free(ptr1);
    recursive_free(ptr2);
    recursive_free(ptr3);

    return 0;
}