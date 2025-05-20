//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: safe
#include <stdlib.h>
#include <stdio.h>

// Custom memory manager
typedef struct {
    void* ptr;
    size_t size;
} MemoryBlock;

MemoryBlock* memory_blocks = NULL;
size_t memory_blocks_count = 0;

void* my_malloc(size_t size) {
    // Allocate memory from the system
    void* ptr = malloc(size);
    if (ptr == NULL) {
        return NULL;
    }

    // Add the memory block to our list
    MemoryBlock* block = realloc(memory_blocks, (memory_blocks_count + 1) * sizeof(MemoryBlock));
    if (block == NULL) {
        free(ptr);
        return NULL;
    }
    memory_blocks = block;

    memory_blocks[memory_blocks_count].ptr = ptr;
    memory_blocks[memory_blocks_count].size = size;
    memory_blocks_count++;

    // Return the pointer to the allocated memory
    return ptr;
}

void my_free(void* ptr) {
    // Find the memory block associated with the pointer
    for (size_t i = 0; i < memory_blocks_count; i++) {
        if (memory_blocks[i].ptr == ptr) {
            // Free the memory block
            free(ptr);

            // Remove the memory block from our list
            memory_blocks[i] = memory_blocks[memory_blocks_count - 1];
            memory_blocks_count--;

            // Reallocate the memory blocks array to a smaller size
            memory_blocks = realloc(memory_blocks, memory_blocks_count * sizeof(MemoryBlock));

            // Return
            return;
        }
    }

    // The pointer was not found, so it was not allocated by our memory manager
}

int main() {
    // Allocate some memory using our custom memory manager
    int* arr = (int*) my_malloc(sizeof(int) * 10);
    if (arr == NULL) {
        printf("Error allocating memory.\n");
        return 1;
    }

    // Use the allocated memory
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }

    // Print the allocated memory
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the allocated memory
    my_free(arr);

    return 0;
}