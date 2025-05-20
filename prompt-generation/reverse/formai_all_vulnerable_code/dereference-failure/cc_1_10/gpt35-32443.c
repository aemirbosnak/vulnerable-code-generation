//FormAI DATASET v1.0 Category: Memory management ; Style: brave
#include <stdio.h>
#include <stdlib.h>

typedef struct MemBlock MemBlock; // Memory block struct
struct MemBlock {
    void* mem;
    size_t size;
    MemBlock* next;
};

MemBlock* head = NULL; // Head of memory block linked list

void* custom_malloc(size_t size) {
    void* mem = malloc(size); // Allocate memory using default malloc
    if (!mem) { // Check if allocation failed
        return NULL;
    }
    MemBlock* block = (MemBlock*)malloc(sizeof(MemBlock)); // Allocate MemBlock
    if (!block) { // Check if allocation failed
        free(mem);
        return NULL;
    }
    block->mem = mem; // Store the memory pointer
    block->size = size; // Store the size of allocated block
    block->next = head; // Add to head of linked list
    head = block;
    return mem; // Return the memory pointer
}

void custom_free(void* mem) {
    if (!mem) { // Check if memory is null
        return;
    }
    MemBlock* prev = NULL;
    for (MemBlock* curr = head; curr; prev = curr, curr = curr->next) {
        if (curr->mem == mem) { // Check if memory pointer matches
            if (prev) {
                prev->next = curr->next; // Remove the block from linked list
            } else {
                head = curr->next;
            }
            free(mem); // Free memory
            free(curr); // Free MemBlock
            return;
        }
    }
}

int main() {
    int* a = custom_malloc(sizeof(int)); // Allocate an int
    *a = 42; // Assign a value
    printf("%d\n", *a); // Print value
    custom_free(a); // Free the memory
    return 0;
}