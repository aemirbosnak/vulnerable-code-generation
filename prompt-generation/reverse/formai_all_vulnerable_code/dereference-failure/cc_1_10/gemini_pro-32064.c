//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Define a custom memory allocator that tracks allocations and deallocations
typedef struct {
    void* ptr;
    size_t size;
    char* file;
    int line;
} MemoryBlock;

typedef struct {
    MemoryBlock* blocks;
    size_t num_blocks;
    size_t capacity;
} MemoryAllocator;

MemoryAllocator* CreateMemoryAllocator() {
    MemoryAllocator* allocator = malloc(sizeof(MemoryAllocator));
    allocator->blocks = NULL;
    allocator->num_blocks = 0;
    allocator->capacity = 0;
    return allocator;
}

void DestroyMemoryAllocator(MemoryAllocator* allocator) {
    for (size_t i = 0; i < allocator->num_blocks; i++) {
        free(allocator->blocks[i].ptr);
    }
    free(allocator->blocks);
    free(allocator);
}

void* AllocateMemory(MemoryAllocator* allocator, size_t size, char* file, int line) {
    // Check if the allocator has enough capacity
    if (allocator->num_blocks == allocator->capacity) {
        // Reallocate the blocks array with double the capacity
        allocator->blocks = realloc(allocator->blocks, 2 * allocator->capacity * sizeof(MemoryBlock));
        allocator->capacity *= 2;
    }

    // Allocate memory for the new block
    MemoryBlock* block = &allocator->blocks[allocator->num_blocks];
    block->ptr = malloc(size);
    block->size = size;
    block->file = file;
    block->line = line;

    // Increment the number of blocks
    allocator->num_blocks++;

    // Return the pointer to the allocated memory
    return block->ptr;
}

void DeallocateMemory(MemoryAllocator* allocator, void* ptr) {
    // Find the block corresponding to the given pointer
    for (size_t i = 0; i < allocator->num_blocks; i++) {
        if (allocator->blocks[i].ptr == ptr) {
            // Free the memory for the block
            free(allocator->blocks[i].ptr);
            // Shift the remaining blocks down to fill the gap
            for (size_t j = i + 1; j < allocator->num_blocks; j++) {
                allocator->blocks[j - 1] = allocator->blocks[j];
            }
            // Decrement the number of blocks
            allocator->num_blocks--;
            // Return
            return;
        }
    }

    // If the block was not found, raise an error
    fprintf(stderr, "Error: pointer not found in memory allocator\n");
    exit(1);
}

// Define a macro to simplify memory allocation
#define MALLOC(size) AllocateMemory(allocator, size, __FILE__, __LINE__)

// Define a macro to simplify memory deallocation
#define FREE(ptr) DeallocateMemory(allocator, ptr)

int main() {
    // Create a memory allocator
    MemoryAllocator* allocator = CreateMemoryAllocator();

    // Allocate some memory using the allocator
    int* array = MALLOC(10 * sizeof(int));
    char* string = MALLOC(20);

    // Use the allocated memory
    for (int i = 0; i < 10; i++) {
        array[i] = i;
    }
    strcpy(string, "Hello, world!");

    // Print the allocated memory
    for (int i = 0; i < 10; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }
    printf("string = %s\n", string);

    // Deallocate the allocated memory
    FREE(array);
    FREE(string);

    // Destroy the memory allocator
    DestroyMemoryAllocator(allocator);

    return 0;
}