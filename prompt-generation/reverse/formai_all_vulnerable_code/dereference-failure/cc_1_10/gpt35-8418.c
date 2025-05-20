//FormAI DATASET v1.0 Category: Memory management ; Style: satisfied
#include <stdlib.h>
#include <stdio.h>

// A struct to represent a block of memory
struct memory_block {
    int size;
    char* start;
    int is_free;
    struct memory_block* next;
};

// A pointer to the first block of memory
struct memory_block* memory = NULL;

// Function to allocate memory
void* allocate_memory(size_t size) {
    struct memory_block *prev, *curr;
    void* result = NULL;

    // If memory is not initialized, initialize it
    if(memory == NULL) {
        memory = (struct memory_block*) malloc(sizeof(struct memory_block));
        memory->size = 0;
        memory->start = NULL;
        memory->is_free = 1;
        memory->next = NULL;
    }

    // Traverse the list of blocks to find a free block that can fit the requested size
    prev = memory;
    curr = memory->next;
    while(curr != NULL) {
        if(curr->is_free && curr->size >= size) {
            curr->is_free = 0;
            result = curr->start;
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    // If a free block was not found, allocate a new block of memory
    if(result == NULL) {
        curr = (struct memory_block*) malloc(sizeof(struct memory_block));
        curr->size = size;
        curr->start = (char*) malloc(size);
        curr->is_free = 0;
        curr->next = NULL;
        prev->next = curr;
        result = curr->start;
    }

    return result;
}

// Function to free memory
void free_memory(void* ptr) {
    struct memory_block *prev, *curr;

    // Traverse the list of blocks to find the block containing the pointer to free
    prev = memory;
    curr = memory->next;
    while(curr != NULL) {
        if(curr->start == ptr) {
            curr->is_free = 1;
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    // If the block being freed is adjacent to a free block, merge them into one block of memory
    if(curr != NULL && curr->is_free) {
        prev->next = curr->next;
        prev->size += curr->size;
        prev->start = curr->start;
        free(curr);
    }
}

// Testing the memory allocation functionality
int main() {
    int* data = (int*) allocate_memory(10 * sizeof(int));
    if(data == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for(int i=0; i<10; i++) {
        data[i] = i;
        printf("%d ", data[i]);
    }

    free_memory(data);

    return 0;
}