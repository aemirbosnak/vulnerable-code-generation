//FormAI DATASET v1.0 Category: Memory management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure for our memory block
typedef struct MemBlock {
    void *address;
    size_t size;
    struct MemBlock *next;
} MemBlock;

// Initially we have a single block containing all of our memory
MemBlock *memory = NULL;

// Helper function for printing all allocated blocks of memory
void print_memory_blocks() {
    MemBlock *curr = memory;
    int i = 1;
    printf("Memory Blocks:\n");
    while (curr != NULL) {
        printf("Block %d: Address=%p, Size=%ld\n", i, curr->address, curr->size);
        curr = curr->next;
        i++;
    }
}

// Helper function for splitting a block of memory into two
MemBlock *split_memory_block(MemBlock *block, size_t size) {
    void *new_address = (char *) block->address + size;
    MemBlock *new_block = malloc(sizeof(MemBlock));
    if (new_block == NULL) {
        printf("Error: Cannot split memory block\n");
        return NULL;
    }
    new_block->address = new_address;
    new_block->size = block->size - size;
    new_block->next = block->next;
    
    block->size = size;
    block->next = new_block;
    return new_block;
}

// Helper function for merging two contiguous memory blocks
void merge_memory_blocks(MemBlock *block1, MemBlock *block2) {
    block1->size += block2->size;
    block1->next = block2->next;
    free(block2);
}

// Function to allocate a block of memory with the given size
void *my_malloc(size_t size) {
    if (size <= 0) {
        printf("Error: Invalid memory size\n");
        return NULL;
    }
    
    // Initialize the memory pool if it doesn't exist yet
    if (memory == NULL) {
        memory = malloc(sizeof(MemBlock));
        if (memory == NULL) {
            printf("Error: Cannot initialize memory pool\n");
            return NULL;
        }
        memory->address = malloc(MAX_SIZE);
        if (memory->address == NULL) {
            printf("Error: Cannot allocate memory block\n");
            free(memory);
            memory = NULL;
            return NULL;
        }
        memory->size = MAX_SIZE;
        memory->next = NULL;
    }
    
    // Find a suitable block of memory with enough space
    MemBlock *curr = memory;
    MemBlock *prev = NULL;
    while (curr != NULL) {
        if (curr->size >= size) {
            // Split the block if it has more space than needed
            if (curr->size > size) {
                split_memory_block(curr, size);
            }
            void *address = curr->address;
            // Remove the block from our list of memory blocks if we've used up all its space
            if (curr->size == 0) {
                if (prev == NULL) {
                    memory = curr->next;
                } else {
                    prev->next = curr->next;
                }
                free(curr);
            }
            return address;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Error: Out of memory\n");
    return NULL;
}

// Function to free a previously allocated block of memory
void my_free(void *ptr) {
    if (ptr == NULL) {
        return;
    }
    
    // Find the block of memory corresponding to this pointer
    MemBlock *curr = memory;
    MemBlock *prev = NULL;
    while (curr != NULL) {
        if (curr->address == ptr) {
            // Find the next contiguous block of memory and merge them together
            MemBlock *next = curr->next;
            if (next != NULL && (char *) curr->address + curr->size == next->address) {
                merge_memory_blocks(curr, next);
            }
            // Find the previous contiguous block of memory and merge them together
            if (prev != NULL && (char *) prev->address + prev->size == curr->address) {
                merge_memory_blocks(prev, curr);
            } else if (curr->size > 0) {
                // Add this block to our list of memory blocks if it's not already there
                MemBlock *new_block = malloc(sizeof(MemBlock));
                if (new_block == NULL) {
                    printf("Error: Cannot add memory block\n");
                } else {
                    new_block->address = curr->address;
                    new_block->size = curr->size;
                    new_block->next = memory;
                    memory = new_block;
                }
            }
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Error: Invalid pointer\n");
}

int main() {
    int *arr = (int *) my_malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) {
        arr[i] = i;
    }
    printf("Array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    print_memory_blocks();
    
    my_free(&arr[2]);
    printf("Array after deleting element 2: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    print_memory_blocks();
    
    my_free(&arr[0]);
    my_free(&arr[1]);
    my_free(&arr[3]);
    my_free(&arr[4]);
    print_memory_blocks();
    
    my_free(&arr[0]);
    return 0;
}