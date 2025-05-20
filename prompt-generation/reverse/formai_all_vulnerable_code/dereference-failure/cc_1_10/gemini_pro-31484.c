//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// A curious memory manager
// We'll use a linked list to keep track of allocated blocks
struct mem_block {
    size_t size;
    void *ptr;
    struct mem_block *next;
};

// The head of the linked list
struct mem_block *head = NULL;

// Allocate a block of memory
void *my_malloc(size_t size) {
    // First, we'll try to find a free block of the appropriate size
    struct mem_block *curr = head;
    while (curr != NULL) {
        if (curr->size == size && curr->ptr == NULL) {
            // We found a free block!
            curr->ptr = malloc(size);
            return curr->ptr;
        }
        curr = curr->next;
    }

    // If we didn't find a free block, we'll allocate a new one
    struct mem_block *new_block = malloc(sizeof(struct mem_block));
    new_block->size = size;
    new_block->ptr = malloc(size);
    new_block->next = NULL;

    // Add the new block to the linked list
    if (head == NULL) {
        head = new_block;
    } else {
        curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new_block;
    }

    return new_block->ptr;
}

// Free a block of memory
void my_free(void *ptr) {
    // Find the block that contains the pointer
    struct mem_block *curr = head;
    while (curr != NULL) {
        if (curr->ptr == ptr) {
            // We found the block!
            curr->ptr = NULL;
            return;
        }
        curr = curr->next;
    }

    // If we didn't find the block, we'll just ignore the request
}

// A test function
int main() {
    // Allocate some memory
    int *p1 = my_malloc(sizeof(int));
    int *p2 = my_malloc(sizeof(int));
    int *p3 = my_malloc(sizeof(int));

    // Free some memory
    my_free(p2);

    // Use the memory
    *p1 = 1;
    *p3 = 3;

    // Print the memory
    printf("%d %d\n", *p1, *p3);

    // Free the rest of the memory
    my_free(p1);
    my_free(p3);

    return 0;
}