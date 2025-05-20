//FormAI DATASET v1.0 Category: Memory management ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Struct to represent a block of memory
struct mem_block {
    int size;
    int free;
    struct mem_block *next;
};

// Global pointer to the first block of memory
struct mem_block *head = NULL;

// Function to initialize memory block with given size
void init_memory(int size) {
    head = (struct mem_block *)malloc(sizeof(struct mem_block));
    head->size = size - sizeof(struct mem_block);
    head->free = 1;
    head->next = NULL;
}

// Function to split a memory block into two blocks
void split_block(struct mem_block *block, int size) {
    struct mem_block *new_block = (struct mem_block *)((char *)block + size + sizeof(struct mem_block));
    new_block->size = block->size - size - sizeof(struct mem_block);
    new_block->free = 1;
    new_block->next = block->next;
    block->size = size;
    block->free = 0;
    block->next = new_block;
}

// Function to allocate memory of given size
void *mem_alloc(int size) {
    struct mem_block *curr = head;
    struct mem_block *prev = NULL;
    while (curr != NULL) {
        if (curr->free && curr->size >= size) {
            if (curr->size >= size + sizeof(struct mem_block) + 1) {
                split_block(curr, size);
            }
            curr->free = 0;
            return (void*)(curr + 1);
        }
        prev = curr;
        curr = curr->next;
    }
    return NULL;
}

// Function to merge adjacent free memory blocks
void merge_blocks() {
    struct mem_block *curr = head;
    while (curr != NULL && curr->next != NULL) {
        if (curr->free && curr->next->free) {
            curr->size += curr->next->size + sizeof(struct mem_block);
            curr->next = curr->next->next;
        }
        curr = curr->next;
    }
}

// Function to free allocated memory
void mem_free(void *ptr) {
    struct mem_block *block = (struct mem_block *)ptr - 1;
    block->free = 1;
    merge_blocks();
}

int main() {
    // Initialize memory with size 1024 bytes
    init_memory(1024);

    // Allocate memory for an integer
    int *a = (int *)mem_alloc(sizeof(int));
    *a = 10;

    // Allocate memory for a string
    char *str = (char *)mem_alloc(10 * sizeof(char));
    str = "hello";

    // Print the allocated memory
    printf("a = %d\n", *a);
    printf("str = %s\n", str);

    // Free the allocated memory
    mem_free(a);
    mem_free(str);

    return 0;
}