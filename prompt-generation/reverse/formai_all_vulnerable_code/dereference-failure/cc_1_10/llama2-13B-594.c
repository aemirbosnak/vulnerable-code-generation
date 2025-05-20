//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to store memory blocks
typedef struct {
    void* data;    // Pointer to the data stored in the block
    size_t size;   // Size of the block
    struct Node* next; // Pointer to the next block in the list
} MemBlock;

// Function to allocate memory
MemBlock* allocMem(size_t size) {
    MemBlock* block = (MemBlock*) malloc(sizeof(MemBlock));
    block->data = malloc(size);
    block->size = size;
    block->next = NULL;
    return block;
}

// Function to deallocate memory
void freeMem(MemBlock* block) {
    if (block == NULL) {
        return;
    }
    free(block->data);
    free(block);
}

// Function to print the memory blocks
void printMem(MemBlock* block) {
    if (block == NULL) {
        return;
    }
    printf("Memory Blocks:\n");
    while (block != NULL) {
        printf("  %p - %zu bytes\n", block->data, block->size);
        block = block->next;
    }
}

int main() {
    // Allocate some memory blocks
    MemBlock* block1 = allocMem(100);
    MemBlock* block2 = allocMem(200);
    MemBlock* block3 = allocMem(300);

    // Print the memory blocks
    printMem(block1);
    printMem(block2);
    printMem(block3);

    // Deallocate the memory blocks
    freeMem(block1);
    freeMem(block2);
    freeMem(block3);

    // Allocate a large memory block
    MemBlock* largeBlock = allocMem(1000);

    // Split the large block into smaller blocks
    MemBlock* block4 = allocMem(500);
    MemBlock* block5 = allocMem(300);
    MemBlock* block6 = allocMem(200);

    // Print the memory blocks again
    printMem(block1);
    printMem(block2);
    printMem(block3);
    printMem(block4);
    printMem(block5);
    printMem(block6);

    // Deallocate the memory blocks
    freeMem(block1);
    freeMem(block2);
    freeMem(block3);
    freeMem(block4);
    freeMem(block5);
    freeMem(block6);

    return 0;
}