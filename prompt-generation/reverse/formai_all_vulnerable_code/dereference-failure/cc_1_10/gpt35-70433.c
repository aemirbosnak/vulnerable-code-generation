//FormAI DATASET v1.0 Category: Memory management ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Define a structure for our memory block
struct MemoryBlock {
    int size;
    int free;
    struct MemoryBlock* next;
};

// Initialize the start of our memory pool
void* memory_pool_start;

// Create a new memory block
struct MemoryBlock* new_memory_block(int size, struct MemoryBlock* next) {
    struct MemoryBlock* block = (struct MemoryBlock*) malloc(sizeof(struct MemoryBlock));
    block->size = size;
    block->free = 0;
    block->next = next;
    return block;
}

// Allocate memory from our memory pool
void* my_malloc(int size) {
    struct MemoryBlock* current = memory_pool_start;
    struct MemoryBlock* previous = NULL;

    while (current != NULL) {
        if (current->free == 1 && current->size >= size) {
            // If this block is free and big enough, allocate memory here
            current->free = 0;
            return (void*) (current + 1);
        }
        previous = current;
        current = current->next;
    }

    // If we don't have enough free memory in our pool, allocate more
    current = (struct MemoryBlock*) malloc(sizeof(struct MemoryBlock) + size);
    current->size = size;
    current->free = 0;
    current->next = NULL;

    if (previous == NULL) {
        memory_pool_start = current;
    } else {
        previous->next = current;
    }

    return (void*) (current + 1);
}

// Free memory from our memory pool
void my_free(void* ptr) {
    if (ptr == NULL) {
        return;
    }

    struct MemoryBlock* block = (struct MemoryBlock*) ptr - 1;
    block->free = 1;

    // Merge free blocks together
    struct MemoryBlock* current = memory_pool_start;
    while (current != NULL && current->next != NULL) {
        if (current->free == 1 && current->next->free == 1) {
            current->size += current->next->size + sizeof(struct MemoryBlock);
            current->next = current->next->next;
        }
        current = current->next;
    }
}

// Initialize our memory pool with a given size
void init_memory_pool(int size) {
    memory_pool_start = (void*) malloc(size);
    struct MemoryBlock* first_block = new_memory_block(size - sizeof(struct MemoryBlock), NULL);
    first_block->free = 1;
    *((struct MemoryBlock*) memory_pool_start) = *first_block;
}

int main() {
    // Initialize our memory pool with 1 MB of memory
    init_memory_pool(1024 * 1024);

    // Allocate some memory
    int* x = (int*) my_malloc(sizeof(int));
    *x = 42;
    char* str = (char*) my_malloc(20);
    sprintf(str, "Hello world!");

    // Print the allocated memory
    printf("x = %d\n", *x);
    printf("str = %s\n", str);

    // Free the memory
    my_free(x);
    my_free(str);

    return 0;
}