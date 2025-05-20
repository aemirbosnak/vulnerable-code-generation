//Falcon-180B DATASET v1.0 Category: Memory management ; Style: enthusiastic
// C Memory Management Example Program

#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory dynamically
void* dynamic_memory_allocation(int size) {
    void* memory = malloc(size);
    if (memory == NULL) {
        printf("Error! Memory could not be allocated.\n");
        exit(1);
    }
    return memory;
}

// Function to free dynamically allocated memory
void free_memory(void* memory) {
    free(memory);
    printf("Memory successfully freed!\n");
}

// Main function
int main() {
    int size;

    // Allocate memory dynamically
    void* memory = dynamic_memory_allocation(10);

    // Use dynamically allocated memory
    printf("Using dynamically allocated memory...\n");
    for (int i = 0; i < 10; i++) {
        ((int*)memory)[i] = i;
    }

    // Free dynamically allocated memory
    free_memory(memory);

    // Allocate memory dynamically
    memory = dynamic_memory_allocation(20);

    // Use dynamically allocated memory
    printf("Using dynamically allocated memory...\n");
    for (int i = 0; i < 20; i++) {
        ((int*)memory)[i] = i;
    }

    // Free dynamically allocated memory
    free_memory(memory);

    // Allocate memory dynamically
    memory = dynamic_memory_allocation(30);

    // Use dynamically allocated memory
    printf("Using dynamically allocated memory...\n");
    for (int i = 0; i < 30; i++) {
        ((int*)memory)[i] = i;
    }

    // Free dynamically allocated memory
    free_memory(memory);

    return 0;
}
// Output:
// Using dynamically allocated memory...
// Memory successfully freed!
// Using dynamically allocated memory...
// Memory successfully freed!
// Using dynamically allocated memory...
// Memory successfully freed!