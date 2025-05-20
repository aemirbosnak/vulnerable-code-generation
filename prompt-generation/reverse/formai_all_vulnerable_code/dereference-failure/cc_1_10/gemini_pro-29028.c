//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: future-proof
#include <stdlib.h>
#include <stdio.h>

// Define a custom memory allocator that uses a linked list to manage memory blocks.
typedef struct MemBlock {
    size_t size;
    struct MemBlock *next;
    void *data;
} MemBlock;

MemBlock *head = NULL;

// Allocate memory using the custom allocator.
void *my_malloc(size_t size) {
    MemBlock *new_block = malloc(sizeof(MemBlock) + size);
    if (new_block == NULL) {
        return NULL;
    }
    new_block->size = size;
    new_block->next = head;
    new_block->data = (void *) (new_block + 1);
    head = new_block;
    return new_block->data;
}

// Free memory using the custom allocator.
void my_free(void *ptr) {
    MemBlock *current = head;
    MemBlock *prev = NULL;
    while (current != NULL) {
        if (current->data == ptr) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
    // If the pointer was not found, print an error message.
    fprintf(stderr, "Error: pointer not found in memory pool.\n");
}

// Test the custom memory allocator.
int main() {
    int *ptr1 = (int *) my_malloc(sizeof(int));
    *ptr1 = 42;
    printf("ptr1: %d\n", *ptr1);

    int *ptr2 = (int *) my_malloc(sizeof(int));
    *ptr2 = 100;
    printf("ptr2: %d\n", *ptr2);

    my_free(ptr1);
    my_free(ptr2);

    return 0;
}