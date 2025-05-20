//Gemma-7B DATASET v1.0 Category: Memory management ; Style: protected
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_MEMORY 1024

typedef struct MemoryBlock {
    struct MemoryBlock* nextBlock;
    void* memory;
    int size;
} MemoryBlock;

MemoryBlock* createMemoryBlock(int size) {
    MemoryBlock* block = malloc(sizeof(MemoryBlock));
    block->nextBlock = NULL;
    block->memory = malloc(size);
    block->size = size;
    return block;
}

void freeMemoryBlock(MemoryBlock* block) {
    free(block->memory);
    free(block);
}

int main() {
    MemoryBlock* head = NULL;

    // Allocate memory for the first block
    MemoryBlock* block = createMemoryBlock(100);
    head = block;

    // Allocate memory for the second block
    block = createMemoryBlock(200);
    block->nextBlock = head;

    // Allocate memory for the third block
    block = createMemoryBlock(300);
    block->nextBlock = head->nextBlock;

    // Free memory for the first block
    freeMemoryBlock(head);

    // Print the remaining blocks
    block = head->nextBlock;
    while (block) {
        printf("Block size: %d\n", block->size);
        block = block->nextBlock;
    }

    return 0;
}