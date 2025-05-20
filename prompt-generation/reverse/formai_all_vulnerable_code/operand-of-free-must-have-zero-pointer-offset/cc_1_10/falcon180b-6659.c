//Falcon-180B DATASET v1.0 Category: Memory management ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory dynamically
void* my_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    return ptr;
}

// Function to free memory dynamically
void my_free(void* ptr) {
    free(ptr);
}

// Function to print the current status of memory
void print_memory_status() {
    size_t total_memory = 0, free_memory = 0;
    if (mallinfo(&total_memory, &free_memory)!= 0) {
        printf("Error getting memory status!\n");
        exit(1);
    }
    printf("Total memory: %zu bytes\n", total_memory);
    printf("Free memory: %zu bytes\n", free_memory);
}

int main() {
    int i;
    printf("Memory management example program\n");

    // Allocate memory dynamically
    int* ptr1 = my_malloc(sizeof(int) * 10);
    printf("Allocated memory: %p\n", ptr1);

    // Initialize the allocated memory
    for (i = 0; i < 10; i++) {
        *ptr1 = i;
        ptr1++;
    }

    // Print the current status of memory
    print_memory_status();

    // Free the allocated memory
    my_free(ptr1);

    // Print the current status of memory
    print_memory_status();

    return 0;
}