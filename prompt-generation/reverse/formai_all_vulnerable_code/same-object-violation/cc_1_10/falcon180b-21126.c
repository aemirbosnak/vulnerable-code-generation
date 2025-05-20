//Falcon-180B DATASET v1.0 Category: Memory management ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Struct to hold a block of memory
typedef struct {
    size_t size;
    int is_free;
    void* data;
} block_t;

// Initialize the memory pool
void init_pool() {
    block_t* first_block = (void*)0x100000; // Start at 1MB
    first_block->size = 0xfffff - sizeof(block_t);
    first_block->is_free = true;
    first_block->data = (void*)(first_block + 1);
}

// Allocate a block of memory
void* malloc(size_t size) {
    block_t* current = (void*)0x100000; // Start at 1MB
    while (current->size < size ||!current->is_free) {
        current = (void*)((int)current + current->size + sizeof(block_t));
        if ((int)current >= (int)0x200000) { // End of memory pool
            return NULL;
        }
    }
    current->is_free = false;
    return current->data;
}

// Free a block of memory
void free(void* ptr) {
    block_t* block = (void*)0x100000; // Start at 1MB
    while (block < (void*)((int)ptr - sizeof(block_t))) {
        if (block->data == ptr) {
            block->is_free = true;
            break;
        }
        block = (void*)((int)block + block->size + sizeof(block_t));
        if ((int)block >= (int)0x200000) { // End of memory pool
            return;
        }
    }
}

// Main function to test memory allocation and deallocation
int main() {
    init_pool();
    void* ptr1 = malloc(100);
    void* ptr2 = malloc(200);
    void* ptr3 = malloc(300);
    void* ptr4 = malloc(400);
    printf("Allocated %p, %p, %p, %p\n", ptr1, ptr2, ptr3, ptr4);
    free(ptr1);
    free(ptr3);
    printf("Freed %p, %p\n", ptr1, ptr3);
    void* ptr5 = malloc(500);
    printf("Allocated %p\n", ptr5);
    free(ptr2);
    free(ptr4);
    free(ptr5);
    return 0;
}